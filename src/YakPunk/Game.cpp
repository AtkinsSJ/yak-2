/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace YakPunk {

ErrorOr<Game> Game::create()
{
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

    u32 sdl_init_flags = SDL_INIT_VIDEO;
    if (SDL_Init(sdl_init_flags) < 0)
        return Error::from_string_literal(SDL_GetError());

    u8 img_init_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_init_flags) & img_init_flags)) {
        SDL_Quit();
        return Error::from_string_literal(IMG_GetError());
    }

    if (TTF_Init() < 0) {
        IMG_Quit();
        SDL_Quit();
        return Error::from_string_literal(TTF_GetError());
    }

    return Game();
}

Game::~Game()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

}
