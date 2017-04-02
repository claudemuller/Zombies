#include "player.h"
#include "game.h"

extern struct Game Game;

struct Player Player = {
    15 * SCREEN_SCALE,
    46 * SCREEN_SCALE,
    0,
    0,
    0,
    0,
    4.0f,
    "girl_1.png",

    player_init,
    player_render,
    player_update
};

void player_init()
{
    Player.x = (Game.screen.w - Player.w) / 2;
    Player.y = (Game.screen.h - Player.h) / 2;
}

void player_render()
{
    SDL_Texture* tex = Game.gfx.buildSprite(Player.filename);
    SDL_Rect rect = {(int)Player.x, (int)Player.y, Player.w, Player.h};
    Game.screen.drawSprite(tex, &rect);
}

void player_update()
{
    Player.x = Player.x + Player.dx;
    Player.y = Player.y + Player.dy;
}
