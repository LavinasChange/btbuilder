/*-------------------------------------------------------------------------*\
  <sdlextend.c> -- SDL extended functions implementation file

  Date      Programmer  Description
  03/09/07  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "sdlextend.h"

/* 8x8 font taken from
   Framebuffer Graphics Libary for Linux, Copyright 1993 Harm Hanemaayer */
unsigned char ITextFont8x8[256][8] = {
 {   0,   0,   0,   0,   0,   0,   0,   0},
 { 126, 129, 165, 129, 189, 129, 126,   0},
 { 126, 255, 219, 255, 195, 255, 126,   0},
 {  54, 127, 127, 127,  62,  28,   8,   0},
 {   8,  28,  62, 127,  62,  28,   8,   0},
 {  28,  28,   8, 107, 127, 107,   8,  28},
 {   8,  28,  62, 127,  62,   8,  28,  62},
 {   0,   0,  24,  60,  60,  24,   0,   0},
 { 255, 255, 231, 195, 195, 231, 255, 255},
 {   0,  60, 102,  66,  66, 102,  60,   0},
 { 255, 195, 153, 189, 189, 153, 195, 255},
 {  15,   7,  13,  60, 102, 102, 102,  60},
 {  60, 102, 102, 102,  60,  24, 126,  24},
 {  48,  56,  60,  54,  52, 112, 240, 224},
 { 127,  99, 127,  99,  99, 103, 230, 192},
 {  24, 219, 126, 102, 102, 126, 219,  24},
 {  64, 112, 124, 127, 124, 112,  64,   0},
 {   1,   7,  31, 127,  31,   7,   1,   0},
 {  24,  60, 126,  24,  24, 126,  60,  24},
 { 102, 102, 102, 102, 102,   0, 102,   0},
 {  63, 122, 122,  58,  10,  10,  10,   0},
 {  30,  51,  28,  54,  54,  28, 102,  60},
 {   0,   0,   0,   0, 126, 126, 126,   0},
 {  24,  60, 126,  24, 126,  60,  24, 126},
 {  24,  60, 126,  24,  24,  24,  24,   0},
 {  24,  24,  24,  24, 126,  60,  24,   0},
 {   0,  12,  14, 127,  14,  12,   0,   0},
 {   0,  24,  56, 127,  56,  24,   0,   0},
 {   0,   0,  96,  96,  96, 127,   0,   0},
 {   0,  36, 102, 255, 102,  36,   0,   0},
 {   0,  24,  60, 126, 255, 255,   0,   0},
 {   0, 255, 255, 126,  60,  24,   0,   0},
 {   0,   0,   0,   0,   0,   0,   0,   0},
 {  24,  24,  24,  24,  24,   0,  24,   0},
 { 102, 102, 102,   0,   0,   0,   0,   0},
 { 108, 108, 254, 108, 254, 108, 108,   0},
 {  16, 124, 208, 124,  22, 124,  16,   0},
 {   0, 198, 204,  24,  48, 102, 198,   0},
 {  56, 108,  56, 118, 220, 204, 118,   0},
 {  24,  24,  48,   0,   0,   0,   0,   0},
 {  12,  24,  48,  48,  48,  24,  12,   0},
 {  48,  24,  12,  12,  12,  24,  48,   0},
 {   0, 108,  56, 254,  56, 108,   0,   0},
 {   0,  24,  24, 126,  24,  24,   0,   0},
 {   0,   0,   0,   0,   0,  24,  24,  48},
 {   0,   0,   0, 126,   0,   0,   0,   0},
 {   0,   0,   0,   0,   0,  48,  48,   0},
 {   0,   6,  12,  24,  48,  96, 192,   0},
 {  60, 102, 110, 126, 118, 102,  60,   0},
 {  12,  28,  60,  12,  12,  12,  12,   0},
 {  60, 102,   6,  28,  48,  96, 126,   0},
 {  60, 102,   6,  28,   6, 102,  60,   0},
 {  28,  60, 108, 204, 254,  12,  12,   0},
 { 126,  96,  96, 124,   6, 102,  60,   0},
 {  60,  96,  96, 124, 102, 102,  60,   0},
 { 126,   6,   6,  12,  24,  48,  48,   0},
 {  60, 102, 102,  60, 102, 102,  60,   0},
 {  60, 102, 102,  62,   6,   6,  60,   0},
 {   0,  48,  48,   0,   0,  48,  48,   0},
 {   0,  24,  24,   0,   0,  24,  24,  48},
 {  12,  24,  48,  96,  48,  24,  12,   0},
 {   0,   0, 126,   0,   0, 126,   0,   0},
 {  48,  24,  12,   6,  12,  24,  48,   0},
 {  60, 102,   6,  12,  24,   0,  24,   0},
 {  60, 102, 110, 110, 108,  96,  60,   0},
 {  24,  60, 102, 102, 126, 102, 102,   0},
 { 124, 102, 102, 124, 102, 102, 124,   0},
 {  60, 102,  96,  96,  96, 102,  60,   0},
 { 124, 102, 102, 102, 102, 102, 124,   0},
 { 126,  96,  96, 124,  96,  96, 126,   0},
 { 126,  96,  96, 124,  96,  96,  96,   0},
 {  60, 102,  96, 110, 102, 102,  60,   0},
 { 102, 102, 102, 126, 102, 102, 102,   0},
 {  60,  24,  24,  24,  24,  24,  60,   0},
 {   6,   6,   6,   6, 102, 102,  60,   0},
 { 102, 108, 120, 112, 120, 108, 102,   0},
 {  96,  96,  96,  96,  96,  96, 126,   0},
 { 198, 238, 254, 214, 198, 198, 198,   0},
 { 102, 118, 126, 110, 102, 102, 102,   0},
 {  60, 102, 102, 102, 102, 102,  60,   0},
 { 124, 102, 102, 124,  96,  96,  96,   0},
 {  60, 102, 102, 102, 102, 110,  60,   6},
 { 124, 102, 102, 124, 102, 102, 102,   0},
 {  60, 102,  96,  60,   6, 102,  60,   0},
 { 126,  24,  24,  24,  24,  24,  24,   0},
 { 102, 102, 102, 102, 102, 102,  60,   0},
 { 102, 102, 102, 102, 102,  60,  24,   0},
 { 198, 198, 198, 214, 254, 238, 198,   0},
 { 102, 102,  60,  24,  60, 102, 102,   0},
 { 102, 102, 102,  60,  24,  24,  24,   0},
 { 126,   6,  12,  24,  48,  96, 126,   0},
 {  60,  48,  48,  48,  48,  48,  60,   0},
 {   0, 192,  96,  48,  24,  12,   6,   0},
 {  60,  12,  12,  12,  12,  12,  60,   0},
 {  24,  60, 102,   0,   0,   0,   0,   0},
 {   0,   0,   0,   0,   0,   0,   0, 255},
 {  24,  24,  12,   0,   0,   0,   0,   0},
 {   0,   0,  60,   6,  62, 102,  62,   0},
 {  96,  96,  96, 124, 102, 102, 124,   0},
 {   0,   0,  60, 102,  96, 102,  60,   0},
 {   6,   6,   6,  62, 102, 102,  62,   0},
 {   0,   0,  60, 102, 126,  96,  62,   0},
 {  28,  54,  48, 124,  48,  48,  48,   0},
 {   0,   0,  62, 102, 102,  62,   6,  60},
 {  96,  96, 124, 102, 102, 102, 102,   0},
 {  24,   0,  24,  24,  24,  24,  24,   0},
 {  12,   0,  12,  12,  12,  12, 108,  56},
 {  96,  96, 102, 108, 120, 108, 102,   0},
 {  48,  48,  48,  48,  48,  48,  24,   0},
 {   0,   0, 236, 254, 214, 214, 198,   0},
 {   0,   0, 124, 102, 102, 102, 102,   0},
 {   0,   0,  60, 102, 102, 102,  60,   0},
 {   0,   0, 124, 102, 102, 124,  96,  96},
 {   0,   0,  62, 102, 102,  62,   6,   6},
 {   0,   0, 124, 102,  96,  96,  96,   0},
 {   0,   0,  62,  96,  60,   6, 124,   0},
 {  48,  48, 124,  48,  48,  54,  28,   0},
 {   0,   0, 102, 102, 102, 102,  62,   0},
 {   0,   0, 102, 102, 102,  60,  24,   0},
 {   0,   0, 198, 214, 254, 238,  68,   0},
 {   0,   0, 102,  60,  24,  60, 102,   0},
 {   0,   0, 102, 102, 102,  62,   6,  60},
 {   0,   0, 126,  12,  24,  48, 126,   0},
 {  28,  48,  48,  96,  48,  48,  28,   0},
 {  24,  24,  24,  24,  24,  24,  24,   0},
 {  56,  12,  12,   6,  12,  12,  56,   0},
 { 118, 220,   0,   0,   0,   0,   0,   0},
 {   0,   0,  24,  60, 102, 102, 126,   0},
 {  60, 102,  96,  96, 102,  60,  24,  48},
 { 102,   0, 102, 102, 102, 102,  62,   0},
 {  14,   0,  60, 102, 126,  96,  60,   0},
 {  60, 102,  60,   6,  62, 102,  62,   0},
 { 102,   0,  60,   6,  62, 102,  62,   0},
 { 112,   0,  60,   6,  62, 102,  62,   0},
 {  24,  24,  60,   6,  62, 102,  62,   0},
 {   0,   0,  62,  96,  96,  62,  24,  48},
 {  60, 102,  60, 102, 126,  96,  60,   0},
 { 102,   0,  60, 102, 126,  96,  60,   0},
 { 112,   0,  60, 102, 126,  96,  60,   0},
 { 102,   0,  24,  24,  24,  24,  24,   0},
 {  60, 102,  24,  24,  24,  24,  24,   0},
 { 112,   0,  24,  24,  24,  24,  24,   0},
 { 198,  56, 108, 198, 254, 198, 198,   0},
 {  24,  24,   0,  60, 102, 126, 102,   0},
 {  14,   0, 124,  96, 120,  96, 124,   0},
 {   0,   0, 126,  26, 126, 216, 126,   0},
 {  62, 120, 216, 222, 248, 216, 222,   0},
 {  60, 102,  60, 102, 102, 102,  60,   0},
 { 102,   0,  60, 102, 102, 102,  60,   0},
 { 112,   0,  60, 102, 102, 102,  60,   0},
 {  60, 102,   0, 102, 102, 102,  62,   0},
 { 112,   0, 102, 102, 102, 102,  62,   0},
 { 102,   0, 102, 102, 102,  62,   6,  60},
 { 102,  60, 102, 102, 102, 102,  60,   0},
 { 102,   0, 102, 102, 102, 102,  60,   0},
 {  12,  12,  62,  96,  96,  62,  12,  12},
 {  56, 108,  96, 240,  96, 102, 252,   0},
 { 102, 102,  60,  24, 126,  24, 126,  24},
 { 124, 102, 102, 124, 102, 111, 102,  99},
 {  14,  27,  24,  60,  24,  24, 120,  48},
 {  14,   0,  60,   6,  62, 102,  62,   0},
 {  14,   0,  24,  24,  24,  24,  24,   0},
 {  14,   0,  60, 102, 102, 102,  60,   0},
 {  14,   0, 102, 102, 102, 102,  62,   0},
 { 118, 220,   0, 124, 102, 102, 102,   0},
 { 126,   0, 102, 118, 126, 110, 102,   0},
 {  62, 102, 102,  62,   0, 126,   0,   0},
 {  60, 102, 102,  60,   0, 126,   0,   0},
 {  24,   0,  24,  48,  96, 102,  60,   0},
 {   0,   0,   0, 126,  96,  96,   0,   0},
 {   0,   0,   0, 126,   6,   6,   0,   0},
 { 198, 204, 216,  62,  99, 198,  12,  31},
 { 198, 204, 216,  54, 110, 214,  31,   6},
 {  24,   0,  24,  24,  24,  24,  24,   0},
 {   0,  54, 108, 216, 108,  54,   0,   0},
 {   0, 216, 108,  54, 108, 216,   0,   0},
 {  34, 136,  34, 136,  34, 136,  34, 136},
 {  85, 170,  85, 170,  85, 170,  85, 170},
 { 221, 119, 221, 119, 221, 119, 221, 119},
 {   8,   8,   8,   8,   8,   8,   8,   8},
 {   8,   8,   8,   8, 248,   8,   8,   8},
 {   8,   8,   8, 248, 248,   8,   8,   8},
 {  28,  28,  28,  28, 252,  28,  28,  28},
 {   0,   0,   0,   0, 252,  28,  28,  28},
 {   0,   0,   0, 248, 248,   8,   8,   8},
 {  28,  28,  28, 252, 252,  28,  28,  28},
 {  28,  28,  28,  28,  28,  28,  28,  28},
 {   0,   0,   0, 252, 252,  28,  28,  28},
 {  28,  28,  28, 252, 252,   0,   0,   0},
 {  28,  28,  28,  28, 252,   0,   0,   0},
 {   8,   8,   8, 248, 248,   0,   0,   0},
 {   0,   0,   0,   0, 248,   8,   8,   8},
 {   8,   8,   8,   8,  15,   0,   0,   0},
 {   8,   8,   8,   8, 255,   0,   0,   0},
 {   0,   0,   0,   0, 255,   8,   8,   8},
 {   8,   8,   8,   8,  15,   8,   8,   8},
 {   0,   0,   0,   0, 255,   0,   0,   0},
 {   8,   8,   8,   8, 255,   8,   8,   8},
 {   8,   8,   8,  15,  15,   8,   8,   8},
 {  28,  28,  28,  28,  31,  28,  28,  28},
 {  28,  28,  28,  31,  31,   0,   0,   0},
 {   0,   0,   0,  31,  31,  28,  28,  28},
 {  28,  28,  28, 255, 255,   0,   0,   0},
 {   0,   0,   0, 255, 255,  28,  28,  28},
 {  28,  28,  28,  31,  31,  28,  28,  28},
 {   0,   0,   0, 255, 255,   0,   0,   0},
 {  28,  28,  28, 255, 255,  28,  28,  28},
 {   8,   8,   8, 255, 255,   0,   0,   0},
 {  28,  28,  28,  28, 255,   0,   0,   0},
 {   0,   0,   0, 255, 255,   8,   8,   8},
 {   0,   0,   0,   0, 255,  28,  28,  28},
 {  28,  28,  28,  28,  31,   0,   0,   0},
 {   8,   8,   8,  15,  15,   0,   0,   0},
 {   0,   0,   0,  15,  15,   8,   8,   8},
 {   0,   0,   0,   0,  31,  28,  28,  28},
 {  28,  28,  28,  28, 255,  28,  28,  28},
 {   8,   8,   8, 255, 255,   8,   8,   8},
 {   8,   8,   8,   8, 248,   0,   0,   0},
 {   0,   0,   0,   0,  15,   8,   8,   8},
 { 255, 255, 255, 255, 255, 255, 255, 255},
 {   0,   0,   0,   0, 255, 255, 255, 255},
 { 240, 240, 240, 240, 240, 240, 240, 240},
 {  15,  15,  15,  15,  15,  15,  15,  15},
 { 255, 255, 255, 255,   0,   0,   0,   0},
 {   0,   0, 118, 204, 204, 204, 118,   0},
 {  60, 102, 102, 124, 102, 102, 124,  96},
 { 126, 102,  96,  96,  96,  96,  96,   0},
 {   0,   0, 254, 108, 108, 108, 102,   0},
 { 126, 102,  48,  24,  48, 102, 126,   0},
 {   0,   0,  62, 108, 108, 108,  56,   0},
 {   0,   0, 102, 102, 102, 102, 127, 192},
 {   0,   0, 126, 216,  24,  24,  12,   0},
 { 124,  56, 124, 214, 214, 124,  56, 124},
 { 124, 198, 198, 254, 198, 198, 124,   0},
 { 124, 198, 198, 198, 108, 108, 238,   0},
 {  30,  48,  24,  60, 102, 102,  60,   0},
 {   0,   0, 126, 219, 219, 126,   0,   0},
 {   3,   6,  62, 107, 115,  62,  96, 192},
 {  30,  48,  96, 126,  96,  48,  30,   0},
 { 124, 198, 198, 198, 198, 198, 198,   0},
 {   0, 126,   0, 126,   0, 126,   0,   0},
 {  24,  24, 126,  24,  24,   0, 126,   0},
 {  48,  24,  12,  24,  48,   0, 126,   0},
 {  12,  24,  48,  24,  12,   0, 126,   0},
 {  14,  27,  27,  24,  24,  24,  24,  24},
 {  24,  24,  24,  24,  24, 216, 216, 112},
 {  24,  24,   0, 126,   0,  24,  24,   0},
 {   0, 118, 220,   0, 118, 220,   0,   0},
 {  60, 102, 102,  60,   0,   0,   0,   0},
 {   0,   0,   0,  24,  24,   0,   0,   0},
 {   0,   0,   0,   0,  24,   0,   0,   0},
 {  30,  24,  24,  24,  24, 216, 120,  56},
 { 120, 108, 108, 108, 108,   0,   0,   0},
 {  56,  12,  24,  48,  60,   0,   0,   0},
 {   0,   0,  60,  60,  60,  60,   0,   0},
 {   0,   0,   0,   0,   0,   0,   0,   0}
};

