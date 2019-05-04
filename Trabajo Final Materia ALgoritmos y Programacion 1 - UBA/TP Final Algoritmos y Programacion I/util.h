#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "type.h"

#define LF '\n'
#define NUL '\0'
#define INIT_CHOP 10
#define CHOP_SIZE 3

bool_t is_empty_string(const char []);
status_t split(char ***, char *, char, size_t *);
status_t destroy_string_array( char ***, size_t);
status_t strdupl (const char [], char **);
status_t read_file_line (FILE *, char **, bool_t *);
status_t destroy_string(char **);
#endif
