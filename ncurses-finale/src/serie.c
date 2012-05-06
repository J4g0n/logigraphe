#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

int *serie_pointC(grille G,int colonne) {
  int i,j=0,indice=0;
	//int c=(((G->n+1)/2)+1);
	//fprintf(stderr,"%d\n",(((G->n)/2)+2));
  int *serie=(int*) malloc((((G->n+1)/2)+1)*sizeof(int));
  int total=0;
  for(i=0;i<G->n;i++) {
    if (G->p_Grille[i][colonne]=='+') {
      if ((i==0)||(G->p_Grille[i-1][colonne]=='.')) {
        if (indice!=0) {
          serie[j]=indice;
          indice=0;
        }
        j++;
      }
      total++; indice++;
    }
  }
  serie[j]=indice;
  serie[0]=j;
  j++;
  for(;j<=((((G->n+1)/2)+1));j++) serie[j]=0;
  //serie[1]=total;
  return serie;
}

int *serie_pointL(grille G,int ligne) {
  int i,j=0,indice=0;
  int *serie=(int*) malloc((((G->m+1)/2)+1)*sizeof(int));
  int total=0;
  for(i=0;i<G->m;i++) {
    if (G->p_Grille[ligne][i]=='+') {
      if ((i==0)||(G->p_Grille[ligne][i-1]=='.')) {
        if (indice!=0) {
          serie[j]=indice;
          indice=0;
        }
        j++;
      }
      total++; indice++;
    }
  }
  serie[j]=indice;
  serie[0]=j;
  j++;
  for(;j<=((((G->m+1)/2)+1));j++) serie[j]=0;
  //serie[1]=total;
  return serie;
}

int **tableauSerieC(grille G) {
  int **tabSerie=NULL; //int *serie;
  tabSerie = (int**) malloc(G->m*sizeof(int*));
  int i;
  for(i=0;i<G->m;i++)
    tabSerie[i]=serie_pointC(G,i);
  return tabSerie;
}

int **tableauSerieL(grille G) {
  int **tabSerie=NULL; //int *serie;
  tabSerie = (int**) malloc(G->n*sizeof(int*));
  int i;
  for(i=0;i<G->n;i++)
    tabSerie[i]=serie_pointL(G,i);
  return tabSerie;
}

void afficheSerieC(int **tabSerie,grille G) {
  int i,j;
  for(j=1;j<=(((G->n+1)/2)+1);j++) {
    for(i=0;i<G->m;i++) {
      if (tabSerie[i][j]!=0) printf("%d ",tabSerie[i][j]);
      else printf("  ");
    }
    printf("\n");
  }
}

void afficheSerieL(int **tabSerie,grille G) {
  int i,j;
  for(i=0;i<G->n;i++) {
    for(j=1;j<=tabSerie[i][0];j++) printf("%d ",tabSerie[i][j]);
    printf("\n");
  }
}

void nbreSerie(int **tabSerie,grille G) {
  int i;
  for(i=0;i<G->m;i++) {
    printf("%d ",tabSerie[i][2]);
  }
  printf("\n");
}


