#ifndef __interaction_h_
#define __interaction_h_
#include "ncurses.h"

void affiche_grille2();
int compare(grille,grille);
void affiche_serieC2(grille);
void affiche_serieL2(grille);
grille feed_line(grille,int);
grille unfeed_line(grille,int);
grille feed_col(grille,int);
grille unfeed_col(grille,int);

#endif
