/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <SDL_image.h>
#include <YakPunk/Graphics/Renderer.h>

namespace YakPunk::Graphics {

Renderer* s_renderer;

Renderer::Renderer(SDL_Window& window, SDL_Renderer& renderer)
    : m_window(window)
    , m_renderer(renderer)
{
}

Renderer::~Renderer()
{
    if (m_font)
        TTF_CloseFont(m_font);

    SDL_DestroyRenderer(&m_renderer);
    SDL_DestroyWindow(&m_window);
}

bool Renderer::init(SDL_Window* window)
{
    if (!window)
        return false;

    SDL_Renderer* sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!sdl_renderer) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        return false;
    }

    s_renderer = new Renderer(*window, *sdl_renderer);
    return true;
}

void Renderer::free()
{
    if (!s_renderer)
        return;

    delete s_renderer;
    s_renderer = nullptr;
}

bool Renderer::load_font(char const* path)
{
    if (m_font) {
        TTF_CloseFont(m_font);
        m_font = nullptr;
    }

    auto* maybe_font = TTF_OpenFont(path, 16);
    if (!maybe_font) {
        SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Failed to load font file `%s`: %s", path, TTF_GetError());
        return false;
    }

    m_font = maybe_font;
    return true;
}

}
