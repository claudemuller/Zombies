#include "game.h"

extern struct Player Player;
extern struct Enemy Enemy;

struct Game Game = {
    SDL_TRUE,
    {},
    {
        SCREEN_WIDTH * SCREEN_SCALE,
        SCREEN_HEIGHT * SCREEN_SCALE,
        SCREEN_NAME,
        NULL,
        NULL,

        screen_drawSprite
    },
    {
        gfx_render,
        gfx_buildSprite,
        gfx_destroySprite
    },

    game_init,
    game_update,
    game_shutdown,
    game_processEvents
};

void game_init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) error("SDL Init failed");

    Game.screen.window = SDL_CreateWindow(Game.screen.name,
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          Game.screen.w,
                                          Game.screen.h,
                                          SDL_WINDOW_SHOWN);
    if (Game.screen.window == NULL) error("Failed to create window");
    Game.screen.renderer = SDL_CreateRenderer(Game.screen.window,
                                              -1,
                                              SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Game.screen.renderer == NULL) error("Failed to create renderer");

    srand((unsigned int)time(NULL));

    Game.running = SDL_TRUE;

    Player.init();

    // Init enemies
    for (int i = 0; i < NUM_OF_ENEMIES; i++) {
        int enemyW = 15 * SCREEN_SCALE;
        int enemyH = 46 * SCREEN_SCALE;
        int randX = rand() % (Game.screen.w - enemyW - 0 + 1) + 0;
        int randY = rand() % (Game.screen.h - enemyH - 0 + 1) + 0;
        int randDx = rand() % (2 - (-2) + 1) + (-2);
        int randDy = rand() % (2 - (-2) + 1) + (-2);
        Game.enemies[i].w = enemyW;
        Game.enemies[i].h = enemyH;
        Game.enemies[i].x = randX;
        Game.enemies[i].y = randY;
        Game.enemies[i].dx = randDx;
        Game.enemies[i].dy = randDy;
        Game.enemies[i].filename = "girl_1.png";
        Game.enemies[i].render = enemy_render;
        Game.enemies[i].update = enemy_update;
        Game.enemies[i].init = enemy_init;
        Game.enemies[i].init(&Game.enemies[i]);
    }
}

void game_update()
{
    Player.update();

    // Update enemies
    for (int i = 0; i < NUM_OF_ENEMIES; i++) {
        Game.enemies[i].update(&Game.enemies[i]);
    }
}

void game_shutdown(int withError)
{
    if (Game.screen.window) {
        SDL_DestroyWindow(Game.screen.window);
        Game.screen.window = NULL;
    }
    if (Game.screen.renderer) {
        SDL_DestroyRenderer(Game.screen.renderer);
        Game.screen.renderer = NULL;
    }

    SDL_Quit();

    exit(withError);
}

void game_processEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE:
            case SDL_QUIT:
                Game.running = SDL_FALSE;
                break;
            default:
                break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        Player.dy = -Player.speed;
        if (Player.y < 0) Player.y = 0;
    } else if (state[SDL_SCANCODE_DOWN]) {
        Player.dy = Player.speed;
        if (Player.y > Game.screen.h - Player.h) Player.y = Game.screen.h - Player.h;
    } else if (state[SDL_SCANCODE_LEFT]) {
        Player.dx = -Player.speed;
        if (Player.x < 0) Player.x = 0;
    } else if (state[SDL_SCANCODE_RIGHT]) {
        Player.dx = Player.speed;
        if (Player.x > Game.screen.w - Player.w) Player.x = Game.screen.w - Player.w;
    } else {
        Player.dx = 0;
        Player.dy = 0;
    }
}

void error(const char* msg)
{
    printf("%s: %s\n", msg, SDL_GetError());
    Game.shutdown(SDL_TRUE);
}

