#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mylib.h"


static void ins_terra();
static void stampa_percorso();
static void canc_terra();
static void chiudi_percorso();

static Terra_t *percorso = NULL;
static Terra_t *ultima_terra = NULL;

static bool endGame = false;

static const char *tipiTerra[] = {"Deserto", "Palude", "Villaggio", "Pianura", "Foresta"};
static const char *tipiMostro[] = {"None", "Scheletro", "Lupo", "Orco", "Drago"};

void crea_percorso(){
    int choice;

    endGame = false;

    do{
        printf("----------------------------\n");
        printf("      Cosa vuoi fare        \n");
        printf("----------------------------\n");
        printf("|     [1] Inserisci terra | \n");
        printf("|     [2] Cancella terra  | \n");
        printf("|     [3] Stampa Percorso | \n");
        printf("|     [4] chiudi percorso | \n");
        printf("----------------------------\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                ins_terra();
                break;
            case 2:
                canc_terra();
                break;
            case 3:
                stampa_percorso();
                break;
            case 4:
                chiudi_percorso();
                break;
            default:
                printf("Inserire una scelta valida");
        }
    }while(!endGame);

}

static void ins_terra() {
    Terra_t *terra = malloc(sizeof(Terra_t));
    terra->successiva = NULL;

    printf("-----------------------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("[%d] per inserire %s \n", i, tipiTerra[i]);
    }
    printf("-----------------------------------\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 0:
            terra->tipo = Deserto;
            printf("Inserimento di %s \n", tipiTerra[0]);
            break;
        case 1:
            terra->tipo = Palude;
            printf("Inserimento di %s \n", tipiTerra[1]);
            break;
        case 2:
            terra->tipo = Villaggio;
            printf("Inserimento di %s \n", tipiTerra[2]);
            break;
        case 3:
            terra->tipo = Pianura;
            printf("Inserimento di %s \n", tipiTerra[3]);
            break;
        case 4:
            terra->tipo = Foresta;
            printf("Inserimento di %s \n", tipiTerra[4]);
            break;
    }
    if(percorso == NULL) {
        percorso = terra;
    }

    if(ultima_terra != NULL) {
        ultima_terra->successiva = terra;
    }

    ultima_terra = terra;
}

static void canc_terra() {
    if(percorso == NULL || ultima_terra == NULL) return;

    if(percorso == ultima_terra) {
        printf("Rimozione di %s \n", tipiTerra[percorso->tipo]);
        free(percorso);
        percorso = NULL;
        ultima_terra = NULL;
    }
    else {
        Terra_t *t = percorso;
        while(t->successiva != ultima_terra){
            t = t->successiva;
        }
        printf("Rimozione di %s \n", tipiTerra[ultima_terra->tipo]);
        free(ultima_terra);
        ultima_terra = t;
        t->successiva = NULL;
    }
}


static void stampa_percorso() {
    // TODO: this function should print all the info
    if(percorso == NULL) return;

    Terra_t *t = percorso;
    int c = 1;

    printf("Percorso Creato: \n");
    do{
        printf("Terra %d %s \n", c++, tipiTerra[t->tipo]);
    }while((t = t->successiva) != NULL);
}


static void chiudi_percorso() {
    endGame = true;
}

