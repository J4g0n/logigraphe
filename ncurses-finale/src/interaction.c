#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "interaction.h"

void affiche_grille2(grille G) {
	int i,j; 
	for(i=0;i<G->n;i++) {
		for(j=0;j<G->m;j++) {
			printw("%c",G->p_Grille[i][j]);
		}
		printw("\n");
	}
}

int compare(grille P,grille G) {
	int i,j,r=1;
	for(i=0; i<P->n; i++) {
		for(j=0; j<P->m; j++) {
			if (P->p_Grille[i][j]!=G->p_Grille[i][j]) r=0;
		}
	}
	return r;
}

void affiche_serieC2(grille G) {
	int **serieC;
	serieC=tableauSerieC(G);
	int i,j;
  for(j=1;j<=(((G->n+1)/2)+1);j++) {
    for(i=0;i<G->m;i++) {
      if (serieC[i][j]!=0) mvprintw(G->n+j,i,"%d",serieC[i][j]);
      else mvprintw(G->n+j,i," ");
    }
    printf("\n");
  }
	for(j=0;j<G->m;j++) {
		free(serieC[j]);
	}		
	free(serieC);
}
/*
void affiche_serieL2(grille G) {
  int **serieL;
	serieL=tableauSerieL(G);
	int i,j;
  for(i=0;i<G->n;i++) {
    for(j=1;j<=serieL[i][0];j++) 
			if (serieL[i][j]!=0) mvprintw(j,i+G->m,"%d ",serieL[i][j]);
			else break;
  }

}
*/
void affiche_serieL2(grille G) {
  int *serieL;
	int i,j;
	for(i=0;i<G->n;i++){
		serieL=serie_pointL(G,i);
		for(j=1;j<((G->m+1)/2)+1;j++)	{
			if (serieL[j]!=0) mvprintw(i,2*j+G->m+1,"%d ",serieL[j]);
			else break;
		}
		free(serieL);
	}
}

grille feed_line(grille G,int n_ligne) {
	int i;
	for(i=0;i<G->m;i++) {
		G->p_Grille[n_ligne][i]='+';
	}
	return G;
}

grille unfeed_line(grille G,int n_ligne) {
	int i;
	for(i=0;i<G->m;i++) {
		G->p_Grille[n_ligne][i]='.';
	}
	return G;
}

grille feed_col(grille G,int n_col) {
	int i;
	for(i=0;i<G->n;i++) {
		G->p_Grille[i][n_col]='+';
	}
	return G;
}

grille unfeed_col(grille G,int n_col) {
	int i;
	for(i=0;i<G->n;i++) {
		G->p_Grille[i][n_col]='.';
	}
	return G;
}



