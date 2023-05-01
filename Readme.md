# It takes IO 

_It takes IO_ est un jeu de plateforme à deux joueurs. Ceux-ci doivent évoluer à travers les différents niveaux pour ouvrir la porte principale et accéder au niveau suivant. Ce jeu est basé sur un ensemble d'énigmes à résoudre pour activer des portes logiques. Les deux personnages incarnés sont ainsi complémentaires en représentant un 0 et un 1. Le but est ainsi de coopérer pour terminer tous les niveaux en trouvant la bonne combinaison pour déverrouiller la porte et en évitant les obstacles.

## Pour commencer

### Organisation des fichiers de notre archive

Notre code est construit de manière à avoir les fonctionalités de base regroupées dans des classes noyau, puis, d'avoir une surcouche pour l'affichage texte et SFML.

L'organistion des fichiers est la suivante.

- **It-Takes-IO/src/core** : les classes de base du jeu qui compile sans aucune dépendance.
- **It-Takes-IO/src/sfml** : les classes s'occupant de faire fonctionner le jeu et de l'afficher avec SFML.
- **It-Takes-IO/src/sfml/menu** : les classes s'occupant de faire fonctionner le menu et de l'afficher avec SFML.
- **It-Takes-IO/src/txt** : les classes s'occupant de faire fonctionner le jeu et de l'afficher en version console.

- **It-Takes-IO/data** : les assets du jeu.
- **It-Takes-IO/data/blocks** : les images des différents blocks à afficher.
- **It-Takes-IO/data/bruitages** : les sons utilisés dans le jeu.
- **It-Takes-IO/data/levels** : les fichiers .txt des niveaux.
- **It-Takes-IO/data/menu** : les images utilisés dans le menu _Manuel_ du jeu.
- **It-Takes-IO/data/object** : les images des différents objets à afficher.
- **It-Takes-IO/data/player** : les sprites des deux personnages pour réaliser les animations.
- **It-Takes-IO/data/preview** : les images des previews des niveaux dans le menu _Select level_.

- **It-Takes-IO/bin** : répertoire où les executables seront compilés.

- **It-Takes-IO/obj** : répertoire comportant les compilations intermédiaires (.o).

- **It-Takes-IO/extern** : répertoire comprtant la librairie SFML afin de permettre l'affichage graphique du jeu.

- **It-Takes-IO/doc** : la documentation de notre projet 
- **It-Takes-IO/doc/html** : la documentation du code générée par doxygen.

- **It-Takes-IO/Makefile** : permet d'effectuer toute le phase de compilation de notre code.

### Compilation du programme

#### Version Texte 
Pour effectuer la compilation du programme, vous devez exécuter la commande `make txt`

#### Version SFML
Pour effectuer la compilation du programme, vous devez exécuter la commande `make`

> Si cela ne fontcionne pas, il faudra installer la librairie SFML à la main avant de pouvoir compiler notre programme. 

## Exécution et démarrage du jeu 

### Version Texte 
Pour procéder à l'exécution, il suffit d'exécuter `bin/main_txt`

### Version SFML

Puis, pour procéder à l'exécution, il suffit d'exécuter `bin/main_sfml`

> Si cela ne fontcionne pas, il faudra installer la librairie SFML à la main avant de pouvoir compiler notre programme. 

### Comment jouer 

- Après le lancement du jeu, vous apparaîssez alors dans le niveau 0.
- Déplacez les personnages et activez les boutons en vous plaçant simplement au-dessus.
- Récupérez des objets au sol pour les déplacer où vous le souhaiter. 
- Vous pouvez sélectionner le niveau souhaité dans le menu _Select Level_.
- Activez les portes logiques en vous plaçant sur les boutons. Vous trouverez un manuel d'explications pour les différentes portes logiques dans le menu _Manuel_. 
- Trouvez la bonne combinaison afin d'envoyer du courant de type 1 dans la porte finale pour la dévérouiller. Cela vous permettra de passer au niveau suivant.
- Si l'un des deux joueurs meurt au cours d'un niveau, celui-ci se réinitialise. 

#### Commandes 

Pour accéder au menu du jeu : `ECHAP`

Pour le joueur 0 : 
- Aller vers la gauche `Q`
- Aller vers la droite `D`
- Sauter `Z`
- Récuperer un objet sur le sol `S`

Pour le joueur 1 : 
- Aller vers la gauche `◄`
- Aller vers la droite `►`
- Sauter `▲`
- Récuperer un objet sur le sol `▼`

> **Tip :** n'oubliez pas d'activer le son afin de profiter de la musique du jeu

## Auteurs

* **HONORÉ Alexandre** p2107949
* **SITHIDEJ Clara** p2101573

Le jeu porte l'indentifiant 27901 sur la forge de Lyon 1, pour le retrouver [cliquez ici](https://forge.univ-lyon1.fr/p2107949/It-Takes-IO).






