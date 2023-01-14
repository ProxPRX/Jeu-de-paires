#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

typedef struct {
  int devoilee;
  int carte;
} Case;

void chargementgrille(int nb_colonnes,int nb_lignes,Case cases[6][6] ){
  /* Fonction => Arguments => Tableau cases[nb_colonnes][nb_lignes] */
  int colonne,ligne,carte_num=0,paire=0,x,y,nx,ny,temp_carte;
  /* Parcours des colonnes */
  for (colonne = 0; colonne < nb_colonnes; colonne++) {
     /* Parcours des lignes */
    for (ligne = 0; ligne < nb_lignes; ligne++) {
       /* On assigne un numero de carte à chaque case */
      cases[colonne][ligne].carte = carte_num;

      /* Pour permettre de generer des paires, on incremente le numero de carte */
      /* une fois sur deux */
      if (paire == 1) {
        carte_num++;
        paire = 0;
      } else {
        paire = 1;
      }
    }
  }

  /* mise en aleatoire des couleurs des cartes */
  srand(Microsecondes(NULL));
  for (x = 0; x < nb_colonnes; x++) {
    for (y = 0; y < nb_lignes; y++) {
     /* pour chaque cas on genere une position aleatoire avec qui echanger la carte */
      nx = rand() % nb_colonnes;
      ny = rand() % nb_lignes;
      temp_carte = cases[x][y].carte;
      cases[x][y].carte = cases[nx][ny].carte;
      cases[nx][ny].carte = temp_carte;
    }
  }
}

void dessinergrille(Case cases[6][6], int nb_colonnes, int nb_lignes, int jeu_x,int jeu_y, int modetriche) {
  int x, y, case_position_x, case_position_y;
  couleur c;

   /* on regarde si une des cases c'est faite cliquer */
  for (x = 0; x < nb_colonnes; x++) {
    for (y = 0; y < nb_lignes; y++) {
      /* Calcul des variables */
      case_position_x = jeu_x + (65 * x);
      case_position_y = jeu_y + (65 * y);	
      if (cases[x][y].devoilee || modetriche) {
         /* Ici on affiche la case dans sa frome devoillee */
        c = CouleurParComposante(cases[x][y].carte * 150,
                                 cases[x][y].carte * 55,
                                 cases[x][y].carte * 175);
	
        ChoisirCouleurDessin(c);

        RemplirRectangle(case_position_x, case_position_y, 55, 55);
      } else {

        c = CouleurParComposante(200, 200, 200);
        ChoisirCouleurDessin(c);
        RemplirRectangle(case_position_x, case_position_y, 55, 55);
      }
    }
  }
}
