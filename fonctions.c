//
// Created by Luc on 16/12/2018.
//

#include "fonctions.h"

Grille* creerGrille(int nb_lignes, int nb_colonnes)
{
    int i, j;
    Grille* grille = malloc(sizeof(Grille));

    if (!grille)
        exit(0);

    grille->pointeurCase = malloc(nb_lignes * sizeof(char*)); // On alloue de la mémoire pour les lignes.
    if (!grille->pointeurCase)
        exit(0);

    grille->nb_colonnes = nb_colonnes; // Renseignement des attributs de la structure.
    grille->nb_lignes = nb_lignes;

    for (i = 0; i < nb_lignes; i++)
    {
        grille->pointeurCase[i] = malloc(nb_colonnes * sizeof(char)); // On alloue de la mémoire pour les colonnes
        if (!grille->pointeurCase[i])
            exit(0);
    }

    for (i = 0; i < nb_lignes ; i++) // Remplissage de cellules mortes.
    {
        for(j = 0; j < nb_colonnes; j++)
        {
            grille->pointeurCase[i][j] = ' ';
        }
    }
    return grille; // Retourne un pointeur de type Grille* sur grille.
}

void affichageGrille(Grille* grille)
{
    int i = 0, j = 0;

    for(i = 0; i < grille->nb_lignes; i++) // Pour chaque ligne, on dessine l'interface graphique
    {
        for (j = 0; j < grille->nb_colonnes*2+1; j++) // Cette formule a été trouvée empiriquement et semble fonctionner, elle permet de dessiner les "-"
        {
            printf("-");
        }
        printf("\n");

        for (j = 0; j < grille->nb_colonnes; j++)
        {
            printf("|%c", grille->pointeurCase[i][j]); // le %c correspond a une cellule morte si on a ' ' sinon c'est une cellule vivante.
        }
        printf("|"); // La dernière barre pour fermer le tableau à droite.
        printf("\n");
    }

    for (j = 0; j < grille->nb_colonnes*2+1; j++) // La dernière ligne "--------..." pour le bas.
    {
        printf("-");
    }
}

void affichageGrille2(Grille* grille) // Un deuxième mode d'affichage... Sans les bords
{
    int i = 0, j = 0;
    for(i = 0; i < grille->nb_lignes; i++)
    {
        for (j = 0; j < grille->nb_colonnes; j++)
        {
            printf("%c", grille->pointeurCase[i][j]);
        }
        printf("\n");
    }
}

//renvoie un nombre entre 0 et le parametre
int random (int probabilite) {
    return rand()% (probabilite+1);
}

Grille* grilleAleatoire (Grille *grille, int probabilite) {
    int i = 0, j =0;
    for (i=0; i<grille->nb_lignes;i++) {
        for (j=0; j<grille->nb_colonnes; j++) {
            if (probabilite <= random(100)) {
                grille->pointeurCase[i][j] = '*';
            }

        }
    }
    return grille;
}

void grilleAleatoire_v2(Grille *grille, int probabilite)
{
    int i = 0, j=0;
    for (i=0; i<grille->nb_lignes;i++) {
        for (j=0; j<grille->nb_colonnes; j++) {
            if (probabilite <= random(100)) {
                grille->pointeurCase[i][j] = '*';
            }
        }
    }
}

//IL RESTE A FAIRE MARCHER LES WHILE POUR QUE LE USER PUISSE PAS RENTRER DE LA MERDE
Grille* grilleManuelle (Grille *grille) {
    int i=0, j=0, k=0, nbCellules=0;
    printf("Combien de cellule vivante voulez-vous entrer dans la grille ?\n");
    scanf("%d", &nbCellules);
    getchar();
    for (k=0; k<nbCellules;k++) {
//        while (i < grille->nb_lignes || i > grille->nb_lignes) {
            printf("Veuillez choisir la ligne de la cellule vivante de la grille : \n");
            scanf("%d", &i);
            getchar();
//        }
    printf("Veuillez choisir la ligne de la cellule vivante de la grille : \n");
//    while (j < grille->nb_colonnes || j > grille->nb_colonnes) {
            scanf("%d", &j);
            getchar();
//        }
        // par exemple, si le user rentre 1 1, alors ca va se mettre aux coordonnées [0][0]
        grille->pointeurCase[i-1][j-1] = '*';
    }
    return grille;
}

