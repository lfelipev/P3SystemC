#include "user.h"
#include "report.h"
#include "resource.h"

void reportMenu()
{
    int choose = 0;
    printf("============================\n");
    printf("------ MENU RELATÓRIO ------\n");
    printf("============================\n");
    printf("[1]Número de usuários\n");
    printf("[2]Número de Recursos: EM PROCESSO DE ALOCAÇÃO\n");
    printf("[3]Número de Recursos: ALOCADO\n");
    printf("[4]Número de Recursos: EM ANDAMENTO\n");
    printf("[5]Número de Recursos: CONCLUÍDO\n");
    printf("[6]Número de Alocações\n");
    printf("[7]Número de Atividades: AULA TRADICIONAL\n");
    printf("[8]Número de Atividades: APRESENTAÇÕES\n");
    printf("[9]Número de Atividades: LABORATÓRIO\n");
    printf("[0]Voltar\n");

    scanf("%i", &choose);
    fflush(stdin);

    switch(choose)
    {
        case 1:
            printf("Número de usuários: %d\n", tam); break;
        case 2:
            printf("Número de Recursos Em processo de alocação: %d\n", status1); break;
        case 3:
            printf("Número de Recursos Alocados: %d\n", status2); break;
        case 4:
            printf("Número de Recursos Em Andamento: %d\n", status3); break;
        case 5:
            printf("Número de Recursos Em Concluídos: %d\n", status4); break;
        case 6:
            printf("Número de Alocações: %d\n", nAll); break;
        case 7:
            printf("AULA TRADICIONAL: %d\n", act1Tam); break;
        case 8:
            printf("APRESENTAÇÕES: %d\n", act2Tam); break;
        case 9:
            printf("LABORATÓRIO: %d\n", act3Tam); break;
        case 0:
            break;
        default:
            printf("Opção inválida:\n");
    }
}

