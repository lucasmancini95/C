#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "type.h"
#include "lang.h"
#include "util.h"

#define SPACE_DELIMITER ' '
#define COLON_DELIMITER ':'
#define DASH_DELIMITER '-'
#define PIPE_DELIMITER '|'
#define LOG_FILE_PATH "/home/camila/algoritmos/tp2/inventory.log"
#define LF '\n'

#define MAX_DATA 200

void print_log (void);
status_t print_date (FILE *);


#endif
