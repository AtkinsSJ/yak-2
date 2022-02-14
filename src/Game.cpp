/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include <SDL.h>

Game::Game(SDL_Window* window, SDL_Renderer* renderer)
    : m_window(*window)
    , m_renderer(*renderer)
    , m_scene(nullptr)
{
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

void Game::set_scene(Scene* scene)
{
    if (m_scene)
        delete m_scene;

    m_scene = scene;
}
