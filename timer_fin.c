#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#define CYCLE 1000000L
#include "menu.h"

void tempecoule(int *secondes, int *minutes,int modetriche, unsigned long int *debut){
   char zonetexte[64];
     if ((unsigned long int)Microsecondes() >*debut) {     
       *debut = (unsigned long int)Microsecondes() + CYCLE;
       if (!modetriche) {
	 (*secondes)++;
	 if (*secondes == 60) {
	   *secondes = 0;
	   (*minutes)++;
	 }
       }
     }
     /* affichage temps ecoulé */ 
     ChoisirCouleurDessin(CouleurParComposante(0, 200, 200));
     RemplirRectangle(470, 95, 325, 40);
     sprintf(zonetexte,"TEMPS ECOULE %02d:%02d", *minutes, *secondes);
     ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
     EcrireTexte(475, 125,zonetexte, 2);
}

void ecranfin(int pair,int nb_carte,int minutes,int secondes){
  char zonetexte[64];
    /* gestion fin de la partie quand toute les cartes sont trouvées */
  if (pair == nb_carte / 2) {
    ChargerImageFond("images/Image_fin.jpg");
    ChoisirCouleurDessin(CouleurParComposante(255, 204, 0));
    sprintf(zonetexte,"%2d min : %2d s", minutes, secondes);
    EcrireTexte(530, 370, zonetexte, 2);
    while (pair==nb_carte/2){  /* pour faire une pause "infini" */
      SourisPosition();
      boutonquitter();
      if (SourisCliquee()) {
	if (boutonquitteractive()) {
	  return;
	}
      }
    }
  }
}
