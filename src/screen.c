#include "game.h"

extern struct Game Game;

void screen_drawSprite(SDL_Texture* spr, SDL_Rect* rect)
{
    SDL_RenderCopy(Game.screen.renderer, spr, NULL, rect);
}

