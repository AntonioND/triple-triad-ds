//Background converted using Mollusk's PAGfx Converter
//This Background uses font2_Pal

const int font2_Info[3] = {7, 192, 48}; // BgMode, Width, Height

//Font Sizes : 
const char font2_Height = 8;

const char font2_Sizes[256] = {
   9, 9, 8, 9, 9, 8, 9, 9, 8, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 3, 0, 0, 0, 9, 9, 8, 9, 9, 9, 9, 9, 
   9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 9, 3, 0, 0, 0, 9, 9, 8, 9, 9, 9, 9, 9, 8, 9, 9, 8, 9, 9, 9, 9, 
   9, 9, 9, 9, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}; 

const unsigned short font2_Map[144] __attribute__ ((aligned (4))) = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
16, 17, 18, 19, 20, 21, 21, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 21, 21, 21, 
43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 
59, 60, 49, 61, 62, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 
21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21
};

const unsigned char font2_Tiles[2016] __attribute__ ((aligned (4))) = {
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 16, 0, 0, 0, 33, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 17, 17, 35, 1, 49, 51, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 1, 18, 33, 51, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 17, 49, 51, 18, 49, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 17, 51, 19, 49, 51, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 1, 19, 33, 51, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 1, 17, 49, 49, 1, 49, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 0, 17, 1, 0, 0, 49, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 17, 17, 1, 1, 49, 49, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 17, 
0, 0, 0, 49, 0, 0, 0, 17, 
17, 1, 0, 17, 49, 1, 0, 49, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 1, 0, 0, 0, 
1, 0, 0, 0, 1, 0, 0, 0, 
17, 17, 17, 17, 17, 19, 49, 18, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 17, 17, 1, 19, 33, 35, 1, 
17, 17, 1, 17, 33, 35, 1, 33, 
49, 49, 1, 49, 49, 49, 1, 17, 
33, 35, 1, 16, 17, 17, 1, 16, 
17, 17, 1, 16, 49, 35, 1, 17, 
17, 0, 17, 17, 19, 0, 49, 35, 
19, 0, 17, 49, 19, 0, 33, 35, 
19, 0, 49, 51, 17, 0, 17, 17, 
17, 0, 17, 17, 19, 1, 49, 35, 
1, 17, 17, 1, 1, 49, 35, 1, 
1, 33, 50, 1, 1, 17, 49, 1, 
1, 49, 35, 1, 1, 17, 17, 1, 
1, 17, 17, 17, 1, 33, 51, 19, 
16, 17, 1, 17, 17, 50, 1, 49, 
33, 49, 1, 49, 49, 51, 1, 17, 
17, 49, 1, 49, 0, 17, 1, 17, 
17, 17, 1, 17, 49, 51, 1, 49, 
17, 1, 17, 17, 51, 1, 33, 51, 
18, 1, 49, 18, 51, 1, 49, 51, 
35, 1, 49, 50, 17, 1, 17, 17, 
17, 1, 17, 17, 49, 1, 49, 49, 
1, 17, 17, 1, 1, 49, 51, 1, 
1, 17, 50, 1, 1, 16, 35, 1, 
1, 16, 19, 1, 1, 16, 17, 0, 
1, 17, 17, 17, 1, 49, 18, 19, 
17, 17, 1, 17, 49, 50, 1, 49, 
33, 35, 1, 49, 49, 49, 1, 17, 
33, 35, 1, 49, 17, 17, 1, 17, 
17, 17, 1, 17, 49, 50, 1, 49, 
17, 1, 0, 0, 50, 1, 0, 0, 
51, 1, 0, 0, 50, 1, 0, 0, 
35, 1, 0, 0, 17, 1, 0, 0, 
17, 1, 17, 17, 49, 1, 49, 51, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 0, 0, 0, 19, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 49, 0, 0, 0, 49, 
0, 0, 0, 49, 0, 0, 0, 17, 
0, 0, 0, 16, 0, 0, 0, 33, 
0, 0, 0, 49, 0, 0, 0, 49, 
49, 1, 49, 34, 51, 1, 49, 17, 
49, 1, 49, 51, 17, 1, 17, 17, 
17, 0, 17, 17, 35, 1, 49, 51, 
49, 1, 49, 34, 51, 1, 49, 17, 
18, 49, 17, 1, 19, 49, 17, 1, 
18, 33, 51, 1, 17, 17, 17, 1, 
17, 17, 17, 1, 18, 33, 51, 1, 
18, 49, 17, 1, 19, 49, 17, 1, 
49, 17, 19, 49, 49, 17, 19, 49, 
49, 51, 18, 49, 17, 17, 17, 17, 
17, 17, 17, 17, 49, 51, 18, 49, 
49, 17, 19, 49, 49, 17, 19, 49, 
34, 17, 49, 17, 17, 17, 49, 51, 
51, 19, 49, 17, 17, 17, 17, 1, 
17, 17, 17, 17, 51, 19, 49, 51, 
34, 17, 49, 17, 17, 17, 49, 51, 
17, 49, 17, 17, 1, 49, 33, 19, 
1, 33, 51, 17, 0, 17, 17, 1, 
17, 17, 17, 1, 19, 33, 51, 1, 
17, 49, 17, 17, 1, 49, 33, 19, 
49, 49, 1, 49, 49, 51, 1, 49, 
49, 49, 1, 49, 17, 17, 1, 17, 
17, 17, 1, 17, 49, 49, 1, 49, 
49, 49, 1, 49, 49, 51, 1, 49, 
1, 0, 17, 49, 1, 0, 49, 49, 
1, 0, 33, 35, 1, 0, 17, 17, 
1, 0, 0, 17, 1, 0, 0, 49, 
1, 0, 17, 49, 1, 0, 49, 49, 
1, 49, 18, 1, 1, 49, 19, 1, 
1, 49, 49, 1, 1, 17, 17, 1, 
1, 17, 17, 1, 1, 49, 49, 1, 
1, 49, 18, 1, 1, 49, 19, 1, 
49, 1, 0, 49, 49, 17, 0, 49, 
49, 19, 0, 49, 17, 17, 0, 17, 
17, 1, 0, 17, 49, 1, 0, 49, 
49, 1, 0, 49, 49, 17, 0, 49, 
35, 19, 49, 35, 34, 19, 49, 50, 
17, 19, 49, 33, 17, 17, 17, 17, 
17, 17, 17, 17, 17, 19, 49, 18, 
35, 19, 49, 35, 34, 19, 49, 50, 
19, 49, 49, 1, 19, 49, 49, 1, 
19, 33, 35, 1, 17, 17, 17, 1, 
17, 17, 17, 1, 19, 33, 35, 1, 
19, 49, 49, 1, 19, 49, 49, 1, 
49, 49, 1, 49, 49, 35, 1, 49, 
49, 17, 1, 17, 17, 1, 0, 16, 
17, 17, 1, 16, 49, 35, 1, 17, 
49, 49, 1, 49, 49, 35, 1, 49, 
49, 1, 49, 49, 50, 1, 49, 19, 
35, 1, 49, 49, 17, 1, 17, 17, 
17, 0, 17, 17, 19, 1, 49, 35, 
49, 1, 49, 49, 50, 1, 49, 19, 
1, 49, 35, 17, 1, 17, 50, 19, 
1, 49, 51, 18, 1, 17, 17, 17, 
1, 17, 17, 17, 1, 33, 51, 19, 
1, 49, 35, 17, 1, 17, 50, 19, 
17, 19, 1, 49, 16, 19, 0, 49, 
16, 19, 0, 33, 16, 17, 0, 17, 
17, 17, 1, 17, 49, 51, 1, 49, 
17, 19, 1, 49, 16, 19, 0, 49, 
49, 1, 49, 49, 49, 1, 49, 49, 
51, 1, 33, 35, 17, 1, 17, 17, 
17, 1, 17, 17, 49, 1, 49, 49, 
49, 1, 49, 49, 49, 1, 49, 49, 
1, 49, 18, 19, 1, 49, 18, 19, 
1, 33, 51, 18, 1, 17, 17, 17, 
1, 17, 17, 17, 1, 49, 18, 19, 
1, 49, 18, 19, 1, 49, 18, 19, 
33, 35, 1, 49, 49, 50, 1, 33, 
49, 49, 1, 49, 17, 17, 1, 17, 
17, 17, 1, 17, 49, 50, 1, 49, 
33, 35, 1, 49, 49, 50, 1, 33, 
49, 1, 17, 50, 35, 1, 33, 35, 
18, 1, 49, 51, 17, 0, 17, 17, 
17, 1, 17, 17, 49, 1, 49, 51, 
49, 1, 17, 50, 35, 1, 33, 35, 
18, 0, 0, 0, 17, 0, 0, 0, 
19, 0, 0, 0, 17, 0, 0, 0, 
17, 0, 0, 0, 19, 0, 0, 0, 
18, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 49, 0, 0, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
49, 1, 49, 51, 17, 1, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
18, 33, 51, 1, 17, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
49, 51, 18, 49, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
51, 19, 49, 17, 17, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 33, 51, 17, 0, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
49, 49, 1, 49, 17, 17, 1, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 0, 33, 35, 1, 0, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 49, 49, 1, 1, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
49, 19, 0, 49, 17, 17, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
17, 19, 49, 33, 17, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
19, 33, 35, 1, 17, 17, 17, 1, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
49, 17, 1, 17, 17, 1, 0, 16, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
35, 1, 49, 49, 17, 1, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 49, 51, 18, 1, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
16, 19, 0, 33, 16, 17, 0, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
51, 1, 33, 35, 17, 1, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
1, 33, 51, 18, 1, 17, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
18, 1, 49, 51, 17, 0, 17, 17, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
19, 0, 0, 0, 17, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0
};

