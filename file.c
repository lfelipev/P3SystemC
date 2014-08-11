#include "file.h"

void saveFile(user *userList)
{
    FILE *file;

    file = fopen("../system/userRegister.txt", "w");

    if(!file)
    {
        printf( "Erro na abertura do arquivo.");
        getchar();
        exit(0);
    }

    user *p;
    char * string;
    int i = 0;

    p = userList->next;

    fputs(" L I S T A  D E  U S Á R I O S\n", file);
    fputs(" = = = = =  = =  = = = = = = = =\n", file);

    while(p != NULL)
    {

        putc('\n', file);
        putc('\n', file);

        fputs(" ID...............: ", file);
        fprintf(file, "%d", p->id);
        putc('\n', file);

        fputs(" Nome............: ", file);
        fputs(p->name, file);
        putc('\n', file);

        fputs(" Email.......: ", file);
        fputs(p->email, file);
        putc('\n', file);

        fputs(" Grau.......: ", file);
        fputs(returnGrade(p->grade), file);
        putc('\n', file);

        p = p->next;
        i++;
    }

    fclose(file);
    printf("%d REGISTROS FORAM GRAVADOS\n", i);
}

void saveResourceFile(resource *resourceList)
{
    FILE *file;

    file = fopen("../system/resourceRegister.txt", "w");

    if(!file)
    {
        printf( "Erro na abertura do arquivo.");
        getchar();
        exit(0);
    }

    resource *p;
    char * string;
    int i = 0;

    p = resourceList->next;

    fputs(" L I S T A  D E  R E C U R S O S\n", file);
    fputs(" = = = = =  = =  = = = = = = = =\n", file);

    while(p != NULL)
    {

        putc('\n', file);
        putc('\n', file);

        fputs(" ID...............: ", file);
        fprintf(file, "%d", p->resourceId);
        putc('\n', file);

        fputs(" Nome............: ", file);
        fputs(p->resourceName, file);
        putc('\n', file);

        fputs(" Responsável.......: ", file);
        fputs(p->responsibleName, file);
        putc('\n', file);

        p = p->next;
        i++;
    }

    fclose(file);
    printf("%d REGISTROS FORAM GRAVADOS.\n", i);
}

void saveActivityFile(activity *activityList)
{
    FILE *file;

    file = fopen("../system/activityRegister.txt", "w");

    if(!file)
    {
        printf( "Erro na abertura do arquivo.");
        getchar();
        exit(0);
    }

    activity *p;
    char * string;
    int i = 0;

    p = activityList->next;

    fputs(" L I S T A  D E  A T I V I D A D E S\n", file);
    fputs(" = = = = =  = =  = = = = = = = = = =\n", file);

    while(p != NULL)
    {

        putc('\n', file);
        putc('\n', file);

        fputs(" Título: ", file);
        fputs(p->title, file);
        putc('\n', file);

        fputs(" Participantes: ", file);
        fputs(p->participants, file);
        putc('\n', file);

        fputs(" Material de Apoio: ", file);
        fputs(p->material, file);
        putc('\n', file);

        fputs(" Descrição: ", file);
        fputs(p->description, file);
        putc('\n', file);

        p = p->next;
        i++;
    }

    fclose(file);
    printf("%d REGISTROS FORAM GRAVADOS.\n", i);
}
