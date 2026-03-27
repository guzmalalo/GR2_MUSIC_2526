#include "musique.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Musique * createMusic(char artiste[30], char titre[50], int duree) {
    // Creation dynamique
    Musique * newMusique = malloc(sizeof(Musique));

    // initialisation
    newMusique->duree = duree;
    strcpy(newMusique->artiste, artiste);
    strcpy(newMusique->titre, titre);
    newMusique->suiv =NULL;

    return newMusique;
}

void addFirst(Musique ** pPlaylist, char artiste[30], char titre[50], int duree) {
    // creation d'un maillon
    Musique * newMusique = createMusic(artiste, titre, duree);

    if (*pPlaylist == NULL) {
        *pPlaylist = newMusique;
    }else {
        newMusique->suiv = *pPlaylist;
        *pPlaylist = newMusique;
    }
}

void afficher(Musique * playList) {
    while (playList != NULL) {
        printf("Titre   : %s\n", playList->titre);
        printf("Artiste : %s\n", playList->artiste);
        printf("Duree   : %d\n", playList->duree);
        printf("----\n");

        playList= playList->suiv;
    }
}

void liberer(Musique ** head) {
    Musique * temp = NULL;

    while (*head !=NULL) {
        temp = *head;
        *head = (*head)->suiv;
        free(temp);
    }
    *head = NULL;
}


void addLast(Musique ** head, char artiste[30], char titre[50], int duree) {
    Musique* new =  createMusic(artiste, titre, duree);
    Musique* last = NULL;

    if (*head == NULL) {
        *head = new;
    }else {
        last = *head;
        while (last->suiv !=NULL) {
            last= last->suiv;
        }
        last->suiv = new;
    }
}
