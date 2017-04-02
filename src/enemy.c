#include "enemy.h"
#include "game.h"

extern struct Game Game;

struct Enemy Enemy = {
    15 * SCREEN_SCALE,
    46 * SCREEN_SCALE,
    10,
    10,
    0,
    0,
    "girl_1.png",

    enemy_render,
    enemy_update
};

void enemy_render()
{
    SDL_Texture* tex = Game.gfx.buildSprite(Enemy.filename);
    SDL_Rect rect = {(int)Enemy.x, (int)Enemy.y, Enemy.w, Enemy.h};
    Game.screen.drawSprite(tex, &rect);
}

void enemy_update()
{
    Enemy.x = Enemy.x + Enemy.dx;
    Enemy.y = Enemy.y + Enemy.dy;
}
