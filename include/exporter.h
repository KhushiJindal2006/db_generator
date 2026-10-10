#ifndef EXPORTER_H
#define EXPORTER_H

#include <stdio.h>
#include "generator.h"

void write_csv_header(FILE *file, const int selectedColumns[]);
void write_user_csv(FILE *file, const struct User *user, const int selectedColumns[]);

#endif
