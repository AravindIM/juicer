#include "config.h"
#include <getopt.h>
#include <stddef.h>

int get_config(int argc, char **argv, struct config *cfg) {
  struct option long_options[] = {OPT_OUTPUT, OPT_TERM};
  char short_options[] = SHORT_OPTS;
  int option;

  while ((option = getopt_long(argc, argv, short_options, long_options,
                               NULL)) != OPT_SUCCESS) {
    switch (option) {
    case OPT_OUTPUT_SHORT:
      cfg->output_file = optarg;
      break;
    case OPT_HAS_ARG:
    /* fall through */
    case OPT_UNKNOWN:
      return ECFG;
    default:
      break;
    }
  }
  if (optind < argc) {
    cfg->input_file = argv[optind];
  } else {
    cfg->input_file = NULL;
    return ECFG;
  }
  if (!cfg->output_file) {
    cfg->output_file = DEFAULT_OUTPUT_FILE;
  }
  return CONFIG_SUCCESS;
}