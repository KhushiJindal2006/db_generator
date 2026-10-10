#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generator.h"
#include "exporter.h"

int main(int argc, char *argv[]) {
    int numRecords;
    int selectedColumns[7] = {0};
    int columnNumber;

    srand(time(NULL));

    printf("Synthetic Database Generator\n");

    if (argc == 2) {
        numRecords = atoi(argv[1]);
    } else {
        printf("How many records would you like to generate: ");
        scanf("%d", &numRecords);
    }

    if (numRecords <= 0) {
        printf("Error: Please enter a valid number of records.\n");
        return 1;
    }

    printf("\nSelect the columns you want:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Age\n");
    printf("4. Gender\n");
    printf("5. Country\n");
    printf("6. Email\n");
    printf("7. Phone\n");

    printf("\nEnter column numbers one by one (enter 0 to finish):\n");

    while (1) {
        printf("Column number: ");

        if (scanf("%d", &columnNumber) != 1) {
            printf("Error: Please enter numbers only.\n");
            return 1;
        }

        if (columnNumber == 0) {
            break;
        }

        if (columnNumber < 1 || columnNumber > 7) {
            printf("Invalid column number. Choose from 1 to 7.\n");
            continue;
        }

        selectedColumns[columnNumber - 1] = 1;
    }

    int hasColumn = 0;

    for (int i = 0; i < 7; i++) {
        if (selectedColumns[i]) {
            hasColumn = 1;
            break;
        }
    }

    if (!hasColumn) {
        printf("Error: Please select at least one column.\n");
        return 1;
    }

    FILE *file = fopen("users.csv", "w");

    if (file == NULL) {
        printf("Error: Could not create users.csv\n");
        return 1;
    }

    write_csv_header(file, selectedColumns);

    for (int i = 0; i < numRecords; i++) {
        struct User user;

        generate_user(&user, i + 1);
        write_user_csv(file, &user, selectedColumns);
    }

    fclose(file);

    printf("\nSuccessfully generated %d records.\n", numRecords);
    printf("Data saved to users.csv\n");

    return 0;
}
