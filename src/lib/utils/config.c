#include "config.h"
#include "../compression/rle/rle.h"
#include <bits/getopt_core.h>
#include <getopt.h>
#include <stddef.h>
#include <string.h>

struct config new_config() {
  struct config cfg;
  cfg.input_file = NULL;
  cfg.output_file = NULL;
  cfg.action = ACT_INVALID;
  cfg.format = FMT_INVALID;
  return cfg;
}

enum compression_format get_format(char *format) {
  if (format == NULL) {
    return FMT_INVALID;
  }
  if (!strcmp(format, RLE_COMPRESSION_ARG)) {
    return FMT_RLE;
  }
  return FMT_INVALID;
}

int get_config(int argc, char **argv, struct config *cfg) {
  struct option long_options[] = {OPT_OUTPUT, OPT_COMPRESS, OPT_EXTRACT,
                                  OPT_TERM};
  char short_options[] = SHORT_OPTS;
  int option;

  *cfg = new_config();

  while ((option = getopt_long(argc, argv, short_options, long_options,
                               NULL)) != OPT_SUCCESS) {
    switch (option) {
    case OPT_OUTPUT_SHORT:
      cfg->output_file = optarg;
      break;
    case OPT_COMPRESS_SHORT:
      if (cfg->action != ACT_INVALID) {
        return EACTCONFL;
      }
      cfg->action = ACT_COMPRESS;
      cfg->format = get_format(optarg);
      if (cfg->format == FMT_INVALID) {
        return EFMTUNK;
      }
      break;
    case OPT_EXTRACT_SHORT:
      if (cfg->action != ACT_INVALID) {
        return EACTCONFL;
      }
      cfg->action = ACT_EXTRACT;
      cfg->format = get_format(optarg);
      if (cfg->format == FMT_INVALID) {
        return EFMTUNK;
      }
      break;
    case OPT_HAS_ARG:
    /* fall through */
    case OPT_UNKNOWN:
      return EOPTUNK;
    default:
      break;
    }
  }
  if (optind < argc) {
    cfg->input_file = argv[optind];
  }
  if (!cfg->output_file) {
    cfg->output_file = DEFAULT_OUTPUT_FILE;
  }
  if (cfg->action == ACT_INVALID) {
    return ENOACT;
  }
  return CONFIG_SUCCESS;
}