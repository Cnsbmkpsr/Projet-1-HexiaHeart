#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "actions.h"
#include "donnees.h"

FILE*	open_beat_file()
{
	FILE *file;
	file = fopen("beat.txt", "r");
	if (!file)
		return NULL;
	return(file);
}

int		fill_array()
{
	FILE *file;
	file = open_beat_file();
	int n = nb_ligne();
	return(n);
}
