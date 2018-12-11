#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Grille Jeu = grille(10, 11, 'm');
    affichage_grille(Jeu);

    return 0;
}