void grilleManuelle_v2(Grille *grille)
{
    int i = 0, j = 0, k = 0, nbCellules = 0;
    int nbTotalCellules = (grille->nb_colonnes)*(grille->nb_lignes);

    printf("\nCombien de cellule.s vivante.s voulez-vous entrer dans la grille ? ");
    scanf("%d", &nbCellules);
    while (getchar() != '\n');
    while (nbCellules < 1 || nbCellules > nbTotalCellules)
    {
        if (nbCellules < 1)
        {
            printf("Vous avez entre un nombre strictement inferieur a 1, recommencez :\n");
            printf("Combien de cellule.s vivante.s voulez-vous entrer dans la grille ? ");
            scanf("%d", &nbCellules);
            while (getchar() != '\n');
        }
        else if (nbCellules > nbTotalCellules)
        {
            printf("Vous avez entre un nombre superieur au nombre total de cellules dans cette grille, recommencez : \n");
            printf("Combien de cellule.s vivante.s voulez-vous entrer dans la grille ? ");
            scanf("%d", &nbCellules);
            while (getchar() != '\n');
        }
        // Pas besoin de rajouter une boucle else si l'utilisateur rentre par exemple 'a'. En effet, on travaille en ASCII, donc c'est déjà géré dans les boucles précédentes.
    }

    for (k = 0; k < nbCellules; k++)
    {
        printf("\n\nVeuillez choisir la ligne de la cellule vivante no %d de la grille : ", k+1);
        scanf("%d", &i);
        while (getchar() != '\n');

        while (i < 1 || i > grille->nb_lignes)
        {
            if (i < 1)
            {
                printf("Vous avez entre un nombre strictement inferieur a 1, recommencez :\n");
                printf("Veuillez choisir la ligne de la cellule vivante no %d de la grille : ", k+1);
                scanf("%d", &i);
                while (getchar() != '\n');
            }
            else if (i > grille->nb_lignes)
            {
                printf("Vous avez entre un nombre superieur au nombre total de lignes dans cette grille, recommencez : \n");
                printf("Veuillez choisir la ligne de la cellule vivante no %d de la grille : ", k+1);
                scanf("%d", &i);
                while (getchar() != '\n');
            }
        }

        printf("Veuillez choisir la colonne de la cellule vivante no %d de la grille : ", k+1);
        scanf("%d", &j);
        while (getchar() != '\n');

        while (j < 1 || j > grille->nb_colonnes)
        {
            if (j < 1)
            {
                printf("Vous avez entre un nombre strictement inferieur a 1, recommencez :\n");
                printf("Veuillez choisir la colonne de la cellule vivante no %d de la grille : ", k+1);
                scanf("%d", &j);
                while (getchar() != '\n');
            }
            else if (j > grille->nb_colonnes)
            {
                printf("Vous avez entre un nombre superieur au nombre total de lignes dans cette grille, recommencez : \n");
                printf("Veuillez choisir la colonne de la cellule vivante no %d de la grille : ", k+1);
                scanf("%d", &j);
                while (getchar() != '\n');
            }
        }
        grille->pointeurCase[i-1][j-1] = '*';
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - MODE MANUEL\n\n");
        affichageGrille(grille);
    }
}

//renvoie le nombre de voisin, en partant de la ligne 0 et de la colonne 0
// ATTENTION aux indices !
int nombreVoisins (Grille* grille, int i, int j) {
//    int i=0, j=0;
    if (
            (i==0 && j==0) ||
            (i==0 && j==grille->nb_colonnes-1) ||
            (i==grille->nb_lignes-1 && j==0) ||
            (i==grille->nb_lignes-1 && j==grille->nb_colonnes-1)
            ) return 3;
    else if (i==0 || i == grille->nb_lignes-1 || j==0 || j==grille->nb_colonnes-1) return 5;
    else return 8;

}

//PENSER A RETIRER LES CONDITIONS POUR LES LIGNES AUX BORDS (CHECKER SI CA CHANGE RIEN)
int nbVoisinsVivants (Grille *grille, int i, int j) {
    int compteur = 0;
    //coin en haut a gauche
    if (i==0 && j==0) {
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        if (grille->pointeurCase[i+1][j+1] == '*') compteur++;
        return compteur;
    }
    //coin en haut a droite
    else if (i==0 && j==grille->nb_colonnes-1) {
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        return compteur;
    }
    //coin en bas a gauche
    else if (i==grille->nb_lignes-1 && j==0) {
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        if (grille->pointeurCase[i-1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        return compteur;
    }
    //coin en bas a droite
    else if (i==grille->nb_lignes-1 && j==grille->nb_colonnes-1) {
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i-1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        return compteur;
    }
    //ligne en haut sauf coin
    else if (i==0 && j>0 && j<grille->nb_colonnes-1) {
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        if (grille->pointeurCase[i+1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        return compteur;
    }
        //ligne a droite sauf coin
    else if (j==grille->nb_colonnes-1 && i>0 && i<grille->nb_lignes-1) {
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        if (grille->pointeurCase[i-1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        return compteur;
    }    //ligne en bas  sauf coin
    else if (i==grille->nb_lignes-1 && j>0 && j<grille->nb_colonnes-1) {
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i-1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        if (grille->pointeurCase[i-1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        return compteur;
    }    //ligne a gauche sauf coin
    else if (j==0 && i>0 && i<grille->nb_lignes-1) {
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        if (grille->pointeurCase[i-1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        return compteur;
    }
    //tout sauf les bords
    else {
        if (grille->pointeurCase[i-1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i-1][j] == '*') compteur++;
        if (grille->pointeurCase[i-1][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j+1] == '*') compteur++;
        if (grille->pointeurCase[i][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j-1] == '*') compteur++;
        if (grille->pointeurCase[i+1][j] == '*') compteur++;
        if (grille->pointeurCase[i+1][j+1] == '*') compteur++;
        return compteur;
    }
}

Grille* simulation (Grille *grille) {
    int i=0, j=0;
    for (i=0; i<grille->nb_lignes; i++) {
        for (j=0; j<grille->nb_colonnes; j++) {
            if (grille->pointeurCase[i][j] == '*') {
                if (nbVoisinsVivants(grille, i,j) != 2 && nbVoisinsVivants(grille, i,j)!=3) grille->pointeurCase[i][j]= ' ';
            }
            else if (grille->pointeurCase[i][j] == ' ') {
                if (nbVoisinsVivants(grille, i,j) == 3) grille->pointeurCase[i][j] = '*';
            }
        }
    }
    return grille;
}
