/*

  Embedded File System (EFS)
  --------------------------

  file        : efs_lib.c 
  author      : Alekmaul & Noda
  description : File system functions

  history : 

    12/05/2007 - v1.0
      = Original release
      
    13/05/2007 - v1.1
      = corrected problems with nds files with loader
      = corrected problems with nds files made with standard libnds makefile
      + optimised variables, now use 505 bytes less in RAM
      + added EFS_Flush() function, to ensure data is written
      + included ASM code for reserved space

    14/05/2007 - v1.1a
      = corrected bug with EFS_fopen() when filename does not begin with "/"
      + added defines for c++ compatibility
      
    28/09/2007 - v1.2
      = corrected a major bug with EFS_fread and EFS_fwrite
      = moved some functions tweaks to fix real fat mode
      + added autoflush on file close by default
      + added extension checking when searching the NDS file (improve speed)
      
    TODO:
      + Add optional sequential file opening mode [add EFS_nextFile()]
      
*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/dir.h>

#include "efs_lib.h"

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef EFS_REAL_FAT_MODE

#define EFS_READBUFFERSIZE  4096
#define EFS_SEARCHFILE      0
#define EFS_SEARCHDIR       1
#define EFS_LISTDIR         2

// mix up the magic string to avoid doubling it in the NDS
const char efsMagicStringP2[] = " EFSstr";
const char efsMagicStringP1[] = "\xCE\x05\xA9\xBF";

FILE *nds_file;
u32 fnt_offset;
u32 fat_offset;
bool hasLoader;

char fileInNDS[EFS_MAXPATHLEN];
bool filematch;
u8 searchmode;
u32 file_idpos;
u32 file_idsize;

// extract directory
void ExtractDirectory(char *prefix, u32 dir_id) {
    char strbuf[EFS_MAXPATHLEN];
    u32 entry_start;    // reference location of entry name
    u16 top_file_id;    // file ID of top entry
    u32 file_id;
    u32 save_filepos = ftell(nds_file);

    fseek(nds_file, fnt_offset + 8*(dir_id & 0xFFF), SEEK_SET);
    fread(&entry_start, 1, sizeof(entry_start), nds_file);
    fread(&top_file_id, 1, sizeof(top_file_id), nds_file);
    fseek(nds_file, fnt_offset + entry_start, SEEK_SET);
    
    if((searchmode == EFS_LISTDIR) && file_idpos)
            fseek(nds_file, file_idpos, SEEK_SET);

    for(file_id=top_file_id; !filematch; file_id++) {
        u8 entry_type_name_length;
        u32 name_length;
        bool entry_type_directory;
        char entry_name[EFS_MAXNAMELEN];
        
        fread(&entry_type_name_length, 1, sizeof(entry_type_name_length), nds_file);
        name_length = entry_type_name_length & 127;
        entry_type_directory = (entry_type_name_length & 128) ? true : false;
        if(name_length == 0)
            break;

        memset(entry_name, 0, EFS_MAXNAMELEN);
        fread(entry_name, 1, entry_type_name_length & 127, nds_file);

        if(searchmode == EFS_LISTDIR) {
            strcpy(fileInNDS, entry_name);
            file_idpos = ftell(nds_file);
            if(entry_type_directory) {
                file_idpos += 2;
                file_idsize = 1;
            } else {
                file_idsize = 0;
            }
            filematch = true;
            break;
        }

        if(entry_type_directory) {
            u16 dir_id;
            fread(&dir_id, 1, sizeof(dir_id), nds_file);
            strcpy(strbuf, prefix);
            strcat(strbuf, entry_name);
            strcat(strbuf, "/");
            
            if((searchmode == EFS_SEARCHDIR) && !strcmp(strbuf, fileInNDS)) {
                file_idpos = dir_id;
                filematch = true;
                break;
            }
            
            ExtractDirectory(strbuf, dir_id);
            
        } else if(searchmode == EFS_SEARCHFILE) {
            strcpy(strbuf, prefix);
            strcat(strbuf, entry_name);
            
            if (!strcmp(strbuf, fileInNDS)) {
                u32 top;
                u32 bottom;
                file_idpos = fat_offset + 8*file_id;
                fseek(nds_file, file_idpos, SEEK_SET);
                fread(&top, 1, sizeof(top), nds_file);
                fread(&bottom, 1, sizeof(bottom), nds_file);
                file_idsize = bottom - top;
                filematch = true;
                break;
            }
        }
    }

    fseek(nds_file, save_filepos, SEEK_SET);
}

// check if the file is the good one, and save the path if desired
bool CheckFile(char *path, bool save) {
    bool ok = false;
    char ext[7], *ext2 = ext + 2;
    int i;
    u32 size;
    FILE *f;
    
    // check file extension
    strcpy(ext, path + strlen(path) - 6);
    for(i=0; i<7; ++i)
        ext[i] = tolower(ext[i]);
    
    if(!strcmp(ext2, ".nds") || !strcmp(ext2, ".bin") || !strcmp(ext, "ds.gba")) {
        if((f = fopen(path, "rb+"))) {
            // check file size
            fseek(f, 0, SEEK_END);
            size = ftell(f);

/* CODE POUR EMULATEUR */

