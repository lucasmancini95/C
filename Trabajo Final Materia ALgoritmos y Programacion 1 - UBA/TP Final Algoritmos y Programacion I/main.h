#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "setting.h"
#include "vector.h"
#include "product.h"
#include "html.h"
#include "xml.h"
#include "inventory.h"
#include "register.h"
#include "type.h"

/* Max */
#define MAX_ARGS 9
#define MAX_DATA 200

/* Specifiers */
#define FORMAT_SPECIFIER "-fmt"
#define ITEMS_SPECIFIER "-items"
#define LIST_SPECIFIER "-list"
#define OUT_SPECIFIER "-out"

/* Specifiers positions */
#define POS_FORMAT_SPECIFIER 1
#define POS_ITEMS_SPECIFIER 3
#define POS_LIST_SPECIFIER 5
#define POS_OUT_SPECIFIER 7

/* Formats */
#define FORMAT_STRING_HTML "html"
#define FORMAT_STRING_XML "xml"

/* 0000000 */
#define LF '\n'
#define NUL '\0'
#define CMP_NUL 2


/* Prototipos */
status_t validate_arguments(int, char **);
status_t validate_arg_amount(int);
status_t validate_specifiers(char **);
status_t validate_format(char []);
status_t open_files (FILE **, FILE **, FILE **); 
status_t close_files (FILE **, FILE **, FILE **);

#endif
