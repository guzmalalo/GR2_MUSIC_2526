#ifndef MUSIQUE_H
#define MUSIQUE_H

// node / noued / maillon

struct musique {
    char titre[50];
    char artiste[30];
    int  duree;

    struct musique * suiv;
};
typedef struct musique Musique;

Musique * createMusic(char artiste[30], char titre[50], int duree);

// Ajout
void addFirst(Musique ** playlist, char artiste[30], char titre[50], int duree);
void addLast(Musique ** playlist, char artiste[30], char titre[50], int duree);

// Affichage et lecture
void afficher(Musique * playlist);
void playNow(Musique* playlist);

// Liberation
void liberer(Musique ** playlist);

// utilités
int dureePlayList(Musique *playlist);


// à faire chez vous
void effacerParArtiste(Musique ** playlist, char artiste[30]);
void effacerParTitre(Musique ** playlist, char artiste[30]);
void classerParDuree(Musique *playlist);

#endif