/*strcpy(efs_path, "fat:/NomDeMaRom.ds.gba");
return true;*/

/* FIN CODE POUR EMULATEUR */
        
            if(size == efs_filesize) {
                bool found = false;
                char dataChunk[EFS_READBUFFERSIZE];
                char magicString[12] = "";
                int dataChunk_size, efs_offset = 0;
                
                // rebuild magic string
                strcat(magicString, efsMagicStringP1);
                strcat(magicString, efsMagicStringP2);
                
                // search for magic string
                i = 0;
                fseek(f, 0, SEEK_SET);
                while(!feof(f) && !found) {
                    dataChunk_size = fread(dataChunk, sizeof(char), EFS_READBUFFERSIZE, f);
                
                    for(i=0; i < dataChunk_size; i++) {
                        if(dataChunk[i] == magicString[0]) {
                            if(dataChunk_size-i < 12) {
                                break;
                            }
                            if(memcmp(&dataChunk[i], magicString, 12) == 0) {
                                found = true;
                                efs_offset += i;
                                break;
                            }
                        }
                    }
                    if(!found) {
                        efs_offset += dataChunk_size;
                    }
                }
    
                // check file id
                if(found == true && (*(int*)(dataChunk+i+12) == efs_id)) {
                    strcpy(efs_path, path);
                    // store file path in NDS
                    if(save) {
                        fseek(f, efs_offset+20, SEEK_SET);
                        fwrite(path, 1, 256, f);
                    }
                    ok = true;
                }
            }
        }
        fclose(f);
    }

    return ok;
}

// search in directory for the NDS file
bool SearchDirectory() {
    DIR_ITER *dir;
    bool found = false;
    char path[EFS_MAXPATHLEN];
    char filename[EFS_MAXPATHLEN];
    struct stat st; 
 
    dir = diropen(".");
    while((dirnext(dir, filename, &st) == 0) && (!found)) {
        if(st.st_mode & S_IFDIR) {
            if(((strlen(filename) == 1) && (filename[0]!= '.')) ||
                ((strlen(filename) == 2) && (strcasecmp(filename, "..")))  ||
                (strlen(filename) > 2))
            {
                chdir(filename);
                found = SearchDirectory();
                chdir("..");
            }
        } else {
            getcwd(path, EFS_MAXPATHLEN-1);
            strcat(path, filename);
        
            if(CheckFile(path, true)) {
                found = true;
                break;
            }
        }
    }
    dirclose(dir);
    
    return found;
} 

// initialize the file system
bool EFS_Init(void) {
    bool found = false;

    // check if there's already a path stored
    if(efs_path[0]) {
        if(CheckFile(efs_path, false)) {
            found = true;
        } else {
            efs_path[0] = '\0';
        }
    }

    // if no path is defined, search the whole FAT space
    if(!efs_path[0]) {
        chdir("/");
        if(SearchDirectory())
            found = true;
    }

    // if nds file is found, open it and read the header
    if(found) {
        char buffer[7];
    
        nds_file = fopen(efs_path, "rb+");

        // check for if a loader is present
        fseek(nds_file, 172, SEEK_SET);
        fread(buffer, 6, 1, nds_file);
        buffer[6] = '\0';
        
        if(strcmp(buffer, "PASSDF") == 0) {
            // loader present
            fseek(nds_file, 512+64, SEEK_SET);
            fread(&fnt_offset, sizeof(u32), 1, nds_file);
            fseek(nds_file, 4, SEEK_CUR);
            fread(&fat_offset, sizeof(u32), 1, nds_file);
            fnt_offset += 512;
            fat_offset += 512;
            hasLoader = true;
        } else {
            fseek(nds_file, 64, SEEK_SET);
            fread(&fnt_offset, sizeof(u32), 1, nds_file);
            fseek(nds_file, 4, SEEK_CUR);
            fread(&fat_offset, sizeof(u32), 1, nds_file);
            hasLoader = false;
        }
        
    }

    return (found && nds_file);
}

// terminate the file system
extern void EFS_Terminate(void) {
    if(nds_file)
        fclose(nds_file);
}

// flush writes in the file system
extern void EFS_Flush(void) {
    if(nds_file)
        fclose(nds_file);
    nds_file = fopen(efs_path, "rb+");
}

// open a file
EFS_FILE *EFS_fopen(char *fname) {
    EFS_FILE *file = NULL;

    if(!nds_file)
        return NULL;
        
    // search for the file in NitroFS
    filematch = false;
    searchmode = EFS_SEARCHFILE;
    file_idpos = 0;
    file_idsize = 0;
    
    if(fname[0] == '/') {
        strcpy(fileInNDS, fname);
    } else {
        strcpy(fileInNDS, "/");
        strcat(fileInNDS, fname);
    }

    ExtractDirectory("/", 0xF000);
    
    if(file_idpos) {
        u32 top;
        fseek(nds_file, file_idpos, SEEK_SET);
        fread(&top, 1, sizeof(top), nds_file);
        file = (EFS_FILE *)malloc(sizeof(EFS_FILE));
        if(hasLoader)
            top += 512;
        file->seek_start = top;
        file->seek_pos = top;
        file->size = file_idsize;
    }
  
    return file;
}

