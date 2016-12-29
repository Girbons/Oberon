#include <stdio.h>
#include <stdbool.h>
#include "mylib.c"

int main() {
    int choice;

    do{
        printf("Cosa vuoi fare ?");
        printf("+-----------------------------------------------------------------------------+\n");
        printf("|                    [1] CREA PERCORSO                                        |\n");
        printf("|                    [2] MUOVI OBERON                                         |\n");
        printf("|                    [3] TERMINA GIOCO                                        |\n");
        printf("+-----------------------------------------------------------------------------+\n");


        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Crea percorso \n");
                crea_percorso();
                break;
            case 2:
                // TODO add function muovi_oberon()
                printf("Muovi Oberon \n");
                break;
            case 3:
                // TODO add function termina_gioco()
                printf("Termina Gioco \n");
                break;
        }
    }while(choice != 3);
}
