#include <stdio.h>
#include "exporter.h"

void write_csv_header(FILE *file, const int selectedColumns[]) {
    const char *headers[] = {
        "id", "name", "age", "gender",
        "country", "email", "phone"
    };

    int first = 1;

    for (int i = 0; i < 7; i++) {
        if (selectedColumns[i]) {
            if (!first) {
                fprintf(file, ",");
            }

            fprintf(file, "%s", headers[i]);
            first = 0;
        }
    }

    fprintf(file, "\n");
}

void write_user_csv(FILE *file, const struct User *user,
                    const int selectedColumns[]) {
    int first = 1;

    for (int i = 0; i < 7; i++) {
        if (selectedColumns[i]) {
            if (!first) {
                fprintf(file, ",");
            }

            switch (i) {
                case 0:
                    fprintf(file, "%d", user->id);
                    break;
                case 1:
                    fprintf(file, "%s", user->name);
                    break;
                case 2:
                    fprintf(file, "%d", user->age);
                    break;
                case 3:
                    fprintf(file, "%s", user->gender);
                    break;
                case 4:
                    fprintf(file, "%s", user->country);
                    break;
                case 5:
                    fprintf(file, "%s", user->email);
                    break;
                case 6:
                    fprintf(file, "%s", user->phone);
                    break;
            }

            first = 0;
        }
    }

    fprintf(file, "\n");
}
