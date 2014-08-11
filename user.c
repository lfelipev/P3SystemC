#include "user.h"

char *returnGrade(int grade)
{
    switch(grade)
    {
        case 1:
            return "Graduando"; break;
        case 2:
            return "Mestre"; break;
        case 3:
            return "Doutor"; break;
        case 4:
            return "Professor"; break;
        case 5:
            return "Pesquisador"; break;
        case 6:
            return "Administrador do Sistema"; break;
    }
    return 0;
}

void listInit(user *userList)
{
    userList->next = NULL;
    tam = 0;
}

void userMenu(user *userList)
{
    int choose = 0;
    printf("==========================\n");
    printf("------ MENU USUÁRIO ------\n");
    printf("==========================\n");
    printf("[1]CADASTRO\n"); //Coloca novo usuário no fim da lista
    printf("[2]ALTERAR\n");  //Altera um usuário na lista
    printf("[3]CONSULTAR\n"); //Consulta um dado usuário na lista
    printf("[4]LISTAR\n");    //Lista todos os usuários da lista
    printf("[5]EXCLUIR\n");   //Exclui usuário da lista
    printf("[6]VOLTAR\n");
    scanf("%i", &choose);
    fflush(stdin);

    switch(choose)
    {
        case 1:
            userRegister(userList); break;
        case 2:
            userModify(userList); break;
        case 3:
            userSearch(userList); break;
        case 4:
            showList(userList); break;
        case 5:
            userDelete(userList); break;
        case 6:
            break;
        default:
            printf("OPÇÃO INVÁLIDA\n");
    }
}

