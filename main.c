#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int lignes = 1, colonnes = 1;
    char mode = 'm';
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &colonnes);
    printf("Entrez le mode, 'a' pour aleatoire, 'm' pour manuel : ");
    while (getchar()!='\n'); // Vidage du buffer
    scanf("%c", &mode);

    Grille Jeu = grille(lignes, colonnes, 'm');
    affichage_grille(Jeu);
    return 0;
}
