#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <thread>

#include "src/RenderWindow.h"

int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1090;

int main() {
    // 1. Display a window
    // 2. Read keystrokes
    // 3. Close window on escape
    // 4. Draw a basic rectangle

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not init! SDL error: %s\n", SDL_GetError());

    RenderWindow window("The Grimoire", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.GetRenderer();

    if (renderer == nullptr)
        printf("Rendered could not be created! SDL error: %s\n", SDL_GetError());

    bool running = true;

    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        SDL_Rect rect = {SCREEN_WIDTH/2 - 30, SCREEN_HEIGHT/2 - 30, 60, 60};
        SDL_SetRenderDrawColor(renderer, 125,15,222,1);
        SDL_RenderDrawRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    return 0;
}