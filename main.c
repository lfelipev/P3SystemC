#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "resource.h"
#include "user.h"
#include "report.h"
#include "file.h"
#include "activity.h"

/** Função Principal **/
int main ()
{
    user *userList = (user *)malloc(sizeof(user));
    resource *resourceList = (resource *)malloc(sizeof(resource));
    activity *activityList = (activity *)malloc(sizeof(activity));
    if(!userList || !resourceList || !activityList)
    {
        printf("Sem memória disponível!\n");
        return 0;
    }
    else
    {
        listInit(userList);
        resourceListInit(resourceList);
        activityListInit(activityList);
        int choose = 0;

        while(choose != 6)
        {
            /** Menu da Tela **/
            printf("===========================================\n");
            printf("------ SELECIONE A OPÇÃO PELO ÍNDICE ------\n");
            printf("===========================================\n");
            printf("[1]USUÁRIO\n");
            printf("[2]RECURSO\n");
            printf("[3]ATIVIDADES\n");
            printf("[4]RELATÓRIO\n");
            printf("[0]SAIR\n");
            scanf("%i", &choose);
            fflush(stdin);

            switch(choose)
            {
                case 1:
                    userMenu(userList); break;
                case 2:
                    resourceMenu(resourceList, userList, activityList); break;
                case 3:
                    activityMenu(activityList); break;
                case 4:
                    reportMenu(); break;
                case 0:
                    saveResourceFile(resourceList);
                    saveActivityFile(activityList);
                    saveFile(userList);
                    free(userList);
                    printf("PROGRAMA ENCERRADO\n");
                    return 0;
                default:
                    printf("OPÇÃO INVÁLIDA\n");
            }

        }

        free(userList);
        return 0;
    }
}
