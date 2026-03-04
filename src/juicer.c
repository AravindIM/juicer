#include "./lib/compression/compression.h"
#include "./lib/compression/rle/rle.h"
#include "./lib/utils/config.h"
#include "./lib/utils/log.h"
#include <stdio.h>

int main(int argc, char **argv) {
  struct config cfg;
  struct ast_node *node;
  if (config_from_opt(argc, argv, &cfg) != CONFIG_SUCCESS) {
    if (!cfg.input_file) {
      fprintf(stderr, ERRMSG_NO_INPUT_FILE);
    }
    fprintf(stderr, HELP_STRING, argv[PROGRAM_NAME_INDEX]);
    return 1;
  }
  FILE *src = fopen(cfg.input_file, "r");
  FILE *dst = fopen(cfg.output_file, "w");
  if (rle(src, dst)) {
    fprintf(stderr, ERRMSG_COMPRESSION_FAILED);
  }
  fclose(src);
  fclose(dst);
}