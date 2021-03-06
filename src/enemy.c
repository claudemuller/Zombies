#include "enemy.h"
#include "game.h"

extern struct Game Game;

void enemy_init(struct Enemy* enemy)
{
    printf("test\n");
    fflush(stdout);
    enemy->texture = Game.gfx.buildSprite(enemy->filename);
}

void enemy_render(struct Enemy* enemy)
{
    SDL_Rect rect = {(int)enemy->x, (int)enemy->y, enemy->w, enemy->h};
    Game.screen.drawSprite(enemy->texture, &rect);
}

void enemy_update(struct Enemy* enemy)
{
    enemy->x = enemy->x + enemy->dx;
    enemy->y = enemy->y + enemy->dy;

    detectCollision(enemy);
}

void detectCollision(struct Enemy* enemy)
{
    if (enemy->x < 0) enemy->dx = -enemy->dx;
    else if (enemy->x > Game.screen.w - enemy->w) enemy->dx = -enemy->dx;
    else if (enemy->y < 0) enemy->dy = -enemy->dy;
    else if (enemy->y > Game.screen.h - enemy->h) enemy->dy = -enemy->dy;
}
