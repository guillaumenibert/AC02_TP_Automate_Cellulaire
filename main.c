#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main(int argc, char *argv[]) // Gestion des paramètres -new et -load
{
    int lignes = 1, colonnes = 1, nbEtapes = 1;
    int regleMortVivantMin = 3, regleMortVivantMax = 3, regleVivantVivantMin = 2, regleVivantVivantMax = 3; // Par défaut, les règles de transition sont celle du jeu de la vie.
    int choixRegles, simuPasPas, probabilite;
    char mode; // Aléatoire ou manuel.
    char nomSauvegarde[51]; // Nom de la sauvegarde choisi par l'utilisateur.

    int i, j;

    Grille* grandJeu = NULL; // Variable globale, c'est la grille du jeu.
    Grille dixDerniers[11] = {NULL}; // Sauvegarde des 10 derniers états de l'automate.

    Grille* VIDE = creerGrille(1,1); // Grille particulière pour la sauvegarde des 10 derniers états.
    VIDE->pointeurCase[0][0] = 'V';

    char sauvegardes[256]; // Variable contenant le chemin relatif du fichier txt de sauvegarde.
    FILE* sauvegarde = NULL; // Pointeur sur un fichier, pour les sauvegardes.

    int compteurLignes = 0, compteurCarac = 0; // Variables pour les lectures des sauvegardes au format txt.
    char chaine[100] = "";
    int nbLignes = 1, nbColonnes = 1;

    // Nom du programme présent partout.
    printf("Bienvenue a ATOMICCELLU - LG Corporation (c)\n\n");

    // Choix des règles de transitions
    printf("CHOIX DES REGLES DE TRANSITIONS\n\n");

    printf("Vous souhaitez jouer au jeu de la vie ou configurer vos propres regles ?\n1 - Jeu de la vie\n2 - Configuration de regles personnalisees\n");
    printf("\nSaisissez votre choix : ");
    scanf("%d", &choixRegles);
    while (getchar() != '\n');

    while (choixRegles < 1 || choixRegles > 2)
    {
        printf("Vous n'avez pas entre un nombre valide, recommencez :");
        printf("Vous souhaitez jouer au jeu de la vie ou configurer vos propres regles ?\n1 - Jeu de la vie\n2 - Configuration de regles personnalisees\n");
        printf("\nSaisissez votre choix : ");
        scanf("%d", &choixRegles);
        while (getchar() != '\n');
    }

    printf("%d", choixRegles);

    if (choixRegles == 1)
    {
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - JEU DE LA VIE\n\n");
        printf("Vous avez choisi de jouer au jeu de la vie !\n\n");
        printf("Appuyez sur Entrer pour continuer...");
        while (getchar()!='\n');
    }
    else if (choixRegles == 2)
    {
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - CHOIX DES REGLES DE TRANSITIONS\n\n");

        printf("Entrez le nombre minimum de voisins vivants pour qu'une cellule morte devienne vivante : ");
        scanf("%d", &regleMortVivantMin);
        while (getchar()!='\n');
        while (regleMortVivantMin < 1 || regleMortVivantMin > 8)
        {
            printf("Vous n'avez pas entre un nombre valide, recommencez :");
            printf("Entrez le nombre minimum de voisins vivants pour qu'une cellule morte devienne vivante : ");
            scanf("%d", &regleMortVivantMin);
            while (getchar()!='\n');
        }

        printf("Entrez le nombre maximum de voisins vivants pour qu'une cellule morte devienne vivante : ");
        scanf("%d", &regleMortVivantMax);
        while (getchar()!='\n');
        while (regleMortVivantMax < 1 || regleMortVivantMax > 8)
        {
            printf("Vous n'avez pas entre un nombre valide, recommencez :");
            printf("Entrez le nombre maximum de voisins vivants pour qu'une cellule morte devienne vivante : ");
            scanf("%d", &regleMortVivantMax);
            while (getchar()!='\n');
        }

        printf("Entrez le nombre minimum de voisins vivants pour qu'une cellule vivante reste vivante : ");
        scanf("%d", &regleVivantVivantMin);
        while (getchar()!='\n');
        while (regleVivantVivantMin < 1 || regleVivantVivantMin > 8)
        {
            printf("Vous n'avez pas entre un nombre valide, recommencez :");
            printf("Entrez le nombre minimum de voisins vivants pour qu'une cellule vivante reste vivante : ");
            scanf("%d", &regleVivantVivantMin);
            while (getchar()!='\n');
        }

        printf("Entrez le nombre maximum de voisins vivants pour qu'une cellule vivante reste vivante : ");
        scanf("%d", &regleVivantVivantMax);
        while (getchar()!='\n');
        while (regleVivantVivantMax < 1 || regleVivantVivantMax > 8)
        {
            printf("Vous n'avez pas entre un nombre valide, recommencez :");
            printf("Entrez le nombre maximum de voisins vivants pour qu'une cellule vivante reste vivante : ");
            scanf("%d", &regleVivantVivantMax);
            while (getchar()!='\n');
        }
        printf("Appuyez sur Entrer pour continuer...");
        while (getchar()!='\n');
    }

    // Programme exécuté avec le paramètre "new"
    if (strcmp(argv[1], "new") == 0) // à la fin du développement mettre argv[1] == "new"
    {
        // Nom du programme présent partout.
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - TAILLE DE LA GRILLE\n\n");

        // Définition de la taille de la grille.
        printf("Commencez par definir la taille de votre grille : \n\n");

        printf("Entrez le nombre de lignes : ");
        scanf("%d", &lignes);
        while (getchar() != '\n');
        printf("Entrez le nombre de colonnes : ");
        scanf("%d", &colonnes);
        while (getchar() != '\n');

        Grille* jeu = creerGrille(lignes, colonnes);

        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - MODE DE JEU\n\n");

        // Choix du mode de jeu (aléatoire ou manuel)
        printf("Deux modes de jeu sont a votre disposition :\n\n - Mode aleatoire (a) : L'etat initial de chaque cellule est genere aleatoirement avec une probabilite qu'une cellule soit vivante que vous definirez.\n - Mode manuel (m) : Une grille composee de cellules mortes est generee. Vous selectionnez les coordonees des cellules vivantes pour la remplir.\n");

        printf("\nTapez 'a' pour le mode aleatoire ou 'm' pour le mode manuel : ");
        scanf("%c", &mode);

        while (mode != 'a' && mode != 'm') // Si l'utilisateur entre autre chose que 'a' ou 'm'
        {
            printf("\nVous n'avez pas rentre un mode de jeu valide, reessayez : ");
            while (getchar() != '\n');
            scanf("%c", &mode);
        }

        if (mode == 'm') // Mode manuel
        {
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - MODE MANUEL\n");
            grilleManuelle(jeu);
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - MODE MANUEL\n\n");
            affichageGrille(jeu);
            printf("\n\n");
        }
        else if (mode == 'a') // Mode aléatoire
        {
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - MODE ALEATOIRE\n\n");
            printf("Entrez votre probabilite entre 0 et 100 : ");
            scanf("%d", &probabilite);
            while(probabilite < 0 || probabilite > 100)
            {
                printf("Vous n'avez pas entre une probabilite valide, recommencez.\n");
                printf("Entrez votre probabilite entre 0 et 100 : ");
                scanf("%d", &probabilite);
            }
            srand(time(NULL));
            grilleAleatoire(jeu, probabilite);
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - MODE ALEATOIRE\n\n");
            affichageGrille(jeu);
        }
        grandJeu = jeu;
    }

    // Programme exécuté avec le paramètre "load", chargement d'une grille sauvegardée.
    if (strcmp(argv[1], "load") == 0)
    {
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - CHARGEMENT D'UNE GRILLE SAUVEGARDEE\n\n");
        printf("Entrez le nom de votre sauvegarde : ");
        gets(nomSauvegarde);

        int caractereActuel = 0;

        sprintf( sauvegardes, "sauvegardes/%s.txt", nomSauvegarde );
        printf( "Ouverture de \"%s\"", sauvegardes );
        sauvegarde = fopen( sauvegardes, "r" );
        memset( sauvegardes, 0x00, 256 ); // On reset le nom de fichier pour pas se trouver avec 10 nom de fichiers à la suite.
        // Ecriture dans ton fichier...

        if (sauvegarde != NULL)
        {
            while (compteurLignes < 2) // Récupération du nombre de lignes et de colonnes
            {
                caractereActuel = fgetc(sauvegarde);
                chaine[compteurCarac] = caractereActuel;
                compteurCarac++;
                if (caractereActuel == '\n')
                {
                    if (compteurLignes == 0)
                    {
                        chaine[compteurCarac] = '\0';
                        nbLignes = atoi(chaine);
                        compteurCarac = 0;
                    }
                    if (compteurLignes == 1)
                    {
                        chaine[compteurCarac] = '\0';
                        nbColonnes = atoi(chaine);
                        compteurCarac = 0;
                    }
                    compteurLignes++;
                }
            }

            Grille* jeu = creerGrille(nbLignes, nbColonnes);
            compteurLignes = 0; // reinitialisation
            compteurCarac = 0;

            do
            {
                caractereActuel = fgetc(sauvegarde);

                if (caractereActuel != '\n')
                {
                    jeu->pointeurCase[compteurLignes][compteurCarac] = caractereActuel;
                    compteurCarac++;
                }
                if (caractereActuel == '\n')
                {
                    compteurLignes++;
                    compteurCarac = 0;
                }

            }while (compteurLignes != nbLignes);

            fclose(sauvegarde);
            grandJeu = jeu;
        }

        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - SAUVEGARDE : %s\n\n", nomSauvegarde);
        affichageGrille(grandJeu);
    }

    // Sélection du nombres d'étapes
    printf("\n\nSelectionnez le nombre d'etape(s) que vous voulez effectuer : ");
    scanf("%d", &nbEtapes);
    while (getchar()!='\n');
    while (nbEtapes < 1) // La première fois, il n'est pas possible d'aller à un état antérieur.
    {
        printf("Vous n'avez pas entre un nombre valide !\n");
        printf("\nSelectionnez le nombre d'etape(s) que vous voulez effectuer : ");
        scanf("%d", &nbEtapes);
        while (getchar()!='\n');
    }

    if (nbEtapes > 11)
    {
        int j = 0;
        for (i = 0; i < nbEtapes-11; i++)
        {
            grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS (ETAPE %d)\n\n", i+1);
            affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par soucis de lisibilité.
        }
        for (i = nbEtapes-11; i < nbEtapes; i++)
        {
            dixDerniers[j] = *grandJeu;
            grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS (ETAPE %d)\n\n", i+1);
            affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par soucis de lisibilité.
            j++;
        }
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - RESULTAT DE LA SIMULATION APRES %d ETAPE(S)\n\n", nbEtapes);
        affichageGrille(grandJeu);
    }
    else
    {
        for (i = 0; i < nbEtapes; i++)
        {
            dixDerniers[i] = *grandJeu;
            grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS\n\n");
            affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par soucis de lisibilité.
        }
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - RESULTAT DE LA SIMULATION APRES %d ETAPE(S)\n\n", nbEtapes);
        affichageGrille(&(dixDerniers[nbEtapes-1]));
        printf("\n");
        affichageGrille(grandJeu);
    }
    printf("\n\nQue souhaitez-vous faire ?\n");
    printf("1 - Continuer la simulation\n");
    printf("2 - Sauvegarder cette partie\n");
    printf("3 - Quitter le programme\n");

    scanf("%d", &simuPasPas);
    while (getchar() != '\n');

    while (simuPasPas < 1 || simuPasPas > 3)
    {
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - MENU\n\n");
        printf("\nEntrez un choix valide !\n");
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1 - Continuer la simulation\n");
        printf("2 - Sauvegarder cette partie\n");
        printf("3 - Quitter le programme\n");

        scanf("%d", &simuPasPas);
        while (getchar() != '\n');
    }

    while (simuPasPas == 1 || simuPasPas == 2)
    {
        if (simuPasPas == 2)
        {
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - SAUVEGARDE\n\n");
            printf("Entrez le nom de votre sauvegarde (50 caracteres max) : ");
            gets(nomSauvegarde);

            sprintf( sauvegardes, "sauvegardes/%s.txt", nomSauvegarde );
            printf( "Creation de \"%s\"", sauvegardes );
            sauvegarde = fopen( sauvegardes, "w" );
            memset( sauvegardes, 0x00, 256 ); // On reset le nom de fichier pour pas se trouver avec 10 nom de fichiers à la suite.

            fprintf(sauvegarde, "%d", grandJeu->nb_lignes); // Enregistrement du nombre de ligne dans la première ligne du fichier texte.
            fputs("\n", sauvegarde);
            fprintf(sauvegarde, "%d", grandJeu->nb_colonnes); // Enregistrement du nombre de colonne dans la deuxième ligne du fichier texte.
            fputs("\n", sauvegarde);

            for(i = 0; i < grandJeu->nb_lignes; i++)
            {
                for (j = 0; j < grandJeu->nb_colonnes; j++)
                {
                    fputc(grandJeu->pointeurCase[i][j], sauvegarde); // Enregistrement de la grille dans le fichier texte.
                }
                fputs("\n", sauvegarde);
            }

            fclose( sauvegarde ); // Fermeture du fichier de sauvegarde.
            printf("\n\nQue souhaitez-vous faire ?\n");
            printf("1 - Continuer la simulation\n");
            printf("2 - Quitter le programme\n");

            scanf("\n%d", &simuPasPas);
            while (getchar() != '\n');

            while (simuPasPas < 1 || simuPasPas > 2) // Gestion d'un choix de l'utilisateur non valide.
            {
                system("cls");
                printf("ATOMICCELLU - LG Corporation (c) - MENU\n\n");
                printf("\nEntrez un choix valide !\n");
                printf("\n\nQue souhaitez-vous faire ?\n");
                printf("1 - Continuer la simulation\n");
                printf("2 - Quitter le programme\n");

                scanf("\n%d", &simuPasPas);
                while (getchar() != '\n');
            }

            if (simuPasPas == 2)
            {
                exit(0);
            }
        }

        int sommeNULL = 0;
        system("cls");
        printf("ATOMICCELLU - LG Corporation (c) - SELECTION DU NOMBRE D'ETAPES\n\n");
        printf("\n\nSelectionnez le nombre d'etape(s) que vous voulez effectuer : ");
        scanf("%d", &nbEtapes);
        while (getchar()!='\n');
        while (nbEtapes < -10)
        {
            printf("Il n'est pas possible de revenir au dela de 10 etats anterieurs !\n");
            printf("\nSelectionnez le nombre d'etape(s) que vous voulez effectuer : ");
            scanf("%d", &nbEtapes);
            while (getchar()!='\n');
        }

        if (nbEtapes > 11) // Les dix derniers états seront automatiquement écrasés.
        {
            int j = 0;
            for (i = 0; i < nbEtapes-11; i++)
            {
                grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
                system("cls");
                printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS (ETAPE %d)\n\n", i+1);
                affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par souci de lisibilité.
            }
            for (i = nbEtapes-11; i < nbEtapes; i++)
            {
                dixDerniers[j] = *grandJeu;
                grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
                system("cls");
                printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS (ETAPE %d)\n\n", i+1);
                affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par souci de lisibilité.
                j++;
            }
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - RESULTAT DE LA SIMULATION APRES %d ETAPE(S)\n\n", nbEtapes);
            affichageGrille(grandJeu);
        }
        else if (nbEtapes > 0 && nbEtapes <= 11)
        {
            for (i = 0; i < nbEtapes; i++) // Réinitialisation des dix derniers états.
            {
                dixDerniers[i] = *VIDE;
            }

            for (i = 0; i < nbEtapes; i++)
            {
                dixDerniers[i] = *grandJeu;
                grandJeu = simulationWithRegles(grandJeu, regleMortVivantMin, regleMortVivantMax, regleVivantVivantMin, regleVivantVivantMax);
                system("cls");
                printf("ATOMICCELLU - LG Corporation (c) - SIMULATION EN COURS (ETAPE %d)\n\n", i+1);
                affichageGrille2(grandJeu); // Utilisation de l'autre fonction d'affichage par soucis de lisibilité.
            }
            system("cls");
            printf("ATOMICCELLU - LG Corporation (c) - RESULTAT DE LA SIMULATION APRES %d ETAPE(S)\n\n", nbEtapes);
            affichageGrille(&(dixDerniers[nbEtapes-1]));
            printf("\n");
            affichageGrille(grandJeu);
        }
        else if (nbEtapes >= -10 && nbEtapes < 0)
        {
            i = 0;
            sommeNULL = 0;

            for (i = 0; i <= 10; i++)
            {
                if (dixDerniers[i].pointeurCase[0][0] == 'V')
                {
                    sommeNULL++;
                }
            }

            if (sommeNULL == 0)
            {
                grandJeu = &(dixDerniers[10+nbEtapes]);
                affichageGrille(grandJeu);
            }
            else if (sommeNULL > 0)
            {
                if ((10-sommeNULL+nbEtapes) < 0)
                {
                    printf("\nIl n'est pas possible de revenir a cet etat !\n");
                }
                else
                {
                    grandJeu = &(dixDerniers[10-sommeNULL+nbEtapes]); // Trouvé empiriquement
                    affichageGrille(grandJeu);
                }
                affichageGrille(&(dixDerniers[10-sommeNULL]));
                affichageGrille(grandJeu);
            }

            for (i = 0; i <= 10; i++) // Réinitialisation des dix derniers états.
            {
                dixDerniers[i] = *VIDE;
            }
        }

        printf("\n\nQue souhaitez-vous faire ?\n");
        printf("1 - Continuer la simulation\n");
        printf("2 - Sauvegarder cette grille\n");
        printf("3 - Quitter le programme\n");

        scanf("\n%d", &simuPasPas);
        while (getchar() != '\n');
    }

    system("cls");
    printf("ATOMICCELLU - LG Corporation (c) - FERMETURE DU PROGRAMME\n\n");
    printf("Merci d'y avoir joue !");

    libererMemoire(grandJeu); // Libération de la mémoire.
    libererMemoire(VIDE);
    for (i = 0; i <= 10; i++)
    {
        libererMemoire(&(dixDerniers[i]));
    }
    free(&dixDerniers);

    return 0;
}
