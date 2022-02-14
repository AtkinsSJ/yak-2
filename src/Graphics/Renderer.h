/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Texture.h"
#include <SDL.h>

namespace Graphics {

class Renderer;
extern Renderer* s_renderer;

class Renderer {
public:
    static Renderer& the() { return *s_renderer; }
    static bool init(SDL_Window* window);
    static void free();

    void clear();
    void display_frame();

    SDL_Rect const& window_bounds() const { return m_window_bounds; }

    Texture* load_texture(char const* path);
    void draw_texture(Texture const& texture, SDL_Rect bounds);

private:
    Renderer(SDL_Window&, SDL_Renderer&);
    ~Renderer();

    SDL_Window& m_window;
    SDL_Renderer& m_renderer;
    SDL_Rect m_window_bounds {};
};
}