simpleFont simple8x8 = { 8, 8, (unsigned char*)ITextFont8x8 };

SDL_Surface *simpleZoomSurface(SDL_Surface *src, int xMult, int yMult)
{
 int x, xCopy, y, yCopy;
 char *srcPixelRow;
 char *dstPixelRow;
 Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 rmask = 0xff000000;
 gmask = 0x00ff0000;
 bmask = 0x0000ff00;
 amask = 0x000000ff;
#else
 rmask = 0x000000ff;
 gmask = 0x0000ff00;
 bmask = 0x00ff0000;
 amask = 0xff000000;
#endif

 SDL_Surface *src32 = src;
 if (src->format->BitsPerPixel != 32)
 {
  src32 = SDL_CreateRGBSurface(SDL_SWSURFACE, src->w, src->h, 32, rmask, gmask, bmask, amask);
  SDL_BlitSurface(src, NULL, src32, NULL);
 }
 SDL_Surface *dst = SDL_CreateRGBSurface(SDL_SWSURFACE, src->w * xMult, src->h * yMult, 32, src32->format->Rmask, src32->format->Gmask, src32->format->Bmask, src32->format->Amask);
 SDL_LockSurface(src32);
 srcPixelRow = (char *)src32->pixels;
 dstPixelRow = (char *)dst->pixels;
 for (y = 0; y < src->h; y++)
 {
  if (xMult == 1)
  {
   memcpy(dstPixelRow, srcPixelRow, dst->pitch);
  }
  else
  {
   for (x = 0; x < src->w; x++)
   {
    for (xCopy = 0; xCopy < xMult; ++xCopy)
    {
     memcpy(dstPixelRow + ((x * xMult) + xCopy) * 4, srcPixelRow + (x * 4), 4);
    }
   }
  }
  for (yCopy = 1; yCopy < yMult; yCopy++)
  {
   memcpy(dstPixelRow + (dst->pitch * yCopy), dstPixelRow, dst->pitch);
  }
  dstPixelRow += dst->pitch * yMult;
  srcPixelRow += src32->pitch;
 }
 SDL_UnlockSurface(src32);
 if (src != src32)
  SDL_FreeSurface(src32);
 return dst;
}

