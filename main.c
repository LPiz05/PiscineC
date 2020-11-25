#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traitement.h"


int main() {

    char scan;
    char **files;

    do {
        system("cls||clear");
        printf("Veuillez choisir une option :\n\n"
               "- Traiter un fichier (1)\n\n"
               "- Quitter le programme (0)\n\n"
               "Votre choix : ");
        scanf("%c", &scan); //on récup qu'un charactere comme ça c'est plus optimiser
        fflush(stdin);

        if (scan == '1'){
            files = takeNameFiles();
            system("cls||clear");
            printf("file 1 : %s\n file 2 : %s\n", files[0], files[1]);

            // TODO: Faire traitement pour retrouver les données de chaque fichier


        }
    } while (scan != '0');

    return 0;
}
