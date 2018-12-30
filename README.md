# ATTOMICCELLU - LG Corporation (c) - Projet AC02

Création d'un automate cellulaire en C, comprenant les fonctionnalités décrites dans le TP.

## Compilation du programme

Utilisation du compilateur [MinGW](http://mingw.org/) présent dans [Code::Blocks](http://www.codeblocks.org/) ou [CLion](https://www.jetbrains.com/clion/)

## Utilisation du programme sous Windows

Après compilation du programme, déplacez vous dans le répertoire où se situe le programme `ATOMICCELLU.exe` et le dossier de sauvegardes `sauvegardes`.

```bat
cd repertoire_de_travail
```
Lancez le programme avec les paramètres voulus (`-load` ou `-new`) :

#### Paramètre `-new`
Pour créer une nouvelle grille on utilise le paramètre `-new` :

```bat
ATTOMICCELLU.exe new
```

#### Paramètre `-load`
Pour charger une grille sauvegardée au format `.txt` dans le répertoire `sauvegardes`, on utilise le paramètre `-load` :

```bat
ATTOMICCELLU.exe load
```
