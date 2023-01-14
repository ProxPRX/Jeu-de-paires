#include <graph.h>
#include <stdio.h>
#include <stdlib.h>

void bouton(couleur bouton_couleur, int bouton_x, int bouton_y, couleur texte_couleur, char *texte, int texte_x, int texte_y){
  int i;
  ChoisirCouleurDessin(bouton_couleur);
  /*pour faire un contour épais des boutons*/
  for (i = 0; i < 3; i++) {
    DessinerRectangle(bouton_x+i, bouton_y+i, 250, 55);
  }
  /*fond du bouton*/
  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(bouton_x+3, bouton_y+3, 247, 52);
  ChoisirCouleurDessin(texte_couleur);
  EcrireTexte(texte_x, texte_y, texte, 2);
}

void boutonquitter(void){
   /* affichage bouton quitter en jeu */
  ChoisirCouleurDessin(CouleurParNom("black"));
  RemplirRectangle(10, 10, 160, 40);
  ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
  DessinerRectangle(9, 9, 161, 41);
  EcrireTexte(20, 40, "QUITTER", 2);
}

int boutonquitteractive(void) {
   /* activation Bouton quitter ecran d'acceuille */
  return ((_X >= 10) && (_X <= 170) && (_Y >= 10) && (_Y <= 50));
}

void affichermenu(void) {
  int i;
   /* Ecriture ecran d'acceuille */
  ChoisirCouleurDessin(CouleurParNom("black")); /* fond bouton */
  RemplirRectangle(426, 280, 410, 25);
  ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
  EcrireTexte(430, 300, "CHOISISSEZ VOTRE NIVEAU DE DIFICULTE", 1);
  DessinerRectangle(426, 280, 410, 25);
  ChoisirCouleurDessin(CouleurParComposante(200, 200, 200));
  for (i = 0; i < 3; i++) {
    DessinerRectangle(500+i, 18+i, 250, 40);
  }
  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte(512, 50, "JEU DE PAIRES", 2);
  
  /*affichage des 3 bouton de difficultés*/
  bouton(CouleurParComposante(20, 220, 20), 100, 600, CouleurParComposante(20, 220, 20), "FACILE 4x4", 140, 640);
  bouton(CouleurParComposante(225, 100, 10), 505, 600, CouleurParComposante(255, 100, 10), "MOYEN 6x4", 535, 640);
  bouton(CouleurParComposante(225, 0, 0), 915, 600, CouleurParComposante(255, 0, 0), "DIFFICILE 6x6", 935, 640);
  
   boutonquitter();
}

void choixniveau(int *nb_carte,int *nb_colonnes, int *nb_lignes,int *jeu_x, int *jeu_y){
   if ((_X >= 100) && (_X <= 350) && (_Y >= 600) && (_Y <= 655)) {
         /* on recupere les infos du jeu correpondant */
       * nb_carte = 16;
       * nb_colonnes = 4;
       * nb_lignes = 4;
       * jeu_x = 500;  /* largeur postion de depart */
       * jeu_y = 225;  /* hauteur position de depart */
      }               /* int nb_cartes = 16 */

      if ((_X >= 505) && (_X <= 755) && (_Y >= 600) && (_Y <= 655)) {
       * nb_carte = 24;
       * nb_colonnes = 6;
       * nb_lignes = 4;
       * jeu_x = 440;  /* largeur postion de depart */
       * jeu_y = 230;  /* hauteur position de depart */
      }               /* int nb_cartes = 24 */

      if ((_X >= 915) && (_X <= 1165) && (_Y >= 600) && (_Y <= 655)) {
       * nb_carte = 36;
       * nb_colonnes = 6;
       * nb_lignes = 6;
       * jeu_x = 430;  /* largeur postion de depart */
       * jeu_y = 175;  /* hauteur position de depart */
       }               /* int nb_cartes = 36 */
}
