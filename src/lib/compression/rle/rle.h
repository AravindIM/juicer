#ifndef _RLE_H_
#define _RLE_H_

#define RLE_COMPRESSION_ARG "rle"

#include <stdio.h>

int rle_compress(FILE *in, FILE *out);

#endif