#ifndef GENERATOR_H
#define GENERATOR_H

struct User {
    int id;
    char name[50];
    int age;
    char gender[10];
    char country[30];
    char email[80];
    char phone[20];
};

void generate_user(struct User *user, int id);

#endif
