#ifndef _GRILLE_H
#define _GRILLE_H

typedef struct {
  int devoilee;
  int carte;
} Case;

void chargementgrille(int nb_colonnes,int nb_lignes,Case cases[6][6]);
void dessinergrille(Case cases[6][6], int nb_colonnes, int nb_lignes,int jeu_x,int jeu_y, int modetriche);

#endif
