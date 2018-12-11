typedef struct Grille Grille;
struct Grille
{
    char** matrix;
    int nb_lignes;
    int nb_colonnes;
};

Grille grille(int nb_lignes, int nb_colonnes, char mode);
//char** grille(int nb_lignes, int nb_colonnes, char mode);
void affichage_grille(Grille matrice);

