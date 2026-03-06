#ifndef _LOG_H_
#define _LOG_H_

#define ERRMSG_UNK_OPT "Error: unknown option was passed\n"
#define ERRMSG_NO_INPUT_FILE "Error: No input file specified\n"
#define ERRMSG_NO_ACT "Error: no action was specified\n"
#define ERRMSG_CONFL_ACT "Error: conflicting compression actions were passed\n"
#define ERRMSG_UNK_FMT "Error: unknown format was passed\n"
#define ERRMSG_COMPRESSION "Error: compression failed\n"
#define HELP_STRING                                                            \
  "Usage: %s [OPTION]... INPUT\n"                                              \
  "  -c, --compress FORMAT   Compress INPUT using FORMAT\n"                    \
  "  -x, --extract FORMAT    Extract INPUT using FORMAT\n"                     \
  "  -o, --output FILE       Write output to FILE\n"

#endif