/** Função de registro de usuário **/
void userRegister(user *userList)
{
    user *newNode = alocate();
    newNode->next = NULL;

    if(nullList(userList))
    {
        userList->next = newNode;
    }
    else
    {
        user *tmp = userList->next;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    tam++;
}

int userModify(user *userList)
{
    char name[100];
    printf("===========================================\n");
    printf("------------- ALTERAR USUÁRIO -------------\n");
    printf("===========================================\n");
    printf("Digite o NOME do usuário que deseja alterar: "); scanf(" %[^\n]s", name);
    user *tmp;
    user *prev;

    if(userList->next == NULL)
    {
        printf("A lista de usuários está vazia!\n");
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
                    printf("Digite o novo nome do usuário: "); scanf(" %[^\n]s", userList->name);
                    printf("Digite o novo email do usuário: "); scanf(" %[^\n]s", userList->email);
                    printf("Digite o novo índice que representa o grau do usuário: \n");
                    printf("[1]Graduando\n");
                    printf("[2]Mestre\n");
                    printf("[3]Doutor\n");
                    printf("[4]Professor\n");
                    printf("[5]Pesquisador\n");
                    scanf("%i", &userList->grade);
                    fflush(stdin);

                    printf("\nANOTE SEU ID: %d", userList->id);
                    printf("\nUSUÁRIO ALTERADO!\n");

                    return 1;
                }
                else
                {
                    printf("Digite o novo nome do usuário: "); scanf(" %[^\n]s", tmp->name);
                    printf("Digite o novo email do usuário: "); scanf(" %[^\n]s", tmp->email);
                    printf("Digite o novo índice que representa o GRAU do usuário: \n");
                    printf("[1]Graduando\n");
                    printf("[2]Mestre\n");
                    printf("[3]Doutor\n");
                    printf("[4]Professor\n");
                    printf("[5]Pesquisador\n");
                    scanf("%i", &tmp->grade);
                    fflush(stdin);

                    printf("\nANOTE SEU ID: %d", tmp->id);
                    printf("\nUSUÁRIO ALTERADO!\n");

                    return 1;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("USUÁRIO NÃO ENCONTRADO!\n");

        return 0;
    }
}

int modifyAllocStatus(user *userList, char *nameQ)
{
    char *name;
    user *tmp;
    user *prev;

    name = nameQ;

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
                    if(tmp->allocStatus == 0)
                    {
                        tmp->allocStatus = 1;
                        return 1;
                    }
                }
                else
                {
                    if(tmp->allocStatus == 0)
                    {
                        tmp->allocStatus = 1;
                        return 1;
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

int searchAllocStatus(user *userList, char *nameQ)
{
    char *name;
    user *tmp;
    user *prev;

    name = nameQ;

    if(userList->next == NULL)
    {
        printf("A lista de usuários está vazia!\n");
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
                    if(tmp->allocStatus == 0)
                    {
                        return 1;
                    }
                }
                else
                {
                    if(tmp->allocStatus == 0)
                    {
                        return 1;
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

int userSearch(user *userList)
{
    char name[100];
    printf("=============================================\n");
    printf("--------------- CONSULTAR USUÁRIO -----------\n");
    printf("=============================================\n");
    printf("Digite o NOME do usuário que deseja consultar: "); scanf(" %[^\n]s", name);
    user *tmp;
    user *prev;

    if(userList->next == NULL)
    {
        printf("A lista de usuários está vazia!\n");
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
                    printf("Nome.............%s\n", tmp->name);
                    printf("Emai.............%s\n", tmp->email);
                    printf("Grau.............%s\n", returnGrade(tmp->grade));
                    printf("ID...............%d\n", tmp->id);

                    return 1;
                }
                else
                {
                    printf("Nome.............%s\n", tmp->name);
                    printf("Email............%s\n", tmp->email);
                    printf("Grau.............%s\n", returnGrade(tmp->grade));
                    printf("ID...............%d\n", tmp->id);

                    return 1;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("USUÁRIO NÃO ENCONTRADO!\n");
        return 0;
    }
}

int userDelete(user *userList)
{
    int id;
    printf("=============================================\n");
    printf("--------------- EXCLUIR USUÁRIO -------------\n");
    printf("=============================================\n");
    printf("Digite ID do usuário que deseja excluir: "); scanf("%d", &id);

    user *tmp;
    user *prev;

    if(userList->next == NULL)
    {
        printf("A lista de usuários está vazia!\n");
        return 0;
    }
    else
    {
        tmp = userList;
        prev = userList;

        while(tmp != NULL)
        {
            if(tmp->id == id)
            {
                if(tmp == userList)
                {
                    userList = userList->next;
                    tam--;
                    free(tmp);
                    printf("USUÁRIO EXCLUÍDO!\n");

                    return 1;
                }
                else
                {
                    prev->next = tmp->next;
                    tam--;
                    free(tmp);
                    printf("USUÁRIO EXCLUÍDO\n");

                    return 1;
                }
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        printf("USUÁRIO NÃO ENCONTRADO!\n");

        return 0;
    }
}

void showList(user *userList)
{
    system("clear");
    if(nullList(userList))
    {
        printf("LISTA VAZIA!\n");
    }

    else
    {
        user *tmp;
        tmp = userList->next;
        printf("=============================================\n");
        printf("--------------- LISTA DE USUÁRIOS -----------\n");
        printf("=============================================\n");

        while(tmp != NULL)
        {
            printf("Nome.............%s\n", tmp->name);
            printf("ID...............%d\n", tmp->id);
            printf("\n");
            tmp = tmp->next;
        }
    }

}

int nullList(user *userList)
{
    if(userList->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

user *alocate()
{
    user *newNode = (user *)malloc(sizeof(user));
    if(!newNode)
    {
        printf("SEM MEMÓRIA SUFICIENTE!\n");
        exit(1);
    }
    else
    {
        printf("================================================\n");
        printf("--------------- REGISTRO DE USUÁRIOS -----------\n");
        printf("================================================\n");
        printf("Digite o nome do usuário: "); scanf(" %[^\n]s", newNode->name);
        printf("Digite o email do usuário: "); scanf(" %[^\n]s", newNode->email);
        printf("Digite o índice que representa o grau do usuário: \n");
        printf("[1]Graduando\n");
        printf("[2]Mestre\n");
        printf("[3]Doutor\n");
        printf("[4]Professor\n");
        printf("[5]Pesquisador\n");
        scanf("%i", &newNode->grade);
        fflush(stdin);

        newNode->id = tam+1;
        newNode->allocStatus = 0;
        printf("\nAnote seu ID: %d\n", newNode->id);
        printf("USUÁRIO REGISTRADO!\n");

        return newNode;
    }
}
