#include<iostream>
#include"game.h"
game* Game = 0;
int main(int argv, char* argc[])
{

    Game = new game;
    Game->init("paddle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, P_WINDOW_WIDTH, P_WINDOW_HEIGHT, SDL_WINDOW_MAXIMIZED|SDL_WINDOW_FULLSCREEN);
    while(Game->running())
    {
        int x = SDL_GetTicks();
        Game->render();
        Game->handleEvents();
        Game->update();
        int y = SDL_GetTicks();
        SDL_Delay((1000+x-y)/60);

    }
    Game->clean();

    return 0;
}
