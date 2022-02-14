/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Renderer.h"
#include <SDL_image.h>

namespace Graphics {

Renderer* s_renderer;

Renderer::Renderer(SDL_Window& window, SDL_Renderer& renderer)
    : m_window(window)
    , m_renderer(renderer)
{
    SDL_GetWindowSize(&m_window, &m_window_bounds.w, &m_window_bounds.h);
}

Renderer::~Renderer()
{
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

void Renderer::clear()
{
    SDL_SetRenderDrawColor(&m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(&m_renderer);
}

void Renderer::display_frame()
{
    SDL_RenderPresent(&m_renderer);
}

Texture* Renderer::load_texture(char const* path)
{
    auto* surface = IMG_Load(path);
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Failed to load image `%s`: %s", path, SDL_GetError());
        return nullptr;
    }

    auto* sdl_texture = SDL_CreateTextureFromSurface(&m_renderer, surface);
    SDL_FreeSurface(surface);
    if (!sdl_texture) {
        SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "Failed to create texture from image `%s`: %s", path, SDL_GetError());
        return nullptr;
    }

    return new Texture(*sdl_texture);
}

void Renderer::draw_texture(Texture const& texture, SDL_Rect bounds)
{
    SDL_RenderCopy(&m_renderer, &texture.m_texture, nullptr, &bounds);
}

}
