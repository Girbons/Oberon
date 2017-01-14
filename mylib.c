#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mylib.h"


static void ins_terra();
static void stampa_percorso();
static void canc_terra();
static void chiudi_percorso();
static void spawn_monster(Mostro_t *monster);

static int count_terre(Terra_t *terra);
static void land_details(Terra_t *terra);
static void initialize_oberon(Oberon_t *oberon);

static void go_forward();
static void get_coins();

static Terra_t *route = NULL;
static Terra_t *last_land = NULL;

static Oberon_t *oberon = NULL;

static bool endGame = false;

static const char *typeLand[] = {"Desert", "Forest", "Swamp", "Village", "Plain"};
static const char *typeMonster[] = {"None", "Skeleton", "Wolf", "Ogre", "Drake"};

/*
TODO: Add docstring for this function
*/
void crea_percorso() {
    system("clear");
    int choice;

    endGame = false;

    do{
        printf("----------------------------\n");
        printf("    What do you want to do? \n");
        printf("----------------------------\n");
        printf("|     [1] Insert a new land | \n");
        printf("|     [2] Remove Land       | \n");
        printf("|     [3] Print the Route   | \n");
        printf("|     [4] Close the Route   | \n");
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
                printf("Insert a valid choice \n");
        }
    }while(!endGame);

}

/*
TODO: Add docstring for this function
*/
static void ins_terra() {
    system("clear");
    Terra_t *terra = malloc(sizeof(Terra_t));

    short coins = 0;

    bool check = false;
    bool isMonsterValid = false;

    // initialization of pointer to the next land
    terra->next = NULL;

    printf("-----------------------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("[%d] %s \n", i, typeLand[i]);
    }
    printf("-----------------------------------\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 0:
            terra->type = Desert;
            printf("Desert inserted \n");
            break;
        case 1:
            terra->type = Forest;
            printf("Forest inserted \n");
            break;
        case 2:
            terra->type = Swamp;
            printf("Swamp inserted \n");
            break;
        case 3:
            terra->type = Village;
            printf("Village inserted \n");
            break;
        case 4:
            terra->type = Plain;
            printf("Plain inserted \n");
            break;
    }

    do{
        printf("Insert coins for this land \n -->");
        scanf("%hd", &coins);
        if(terra->type == Village && coins > 10) {
            printf("--------------------Warning------------------ \n");
            printf("    Village can't contain more than 10 coins  \n");
            printf("--------------------------------------------- \n");
        } else {
            check = true;
            terra->coins = coins;
        }

    }while(check != true);

    if(count_terre(route) == 0) {
        terra->monster.type = None;
        terra->monster.hp = 0;
        terra->monster.damage = 0;
    }

    if(terra->type == Village) {
        terra->monster.type = None;
        terra->monster.hp = 0;
        terra->monster.damage = 0;
    }

    if(terra->type != Village && count_terre(route) > 0) {
        while(isMonsterValid != true) {
            spawn_monster(&(terra)->monster);
            if((terra->type == Swamp && terra->monster.type == Skeleton) || (terra->type == Desert && terra->monster.type == Ogre) ||
                (terra->type == Swamp && terra->monster.type == Wolf) || (terra->type == Desert && terra->monster.type == Wolf)) {
                    printf("--------------------Warning--------------------------- \n");
                    printf("You can't insert %s in %s \n", typeMonster[terra->monster.type], typeLand[terra->type]);
                }
                else {
                    isMonsterValid = true;
                }
        }
    }

    if(route == NULL) {
        route = terra;
    }

    if(last_land != NULL) {
        last_land->next = terra;
    }

    last_land = terra;
    system("clear");
}

/*
TODO: Add docstring for this function
*/
static void canc_terra() {
    if(route == NULL || last_land == NULL) return;

    if(route == last_land) {
        printf("Removing %s \n", typeLand[route->type]);
        free(route);
        route = NULL;
        last_land = NULL;
    }
    else {
        Terra_t *t = route;
        while(t->next != last_land){
            t = t->next;
        }
        printf("Removing %s \n", typeLand[last_land->type]);
        free(last_land);
        last_land = t;
        t->next = NULL;
    }
    system("clear");
}

