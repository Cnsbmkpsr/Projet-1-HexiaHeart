#ifndef ACTIONS_H
#define ACTIONS_H

int n;
int *ptr;

typedef struct DATA
{
	int temps;
	int pouls;
	}DATA;
DATA tab[10];

int		fill_array();
FILE*	open_beat_file();
#endif
