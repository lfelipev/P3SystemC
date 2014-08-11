#ifndef ACTIVITY_H
#define ACTIVITY_H

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "user.h"
#include "activity.h"

struct Activity
{
    char activityName[20];
    char title[100];
    char participants[1000];
    char description[1000];
    char material[1000];
    int activity;
    struct Activity *next;
};
typedef struct Activity activity;

int actTam;
int act1Tam;
int act2Tam;
int act3Tam;

void activityListInit(activity *activityList);
void activityMenu(activity *activityList);
int activityNullList(activity *activityList);
activity *aAlocate(int activityID);
void activityRegister(activity *activityList, int activityID);
char *returnActivity(int grade);

#endif // ACTIVITY_H
