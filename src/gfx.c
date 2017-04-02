#include "game.h"
#include "enemy.h"

extern struct Game Game;
extern struct Player Player;
extern struct Enemy Enemy;

void gfx_render()
{
    SDL_SetRenderDrawColor(Game.screen.renderer, 0, 0, 0, 255);
    SDL_RenderClear(Game.screen.renderer);

    Player.render();
    Enemy.render();

    SDL_RenderPresent(Game.screen.renderer);
}

SDL_Texture* gfx_buildSprite(const char* name)
{
    SDL_Surface* surface = IMG_Load(name);
    if (surface == NULL) error("Could not load image");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game.screen.renderer, surface);
    if (surface) SDL_FreeSurface(surface);

    return tex;
}

void gfx_destroySprite(SDL_Texture* tex)
{
    SDL_DestroyTexture(tex);
}

