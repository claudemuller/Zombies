#include "game.h"

extern struct Game Game;
extern struct Player Player;

void gfx_render()
{
    SDL_SetRenderDrawColor(Game.screen.renderer, 0, 0, 0, 255);
    SDL_RenderClear(Game.screen.renderer);

    Player.render();

    // Render enemies
    for (int i = 0; i < NUM_OF_ENEMIES; i++) {
        Game.enemies[i].render(&Game.enemies[i]);
    }

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

