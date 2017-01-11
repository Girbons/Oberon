#include "mylib.c"


int main() {
    int choice;

    do{
        printf("Cosa vuoi fare ? \n");
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
                printf("Muovi Oberon \n");
                muovi_oberon();
                break;
            case 3:
                // TODO add function termina_gioco()
                printf("Termina Gioco \n");
                break;
        }
    }while(choice != 3);
}
