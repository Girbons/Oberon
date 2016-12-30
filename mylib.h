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
    short tesoro;
    struct Terra *successiva;
} Terra_t;

typedef struct Oberon {
    short borsa_oro;
    short punti_ferita;
    short incantesimi;
    short pozione_guarigione;
} Oberon_t;
