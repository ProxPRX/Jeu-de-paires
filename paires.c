#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "timer_fin.h"
#include "grille.h"
#include "jeu.h"

#define tx 1280
#define ty 720

int main(void) {
  int nb_carte = 0;
  int jeu_x = 0, jeu_y = 0,nb_colonnes = 0, nb_lignes = 0;
  int case_clickee = 0, derniere_case_clickee_x = 0,
      derniere_case_clickee_y = 0, derniere_carte = 0;
  Case cases[6][6] = {0};  /* initialisation tableau niveaux on met un 6 */
                           /* par 6 car notre grille la plus grande */
   /* gestion du temps */
  unsigned long int debut = Microsecondes();
  int secondes = 0, minutes = 0;
   /* fin du jeu */
  int pair = 0;
  /* mode tricheur */
  int modetriche = 0;
  
  /*--------------------------------------------------------------------------*/
  InitialiserGraphique();
  CreerFenetre(200, 150, tx, ty);
  ChargerImageFond("images/fond_demarrage.png");
  /*on affiche l'écran d'aceuille*/
  affichermenu(); 
  /*--------------------------------------------------------------------------*/
   /* 01) Choix  du jeu et chargement des variables de travail */
  while (nb_carte == 0) {
    SourisPosition();
    if (SourisCliquee()) {
      choixniveau(&nb_carte,&nb_colonnes,&nb_lignes,&jeu_x,&jeu_y);
      if(boutonquitteractive()){
	return EXIT_SUCCESS; 
      }
    }
  }
  /*--------------------------------------------------------------------------*/
   /* 02) Afficher la grille correspondante au jeu selectionne */
   /* 02-1) Chargement de l'image de fond */
  ChargerImageFond("images/fond.png");
  boutonquitter();
  /*--------------------------------------------------------------------------*/
  /*  02-2) Chargement de la grille */
  /* Parcours des colonnes */
  chargementgrille(nb_colonnes,nb_lignes,cases);
  /*--------------------------------------------------------------------------*/
  while (pair!=nb_carte/2) {      
    tempecoule(&secondes,&minutes,modetriche,&debut);
    dessinergrille(cases, nb_colonnes, nb_lignes, jeu_x, jeu_y, modetriche);
    /* mode triche */
    if (ToucheEnAttente()) {
      if (Touche() == XK_t) {
        modetriche = !modetriche;
      }
    } 
    /* On demande les infos de postions de la souris */
    SourisPosition();
    /* Si la souris est clique, on verifie si c'est sur un bouton ou une case */
    if (SourisCliquee())
      {
	/* activation bouton quitter */
	if (boutonquitteractive()) {
	  return EXIT_SUCCESS;
	}
	
	if(!modetriche) {
	  jeu(nb_colonnes,nb_lignes,&pair,modetriche,jeu_x,jeu_y,cases,&derniere_case_clickee_x,&derniere_case_clickee_y,&case_clickee,&derniere_carte);	  
	}
      }
  }
  /* gestion fin de la partie quand toute les cartes sont trouvées */
  ecranfin(pair,nb_carte,minutes,secondes);
  return EXIT_SUCCESS;
}

