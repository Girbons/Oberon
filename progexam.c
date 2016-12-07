#include <stdio.h>
#include <stdbool.h>

int main() {
    int choice = 0;

    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                    [1] CREA PERCORSO                                        |\n");
    printf("|                    [2] MUOVI OBERON                                         |\n");
    printf("|                    [3] TERMINA GIOCO                                        |\n");
    printf("+-----------------------------------------------------------------------------+\n");

    do{

        printf("Cosa vuoi fare ? ");
        scanf(" %d ", &choice);

        switch(choice){
            case 1:
                // TODO add function crea_percorso()
                printf("Crea percorso \n");
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
