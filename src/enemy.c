#include "enemy.h"
#include "game.h"

extern struct Game Game;

//struct Enemy Enemy = {
//    15 * SCREEN_SCALE,
//    46 * SCREEN_SCALE,
//    10,
//    10,
//    0,
//    0,
//    2.0f,
//    "girl_1.png",
//
//    enemy_render,
//    enemy_update
//};

void enemy_render(struct Enemy* enemy)
{
    SDL_Texture* tex = Game.gfx.buildSprite(enemy->filename);
    SDL_Rect rect = {(int)enemy->x, (int)enemy->y, enemy->w, enemy->h};
    Game.screen.drawSprite(tex, &rect);
}

void enemy_update()
{
//    Enemy.dy = Enemy.speed;
//    Enemy.dx = Enemy.speed;
//    Enemy.x = Enemy.x + Enemy.dx;
//    Enemy.y = Enemy.y + Enemy.dy;
//
//    detectCollision();
}

void detectCollision()
{
//   if (Enemy.x < 0) Enemy.dx = -1 * Enemy.speed;
//   else if (Enemy.x > Game.screen.w - Enemy.w) Enemy.dx = -1 * Enemy.speed;
//   else if (Enemy.y < 0) Enemy.dy = -1 * Enemy.speed;
//   else if (Enemy.y > Game.screen.h - Enemy.h) Enemy.dy = -1 * Enemy.speed;
}
