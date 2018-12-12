#include <stdio.h>
#include <stdlib.h>


typedef struct Grille Grille;
struct Grille
{
    //premioer pointeur pointe sur les lignes
    //ces lignes contient des colonnes donc le deuxieme pointeur pointe sur les colonnes
    char** matrice; // L'atribut "matrice" est la matrice représentant la grille (un tableau à deux dimensions). En l'occurence nous privilégions l'utilisation d'un double pointeuur (un pour les lignes) (un pour les colonnes) car l'utilisateur a le choix de la taille de son tableau.
    int nb_lignes; // Utile pour utiliser d'autres informations (longueur entre autres) dans des fonctions.
    int nb_colonnes;
};

Grille* creerGrille(int nb_lignes, int nb_colonnes, char mode);
void affichageGrille(Grille* matrice);
