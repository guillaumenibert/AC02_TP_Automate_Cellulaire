[![](https://img.shields.io/github/license/MCDoors/AC02_TP_Automate_Cellulaire.svg)](https://github.com/MCDoors/AC02_TP_Automate_Cellulaire/blob/master/LICENSE)

# ATOMICCELLU - LG Corporation (c) - Projet AC02 - v1.0.2

Création d'un automate cellulaire en C, comprenant les fonctionnalités décrites dans le TP.

## Compilation du programme

Utilisation du compilateur [GCC](https://gcc.gnu.org/)

## Utilisation du programme sous Linux

Après compilation du programme, ouvrez une invite de commande `cmd` et déplacez vous dans le répertoire où se situe le programme et le dossier de sauvegardes `sauvegardes`.

```sh
cd repertoire_de_travail
```
Lancez le programme avec les paramètres voulus (`-load` ou `-new`) :

### Paramètre `-new`
Pour créer une nouvelle grille on utilise le paramètre `-new` :

####  Linux 32 bits
```sh
./ATOMICCELLU_v1.0.2_IA-32 -new
```
#### Linux 64 bits
```sh
./ATOMICCELLU_v1.0.2_x86-64 -new
```

### Paramètre `-load`
Pour charger une grille sauvegardée au format `.txt` dans le répertoire `sauvegardes`, on utilise le paramètre `-load` :

#### Linux 32 bits
```sh
./ATOMICCELLU_v1.0.2_IA-32 -load
```
#### Linux 64 bits
```sh
./ATOMICCELLU_v1.0.2_x86-64 -load
```


## Utilisation du programme sous Windows

Après compilation du programme, ouvrez une invite de commande `cmd` et déplacez vous dans le répertoire où se situe le programme et le dossier de sauvegardes `sauvegardes`.

```bat
cd repertoire_de_travail
```
Lancez le programme avec les paramètres voulus (`-load` ou `-new`) :

### Paramètre `-new`
Pour créer une nouvelle grille on utilise le paramètre `-new` :

####  Windows 32 bits
```bat
ATOMICCELLU_v1.0.2_IA-32.exe -new
```
#### Windows 64 bits
```bat
ATOMICCELLU_v1.0.2_x86-64.exe -new
```

### Paramètre `-load`
Pour charger une grille sauvegardée au format `.txt` dans le répertoire `sauvegardes`, on utilise le paramètre `-load` :

#### Windows 32 bits
```bat
ATOMICCELLU_v1.0.2_IA-32.exe -load
```
#### Windows 64 bits
```bat
ATOMICCELLU_v1.0.2_x86-64.exe -load
```

## Version compilée

Des versions compilées du programme pour Linux et Windows sont disponibles dans la section [Releases](https://github.com/MCDoors/AC02_TP_Automate_Cellulaire/releases).

## Licence

[MIT](https://github.com/MCDoors/AC02_TP_Automate_Cellulaire/blob/master/LICENSE)
