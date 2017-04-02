#ifndef _ENEMY_H
#define _ENEMY_H

extern struct Enemy {
    int w, h;
    float x, y;
    float dx, dy;
    const char* filename;

    void (*render)(struct Enemy*);
    void (*update)(struct Enemy*);
};

void enemy_render(struct Enemy*);
void enemy_update(struct Enemy*);
void detectCollision(struct Enemy*);

#endif //_ENEMY_H