/*
TODO: Add docstring for this function
*/
static void stampa_percorso() {
    if(route == NULL) {
        printf("There are no land to remove \n");
        return;
    };

    Terra_t *t = route;

    printf("--------------------------------------------- \n");
    while(t != NULL) {
        printf("Land: %s \n", typeLand[t->type]);
        printf("Coins: %hd \n", t->coins);
        printf("Monster: %s \n", typeMonster[t->monster.type]);
        printf("--------------------------------------------- \n");

        t = t->next;
    }
}

/*
TODO: Add docstring for this function
*/
static void chiudi_percorso() {
    endGame = true;
}

/*
TODO: Add docstring for this function
*/
static void spawn_monster(Mostro_t *monster) {
    int choice;

    printf("--------------------------------------------------------  \n"
            "                   CONSTRAINTS                           \n"
            "        Skeleton cannot be inserted in Swamp             \n"
            "        Ogre cannot be inserted in Desert                \n"
            "        Wolf cannot be inserted in Desert or Swamp       \n"
            "-------------------------------------------------------  \n");

    for(int i = 0; i < 5; i++) {
        printf("[%d] %s \n", i, typeMonster[i]);
    }
    printf("-------------------------------------------------- \n");

    printf("Which monster want you insert?  \n");
    scanf("%d", &choice);

    switch(choice) {
        case 0:
            monster->type = None;
            monster->hp = 0;
            monster->damage = 0;
            break;
        case 1:
            monster->type = Skeleton;
            monster->hp = 2;
            monster->damage = 2;
            break;
        case 2:
            monster->type = Wolf;
            monster->hp = 1;
            monster->damage = 1;
            break;
        case 3:
            monster->type = Ogre;
            monster->hp = 3;
            monster->damage = 3;
            break;
        case 4:
            monster->type = Drake;
            monster->hp = 5;
            monster->damage = 5;
            break;
    }
}

/*
TODO: Add docstring for this function
*/
static int count_terre(Terra_t *terra) {
    int count = 0;

    while(terra != NULL) {
        count++;
        terra = terra->next;
    }
    return count;
}

void muovi_oberon() {
    initialize_oberon(oberon);

    system("clear");
    int choice;

    do{
        printf("----------------------------\n");
        printf("    What Oberon has to do?  \n");
        printf("----------------------------\n");
        printf("|     [1] Go Forward        | \n");
        printf("|     [2] Get Coins         | \n");
        printf("|     [3] Use Potions       | \n");
        printf("|     [4] Fight             | \n");
        printf("|     [5] Destroy Land      | \n");
        printf("----------------------------\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                go_forward(route->next);
                break;
            case 2:
                get_coins();
                break;
            case 3:
                printf("Usa pozione \n");
                break;
            case 4:
                printf("Combatti \n");
                break;
            case 5:
                printf("Distruggi Terra \n");
                break;
        }
    }while(true);
}

static void land_details(Terra_t *terra) {
    printf("========================================== \n");
    printf("Land: %s \n", typeLand[terra->type]);
    printf("Monster: %s \n", typeMonster[terra->monster.type]);
    printf("Coins: %d \n", terra->coins);
    printf("========================================== \n");
}

static void initialize_oberon() {
    Oberon_t *ober = malloc(sizeof(Oberon_t));
    ober->bag_gold = 10;
    ober->hp = 5;
    ober->spells = 2;
    ober->health_potion = 2;

    oberon = ober;
}

static void go_forward() {
    Terra_t *terra = route;

    printf("========================================== \n");
    printf("Land: %s \n", typeLand[terra->type]);
    printf("Monster: %s \n", typeMonster[terra->monster.type]);
    printf("Coins: %d \n", terra->coins);
    printf("========================================== \n");

    if(terra->monster.type == Drake && terra->monster.hp > 0) {
        printf("You can't skip this land \n");
        printf("You have to fight this %s \n", typeMonster[terra->monster.type]);
        return;
    } else {
        if(route->next != NULL) {
            route = route->next;
        }
    }
}

static void get_coins() {
    Terra_t *terra = route;

    if(terra->coins > 0 && oberon->bag_gold < 500) {
        oberon->bag_gold += terra->coins;
        printf("Oberon collect: %hd coins \n", terra->coins);
        printf("Oberon's gold: %hd \n", oberon->bag_gold);
        terra->coins = 0;
    }

    if(terra->coins == 0) {
        printf("There are 0 coin in this land... \n");
    }

    if(oberon->bag_gold >= 500) {
        printf("Oberon's bag is full of coins \n");
    }
}

// static void use_potion() {
// }

// static void fight() {
// }

// static void destroy_land() {
// }