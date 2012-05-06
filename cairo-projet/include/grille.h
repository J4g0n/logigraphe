#ifndef __grille_h_
#define __grille_h_
#include "base.h"
//picross 
typedef struct {
	char **p_Grille;
	int n,m;
} Grille, *grille;

grille creer_grille(int, int);
void afficher_grille(grille);
grille init_grille(grille);//mettre un pointeur
void desalloue_grille(grille);
grille charge_grille();
int *serie_pointL(grille,int);
int *serie_pointC(grille,int);
int **tableauSerieC(grille);
int **tableauSerieL(grille);
void afficheSerieC(int** , grille); 
void nbreSerie(int** , grille);

#endif
