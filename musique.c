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

    return newMusique;
}

// Ajout en tête
void addFirst(Musique **pPlaylist, char artiste[30], char titre[50], int duree) {
    // creation d'un maillon (une chanson)
    Musique *newMusique = createMusic(artiste, titre, duree);

    if (*pPlaylist == NULL) {
        *pPlaylist = newMusique;
    } else {
        newMusique->suiv = *pPlaylist;
        *pPlaylist = newMusique;
    }
}

// Ajout à la fin
void addLast(Musique **head, char artiste[30], char titre[50], int duree) {
    Musique *new = createMusic(artiste, titre, duree);
    Musique *last = NULL;

    if (*head == NULL) {
        *head = new;
    } else {
        last = *head;
        while (last->suiv != NULL) {
            last = last->suiv;
        }
        last->suiv = new;
    }
}

void afficher(Musique *playList) {
    while (playList != NULL) {
        printf("Titre   : %s\n", playList->titre);
        printf("Artiste : %s\n", playList->artiste);
        printf("Duree   : %d\n", playList->duree / 60);
        printf("---\n");

        playList = playList->suiv;
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
        printf("1: Next | 0: Quit \n");
        scanf("%d", &choice);

        // choix
        switch (choice) {
            case 0:
                printf("Lecture arrêtée\n");
                break;
            case 1:
                current = current->suiv;
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
    Musique *temp = NULL;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->suiv;
        free(temp);
    }
    *head = NULL;
}
