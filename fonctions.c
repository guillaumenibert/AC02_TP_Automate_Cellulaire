#include "fonctions.h"

Grille* creerGrille(int nb_lignes, int nb_colonnes, char mode)
{
    int i, j;
    Grille* grille = malloc(sizeof(Grille));

    if (!grille)
        exit(0);

    (*grille).matrice = malloc(nb_lignes * sizeof(char*)); // On alloue de la mémoire pour les lignes.
    if (!(*grille).matrice)
        exit(0);

    (*grille).nb_colonnes = nb_colonnes;
    (*grille).nb_lignes = nb_lignes;

    for (i = 0; i < nb_lignes; i++) // Parcours des i lignes.
    {
        (*grille).matrice[i] = malloc(nb_colonnes * sizeof(char)); // Chaque ligne contient des colonnes, il faut allouer de la mémoire aux colonnes donc.
        if (!(*grille).matrice[i])
            exit(0);
    }

    for (i = 0; i < nb_lignes ; i++) // Permet d'initialiser la grille avec que des ' ' pour ne pas avoir n'importe quoi.
    {
        for(j = 0; j < nb_colonnes; j++)
        {
            (*grille).matrice[i][j] = ' ';
        }
    }
    return(grille);
}

void affichageGrille(Grille* matrice)
{
    int i = 0, j = 0;

    printf("\n");

    for(i = 0; i < (*matrice).nb_lignes; i++) // Pour chaque ligne, on dessine l'interface graphique
    {
        for (j = 0; j < (*matrice).nb_colonnes*2+1; j++) // Cette formule a été trouvée empiriquement et semble fonctionner, elle permet de dessiner les "-"
        {
            printf("-");
        }
        printf("\n");

        for (j = 0; j < (*matrice).nb_colonnes; j++)
        {
            printf("|%c", (*matrice).matrice[i][j]); // le %c correspond a une cellule morte si on a ' ' sinon c'est une cellule vivante.
        }
        printf("|"); // La dernière barre pour fermer le tableau à droite.
        printf("\n");
    }

    for (j = 0; j < (*matrice).nb_colonnes*2+1; j++) // La dernière ligne "--------..." pour le bas.
    {
        printf("-");
    }
    printf("\n");
}
