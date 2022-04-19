/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <AK/Error.h>
#include <AK/String.h>
#include <AK/Types.h>

struct SDL_Renderer;
struct SDL_Window;

namespace YakPunk {

class Game {
public:
    static ErrorOr<Game> create(String const& window_title, int window_width, int window_height);
    ~Game();

private:
    Game(SDL_Window&, SDL_Renderer&);

    SDL_Window& m_window;
    SDL_Renderer& m_renderer;
};

}
