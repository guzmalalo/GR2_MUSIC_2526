#include "musique.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Musique *createMusic(char artiste[30], char titre[50], int duree) {
    // Creation dynamique
    Musique *newMusique = malloc(sizeof(Musique));

    // Initialisation
    newMusique->duree = duree;
    strcpy(newMusique->artiste, artiste);
    strcpy(newMusique->titre, titre);

    newMusique->suiv = NULL;
    newMusique->prec = NULL;

    return newMusique;
}

// Ajout en tête
void addFirst(Musique **pPlaylist, char artiste[30], char titre[50], int duree) {
    // creation d'un maillon (une chanson)
    Musique *newMusique = createMusic(artiste, titre, duree);

    if (*pPlaylist == NULL) {
        *pPlaylist = newMusique;
        newMusique->suiv = newMusique;
        newMusique->prec = newMusique;
    } else {
        (*pPlaylist)->prec->suiv = newMusique;
        newMusique->prec =(*pPlaylist)->prec;
        (*pPlaylist)->prec = newMusique;
        newMusique->suiv = (*pPlaylist);

        *pPlaylist = newMusique;
    }
}

// Ajout à la fin
void addLast(Musique **head, char artiste[30], char titre[50], int duree) {
    Musique *newMusique = createMusic(artiste, titre, duree);
    Musique *last = NULL;

    if (*head == NULL) {
        *head = newMusique;
        newMusique->suiv = newMusique;
        newMusique->prec = newMusique;
    } else {
        (*head)->prec->suiv = newMusique;
        newMusique->prec =(*head)->prec;
        (*head)->prec = newMusique;
        newMusique->suiv = (*head);
    }
}

void afficher(Musique *playList) {

    if (playList == NULL) {
        printf("La liste es vide");
        return;
    }

    Musique* parcours = playList;
    while (parcours->suiv != playList) {
        printf("Titre   : %s\n", parcours->titre);
        printf("Artiste : %s\n", parcours->artiste);
        printf("Duree   : %d\n", parcours->duree / 60);
        printf("---\n");

        parcours = parcours->suiv;
    }
}

void playNow(Musique *playlist) {
    int choice = 1;
    Musique *current = playlist;

    if (current == NULL) {
        printf("Playlist vide ...\n");
        return;
    }

    printf("Lecture en cours...\n\n");

    while (current != NULL && choice != 0) {
        // affichage de la chanson
        printf("> %s - %s (%d sec)\n", current->titre, current->artiste, current->duree);
        printf("1: Next | 2: Prev | 0: Quit \n");
        scanf("%d", &choice);

        // choix
        switch (choice) {
            case 0:
                printf("Lecture arrêtée\n");
                break;
            case 1:
                current = current->suiv;
                break;
            case 2:
                current = current->prec;
                break;
            default:
                printf("Choix inconnu\n");
        }
    }

    if (current == NULL) {
        printf("\nFin de la playlist.\n");
    }
}


void liberer(Musique **head) {
    // si la liste est vide
    if (*head == NULL) {
        return;
    }

    Musique *parcours = (*head)->suiv;
    while (parcours != *head) {
        Musique * aEffacer = parcours;
        parcours = parcours ->suiv;
        free(aEffacer);
    }

    free(*head);
    *head = NULL;
}
