#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"
#include "menu.h"
#include "actions.h"

////////////////////////AFFICHAGE DONNEES//////////////////////////////

int		display_data(int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	int i = 0;
	while (i <= n)
	{
		fscanf(file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
		i++;
	}
	for(i = 0; i < n; i++)
	{
		printf("temps = %d\t|\tpouls = %d\n", tab[i].temps, tab[i].pouls);
	}
	return 0;
}

////////////////////////////TRI CROISSANT////////////////////////////////////

int tri_croissant(int choix, int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	void tri_bulle_pouls(DATA tab[])
	{
		int swap;
		DATA aux;
		do
		{
			swap = 0;
			for(int i = 0; i < (n-1); i++)
			{
				if(tab[i].pouls > tab[i+1].pouls)
				{
					aux = tab[i];
					tab[i] = tab[i + 1];
					tab[i + 1] = aux;
					swap = 1;
				}
			}
		}while(swap);
		for(int x = 0 ; x < n ; x++)
		{
			printf("temps = %d\t|\tpouls = %d\n", tab[x].temps, tab[x].pouls);
		}
	}
	int i = 0;
	while (i != n)
	{
		fscanf(file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
		i++;
	}
	if( choix == 1) //tri selon le temps
	{
		for(int x = 0 ; x < n ; x++)
		{
			printf("temps = %d\t|\tpouls = %d\n", tab[x].temps, tab[x].pouls);
		}
	}
	if( choix == 2) // tris selon le pouls
	{
		tri_bulle_pouls(tab);
	}
	fclose (file);
	return 0;
}

//////////////////////////////TRI DECROISSANT/////////////////////////////

void	tri_bulle_pouls_decroissant(DATA tab[], int n)
{
	int swap;
	DATA aux;
	do{
		swap = 0;
		for (int i=0; i<(n-1); i++) {
			if (tab[i].pouls < tab[i+1].pouls) {
				aux = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = aux;
				swap = 1;
			}
		}
	}while(swap);
	for(int x=0; x<n; ++x)
	{
		printf("temps = %d\t|\tpouls =  %d\n", tab[x].temps, tab[x].pouls);
	}
}
int		tri_temps_decroissant(DATA tab[], int n)
{
	int swap;
	DATA aux;
	do{
		swap = 0;
		for (int i=0; i<(n-1); i++) {
			if (tab[i].temps < tab[i+1].temps) {
				aux = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = aux;
				swap = 1;
			}
		}
	}while(swap);
	for(int x=0; x<n; ++x)
	{
		printf("temps = %d\t|\tpouls = %d\n", tab[x].temps, tab[x].pouls);
	}
}
int		tri_decroissant(int choix, int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];

	for(int i = 0; i < n; i++)
	{
		fscanf (file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
	}

	if( choix == 1) //tri selon le temps
	{
		tri_temps_decroissant(tab, n);
	}
	if( choix == 2) // tris selon le pouls
	{
		tri_bulle_pouls_decroissant(tab, n);
	}
	fclose (file);
}

////////////////////RECHERCHE SELON LE TEMPS/////////////////////////////////

int		search_time(int time, int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	for(int i = 0; i <= n; i++)
	{
		fscanf (file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
	}
	float time_deb = 2.90;
	float time_fin = 3.10;
	int trouve = 0;
	int i = 0;
	while (!trouve)
	{
		if ((time > time_deb) && (time < time_fin))
		{
			printf("Le pouls est de %i bpm à %i secondes.\n", tab[i].pouls, tab[i].temps);
			trouve = 1;
		}
		else
		{/*
			time_deb += 3.0;
			time_fin += 3.0;
			i++;*/
			printf("Il n'y a pas de pouls relevé à ce temps.");
			return 0;
		}
	}
}

///////////////////////CALCUL MOYENNE/////////////////////////////////////

int		moyenne(int min,int max, int n)
{
	int total = 0;
	int compteur = 0;
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	for(int i = 0; i <= n; i++)
	{
		fscanf (file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
	}
	for(int x = 0 ; x <= n ; x++)
	{
		if(tab[x].temps > min && tab[x].temps < max)
		{
			total += tab[x].pouls;
			compteur++;
		}
	}
	int moyenne = total/compteur;
	printf("La moyenne de pouls est de %i bpm.\n", moyenne);
}

//////////////////CALCUL LIGNES EN MEMOIRE/////////////////////////////////

int		nb_ligne()
{
	int nb_ligne = 1;
	FILE *file;
	file = open_beat_file();
	if (!file)
	{
		return EXIT_FAILURE;
	}
	char c;
	while((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			nb_ligne++;
	}
//	printf("Il y a %d lignes en mémoire.\n", nb_ligne);
	return nb_ligne;
}

/////////////////RECHERCHE POULS MINIMUM////////////////////////////////////

int		search_min(int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	for(int i = 0; i <= n; i++)
	{
		fscanf (file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
	}
	DATA aux = tab[0];
	for(int i = 1; i <= n; i++)
	{
		if(tab[i].pouls < aux.pouls)
		{
			aux = tab[i];
		}
	}
	printf("Le pouls minimum est de %i bpm à %i secondes.\n", aux.pouls, aux.temps);
}

/////////////////RECHERCHE POULS MAXIMUM////////////////////////////////////

int		search_max(int n)
{
	FILE *file;
	file = open_beat_file();
	DATA tab[n];
	for(int i = 0; i < n; i++)
	{
		fscanf (file, "%i;%i" , &tab[i].temps, &tab[i].pouls);
	}
	DATA aux = tab[0];
	for(int i = 1; i < n; i++)
	{
		if(tab[i].pouls > aux.pouls)
		{
			aux = tab[i];
		}
	}
	printf("Le pouls maximum est de %i bpm à %i secondes.\n", aux.pouls, aux.temps);
}
