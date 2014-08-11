#ifndef USER_H
#define USER_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int tam;

struct User
{
    char name[100];
    char email[50];
    int grade;
    int id;
    int allocStatus;
    struct User *next;
};
typedef struct User user;

void userMenu(user *userList);
void userRegister(user *userList);
int userModify(user *userList);
int userSearch(user *userList);
void showList(user *userList);
int userDelete(user *userList);

/** Auxiliares **/
void listInit(user *userList);
int nullList(user *userList);
char *returnGrade(int grade);
int searchAllocStatus(user *userList, char *nameQ);
int modifyAllocStatus(user *userList, char *nameQ);
user *alocate();

#endif // USER_H
