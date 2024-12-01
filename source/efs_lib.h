/*

  Embedded File System (EFS)
  --------------------------

  file        : efs_lib.h 
  author      : Alekmaul & Noda
  description : File system functions

  history : 

    12/05/2007 - v1.0
      = Original release

    13/05/2007 - v1.1
      = cleaned up code a bit
      - removed header struct
      + added EFS_Flush() function, to ensure data is written

    18/05/2007 - v1.1a
      + added defines for c++ compatibility
      
    28/09/2007 - v1.2
      = fixed real fat mode (hopefully)
      + added some options

*/

#ifndef __EFS_LIB_H__
#define __EFS_LIB_H__

//---- EFS options ------------------------------------------
// uncomment the defines below to activate the desired option

// deactivate autoflush on closing files (increase speed when manipulating lots of file)
//#define EFS_NO_AUTOFLUSH

// activate standard fat mode wrapper (for debugging use)
//#define EFS_REAL_FAT_MODE

//-----------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

#define EFS_MAXPATHLEN      256
#define EFS_MAXNAMELEN      128
#define EFS_ISFILE          0
#define EFS_ISDIR           1

// export variables
extern int efs_id;
extern u8 efs_hasloader;
extern u32 efs_filesize;
extern char efs_path[256];

#ifndef EFS_REAL_FAT_MODE

typedef struct {
    u32 seek_start;
    u32 seek_pos;
    u32 size;
} EFS_FILE;

typedef struct {
    u32 dir_id;
    u32 curr_seek;
} EFS_DIR;

// initialize the file system
extern bool EFS_Init(void);

// terminate the file system
extern void EFS_Terminate(void);

// flush writes in the file system
void EFS_Flush(void);

// open a file
extern EFS_FILE *EFS_fopen(char *fname);

// close a file
extern void EFS_fclose(EFS_FILE *file);

// read data from current file, return the number of blocks read
extern int EFS_fread(void *buffer, u32 blockSize, u32 numBlocks, EFS_FILE *file);

// write data into current file, return the number of blocks written
extern int EFS_fwrite(void *buffer, u32 blockSize, u32 numBlocks, EFS_FILE *file);

// set the current position in the file
extern void EFS_fseek(EFS_FILE *file, int offset, int origin);

// return the current position in file 
extern int EFS_ftell(EFS_FILE *file);

// return file size
extern u32 EFS_GetFileSize(EFS_FILE *file);

// return true if at the end of file
extern bool EFS_feof(EFS_FILE *file);

// open a directory
extern EFS_DIR *EFS_diropen(const char *path);

// go back to the beginning of the directory
extern void EFS_dirreset(EFS_DIR *dir);

// read next entry of the directory, and fill in its filename.
// return -1 if it's the end of the directory, EFS_FILE if the new entry is a file,
// EFS_DIR if the new entry is a directory
extern int EFS_dirnext(EFS_DIR *dir, char *fname);

// close a directory
extern void EFS_dirclose(EFS_DIR *dir);

#else

#include <nds.h>
#include <stdio.h>
#include <sys/dir.h>

// simple EFS to FAT redefinition
#define EFS_FILE            FILE
#define EFS_Init()          true
#define EFS_Terminate()     void
#define EFS_Flush()         void
#define EFS_fopen(n)        fopen(n, "rb+")
#define EFS_fclose          fclose
#define EFS_fread           fread
#define EFS_fwrite          fwrite
#define EFS_fseek           fseek
#define EFS_ftell           ftell
#define EFS_feof            feof

#define EFS_DIR             DIR_ITER
#define EFS_diropen         diropen
#define EFS_dirreset        dirreset
#define EFS_dirclose        dirclose

// those two functions need some tweaking as there's no libfat equivalent
extern int EFS_dirnext(EFS_DIR *dir, char *fname);
extern u32 EFS_GetFileSize(EFS_FILE *file);

#endif  // ifndef EFS_REAL_FAT_MODE

#ifdef __cplusplus
}
#endif

#endif  // define __EFS_LIB_H__
