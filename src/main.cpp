/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Types.h"
#include <SDL.h>
#include <SDL_image.h>

int main()
{
    SDL_Window* window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to init sdl :^(");
        return 1;
    }

    u8 img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        SDL_Log("Unable to init sdl_image :^(");
        return 1;
    }

    // Window
    u32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("Heinous Yak Destruction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, window_flags);

    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
