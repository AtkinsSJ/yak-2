/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include <AK/ScopeGuard.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace YakPunk {

ErrorOr<Game> Game::create(String const& window_title, int window_width, int window_height)
{
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
    bool succeeded = false;
    u32 sdl_init_flags = SDL_INIT_VIDEO;
    u8 img_init_flags = IMG_INIT_PNG;
    SDL_Window* window;
    SDL_Renderer* renderer;

    ScopeGuard guard { [&]() {
        if (succeeded)
            return;

        if (renderer)
            SDL_DestroyRenderer(renderer);

        if (window)
            SDL_DestroyWindow(window);

        if (TTF_WasInit())
            TTF_Quit();

        IMG_Quit();

        if (SDL_WasInit(sdl_init_flags))
            SDL_Quit();
    } };

    if (SDL_Init(sdl_init_flags) < 0)
        return Error::from_string_literal(SDL_GetError());

    if (!(IMG_Init(img_init_flags) & img_init_flags))
        return Error::from_string_literal(IMG_GetError());

    if (TTF_Init() < 0)
        return Error::from_string_literal(TTF_GetError());

    u32 window_flags = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(window_title.characters(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, window_flags);
    if (!window)
        return Error::from_string_literal(SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
        return Error::from_string_literal(SDL_GetError());

    succeeded = true;
    return Game { *window, *renderer };
}

Game::Game(SDL_Window& window, SDL_Renderer& renderer)
    : m_window(window)
    , m_renderer(renderer)
{
}

Game::~Game()
{
    SDL_DestroyRenderer(&m_renderer);
    SDL_DestroyWindow(&m_window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

}
