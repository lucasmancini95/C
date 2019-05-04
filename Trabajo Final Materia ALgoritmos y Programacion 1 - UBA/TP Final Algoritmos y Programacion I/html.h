#ifndef HTML_H
#define HTML_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
#include "type.h"

/* HTML */
#define TABLE_OPEN "<table>\n"
#define TABLE_CLOSE "</table>\n"
#define OBJECT_OPEN "<tr bgcolor="
#define TR_CLOSE ">\n"
#define OBJECT_CLOSE "</tr>\n"
#define CELL_OPEN "\t<td>"
#define CELL_CLOSE "</td>\n"
#define HTML_HEADER_OPEN "<html>\n<head>\n<title>Compras</title>\n</head>\n<body bgcolor=\"#99ccff\">\n<center>\n<b>Listado de Novedades</b>\n</center>\n<br>\n<br>\n<table align=\"center\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n<tr bgcolor=\"#c0c0c0\">\n<tr bgcolor=\"#c0c0c0\">\n<td align=\"center\">Producto</td>\n<td align=\"center\">Precio</td>\n<td align=\"center\">C&oacute;digo</td>\n"
#define HTML_HEADER_CLOSE "</table>\n<br>\n<hr align=\"center\" width=\"50%\" size=\"2\" color=\"#050505\">\n</body>\n</html>\n"

/* COLORS */
#define COLOR_BLUE "#ffffcc"
#define COLOR_ORANGE "#ffaaaa"

#define MAX_COLOR 50

status_t print_header_open (FILE *);
status_t print_html_object_info (FILE *, void *, size_t);
status_t print_header_close (FILE *);


#endif
