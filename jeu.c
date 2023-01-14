#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "grille.h"

void jeu(int nb_colonnes,int nb_lignes,int* pair,int modetriche,int jeu_x,int jeu_y, Case cases[6][6],int*derniere_case_clickee_x,int* derniere_case_clickee_y,int*case_clickee,int* derniere_carte){
  int x,y,xdepart,ydepart,xfin,yfin;
  unsigned long micro;

  
  	  /* on regarde si une des cases c'est faite cliquer */
	  for (x = 0; x < nb_colonnes; x++) {
	    for (y = 0; y < nb_lignes; y++) {

	      /* Position de depart de la case */
	      xdepart = jeu_x + x * 65;
	      ydepart = jeu_y + y * 65;

	      /* Position de fin de la case */
	      xfin = xdepart + 55;
	      yfin = ydepart + 55;

	      /* Activation bouton de la case */
	      /* Si la case est dejà cliquer on ignore le clique */
	      if ((_X >= xdepart) && (_X <= xfin) && (_Y >= ydepart) &&
		  (_Y <= yfin) && !cases[x][y].devoilee) {

		cases[x][y].devoilee = 1;

		/* Si une case à dejà ete cliquee avant, on verifie que les deux */
		/*  cases cliquees sont la même paire */
		if (*case_clickee==1) {
		  /* Si la carte de la case actuelle et de la case precedentes */
		  /* sont les mêmes, cela frome une paire; on laisse les deux */
		  /* cartes devoilees */
		  if (*derniere_carte == cases[x][y].carte) {
		    /* on incrémente la paire trouvée dans la variable pair */
		   *pair = *pair+1;		               			      		
		    /* Si les deux cartes ne sont pas les mêmes, on fait une */
		    /*  petite pause et on recache les deux case selectionnees */
		  } else {		   
		    /* Pour faire une pause de 1 seconde(1.000.000 */
		    /*  microsecondes), on enregristre le temps de depart pour */
		    /*  savoir quand finir */
		    micro = Microsecondes();
		    while (micro + 1000000 > Microsecondes()) {
		      /*  On fait appel à un Souriscliquee() pour que si */
		      /* l'utilisatuer fait un clik pendant la pause de 1s, ce */
		      /* clik ne soit pas conserve */
		      SourisCliquee();

		      dessinergrille(cases, nb_colonnes, nb_lignes, jeu_x, jeu_y,
				     modetriche);
		    }

		    /* On cache les deux cases */
		    cases[x][y].devoilee = 0;
		    cases[*derniere_case_clickee_x][*derniere_case_clickee_y]
		      .devoilee = 0;
		  }
		  /* Une fois que l'on a clique les deux paires, on considere */
		  /* qu'il n'y a plus de case cliquees pour permetttre de */
		  /* selectionne une nouvelle paire */
		 *case_clickee = 0;
		}
		/* S'il n'y à pas de case cliquee auparavent, on enregistre */
		/* cette case comme etant cliquee */
		else {
		  *case_clickee = 1;
		  *derniere_case_clickee_x = x;
		  *derniere_case_clickee_y = y;
		  *derniere_carte = cases[x][y].carte;
		}
	      }
	    }
	  }
}
