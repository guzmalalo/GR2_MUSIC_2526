#include <stdio.h>
#include "musique.h"

int main(void) {
    // tete de la liste chainée
    Musique *playlist = NULL;

    // Ajout en tête
    addFirst(&playlist, "Computer Love", "Kraftwerk", 450);
    addFirst(&playlist, "Digital Love", "Daft Punk", 300);
    addFirst(&playlist, "Voyager", "Daft Punk", 225);

    // Ajout à la fin
    addLast(&playlist, "Computer World", "Kraftwerk", 330);
    addLast(&playlist, "Algorithm", "Muse", 300);

    // affichage de la playlist
    afficher(playlist);

    // simulation de lecture
    playNow(playlist);

    // Liberation dynamique
    liberer(&playlist);
    return 0;
}
