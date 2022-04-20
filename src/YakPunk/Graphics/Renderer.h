/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <YakPunk/Graphics/Texture.h>

namespace YakPunk::Graphics {

extern class Renderer* s_renderer;

class Renderer {
public:
    static Renderer& the() { return *s_renderer; }
    static bool init(SDL_Window* window);
    static void free();

    bool load_font(char const* path);

private:
    Renderer(SDL_Window&, SDL_Renderer&);
    ~Renderer();

    SDL_Window& m_window;
    SDL_Renderer& m_renderer;

    TTF_Font* m_font { nullptr };
};
}