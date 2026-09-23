#ifndef EXPORTER_H
#define EXPORTER_H

#include <stdio.h>
#include "generator.h"

void write_csv_header(FILE *file);
void write_user_csv(FILE *file, const struct User *user);

#endif
