#include "resource.h"

void resourceListInit(resource *resourceList)
{
    resourceList->next = NULL;
    resTam = 0;
}

void resourceMenu(resource *resourceList, user *userList, activity *activityList)
{
    int choose = 0;
    printf("==========================\n");
    printf("------ MENU RECURSO ------\n");
    printf("==========================\n");
    printf("[1]REGISTRAR\n"); //Coloca novo rescurso no fim da lista
    printf("[2]ALOCAR\n");  //Altera um recurso na lista
    printf("[3]CONFIRMAR ALOCAÇÃO\n"); //Consulta a alocação do recurso
    printf("[4]CONSULTAR\n");
    printf("[5]ADMINISTRADOR - DELETAR\n");   //Exclui recurso da lista
    printf("[6]ADMINISTRADOR - CONCLUIR ALOCAÇÃO\n");
    printf("[7]ADMINISTRADOR - RESETAR ALOCAÇÃO\n");
    printf("[0]VOLTAR\n");
    scanf("%i", &choose);
    fflush(stdin);

    switch(choose)
    {
        case 0:
            break;
        case 1:
            resourceRegister(resourceList, userList); break;
        case 2:
            resourceAlloc(resourceList, userList); break;
        case 3:
            confirmAlloc(resourceList, activityList, userList); break;
        case 4:
            resourceSearch(resourceList); break;
        case 5:
            resourceDelete(resourceList); break;
        case 6:
            admConclude(resourceList, userList); break;
        case 7:
            resourceReset(resourceList, userList); break;
        default:
            printf("Opção inválida:\n");
    }
}

