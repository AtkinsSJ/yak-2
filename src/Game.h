/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Scene.h"
#include <SDL.h>

class Game {
public:
    Game(SDL_Window*, SDL_Renderer*);
    ~Game() = default;

    void run();

    void set_scene(Scene* scene);

private:
    SDL_Window& m_window;
    SDL_Renderer& m_renderer;
    Scene* m_scene;
};
