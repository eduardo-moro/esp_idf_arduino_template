#if defined(QRCODEVERSION) && QRCODEVERSION == 10
const unsigned char neccblk1 = 2;
const unsigned char neccblk2 = 2;
const unsigned char datablkw = 68;
const unsigned char eccblkwid = 18;
const unsigned char VERSION = 10;
const unsigned char ECCLEVEL = 1;
const unsigned char WD = 57;
const unsigned char WDB = 8;
unsigned char strinbuf[456];
unsigned char qrframe[600];
unsigned char rlens[58];
#ifndef AVR
#define PROGMEM
#define memcpy_P memcpy
#define __LPM(x) *x
#else
#include <avr/pgmspace.h>
#endif
const unsigned char framebase[] PROGMEM = {
0xfe,0x00,0x00,0x00,0x00,0x03,0x3f,0x80,
0x82,0x00,0x00,0x00,0x00,0x01,0x20,0x80,
0xba,0x00,0x00,0x00,0x00,0x03,0x2e,0x80,
0xba,0x00,0x00,0x00,0x00,0x01,0x2e,0x80,
0xba,0x00,0x00,0x3e,0x00,0x01,0x2e,0x80,
0x82,0x00,0x00,0x22,0x00,0x02,0x20,0x80,
0xfe,0xaa,0xaa,0xaa,0xaa,0xaa,0xbf,0x80,
0x00,0x00,0x00,0x22,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x3e,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0f,0x80,0x00,0x3e,0x00,0x00,0xf8,0x00,
0x08,0x80,0x00,0x22,0x00,0x00,0x88,0x00,
0x0a,0x80,0x00,0x2a,0x00,0x00,0xa8,0x00,
0x08,0x80,0x00,0x22,0x00,0x00,0x88,0x00,
0x0f,0x80,0x00,0x3e,0x00,0x00,0xf8,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xa6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x02,0x00,0x00,0x3e,0x00,0x00,0xf8,0x00,
0x00,0x80,0x00,0x22,0x00,0x00,0x88,0x00,
0xfe,0x00,0x00,0x2a,0x00,0x00,0xa8,0x00,
0x82,0x00,0x00,0x22,0x00,0x00,0x88,0x00,
0xba,0x00,0x00,0x3e,0x00,0x00,0xf8,0x00,
0xba,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xba,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const unsigned char framask[] PROGMEM = {
0xff,0xff,0xff,0xff,0xff,0xf8,0x10,0x04,
0x00,0x80,0x08,0x00,0x40,0x01,0x00,0x02,
0x00,0x02,0x00,0x01,0x00,0x00,0x40,0x00,
0x08,0x00,0x00,0x80,0x00,0x04,0x00,0x00,
0x10,0x00,0x00,0x20,0x00,0x00,0x20,0x00,
0x00,0x10,0x00,0x00,0x1f,0x00,0x00,0x43,
0xe0,0x00,0x0c,0x3e,0x00,0x00,0xe1,0xf0,
0x00,0x07,0x87,0xc0,0x00,0x1f,0x02,0x00,
0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,
0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x08,
0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,
0x04,0x00,0x00,0x00,0x00,0x10,0x00,0x00,
0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x20,
0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,
0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x80,
0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x7f,
0x00,0x00,0x00,0x00,0x00,0xfe,0x00,0x00,
0x00,0x00,0x00,0xfe,0x00,0x00,0x3e,0x00,
0x00,0xff,0xc0,0x00,0x1f,0x00,0x00,0x7f,
0xf0,0x00,0x07,0xc0,0x00,0x1f,0xfe,0x00,
0x00,0xf8,0x00,0x03,0xff,0xe0,0x00,0x0f,
0x80,0x00,0x3f,0xff,0x00,0x00,0x00,0x00,
0x00,0x07,0xfc,0x00,0x00,0x00,0x00,0x00,
0x0f,0xf8,0x00,0x00,0x00,0x00,0x00,0x0f,
0xf8,0x00,0x00,0x00,0x00,0x00,0x00,
};
#endif