/** Função de registro de usuário **/
void resourceRegister(resource *resourceList, user *userList)
{
    resource *newNode = rAlocate(userList);
    newNode->next = NULL;

    if(resourceNullList(resourceList))
    {
        resourceList->next = newNode;
    }
    else
    {
        resource *tmp = resourceList->next;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    resTam++;
}

resource *rAlocate(user *userList)
{
    char name[100];
    resource *newNode = (resource *)malloc(sizeof(resource));
    if(!newNode)
    {
        printf("Sem memória suficiente!\n");
        exit(1);
    }
    else
    {
        printf("===========================================\n");
        printf("------------ REGISTRAR RECURSO ------------\n");
        printf("===========================================\n");
        printf("Digite o nome do recurso: "); scanf(" %[^\n]s", newNode->resourceName);
        fflush(stdin);
        printf("Digite o nome do Responsável pelo recurso: "); scanf(" %[^\n]s", newNode->responsibleName);
        if(gradeSearch(userList, newNode->responsibleName) == 0)
        {
            printf("Usuário não encontrado ou não possui os requísitos para alocar o recurso!\n");
            printf("Requísitos: Professor, Pesquisador, Administrador do Sistema.\n");
        }
        else
        {
            newNode->resourceId = resTam+1;
            newNode->alocationProcessStatus = 1;
            status1++;
            printf("\nID DO RECURSO: %d", newNode->resourceId);
            printf("\nRECURSO REGISTRADO!\n");
            fflush(stdin);

            return newNode;
        }
    }
    return newNode;
}

int gradeSearch(user *userList, char *responsible)
{
    char *name;
    user *tmp;
    user *prev;

    name = responsible;

    if(userList->next == NULL)
    {
        printf("A lista de usuŕios está vazia!\n");
        return 0;
    }
    else
    {
        tmp = userList;
        prev = userList;

        while(tmp != NULL)
        {
            if(strcmp(tmp->name, name) == 0)
            {
                if(tmp == userList)
                {
                    if(tmp->grade == 6 || tmp->grade == 5 || tmp->grade == 4)
                    {
                        return tmp->grade;
                    }
                }
                else
                {
                    if(tmp->grade == 6 || tmp->grade == 5 || tmp->grade == 4)
                    {
                        return tmp->grade;
                    }
                    return 0;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        return 0;
    }
}

int resourceNullList(resource *resourceList)
{
    if(resourceList->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int resourceAlloc(resource *resourceList, user *userList)
{
    char rName[100];
    char *userName = malloc(sizeof(*userName));
    printf("========================================\n");
    printf("------------ ALOCAR RECURSO ------------\n");
    printf("========================================\n");
    printf("Digite nome do Recurso que deseja Alocar: "); scanf(" %[^\n]s", rName);
    resource *tmp;
    resource *prev;

    if(resourceList->next == NULL)
    {
        printf("A lista de recursos está vazia!\n");
        return 0;
    }
    else
    {
        tmp = resourceList;
        prev = resourceList;

        while(tmp != NULL)
        {
            if(strcmp(tmp->resourceName, rName) == 0 && tmp->alocationProcessStatus == 1)
            {
                if(tmp == resourceList)
                {
                    printf("Digite o seu NOME de usuário: "); scanf(" %[^\n]s", userName);
                    fflush(stdin);
                    if(searchAllocStatus(userList, userName) == 0)
                    {
                        printf("TAL USUÁRIO JÁ TEM UM PROCESSO DE ALOCAÇÃO ABERTO!\n");
                    }
                    else
                    {
                        printf("Digite o dia e hora do início da alocação: (Formato: dia/mês/ano hora): "); scanf("%d/%d/%d %d", &tmp->iDay,
                                                                                                                  &tmp->iMonth,
                                                                                                                  &tmp->iYear,
                                                                                                                  &tmp->iHour);

                        printf("\nDigite o dia e hora do fim da alocação: (Formato: dia/mês/ano hora): "); scanf("%d/%d/%d %d", &tmp->fDay,
                                                                                                                                &tmp->fMonth,
                                                                                                                                &tmp->fYear,
                                                                                                                                &tmp->fHour);
                        fflush(stdin);
                        tmp->userAlloc = userName;
                        tmp->alocationProcessStatus = 2;
                        status2++;
                        nAll++;
                        modifyAllocStatus(userList, userName);
                        printf("\nSTATUS DO RECURSO ALTERADO PARA: 'ALOCADO'\n");

                        return 1;
                    }
                }
                else
                {
                    printf("Digite o seu nome de usuário: "); scanf(" %[^\n]s", userName);
                    fflush(stdin);
                    if(searchAllocStatus(userList, userName) == 0)
                    {
                        printf("TAL USUÁRIO JÁ TEM UM PROCESSO DE ALOCAÇÃO ABERTO!\n");
                    }
                    else
                    {
                        printf("Digite o dia e hora do início da alocação: (Formato: dia/mês/ano hora): "); scanf("%d/%d/%d %d", &tmp->iDay,
                                                                                                                  &tmp->iMonth,
                                                                                                                  &tmp->iYear,
                                                                                                                  &tmp->iHour);

                        printf("\nDigite o dia e hora do fim da alocação: (Formato: dia/mês/ano hora): "); scanf("%d/%d/%d %d", &tmp->fDay,
                                                                                                                                &tmp->fMonth,
                                                                                                                                &tmp->fYear,
                                                                                                                                &tmp->fHour);
                        fflush(stdin);
                        tmp->userAlloc = userName;
                        tmp->alocationProcessStatus = 2;
                        status2++;
                        nAll++;
                        modifyAllocStatus(userList, userName);
                        printf("\nSTATUS DO RECURSO ALTERADO PARA: 'ALOCADO'\n");

                        return 1;
                    }
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("RECURSO NÃO ENCONTRADO OU NÃO PODE SER ALOCADO!\n");
        return 0;
    }
}

int confirmAlloc(resource *resourceList, activity *activityList, user *userList)
{
    char rName[100];
    char userName[100];
    printf("==========================================================\n");
    printf("------------------- CONFIRMAR ALOCAÇÃO -------------------\n");
    printf("==========================================================\n");
    printf("Digite nome do Recurso no qual deseja confirmar a Alocação: "); scanf(" %[^\n]s", rName);
    resource *tmp;
    resource *prev;

    if(resourceList->next == NULL)
    {
        printf("A lista de recursos está vazia!\n");
        return 0;
    }
    else
    {
        tmp = resourceList;
        prev = resourceList;

        while(tmp != NULL)
        {
            if(strcmp(tmp->resourceName, rName) == 0 && tmp->alocationProcessStatus == 2)
            {
                if(tmp == resourceList)
                {
                    printf("Digite o seu NOME de usuário: "); scanf(" %[^\n]s", userName);
                    fflush(stdin);
                    if(strcmp(userName, tmp->userAlloc) != 0)
                    {
                        printf("VOCÊ NÃO ALOCOU ESTE RECURSO!\n");
                    }
                    else
                    {
                        printf("Digite o índice da Atividade a ser realizada: \n");
                        printf("[1]Aula Tradicional\n");
                        printf("[2]Apresentações\n");
                        printf("[3]Laboratório\n");
                        scanf("%d", &tmp->activity);
                        fflush(stdin);
                        if((tmp->activity == 1 && gradeSearch(userList, tmp->userAlloc) != 4) ||
                                (tmp->activity == 3 && gradeSearch(userList, tmp->userAlloc) != 4))
                        {
                            printf("\nVOCÊ NÃO TEM OS REQUÍSITOS PARA ESTE TIPO DE ATIVIDADE\n");
                            printf("Requísitos: Professor\n");
                            tmp->alocationProcessStatus = 0;
                            return 0;
                        }
                        else
                        {
                            activityRegister(activityList, tmp->activity);

                            tmp->alocationProcessStatus = 3;
                            status3++;
                            printf("\nSTATUS DO RECURSO ALTERADO PARA: 'EM ANDAMENTO'\n");

                            return 1;
                        }
                    }
                }
                else
                {
                    printf("Digite o seu NOME de usuário: "); scanf(" %[^\n]s", userName);
                    fflush(stdin);
                    if(strcmp(userName, tmp->userAlloc) != 0)
                    {
                        printf("VOCÊ NÃO ALOCOU ESTE RECURSO!\n");
                    }
                    else
                    {
                        printf("Digite o índice da Atividade a ser realizada: \n");
                        printf("[1]Aula Tradicional\n");
                        printf("[2]Apresentações\n");
                        printf("[3]Laboratório\n");
                        scanf("%d", &tmp->activity);
                        fflush(stdin);
                        if((tmp->activity == 1 && gradeSearch(userList, tmp->userAlloc) != 4) ||
                                (tmp->activity == 3 && gradeSearch(userList, tmp->userAlloc) != 4))
                        {
                            printf("\nVOCÊ NÃO TEM OS REQUÍSITOS PARA ESTE TIPO DE ATIVIDADE\n");
                            printf("Requísitos: Professor\n");
                            tmp->alocationProcessStatus = 0;
                            return 0;
                        }
                        else
                        {
                            activityRegister(activityList, tmp->activity);

                            tmp->alocationProcessStatus = 3;
                            status3++;
                            printf("\nSTATUS DO RECURSO ALTERADO PARA: 'EM ANDAMENTO'\n");

                            return 1;
                        }
                        activityRegister(activityList, tmp->activity);

                        tmp->alocationProcessStatus = 3;
                        status3++;
                        printf("\nSTATUS DO RECURSO ALTERADO PARA: 'EM ANDAMENTO'\n");

                        return 1;
                    }
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("RECURSO NÃO ENCONTRADO OU NÃO PODE SER ALOCADO!\n");
        return 0;
    }
}

int admConclude(resource *resourceList, user *userList)
{
    char rName[100];
    char userName[100];
    printf("============================================\n");
    printf("------------- CONCLUIR ALOCAÇÃO-------------\n");
    printf("============================================\n");
    printf("Digite seu nome: "); scanf(" %[^\n]s", userName);
    if(gradeSearch(userList, userName) != 6)
    {
        printf("Você não é um administrador do sistema!\n");
        return 0;
    }
    else
    {
        printf("Digite nome do Recurso no qual deseja concluir a Alocação: "); scanf(" %[^\n]s", rName);
        resource *tmp;
        resource *prev;

        if(resourceList->next == NULL)
        {
            printf("A lista está vazia!\n");
            return 0;
        }
        else
        {
            tmp = resourceList;
            prev = resourceList;

            while(tmp != NULL)
            {
                if(strcmp(tmp->resourceName, rName) == 0)
                {
                    if(tmp == resourceList)
                    {
                            printf("ID do recurso: %d\n", tmp->resourceId);
                            printf("Nome do Recurso: %s\n", tmp->resourceName);
                            printf("Responsável pelo recurso: %s\n", tmp->responsibleName);
                            printf("Status do Recurso: %d\n", tmp->alocationProcessStatus);
                            printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->iDay, tmp->iMonth, tmp->iYear, tmp->iHour);
                            printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->fDay, tmp->fMonth, tmp->fYear, tmp->fHour);
                            printf("Usuário que Alocou o Recurso: %s\n", tmp->userAlloc);
                            printf("Atividade a ser realizada: %s\n", returnActivity(tmp->activity));
                            printf("\n");
                            printf("Deseja Confirmar a alocação?\n");
                            printf("[1]Sim\n");
                            printf("[0]Não\n");
                            int choose3;
                            scanf("%d", &choose3);
                            switch(choose3)
                            {
                                case 1:
                                    printf("STATUS DO RECURSO ALTERADO PARA: CONCLUÍDO\n");
                                    tmp->alocationProcessStatus = 4; break;
                                case 0:
                                    printf("STATUS DO RECURSO: EM ANDAMENTO\n");
                                    tmp->alocationProcessStatus = 3;
                                    return 1;
                            }

                            return 1;
                        }
                    else
                    {
                        printf("ID do recurso: %d\n", tmp->resourceId);
                        printf("Nome do Recurso: %s\n", tmp->resourceName);
                        printf("Responsável pelo recurso: %s\n", tmp->responsibleName);
                        printf("Status do Recurso: %s\n", returnStatus(tmp->alocationProcessStatus));
                        printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->iDay, tmp->iMonth, tmp->iYear, tmp->iHour);
                        printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->fDay, tmp->fMonth, tmp->fYear, tmp->fHour);
                        printf("Usuário que Alocou o Recurso: %s\n", tmp->userAlloc);
                        printf("Atividade a ser realizada: %s\n", returnActivity(tmp->activity));
                        printf("\n");
                        printf("Deseja Confirmar a alocação?\n");
                        printf("[1]Sim\n");
                        printf("[0]Não\n");
                        int choose2;
                        scanf("%d", &choose2);
                        switch(choose2)
                        {
                            case 1:
                                printf("STATUS DO RECURSO ALTERADO PARA: CONCLUÍDO\n");
                                status4++;
                                tmp->alocationProcessStatus = 4; break;
                            case 0:
                                printf("STATUS DO RECURSO: EM ANDAMENTO\n");
                                tmp->alocationProcessStatus = 3;
                                return 1;
                        }
                        return 1;
                    }
                }
                else
                {
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
            printf("RECURSO NÃO ENCONTRADO OU NÃO PODE SER ALOCADO!\n");
            return 0;
        }
    }
}

int resourceDelete(resource *resourceList)
{
    int id;
    printf("Digite ID do recurso que deseja deletar: "); scanf("%d", &id);

    resource *tmp;
    resource *prev;

    if(resourceList->next == NULL)
    {
        printf("A lista está vazia!\n");
        return 0;
    }
    else
    {
        tmp = resourceList;
        prev = resourceList;

        while(tmp != NULL)
        {
            if(tmp->resourceId == id)
            {
                if(tmp == resourceList)
                {
                    resourceList = resourceList->next;
                    resTam--;
                    free(tmp);
                    printf("Recurso removido!\n");
                    return 1;
                }
                else
                {
                    prev->next = tmp->next;
                    resTam--;
                    free(tmp);
                    printf("Recurso removido!\n");
                    return 1;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("Recurso não encontrado!\n");
        return 0;
    }
}

int resourceSearch(resource *resourceList)
{
    char rName[100];
    printf("Digite nome do Recurso no qual deseja consultar: "); scanf(" %[^\n]s", rName);
    resource *tmp;
    resource *prev;

    if(resourceList->next == NULL)
    {
            printf("A lista está vazia!\n");
            return 0;
    }
    else
    {
        tmp = resourceList;
        prev = resourceList;

        while(tmp != NULL)
        {
            if(strcmp(tmp->resourceName, rName) == 0)
            {
                if(tmp == resourceList)
                {
                        printf("ID do recurso: %d\n", tmp->resourceId);
                        printf("Nome do Recurso: %s\n", tmp->resourceName);
                        printf("Responsável pelo recurso: %s\n", tmp->responsibleName);
                        printf("Status do Recurso: %d\n", tmp->alocationProcessStatus);
                        printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->iDay, tmp->iMonth, tmp->iYear, tmp->iHour);
                        printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->fDay, tmp->fMonth, tmp->fYear, tmp->fHour);
                        printf("Usuário que Alocou o Recurso: %s\n", tmp->userAlloc);
                        printf("Atividade a ser realizada: %s\n", returnActivity(tmp->activity));
                        printf("\n");

                        return 1;
                        }
                else
                {
                    printf("ID do recurso: %d\n", tmp->resourceId);
                    printf("Nome do Recurso: %s\n", tmp->resourceName);
                    printf("Responsável pelo recurso: %s\n", tmp->responsibleName);
                    printf("Status do Recurso: %d\n", tmp->alocationProcessStatus);
                    printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->iDay, tmp->iMonth, tmp->iYear, tmp->iHour);
                    printf("Data inical da Alocação: %d/%d/%d %d horas\n", tmp->fDay, tmp->fMonth, tmp->fYear, tmp->fHour);
                    printf("Usuário que Alocou o Recurso: %s\n", tmp->userAlloc);
                    printf("Atividade a ser realizada: %s\n", returnActivity(tmp->activity));
                    printf("\n");
                    return 1;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("RECURSO NÃO ENCONTRADO OU NÃO PODE SER ALOCADO!\n");
        return 0;
    }
}

int resourceReset(resource *resourceList, user *userList)
{
    char rName[100];
    char userName[100];
    printf("============================================\n");
    printf("------------- RESETAR ALOCAÇÃO-------------\n");
    printf("============================================\n");
    printf("Digite seu nome: "); scanf(" %[^\n]s", userName);
    if(gradeSearch(userList, userName) != 6)
    {
        printf("Você não é um administrador do sistema!\n");
        return 0;
    }
    else
    {
        printf("Digite nome do Recurso no qual deseja resetar a Alocação: "); scanf(" %[^\n]s", rName);
        resource *tmp;
        resource *prev;

        if(resourceList->next == NULL)
        {
            printf("A lista está vazia!\n");
            return 0;
        }
        else
        {
            tmp = resourceList;
            prev = resourceList;

            while(tmp != NULL)
            {
                if(strcmp(tmp->resourceName, rName) == 0)
                {
                    if(tmp == resourceList)
                    {
                        tmp->fDay = 0;
                        tmp->fHour = 0;
                        tmp->fMonth = 0;
                        tmp->fYear = 0;
                        tmp->activity = 1;
                        tmp->alocationProcessStatus = 1;
                        tmp->iDay = 0;
                        tmp->iHour = 0;
                        tmp->iYear = 0;
                        tmp->userAlloc = "Ninguém";

                        return 1;
                    }
                    else
                    {
                        tmp->fDay = 0;
                        tmp->fHour = 0;
                        tmp->fMonth = 0;
                        tmp->fYear = 0;
                        tmp->activity = 1;
                        tmp->alocationProcessStatus = 1;
                        tmp->iDay = 0;
                        tmp->iHour = 0;
                        tmp->iYear = 0;
                        tmp->userAlloc = "Ninguém";

                        return 1;
                    }
                }
                else
                {
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
            printf("RECURSO NÃO ENCONTRADO!\n");
            return 0;
        }
    }
}


char *returnStatus(int status)
{
    switch(status)
    {
        case 1:
            return "Em processo de alocação"; break;
        case 2:
            return "Alocado"; break;
        case 3:
            return "Em andamento"; break;
        case 4:
            return "Concluído"; break;
        default:
            printf("Opção inválida\n"); break;
    }
    return 0;
}
