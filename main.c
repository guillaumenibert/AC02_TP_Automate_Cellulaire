#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int lignes = 1, colonnes = 1;
    char mode;
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &colonnes);
    printf("Entrez le mode, 'a' pour aleatoire, 'm' pour manuel : ");
    while (getchar()!='\n'); // Vidage du buffer
    scanf("%c", &mode);

    Grille* Jeu = creerGrille(lignes, colonnes, 'm');
    affichageGrille(Jeu);
    return 0;
}
