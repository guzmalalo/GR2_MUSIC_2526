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
void addFirst(Musique ** playlist, char artiste[30], char titre[50], int duree);
void afficher(Musique * playlist);

#endif