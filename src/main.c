#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generator.h"
#include "exporter.h"

int main() {
    int numRecords;

    srand(time(NULL));

    printf("Database Generator\n");
    printf("Enter number of records to generate: ");

    scanf("%d", &numRecords);

    if (numRecords <= 0) {
        printf("Number of records must be greater than 0.\n");
        return 1;
    }

    FILE *file = fopen("users.csv", "w");

    if (file == NULL) {
        printf("Error: Could not create users.csv\n");
        return 1;
    }

    write_csv_header(file);

    for (int i = 0; i < numRecords; i++) {
        struct User user;

        generate_user(&user, i + 1);

        write_user_csv(file, &user);
    }

    fclose(file);

    printf("\nSuccessfully generated %d records.\n", numRecords);
    printf("Data saved to users.csv\n");

    return 0;
}
