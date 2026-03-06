#ifndef _CONFIG_H_
#define _CONFIG_H_

#define OPT_SUCCESS -1
#define CONFIG_SUCCESS 0
#define ECFG -1

#define PROGRAM_NAME_INDEX 0
#define OPT_END '\0'

#define OPT_HAS_ARG ':'
#define OPT_UNKNOWN '?'

#define OPT_OUTPUT_LONG "output"
#define OPT_OUTPUT_SHORT 'o'

#define SHORT_OPTS {OPT_OUTPUT_SHORT, OPT_HAS_ARG, OPT_END}
#define OPT_OUTPUT {OPT_OUTPUT_LONG, required_argument, 0, OPT_OUTPUT_SHORT}
#define OPT_TERM {0, 0, 0, 0}

#define DEFAULT_OUTPUT_FILE "out.jcr"

struct config {
  char *input_file;
  char *output_file;
};

int get_config(int argc, char **argv, struct config *cfg);

#endif