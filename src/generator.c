#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

void generate_user(struct User *user, int id) {

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

    int firstIndex = rand() % firstNameCount;
    int lastIndex = rand() % lastNameCount;
    int genderIndex = rand() % genderCount;
    int countryIndex = rand() % countryCount;

    user->id = id;

    snprintf(
        user->name,
        sizeof(user->name),
        "%s %s",
        firstNames[firstIndex],
        lastNames[lastIndex]
    );

    user->age = 18 + rand() % 43;

    snprintf(
        user->gender,
        sizeof(user->gender),
        "%s",
        genders[genderIndex]
    );

    snprintf(
        user->country,
        sizeof(user->country),
        "%s",
        countries[countryIndex]
    );

    snprintf(
        user->email,
        sizeof(user->email),
        "%s.%s%d@example.com",
        firstNames[firstIndex],
        lastNames[lastIndex],
        user->id
    );

    for (int i = 0; user->email[i] != '\0'; i++) {
        if (user->email[i] >= 'A' && user->email[i] <= 'Z') {
            user->email[i] += 'a' - 'A';
        }
    }

    snprintf(
        user->phone,
        sizeof(user->phone),
        "%d%09d",
        6 + (rand() % 4),
        rand() % 1000000000
    );
}
