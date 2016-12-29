typedef enum TipoMostro {
    None,
    Scheletro,
    Lupo,
    Orco,
    Drago,
} TipoMostro_t;

typedef enum TipoTerra {
    Deserto,
    Foresta,
    Palude,
    Villaggio,
    Pianura,
} TipoTerra_t;

typedef struct Mostro {
    TipoMostro_t tipo;
    int hp;
    int danno;
} Mostro_t;

typedef struct Terra {
    TipoTerra_t tipo;
    Mostro_t mostro;
    struct Terra* successiva;
} Terra_t;
