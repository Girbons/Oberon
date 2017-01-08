#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "mylib.h"


static void ins_terra();
static void stampa_percorso();
static void canc_terra();
static void chiudi_percorso();
static void spawn_monster(Mostro_t *monster);
static int count_terre(Terra_t *terra);

static Terra_t *route = NULL;
static Terra_t *last_land = NULL;

static Oberon_t *oberon;

static bool endGame = false;
bool validateMonster = false;

static const char *typeLand[] = {"Desert", "Forest", "Swamp", "Villagge", "Plain"};
static const char *typeMonster[] = {"Skeleton", "Wolf", "Ogre", "Drake"};

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
    terra->next = NULL;

    printf("-----------------------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("[%d] per inserire %s \n", i, typeLand[i]);
    }
    printf("-----------------------------------\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 0:
            terra->type = Desert;
            printf("Inserimento di Deserto \n");
            break;
        case 1:
            terra->type = Swamp;
            printf("Inserimento di Palude \n");
            break;
        case 2:
            terra->type = Village;
            printf("Inserimento di Villaggio \n");
            break;
        case 3:
            terra->type = Plain;
            printf("Inserimento di Pianura \n");
            break;
        case 4:
            terra->type = Forest;
            printf("Inserimento di Foresta \n");
            break;
    }

   // if(terra->type != Village && count_terre(route) > 0) {
        spawn_monster(&(terra)->monster);
    //}

    if(route == NULL) {
        route = terra;
    }

    if(last_land != NULL) {
        last_land->next = terra;
    }

    last_land = terra;
}

static void canc_terra() {
    if(route == NULL || last_land == NULL) return;

    if(route == last_land) {
        printf("Rimozione di %s \n", typeLand[route->type]);
        free(route);
        route = NULL;
        last_land = NULL;
    }
    else {
        Terra_t *t = route;
        while(t->next != last_land){
            t = t->next;
        }
        printf("Rimozione di %s \n", typeLand[last_land->type]);
        free(last_land);
        last_land = t;
        t->next = NULL;
    }
}


static void stampa_percorso() {
    // TODO: this function should print all the info
    if(route == NULL) {
        printf("Non sono presenti terre da rimuovere \n");
        return;
    };

    Terra_t *t = route;

    while(t != NULL) {
        printf("Terra: %s \n", typeLand[t->type]);
        printf("Mostro: %s \n", typeMonster[t->monster.type]);
        // todo add oro presente in questa terra
        t = t->next;
    }
}


static void chiudi_percorso() {
    endGame = true;
}

static void spawn_monster(Mostro_t *monster) {
    int choice;

    printf("-------------------------------------------------------- \n"
            "Scheletro/Skeleton non puo' essere inserito in Palude \n"
            "Orco/Ogre non puo' essere inserito in Deserto \n"
            "Lupo non pu'o essere inserito in Deserto o Palude \n"
            "---------------------------------------------------- \n");

    for(int i = 0; i < 4; i++) {
        printf("[%d] per inserire %s \n", i, typeMonster[i]);
    }
    printf("Quale mostro vuoi inserire ? \n");
    scanf("[%d]", &choice);
    printf("---------------------------------------------------- \n");

    switch(choice) {
        case 0:
            monster->type = Skeleton;
            monster->hp = 2;
            monster->damage = 2;
            break;
        case 1:
            monster->type = Wolf;
            monster->hp = 1;
            monster->damage = 1;
            break;
        case 2:
            monster->type = Ogre;
            monster->hp = 3;
            monster->damage = 3;
            break;
        case 3:
            monster->type = Dragon;
            monster->hp = 5;
            monster->damage = 5;
            break;
    }
}

static int count_terre(Terra_t *terra) {
    int count = 0;

    while(terra != NULL) {
        count++;
        terra = terra->next;
    }
    return count;
}