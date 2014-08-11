#include "activity.h"

void activityListInit(activity *activityList)
{
    activityList->next = NULL;
    actTam = 0;
}

void activityMenu(activity *activityList)
{
    int choose = 0;
    printf("=============================\n");
    printf("------ MENU ATIVIDADES ------\n");
    printf("=============================\n");
    printf("[1]CADASTRO\n"); //Coloca nova atividade na lista
    printf("[0]VOLTAR\n");
    scanf("%i", &choose);
    fflush(stdin);

    switch(choose)
    {
        case 0:
            break;
        case 1:
            activityRegister(activityList, 0); break;
        default:
            printf("Opção inválida:\n");
    }
}

void activityRegister(activity *activityList, int activityID)
{
    activity *newNode = aAlocate(activityID);
    newNode->next = NULL;

    if(activityNullList(activityList))
    {
        activityList->next = newNode;
    }
    else
    {
        activity *tmp = activityList->next;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    actTam++;
}

int activityNullList(activity *activityList)
{
    if(activityList->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

activity *aAlocate(int activityID)
{
    activity *newNode = (activity *)malloc(sizeof(activity));
    if(!newNode)
    {
        printf("Sem memória suficiente!\n");
        exit(1);
    }
    else
    {
        if(activityID == 0)
        {
            printf("Digite o índice da Atividade a ser realizada: \n");
            printf("[1]Aula Tradicional\n");
            printf("[2]Apresentações\n");
            printf("[3]Laboratório\n");
            scanf("%d", &newNode->activity);
            fflush(stdin);
            switch(newNode->activity)
            {
                case 1:
                    act1Tam++; break;
                case 2:
                    act2Tam++; break;
                case 3:
                    act3Tam++; break;
            }

            printf("Título da Atividade: "); scanf(" %[^\n]s", newNode->title);
            fflush(stdin);
            printf("Participantes(Separados por espaços): "); scanf(" %[^\n]s", newNode->participants);
            fflush(stdin);
            printf("Material de Apoio(Separados por espaços): "); scanf(" %[^\n]s", newNode->material);
            fflush(stdin);
            printf("Escreva uma breve descrição da atividade: "); scanf(" %[^\n]s", newNode->description);
            fflush(stdin);

            return newNode;
        }
        else
        {
            printf("Título da Atividade: "); scanf(" %[^\n]s", newNode->title);
            fflush(stdin);
            printf("Participantes(Separados por espaços): "); scanf(" %[^\n]s", newNode->participants);
            fflush(stdin);
            printf("Material de Apoio(Separados por espaços): "); scanf(" %[^\n]s", newNode->material);
            fflush(stdin);
            printf("Escreva uma breve descrição da atividade: "); scanf(" %[^\n]s", newNode->description);
            fflush(stdin);

            return newNode;
        }
    }
    return 0;
}

char *returnActivity(int grade)
{
    switch(grade)
    {
        case 1:
            return "Aula Tradicional"; break;
        case 2:
            return "Apresentações"; break;
        case 3:
            return "Laboratório"; break;
        case 0:
            return "Nenhuma Atividade Relacionada"; break;
    }
    return 0;
}
