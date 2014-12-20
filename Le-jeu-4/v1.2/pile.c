/**
 *\file pile.c
 *\brief Projet informatique S3 Deplacement du personnage et colisions sur le parois
 *\author TOULMONDE Joris
 *\version 0.2
 *\date 22 Octobre 2014
*/

#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "header.h"

#define M 100

//typedef struct {int x, y;}t_coordonees;

static t_coord pile[M][M];
static int sommet[M];

void initpile(int numPile){
	sommet[numPile]=-1;
}

void empiler(t_coord coord, int numPile){
	if(sommet[numPile]<M-1){
		sommet++;
		pile[numPile][sommet].X=coord.X;
		pile[numPile][sommet].Y=coord.Y;
		//pile[sommet] = coord;
	}
}

void depiler(t_coord *coord, int numPile){
	if(sommet[numPile]>-1){
		coord->X=pile[numPile][sommet].X;
		coord->Y=pile[numPile][sommet].Y;
		sommet--;
	}
}

int sommet_pile(t_coord *coord, int numPile){
	if(sommet[numPile]>-1){
		coord->X=pile[numPile][sommet].X;
		coord->Y=pile[numPile][sommet].Y;
		return 1;
	}
	return 0;
}

int pilevide(int numPile){
	return(sommet[numPile]==-1);
}
