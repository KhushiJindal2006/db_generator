#include <stdio.h>
#include "exporter.h"

void write_csv_header(FILE *file) {
    fprintf(
        file,
        "id,name,age,gender,country,email,phone\n"
    );
}

void write_user_csv(FILE *file, const struct User *user) {
    fprintf(
        file,
        "%d,%s,%d,%s,%s,%s,%s\n",
        user->id,
        user->name,
        user->age,
        user->gender,
        user->country,
        user->email,
        user->phone
    );
}
