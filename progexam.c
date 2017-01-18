#include "mylib.c"


int main() {
    int choice;

    do{
        printf("What do you want to do ? \n");
        printf("+-----------------------------------------------------------------------------+\n");
        printf("|                    [1] Create Route                                          |\n");
        printf("|                    [2] Move Oberon                                           |\n");
        printf("|                    [3] End Game                                              |\n");
        printf("+-----------------------------------------------------------------------------+\n");


        scanf("%d", &choice);

        switch(choice){
            case 1:
                crea_percorso();
                break;
            case 2:
                muovi_oberon();
                break;
            case 3:
                termina_gioco();
                break;
            default:
                printf("Insert a valid chocice \n");
        }
    }while(choice != 3);
}
