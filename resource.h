#ifndef RESOURCE_H
#define RESOURCE_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "user.h"
#include "activity.h"

int resTam;
int nAll; //Número de Alocações
int status1; //Em processo de alocação
int status2; //Alocados
int status3; //Em andamento
int status4; //Concluídos

struct Resource
{
    char resourceName[100];
    char responsibleName[100];
    char *userAlloc;
    int iDay, iMonth, iYear, iHour;
    int fDay, fMonth, fYear, fHour;
    int resourceId;
    int activity;
    int alocationProcessStatus;
    struct Resource *next;
};
typedef struct Resource resource;

void resourceMenu(resource *resourceList, user *userList, activity *activityList);
void resourceRegister(resource *resourceList, user *userList);
int resourceAlloc(resource *resourceList, user *userList);
int confirmAlloc(resource *resourceList, activity *activityList, user *userList);
int admConclude(resource *resourceList, user *userList);
int resourceDelete(resource *resourceList);
int resourceSearch(resource *resourceList);
int resourceReset(resource *resourceList, user *userList);
//void showResourceList(user *resourceList);
//int resourceDelete(user *resourceList);

/** Auxiliares **/
char *returnStatus(int status);
int gradeSearch(user *userList, char *responsible);
void resourceListInit(resource *resourceList);
int resourceNullList(resource *resourceList);
resource *rAlocate(user *userList);

#endif // RESOURCE_H
