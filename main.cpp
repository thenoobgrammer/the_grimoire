#include <bitset>
#include <iostream>
#include <SDL.h>
#include <thread>

#include "src/Engine/Entity.h"
#include "src/Logger/Logger.h"
#include "src/RenderWindow.h"
#include "Systems/KeystrokeSystem.h"

int SCREEN_WIDTH = 1920;
int SCREEN_HEIGHT = 1090;
unsigned Entity::next_id = 1;

extern int s_componentCounter;
template <class T>
int GetId() {
    static int s_componentId = s_componentCounter++;
    return s_componentId;
}

int s_componentCounter = 0;

struct TransformComponent {
    float position{ 1.0f };
    float rotation{ 2.0f };
};



int main() {
    printf("Transform component ID: %i\n", GetId<TransformComponent>());
    std::list<System*> systems;

    systems.emplace_back(new KeystrokeSystem());

    auto playerEntity = new Entity("player", std::list<std::string>{"main", "character"});

    Logger::Log("Name: " + playerEntity->getName() + " | ID: " + std::to_string(playerEntity->getId()));

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not init! SDL error: %s\n", SDL_GetError());

    RenderWindow window("The Grimoire", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.GetRenderer();

    if (renderer == nullptr)
        printf("Rendered could not be created! SDL error: %s\n", SDL_GetError());

    bool running = true;

    SDL_Event event;

    SDL_Rect rect = {SCREEN_WIDTH/2 - 30, SCREEN_HEIGHT/2 - 30, 60, 60};

    while (running) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 125,15,222,1);
        SDL_RenderDrawRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                } else if (event.key.keysym.sym == SDLK_w) {
                    rect.y -= 2;
                } else if (event.key.keysym.sym == SDLK_a) {
                    rect.x -= 2;
                } else if (event.key.keysym.sym == SDLK_s) {
                    rect.y += 2;
                } else if (event.key.keysym.sym == SDLK_d) {
                    rect.x += 2;
                }
            }
        }
    }

    return 0;
}