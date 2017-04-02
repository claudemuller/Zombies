#ifndef _ENEMY_H
#define _ENEMY_H

#include <SDL2/SDL.h>

extern struct Enemy {
    int w, h;
    float x, y;
    float dx, dy;
    const char* filename;
    SDL_Texture* texture;

    void (*init)(struct Enemy*);
    void (*render)(struct Enemy*);
    void (*update)(struct Enemy*);
};

void enemy_init(struct Enemy*);
void enemy_render(struct Enemy*);
void enemy_update(struct Enemy*);
void detectCollision(struct Enemy*);

#endif //_ENEMY_H
