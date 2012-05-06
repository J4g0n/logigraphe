#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "interaction.h"


void paint(cairo_surface_t *surface,grille P,grille G)
{
	float i,j;
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_paint(cr);

	// filled rectangle
	cairo_rectangle(cr,0,0,40*(1+P->n),40*(1+P->m));
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_fill(cr);	
	for(i=0.0;i<(float)P->n;i=i+1.0) {	
		for(j=0.0;j<(float)P->m;j=j+1.0) {	
			cairo_move_to (cr, width*i, width*j);
			if (P->p_Grille[(int)i][(int)j]=='+') {
				cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
				cairo_rectangle(cr,(int)(width*j),(int)(width*i),(float)width,(float)width);
				cairo_fill(cr);	
			}
		}
	}

	// line
	cairo_set_source_rgb (cr, 1.0, 0.5, 0.5);
	for(i=0.0;i<=(float)P->n;i=i+1.0) {
		cairo_move_to (cr, 1.0, width*i);
		cairo_line_to(cr, width*((float)P->m),width*i);
		cairo_set_line_width (cr, 2);
		cairo_stroke (cr);
	}
	for(i=0.0;i<=(float)P->m;i=i+1.0) {
		cairo_move_to (cr, width*i, 1.0);
		cairo_line_to(cr, width*i, width*((float)P->n));
		cairo_set_line_width (cr, 2);
		cairo_stroke (cr);
	}
	//text
	//vertical
	affiche_serieC2(G,cr);

	//horizontal
	affiche_serieL2(G,cr);

	cairo_destroy(cr); // destroy cairo mask
}

void youWin(cairo_surface_t *surface) {
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_paint(cr);

	//text
	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); 
	cairo_select_font_face(cr,
	"cairo:",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 50);
	cairo_move_to(cr,100,100);
	cairo_show_text(cr,"Vous avez gagné!"); 
	cairo_set_font_size(cr, 20);
	cairo_move_to(cr,200,200);
	cairo_show_text(cr,"Cliquer pour continuer..."); 

	cairo_destroy(cr); 
}

void youLose(cairo_surface_t *surface) {
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_paint(cr);

	//text
	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); 
	cairo_select_font_face(cr,
	"cairo:",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 50);
	cairo_move_to(cr,100,100);
	cairo_show_text(cr,"Vous avez Perdu..."); 
	cairo_set_font_size(cr, 20);
	cairo_move_to(cr,200,200);
	cairo_show_text(cr,"Cliquer pour réessayer..."); 

	cairo_destroy(cr); 
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

void affiche_serieC2(grille G,cairo_t *cr) {
	int **serieC;
	char *tab=(char*)calloc(10,sizeof(char));
	serieC=tableauSerieC(G);
	int i,j;
	for(j=1;j<=(((G->n+1)/2)+1);j++) {
		for(i=0;i<G->m;i++) {
			if (serieC[i][j]!=0) {
				cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); 
				cairo_select_font_face(cr,
				"cairo:",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
				cairo_set_font_size(cr, 20);
				cairo_move_to(cr,10+i*((int)width),(G->n*((int)width))+20+j*30);
				//printf("%d\n",serieC[i][j]);
				sprintf(tab,"%2d",serieC[i][j]);
				cairo_show_text(cr,tab); 
			}
		}
	}
	for(j=0;j<G->m;j++) {
		free(serieC[j]);
	}		
	free(serieC);
}

void affiche_serieL2(grille G,cairo_t *cr) {
	int *serieL;
	char *tab=(char*)calloc(10,sizeof(char));
	int i,j;
	for(i=0;i<G->n;i++){
		serieL=serie_pointL(G,i);
		for(j=1;j<((G->m+1)/2)+1;j++)	{
			if (serieL[j]!=0) {
				cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); 
				cairo_select_font_face(cr,
				"cairo:",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_NORMAL);
				cairo_set_font_size(cr, 20);
				cairo_move_to(cr, (G->m*((int)width))+j*30,30+i*((int)width));
				//printf("%d\n",serieL[j]);
				sprintf(tab,"%2d",serieL[j]);
				cairo_show_text(cr,tab);  
			}
			else break;
		}
		free(serieL);
	}
}

/*
	 void affiche_grille2(grille G) {
	 int i,j; 
	 for(i=0;i<G->n;i++) {
	 for(j=0;j<G->m;j++) {
	 printw("%c",G->p_Grille[i][j]);
	 }
	 printw("\n");
	 }
	 }
 */

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
 */




