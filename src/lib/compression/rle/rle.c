#include "rle.h"
#include "../compression.h"
#include <stdio.h>

int rle(FILE *in, FILE *out) {
  int current = fgetc(in);
  int next;
  int count = 1;
  if (current == EOF) {
    return EOF;
  }
  while ((next = fgetc(in)) != EOF) {
    if (next == current && count < 255) {
      ++count;
    } else {
      if (fputc(count, out) == EOF) {
        return EWRITE;
      }
      if (fputc(current, out) == EOF) {
        return EWRITE;
      }
      current = next;
      count = 1;
    }
  }
  return COMPRESSION_SUCCESS;
}