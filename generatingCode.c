#include <stdio.h>
#include <stdlib.h>

int main1()
{
    FILE* fichier = NULL;
    int methode = 0;
    int nombre = 0;

    fichier = fopen("param.h", "w+");
    if (fichier != NULL)
    {
        fprintf(fichier, "#ifndef PARAM_H_INCLUDED\n#define PARAM_H_INCLUDED\n\n");
        printf("Quel est la methode de clignotement que vous souhaitez utiliser ?\n1 - Tout clignote\n2 - 1 sur ...\n");
        scanf("%d", &methode);
        if (methode == 2)
        {
            printf("Choisir un nombre entre 2 et 9 compris\n");
            scanf("%d", &nombre);

        }
        fprintf(fichier, "#define methodeclignote %d\n#define jesaispasquoi %d\n\n#endif\n", methode, nombre);
        fclose(fichier);
    }
    else
        printf("ERROR");
    return 0;
}
