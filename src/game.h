#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "player.h"

#define SCREEN_SCALE 1
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_NAME "Zombies"

void game_init(void);
void game_shutdown(int);
void game_update(void);
void game_processEvents(void);
void screen_drawSprite(SDL_Texture*, SDL_Rect*);
void gfx_render(void);
SDL_Texture* gfx_buildSprite(const char* name);
void gfx_destroySprite(SDL_Texture* spr);
void error(const char*);

extern struct Game {
    int running;

    struct {
        unsigned int w;
        unsigned int h;
        const char *name;
        SDL_Window *window;
        SDL_Renderer *renderer;

        void (*drawSprite)(SDL_Texture *spr, SDL_Rect *rect);
    } screen;

    struct {
        void (*render)(void);
        SDL_Texture *(*buildSprite)(const char* name);
        void (*destroySprite)(SDL_Texture *spr);
    } gfx;

    void (*init)(void);
    void (*update)(void);
    void (*shutdown)(int);
    void (*processEvents)(void);
};

#endif //_GAME_H
