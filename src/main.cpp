/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include "Graphics/Renderer.h"
#include "MenuScene.h"
#include "Types.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main()
{
    SDL_Window* window = nullptr;

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to init sdl: %s", SDL_GetError());
        return 1;
    }

    u8 img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        SDL_Log("Unable to init sdl_image: %s", IMG_GetError());
        return 1;
    }

    if (TTF_Init() < 0) {
        SDL_Log("Unable to init sdl_ttf: %s", TTF_GetError());
        return 1;
    }

    const int scale = 2;

    u32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow("Heinous Yak Destruction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256 * scale, 224 * scale, window_flags);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        return 1;
    }

    Graphics::Renderer::init(window);

    Game game;
    game.set_scene(new MenuScene);
    game.run();

    Graphics::Renderer::free();

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