SDL_Surface *simpleRender_Solid(simpleFont *font, const char *text, SDL_Color c)
{
 int bpc;
 int len, i, k, x, y, w;
 unsigned char bit;
 SDL_Surface *s;
 Uint32 c32;
 Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
 rmask = 0xff000000;
 gmask = 0x00ff0000;
 bmask = 0x0000ff00;
 amask = 0x000000ff;
#else
 rmask = 0x000000ff;
 gmask = 0x0000ff00;
 bmask = 0x00ff0000;
 amask = 0xff000000;
#endif

 bpc = font->w * font->h / 8;
 if (font->w * font->h % 8 > 0)
  bpc++;
 len = strlen(text);
 s = SDL_CreateRGBSurface(SDL_SWSURFACE, font->w * len, font->h, 32, rmask, gmask, bmask, amask);
 c32 = SDL_MapRGB(s->format, c.r, c.g, c.b);
 unsigned char *pixels = (unsigned char *)s->pixels;
 x = 0;
 for (i = 0; i < len; i++)
 {
  y = w = 0;
  for (k = 0; k < bpc; k++)
  {
   for (bit = 128; bit > 0; bit = (bit >> 1))
   {
    if ((font->bitmap[((unsigned char)text[i]) * bpc + k]) & bit)
    {
     *((Uint32 *)(pixels + y * s->pitch + (x + w) * 4)) = c32;
    }
    w++;
    if (w >= font->w)
    {
     w = 0;
     ++y;
    }
   }
  }
  x += font->w;
 }
 return s;
}

