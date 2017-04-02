#include "game.h"

extern struct Game Game;

int main(int argc, char* argv[])
{
    Game.init();

    double dt = 0;
    Uint64 currentTime = SDL_GetPerformanceCounter();
    Uint64 oldTime = 0;

    while (Game.running) {
        Game.processEvents();

        oldTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        dt = ((currentTime - oldTime) * 1000 / (double)SDL_GetPerformanceFrequency() );
//        printf("%f\n", dt);
//        fflush(stdout);

        Game.update();
        Game.gfx.render();

        SDL_Delay((Uint32)dt);
    }

    Game.shutdown(SDL_FALSE);
}
