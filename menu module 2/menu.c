#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "generatingCode.h"
#include "cardio.h"

void menu(){
    int choix = 0;
    char a =  0x282;

printf("             ================================================\n");
printf("            |                                                |\n");
printf("            |         Bienvenue dans le gestionnaire         |\n");
printf("            |      de donn%ces de votre rythme cardiaque      |\n", a);
printf("            |                                                |\n");
printf("             ================================================\n\n");

printf("0 => sortir\n");
printf("1 => afficher les donn%ces en sortie du fichier.csv\n",a);
printf("2 => afficher les donn%ces dans l'ordre croissant en fonction du pouls\n",a);
printf("3 => afficher les donn%ces dans l'ordre decroissant en fonction du pouls\n",a);
printf("4 => afficher les donn%ces dans l'ordre croissant en fonction du temps\n",a);
printf("5 => afficher les donn%ces dans l'ordre decroissant en fonction du temps\n",a);
printf("6 => afficher la valeur minimale et maximale du pouls\n");
printf("7 => Recherche d'un temps pr%ccis\n");
printf("8 => afficher la moyenne du pouls sur un intervalle de temps\n");
printf("9 => afficher le nombre de ligne du fichier\n");
 scanf("%d", &choix);



}
