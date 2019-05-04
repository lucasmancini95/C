#ifndef SETTING_H
#define SETTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "type.h"


/* Specifiers positions */
#define POS_FORMAT_SPECIFIER 1
#define POS_ITEMS_SPECIFIER 3
#define POS_LIST_SPECIFIER 5
#define POS_OUT_SPECIFIER 7

/* Formats array positions */
#define POS_FORMAT_HTML 0
#define POS_FORMAT_XML 1

/* Formats strings */
#define FORMAT_STRING_HTML "html"
#define FORMAT_STRING_XML "xml"

#define MAX_PATH 100

typedef struct {
		char items_path[MAX_PATH];
		char catalog_path[MAX_PATH];
		char out_path[MAX_PATH];
		format_t fmt;
		} setting_t;

/* Variables globales */

status_t str2setting (char **);
status_t str2format(const char[], format_t *);

#endif
