#include "grille.h"
#include <stdio.h>
#include <stdlib.h>
#include "interaction.h"
#include "ncurses.h"

int main() {
	int x,y; grille G,P;
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
/*	//G=creer_grille(n,m);
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
 