void simpleZoomAnimation(MNG_Image *animation, int xMult, int yMult)
{
 int i;
 for (i = 0; i < animation->frame_count; ++i)
 {
  SDL_Surface *img2 = simpleZoomSurface(animation->frame[i], xMult, yMult);
  SDL_FreeSurface(animation->frame[i]);
  animation->frame[i] = img2;
 }
}

#ifdef SDLLIB
void simpleBlitSurface(SDL_Surface *src, SDL_Rect *srcRect, SDL_Surface *dst, SDL_Rect *dstRect)
{
 if (src->format->BitsPerPixel != 32)
 {
  SDL_BlitSurface(src, srcRect, dst, dstRect);
  return;
 }
 int h = srcRect->h + srcRect->y;
 int w = srcRect->w + srcRect->x;
 SDL_LockSurface(src);
 SDL_LockSurface(dst);
 Uint32 *pixelSource = (Uint32*)src->pixels;
 Uint32 *pixelDest = (Uint32*)dst->pixels;
 SDL_PixelFormat *srcFmt = src->format;
 SDL_PixelFormat *dstFmt = dst->format;
 for (int cy = srcRect->y; cy < h; cy++)
 {
  for (int cx = srcRect->x; cx < w; cx++)
  {
   int pos = cy * (src->pitch / 4) + cx;
   int r = ((pixelSource[pos] & srcFmt->Rmask) >> srcFmt->Rshift) << srcFmt->Rloss;
   int g = ((pixelSource[pos] & srcFmt->Gmask) >> srcFmt->Gshift) << srcFmt->Gloss;
   int b = ((pixelSource[pos] & srcFmt->Bmask) >> srcFmt->Bshift) << srcFmt->Bloss;
   int a = ((pixelSource[pos] & srcFmt->Amask) >> srcFmt->Ashift) << srcFmt->Aloss;
   if (a != SDL_ALPHA_TRANSPARENT)
   {
    r = ((r >> dstFmt->Rloss) << dstFmt->Rshift) & dstFmt->Rmask;
    g = ((g >> dstFmt->Gloss) << dstFmt->Gshift) & dstFmt->Gmask;
    b = ((b >> dstFmt->Bloss) << dstFmt->Bshift) & dstFmt->Bmask;
    a = ((a >> dstFmt->Aloss) << dstFmt->Ashift) & dstFmt->Amask;
    int dstPos = (cy - srcRect->y + dstRect->y) * (dst->pitch / 4) + (cx - srcRect->x + dstRect->x);
    pixelDest[dstPos] = r + g + b + a;
   }
  }
 }
 SDL_UnlockSurface(dst);
 SDL_UnlockSurface(src);
}
#endif
