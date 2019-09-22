<h1 align="center">Wolf 3d (WIP 🚧)</h1>

Le projet Wolf 3d est une version simplifiée du célèbre jeu "Wolfenstein 3D" d'Id Software. Il permet d'aller un peu plus loin dans la compréhension de la programmation graphique. Gestion d'évènements plus complexe, utilisation des textures, du son etc. C'est aussi l'occasion de mettre en application des concepts mathématiques dans un jeu pour créer des algorithmes efficaces et bien conçus.

## Installation

NB: Le projet compile la libraire graphique SDL depuis ses sources. Cela peut prendre quelques minutes.

```sh
https://github.com/brpinto/wolf3d.git
make
```

## Usage

Les cartes jouables se trouvent dans le dossier maps.

```sh
./wolf3d [map]
```

## Makefile

```sh
make clean
```
Supprime les dossiers obj contenant les fichiers .o nécessaires à la compilation

```sh
make fclean
```
Supprime le dossier obj ainsi que l'executable du projet

```sh
make fcleansdl
```
Supprime les sources de la SDL

```sh
make re
```
Exécute les règles clean et fclean et recompile le projet (make)

```sh
make resdl
```
Exécute les règles fcleansdl et all et recompile le projet (make) ainsi que la SDL

## Controles

ESC : Fermer la fenêtre <br />
W: Déplacer le joueur vers l'avant <br />
A: Déplacer le joueur vers la gauche <br />
S: Déplacer le joueur vers le bas <br />
D: Déplacer le joueur vers la droite <br />
Q: Rotation de la caméra vers la gauche <br />
E: Rotation de la caméra vers la droit <br />

La souris peut également servir à faire pivoter la caméra, comme dans un FPS.
