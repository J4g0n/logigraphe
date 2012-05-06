#include <stdlib.h>
#include <stdio.h>
#include "image.h"
//#include "grille.h"

grille loadFromPpm(char *image) {
	FILE *ppm;
	grille G;
	unsigned char max,**pixmap,c,v;
	int n,m,p,k,i,j;
	p=0; k=0;
	int dimH,dimL;
	int y,x,r;
	x=0; y=0; r=0;
	
	ppm=fopen(image,"r");
	fscanf(ppm,"P%d",&v);
	fscanf(ppm,"%d %d",&n,&m);
	fscanf(ppm,"%d",&max);
	
	printf("taille du logigraphe voulue <L l>?\n");
	//while ((p>n)&&(k>m)&&(p<=0)&&(k<=0)) {
		scanf("%d %d",&p,&k);
	//}

	G=creer_grille(p,k);
	
	pixmap=(unsigned char**) malloc(n*sizeof(unsigned char*));
  for(i=0;i<n;i++) {
   	pixmap[i]=(unsigned char*) malloc(m*sizeof(unsigned char));
  }
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			fscanf(ppm,"%d",&c);
			pixmap[i][j]=c;
		}
	}
	c=0;

	fclose(ppm);

	dimL=n/p;
	dimH=m/k;
	
	while (y<k-1) {
		for(i=0;i<dimL;i++) {
			for(j=0;j<dimH;j++) {
				r+=(int) pixmap[i+x*dimL][j+y*dimH];
			}
		}
		r=r/(dimL*dimH);
		c=(unsigned char) r;
		r=0;
		if (c>max/2) {
			G->p_Grille[x][y]='+';
		}
		else {
			G->p_Grille[x][y]='.';
		}
		if (x<p-1) x++;
		else {
			x=0;
			y++;
		}
	}
	
	for(i=0;i<n;i++) {
		free(pixmap[i]);
	}
	free(pixmap);

	return G;
}
