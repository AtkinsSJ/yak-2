/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include "MenuScene.h"
#include "Types.h"
#include <SDL.h>
#include <SDL_image.h>

int main()
{
    SDL_Window* window = nullptr;

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to init sdl :^(");
        return 1;
    }

    u8 img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        SDL_Log("Unable to init sdl_image :^(");
        return 1;
    }

    const int scale = 2;

    u32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("Heinous Yak Destruction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256 * scale, 224 * scale, window_flags);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        return 1;
    }

    Game game { window, renderer };
    game.set_scene(new MenuScene(*renderer));
    game.run();

    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
