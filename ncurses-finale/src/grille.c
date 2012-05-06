#include "grille.h"
#include <stdio.h>
#include <stdlib.h>
#define sizeBuffer 50

char buffer[sizeBuffer];

grille creer_grille(int n, int m) {
  grille G=(grille) malloc(sizeof(Grille)); int i;
  G->n=n;
  G->m=m;
  G->p_Grille=(char**) malloc(n*sizeof(char*));
  for(i=0;i<n;i++) {
    G->p_Grille[i]=(char*) malloc(m*sizeof(char));
  }
  return G;
}

grille init_grille(grille G) {
  int i,j;
  for(i=0;i<G->n;i++) {
    for(j=0;j<G->m;j++) {
      G->p_Grille[i][j]='.';
    }
  }
  return G;
}

void afficher_grille(grille G) {
  int i,j;
  if (G->p_Grille!=NULL) {
    for(i=0;i<G->n;i++) {
      for(j=0;j<G->m;j++) {
        printf("%c ",G->p_Grille[i][j]);
      }
      printf("\n");
    }
  }
  return ;
}

void desalloue_grille(grille G) {
  int j;
	for(j=0;j<G->n;j++) {
		free(G->p_Grille[j]);
	}
	free(G->p_Grille);
	free(G);
}

int puiss(int base,int exposant)
{
  if (base==0) return 0;
  if (exposant==0) return base;
  else return base*(puiss(base,exposant-1));
}

grille charge_grille() {
  FILE *fichier = NULL;
  fichier = fopen(("grille.txt"), ("r"));
  int i,k,j,n,m;
  grille G;
  if (fichier==NULL) {
    printf("erreur: le fichier \"grille\" n'existe pas!!!\n");
  }
  else {
    if (feof(fichier)) {
      printf("erreur: le fichier \"grille\" est vide\n");
    }
    else {
      fscanf(fichier,"%d %d\n",&n,&m);
			printf("%d %d",n,m);
      G=creer_grille(n,m);
      for(i=0;i<G->n;i++) {
				char *buff=(char*) malloc(m*sizeof(char));
        fgets(buffer,256,fichier);
				for (k=0;k<G->m;k++) buff[k]=buffer[k]; 
        for(j=0;j<G->m;j++) {
          if ((buff[j]=='.')||(buff[j]=='+'))
            G->p_Grille[i][j]=buffer[j];
          else continue;
        }
				free(buff);
      }
    }
    fclose(fichier);
  }
  return G;
}
/*
int *serie_pointC(grille G,int colonne) {
  int i,j=0,indice=0;
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

void nbreSerie(int **tabSerie,grille G) {
  int i;
  for(i=0;i<G->m;i++) {
    printf("%d ",tabSerie[i][2]);
  }
  printf("\n");
}

void afficheSerieC(int **tabSerie,grille G) {
  int i,j;
  for(i=0;i<G->m;i++) {
    for(j=1;j<=tabSerie[i][0];j++) printf("%d ",tabSerie[i][j]);
    printf("\n");
  }
}
*/
