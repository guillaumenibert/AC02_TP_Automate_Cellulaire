#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Grille grille(int nb_lignes, int nb_colonnes, char mode)
{
    int i, j;
    Grille matrice;

    matrice.matrix = malloc(nb_lignes * sizeof(char*));

    if (!matrice.matrix)
        exit(0);

    matrice.nb_colonnes = nb_colonnes;
    matrice.nb_lignes = nb_lignes;

    for (i = 0; i < nb_colonnes; i++)
    {
        matrice.matrix[i] = malloc(nb_colonnes * sizeof(char));
    }

    for (i = 0; i < nb_lignes ; i++) // Permet d'initialiser la grille avec que des ' ' pour ne pas avoir n'importe quoi.
    {
        for(j = 0; j < nb_colonnes; j++)
        {
            matrice.matrix[i][j] = ' ';
        }
    }
    return(matrice);
}

void affichage_grille(Grille matrice)
{
    int i = 0, j = 0;

    for(i = 0; i < matrice.nb_lignes; i++)
    {
        for (j = 0; j < matrice.nb_colonnes*2+1; j++)
        {
            printf("-");
        }
        printf("\n");

        for (j = 0; j < matrice.nb_colonnes; j++)
        {
            printf("|%c", matrice.matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }

    for (j = 0; j < matrice.nb_colonnes*2+1; j++)
        {
            printf("-");
        }
}

