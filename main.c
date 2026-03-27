#include <stdio.h>
#include "musique.h"

int main(void) {
    Musique * playlist=NULL;
    addFirst(&playlist, "ACDC", "TNT", 120);
    addFirst(&playlist, "Shakira", "Waka Waka", 120);
    addFirst(&playlist, "Cold Play", "Scientist", 120);

    afficher(playlist);

    return 0;
}
