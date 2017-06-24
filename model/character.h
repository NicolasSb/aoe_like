#ifndef CHAR_H
#define CHAR_H

typedef struct Target_s Target_s;
struct Target_s{
    int type;
    void *t;
};


enum {
    WAIT, MOVE, ATTACK, COLLECT, BUILD, CONSTRUCT, DO_NOTHING
};

enum target_t{
    TARGET_INVALID=0,
    TARGET_RESSOURCE,
    TARGET_PERSO,
    TARGET_BUILDING,
    TARGET_ANIMALS
};

#endif // CHAR_H
