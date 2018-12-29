//
// Created by Luc on 16/12/2018.
//

#ifndef AUTOMATES_CELLULAIRES_FONCTIONS_H
#define AUTOMATES_CELLULAIRES_FONCTIONS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Grille Grille;
struct Grille
{
    char** pointeurCase;
    int nb_lignes;
    int nb_colonnes;
};

Grille* creerGrille(int nb_lignes, int nb_colonnes);
void affichageGrille(Grille* grille);
void affichageGrille2(Grille* grille);
int random (int probabilite);
Grille* grilleAleatoire (Grille *grille, int probabilite);
void grilleAleatoire_v2(Grille *grille, int probabilite);
Grille* grilleManuelle (Grille *grille);
void grilleManuelle_v2(Grille *grille);
int nombreVoisins (Grille* grille, int i, int j);
int nbVoisinsVivants (Grille *grille, int i, int j);
Grille* simulation (Grille *grille);
int nbEmplacementSauvLibre(FILE* emplacements[]);



#endif //AUTOMATES_CELLULAIRES_FONCTIONS_H