// set the current position in the file
extern void EFS_fseek(EFS_FILE *file, int offset, int origin) {
    switch(origin) {
        case SEEK_SET:
            file->seek_pos = file->seek_start + offset;
            break;
        case SEEK_CUR:
            file->seek_pos += offset;
            break;
        case SEEK_END:
            file->seek_pos = file->seek_start + file->size + offset;
            break;
    }
}

// return the current position in file 
extern int EFS_ftell(EFS_FILE *file) {
    return (file->seek_pos - file->seek_start);
}

// read data from current file, returns the number of blocks read
extern int EFS_fread(void *buffer, u32 blockSize, u32 numBlocks, EFS_FILE *file) {
    int bytes_read;
    // seek to right position and read data in buffer
    fseek(nds_file, file->seek_pos, SEEK_SET);
    bytes_read = fread(buffer, blockSize, numBlocks, nds_file);
    if (bytes_read > 0)
        file->seek_pos += bytes_read * blockSize;
    return bytes_read;
}

// write data into current file, return the number of blocks written
extern int EFS_fwrite(void *buffer, u32 blockSize, u32 numBlocks, EFS_FILE *file) {
    int bytes_written;
    // seek to right position and write data from buffer
    fseek(nds_file, file->seek_pos, SEEK_SET);
    bytes_written = fwrite(buffer, blockSize, numBlocks, nds_file);
    if (bytes_written > 0)
        file->seek_pos += bytes_written * blockSize;
    return bytes_written;
}

// close current file
void EFS_fclose(EFS_FILE *file) {
    free(file);
#ifndef EFS_NO_AUTOFLUSH    
    EFS_Flush();
#endif
}

// return file size
extern u32 EFS_GetFileSize(EFS_FILE *file) {
    return file->size;
}

// return true if at the end of file
extern bool EFS_feof(EFS_FILE *file) {
    return (file->seek_start+file->size < file->seek_pos);
}

// open a directory
extern EFS_DIR *EFS_diropen(const char *path) {
    EFS_DIR *dir = NULL;

    if(!nds_file)
        return NULL;
        
    // search for the directory in NitroFS
    filematch = false;
    searchmode = EFS_SEARCHDIR;
    file_idpos = 0;
    file_idsize = 0;
    strcpy(fileInNDS, path);
    
    if(fileInNDS[strlen(fileInNDS)-1] != '/')
        strcat(fileInNDS, "/");

    ExtractDirectory("/", 0xF000);
    
    if(file_idpos) {
        dir = (EFS_DIR *)malloc(sizeof(EFS_DIR));
        dir->dir_id = file_idpos;
        dir->curr_seek = 0;
    }
  
    return dir;
}

// go back to the beginning of the directory
extern void EFS_dirreset(EFS_DIR *dir) {
    dir->curr_seek = 0;
}

// read next entry of the directory, and fill in its filename.
// return -1 if it's end of the directory or error, 0 if the new entry is a file,
// 1 if the new entry is a directory
extern int EFS_dirnext(EFS_DIR *dir, char *fname) {
    if(!nds_file)
        return -1;
        
    // search for the file in NitroFS
    filematch = false;
    searchmode = EFS_LISTDIR;
    file_idpos = dir->curr_seek;
    file_idsize = 2;
    ExtractDirectory("", dir->dir_id);
    
    if(file_idsize != 2) {
        strcpy(fname, fileInNDS);
        dir->curr_seek = file_idpos;
        return file_idsize;
    }
  
    return -1;
}

// close a directory
extern void EFS_dirclose(EFS_DIR *dir) {
    free(dir);
}

#else   // tweak here some functions for libfat mode compatibility

extern u32 EFS_GetFileSize(EFS_FILE *file) {
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

extern int EFS_dirnext(EFS_DIR *dir, char *fname) {
    struct stat st;
    int err = dirnext(dir, fname, &st);
    if(!err && (st.st_mode & S_IFDIR))
        return 1;
    return err;
}

#endif  // ifndef EFS_REAL_FAT_MODE

// reserved space for post-compilation adding of EFS tags
asm (
"@--------------------------------------------------------------------------------------\n"
"   .balign	32                                                                          \n"
"   .arm                                                                                \n"
"@--------------------------------------------------------------------------------------\n"
"   .word   0xBFA905CE      @ Magic number to identify this region                      \n"
"   .asciz  \" EFSstr\"     @ Identifying Magic string (8 bytes with null terminator)   \n"
"   .global efs_id                                                                      \n"
"efs_id:                                                                                \n"
"   .word   0x00            @ ID of the rom                                             \n"
"   .global efs_filesize                                                                \n"
"efs_filesize:                                                                          \n"
"   .word   0x00            @ Size of the rom                                           \n"
"   .global efs_path                                                                    \n"
"efs_path:                                                                              \n"
"   .skip   256             @ Path of the rom                                           \n"
"@--------------------------------------------------------------------------------------\n"
);

#ifdef __cplusplus
}
#endif
