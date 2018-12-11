typedef struct Grille Grille;
struct Grille
{
    char** matrix; // L'atribut "matrix" est la matrice représentant la grille (un tableau à deux dimensions). En l'occurence nous priviliégons l'utilisation d'un double pointeuur (un pour les lignes) (un pour les colonnes) car l'utilisateur a le choix de la taille de son tableau.
    int nb_lignes; // Utile pour utiliser d'autres informations (longueur entre autres) dans des fonctions.
    int nb_colonnes;
};

Grille grille(int nb_lignes, int nb_colonnes, char mode);
void affichage_grille(Grille matrice);
