#ifndef _CONFIG_H_
#define _CONFIG_H_

#define OPT_SUCCESS -1
#define CONFIG_SUCCESS 0
#define EOPTUNK -1
#define ENOINP -2
#define ENOACT -3
#define EACTCONFL -4
#define EFMTUNK -5

#define PROGRAM_NAME_INDEX 0
#define OPT_END '\0'

#define OPT_HAS_ARG ':'
#define OPT_UNKNOWN '?'

#define OPT_OUTPUT_LONG "output"
#define OPT_OUTPUT_SHORT 'o'

#define OPT_COMPRESS_LONG "compress"
#define OPT_COMPRESS_SHORT 'c'

#define OPT_EXTRACT_LONG "extract"
#define OPT_EXTRACT_SHORT 'e'

#define SHORT_OPTS                                                             \
  {OPT_OUTPUT_SHORT, OPT_HAS_ARG,       OPT_COMPRESS_SHORT,                    \
   OPT_HAS_ARG,      OPT_EXTRACT_SHORT, OPT_HAS_ARG,                           \
   OPT_END}

#define OPT_OUTPUT {OPT_OUTPUT_LONG, required_argument, 0, OPT_OUTPUT_SHORT}
#define OPT_COMPRESS                                                           \
  {OPT_COMPRESS_LONG, required_argument, 0, OPT_COMPRESS_SHORT}
#define OPT_EXTRACT {OPT_EXTRACT_LONG, required_argument, 0, OPT_EXTRACT_SHORT}

#define OPT_TERM {0, 0, 0, 0}

#define DEFAULT_OUTPUT_FILE "out.jcr"

enum compression_format { FMT_INVALID, FMT_RLE };
enum compression_action { ACT_INVALID, ACT_COMPRESS, ACT_EXTRACT };

struct config {
  char *input_file;
  char *output_file;
  enum compression_action action;
  enum compression_format format;
};

struct config new_config();

int get_config(int argc, char **argv, struct config *cfg);

#endif