typedef enum TipoMostro {
    Skeleton,
    Wolf,
    Ogre,
    Dragon,
} TipoMostro_t;

typedef enum TipoTerra {
    Desert,
    Forest,
    Swamp,
    Village,
    Plain,
} TipoTerra_t;

typedef struct Mostro {
    TipoMostro_t type;
    int hp;
    int damage;
} Mostro_t;

typedef struct Terra {
    TipoTerra_t type;
    Mostro_t monster;
    short treasure;
    struct Terra *next;
} Terra_t;

typedef struct Oberon {
    short bag_gold;
    short hit_points;
    short spells;
    short health_potion;
} Oberon_t;
