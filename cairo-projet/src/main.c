#include <stdio.h>
#include <stdlib.h>
#include </usr/include/cairo/cairo.h>
#include </usr/include/cairo/cairo-xlib.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "interaction.h"
#include "grille.h"


#define SIZEX 1200
#define SIZEY 900

int main (int argc, char *argv[]){
	//chargement grille et masque de la grille
	grille G=charge_grille();
	grille P=creer_grille(G->n,G->m);
	P=init_grille(P);
	int x=0; int y=0;
	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;
	KeySym keysym;		
	char text[255];

	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0, 
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "Logigraphe");
	XSelectInput(dpy, win, ExposureMask | ButtonPressMask | KeyPressMask);
	XMapWindow(dpy, win);

	// create cairo surface
	cairo_surface_t *cs;
	//  create cairo surface on the xwindow
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);

	// run the event loop
	while(1) {
		XNextEvent(dpy, &e);

		// catch the key pressed
		if (e.type==KeyPress &&
				XLookupString(&e,text,255,&keysym,0)==1) {
			if (text[0]=='q') {
				break;
			}
			if (text[0]=='v') {
				if (compare(P,G)==1) youWin(cs);
				else youLose(cs);
				P=init_grille(P);
			}
			//printf("You pressed the %c key!\n",text[0]);
		}

		if(e.type==Expose && e.xexpose.count<1) {
			paint(cs,P,G);
		}
		// catch the mouse button pressed
		else if(e.type==ButtonPress) {
			y=(e.xbutton.x/(int)width);
			x=(e.xbutton.y/(int)width);
			if ((y<G->m)&&(x<G->n)) { 
				if(P->p_Grille[x][y]=='.') P->p_Grille[x][y]='+';
				else if(P->p_Grille[x][y]=='+') P->p_Grille[x][y]='.';
				//printf("You pushed the mouse button (%d,%d)\n", e.xbutton.x, e.xbutton.y);
			}	
			paint(cs,P,G);
		}

	}

	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
	return 0;
}




/*	int x,y; grille G,P;
		x=1; y=1;

		P=charge_grille();
		G=creer_grille(P->n,P->m);
		G=init_grille(G);	

		initscr();
		keypad(stdscr,1);
		cbreak();
		affiche_grille2(G);
		affiche_serieC2(P);
		affiche_serieL2(P);
		refresh();
		int entree;	

		while ((entree=getch())!='q'){
		clear();
		affiche_grille2(G);
		affiche_serieL2(P);
		affiche_serieC2(P);
		refresh();
		if (entree==KEY_DOWN) {
		if (G->n>y+1) y++;
		mvprintw(y,x,"X");
		}
		if (entree==KEY_UP) {
		if (y>0) y--;
		mvprintw(y,x,"X");
		}
		if (entree==KEY_LEFT) {	
		if (x>0) x--;
		mvprintw(y,x,"X");
		}
		if (entree==KEY_RIGHT)	{
		if (x+1<G->m) x++;
		mvprintw(y,x,"X");
		}
		if (entree=='+')	{
		G->p_Grille[y][x]='+';
		mvprintw(y,x,"X");
		}
		if (entree=='.')	{
		G->p_Grille[y][x]='.';
		mvprintw(y,x,"X");
		}
		if (entree=='\n')	{
		compare(G,P)?mvprintw(G->n+5,G->m+5,"GAGNE"):mvprintw(G->n+3,G->m+5,"PERDU");
		}
		if (entree=='X') {
		feed_line(G,y);
		}
		if (entree=='x') {
		unfeed_line(G,y);
		}
		if (entree=='W') {
		feed_col(G,x);
		}
		if (entree=='w') {
		unfeed_col(G,x);
		}
		}

		endwin();

		desalloue_grille(P);
		desalloue_grille(G);

		return 0;
		}
//G=creer_grille(n,m);
//G=init_grille(G);
//afficher_grille(G);
//free(G);
//afficher_grille(G);
G=charge_grille();
//G=init_grille(G);
tabSerie=tableauSerieC(G); 
//nbreSerie(tabSerie,G);
afficheSerieC(tabSerie,G);
afficher_grille(G);
//free(G);
int i;
for(i=0;i<G->m;i++) {
	pSerie=serie_pointC(G,i);
	//printf("%d\n",pSerie[5]);
	//printf("%d\n",pSerie[4]);
	//printf("%d\n",pSerie[3]);
	//printf("%d\n",pSerie[2]);
	//printf("%d\n",pSerie[1]);
	printf("%d ",pSerie[0]);
}
printf("\n");
for(i=0;i<G->n;i++) {
	pSerie=serie_pointL(G,i);
	//printf("%d\n",pSerie[5]);
	//printf("%d\n",pSerie[4]);
	//printf("%d\n",pSerie[3]);
	//printf("%d\n",pSerie[2]);
	//printf("%d\n",pSerie[1]);
	printf("%d ",pSerie[0]);
}
*/

