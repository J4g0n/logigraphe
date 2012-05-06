#ifndef __interaction_h_
#define __interaction_h_
#include </usr/include/cairo/cairo.h>
#include </usr/include/cairo/cairo-xlib.h>
#include "grille.h"
//#include "ncurses.h"

#define width 40.0

void paint(cairo_surface_t*, grille, grille);
void youWin(cairo_surface_t*);
void youLose(cairo_surface_t*);

int compare(grille,grille);
void affiche_serieC2(grille,cairo_t*);
void affiche_serieL2(grille,cairo_t*);
//void affiche_grille2();
/*grille feed_line(grille,int);
grille unfeed_line(grille,int);
grille feed_col(grille,int);
grille unfeed_col(grille,int);
*/

#endif
