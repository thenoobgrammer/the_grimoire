#pragma once

#include "RenderWindow.h"
#include <SDL.h>

RenderWindow::RenderWindow(const char *title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("SDL could not create window! SDL error: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        printf("SDL could not create renderer! SDL error: %s\n", SDL_GetError());
    }
}

SDL_Renderer *RenderWindow::GetRenderer() {
    return renderer;
}

void RenderWindow::close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;
    SDL_Quit();
}




