#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct User {
    int id;
    char name[50];
    int age;
    char gender[10];
    char country[30];
    char email[80];
    char phone[20];
};

int main() {
    int numRecords;

    const char *firstNames[] = {
        "Aarav", "Diya", "Rohan", "Ananya",
        "Vivaan", "Isha", "Arjun", "Meera",
        "Kabir", "Aanya", "Aditya", "Kiara"
    };

    const char *lastNames[] = {
        "Sharma", "Gupta", "Kumar", "Singh",
        "Patel", "Verma", "Jain", "Mehta",
        "Yadav", "Agarwal", "Malhotra", "Kapoor"
    };

    const char *countries[] = {
        "India",
        "USA",
        "Canada",
        "Australia",
        "Germany",
        "Japan"
    };

    const char *genders[] = {
        "Male",
        "Female"
    };

    int firstNameCount = 12;
    int lastNameCount = 12;
    int countryCount = 6;
    int genderCount = 2;

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

    fprintf(
        file,
        "id,name,age,gender,country,email,phone\n"
    );

    for (int i = 0; i < numRecords; i++) {
        struct User user;

        user.id = i + 1;

        int firstIndex = rand() % firstNameCount;
        int lastIndex = rand() % lastNameCount;
        int genderIndex = rand() % genderCount;
        int countryIndex = rand() % countryCount;

        snprintf(
            user.name,
            sizeof(user.name),
            "%s %s",
            firstNames[firstIndex],
            lastNames[lastIndex]
        );

        user.age = 18 + rand() % 43;

        snprintf(
            user.gender,
            sizeof(user.gender),
            "%s",
            genders[genderIndex]
        );

        snprintf(
            user.country,
            sizeof(user.country),
            "%s",
            countries[countryIndex]
        );

        snprintf(
            user.email,
            sizeof(user.email),
            "%s.%s%d@example.com",
            firstNames[firstIndex],
            lastNames[lastIndex],
            user.id
        );

	for (int j = 0; user.email[j] != '\0'; j++) {
           if (user.email[j] >= 'A' && user.email[j] <= 'Z') {
              user.email[j] = user.email[j] + ('a' - 'A');
           }
        }


        snprintf(
            user.phone,
            sizeof(user.phone),
            "%d%09d",
            6 + (rand() % 4),
            rand() % 1000000000
        );

        fprintf(
            file,
            "%d,%s,%d,%s,%s,%s,%s\n",
            user.id,
            user.name,
            user.age,
            user.gender,
            user.country,
            user.email,
            user.phone
        );
    }

    fclose(file);

    printf("\nSuccessfully generated %d records.\n", numRecords);
    printf("Data saved to users.csv\n");

    return 0;
}
