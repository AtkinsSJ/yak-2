/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Game.h"
#include <AK/ScopeGuard.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace YakPunk {

Game* g_game = nullptr;

Game& Game::the()
{
    VERIFY(g_game);
    return *g_game;
}

ErrorOr<NonnullOwnPtr<Game>> Game::create(String const& window_title, int window_width, int window_height)
{
    VERIFY(!g_game);

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
    u32 sdl_init_flags = SDL_INIT_VIDEO;
    u8 img_init_flags = IMG_INIT_PNG;
    SDL_Window* window;
    SDL_Renderer* renderer;

    ArmedScopeGuard guard { [&]() {
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

    auto assets = TRY(Assets::create());

    guard.disarm();
    auto game_ptr = TRY(adopt_nonnull_own_or_enomem(new Game(*window, *renderer, move(assets))));
    g_game = game_ptr;
    return game_ptr;
}

Game::Game(SDL_Window& window, SDL_Renderer& renderer, NonnullOwnPtr<Assets> assets)
    : m_window(window)
    , m_renderer(renderer)
    , m_assets(move(assets))
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

void Game::run()
{
    bool running = true;
    while (running) {
        // Update
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        if (m_scene)
            m_scene->update();

        // Render
        SDL_SetRenderDrawColor(&m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(&m_renderer);

        if (m_scene)
            m_scene->render();

        SDL_RenderPresent(&m_renderer);
    }
}

Gfx::IntSize Game::window_size() const
{
    int width;
    int height;
    SDL_GetWindowSize(&m_window, &width, &height);
    return { width, height };
}

}
