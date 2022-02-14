/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include <Graphics/Renderer.h>
#include <SDL.h>

void Game::run()
{
    auto& renderer = Graphics::Renderer::the();

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
        renderer.clear();

        if (m_scene)
            m_scene->render();

        renderer.display_frame();
    }
}

void Game::set_scene(Scene* scene)
{
    if (m_scene)
        delete m_scene;

    m_scene = scene;
}
