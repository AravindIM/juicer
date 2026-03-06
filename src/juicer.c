#include "./lib/compression/compression.h"
#include "./lib/compression/rle/rle.h"
#include "./lib/utils/config.h"
#include "./lib/utils/log.h"
#include <stdio.h>

int main(int argc, char **argv) {
  struct config cfg;
  struct ast_node *node;
  int config_status = get_config(argc, argv, &cfg);
  if (config_status != CONFIG_SUCCESS) {
    switch (config_status) {
    case EOPTUNK:
      fprintf(stderr, ERRMSG_UNK_OPT);
      break;
    case ENOINP:
      fprintf(stderr, ERRMSG_NO_INPUT_FILE);
      break;
    case ENOACT:
      fprintf(stderr, ERRMSG_NO_ACT);
      break;
    case EACTCONFL:
      fprintf(stderr, ERRMSG_CONFL_ACT);
      break;
    case EFMTUNK:
      fprintf(stderr, ERRMSG_UNK_FMT);
      break;
    default:
      break;
    }
    fprintf(stderr, HELP_STRING, argv[PROGRAM_NAME_INDEX]);
    return 1;
  }
  FILE *src = fopen(cfg.input_file, "r");
  FILE *dst = fopen(cfg.output_file, "w");
  if (cfg.action == ACT_COMPRESS) {
    switch (cfg.format) {
    case FMT_RLE:
      if (rle_compress(src, dst)) {
        fprintf(stderr, ERRMSG_COMPRESSION_FAILED);
      }
      break;
    default:
      break;
    }
  }
  fclose(src);
  fclose(dst);
}