#ifndef _PLAYER_H
#define _PLAYER_H

#include <SDL2/SDL.h>

extern struct Player {
    int w, h;
    float x, y;
    float dx, dy;
    float speed;
    const char* filename;
    SDL_Texture* texture;

    void (*init)(void);
    void (*render)(void);
    void (*update)(void);
};

void player_init(void);
void player_render(void);
void player_update(void);

#endif //_PLAYER_H
