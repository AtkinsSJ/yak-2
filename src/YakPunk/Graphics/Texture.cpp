/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Texture.h"
#include <SDL_image.h>
#include <YakPunk/Game.h>

namespace YakPunk::Graphics {

Texture::Texture(Badge<YakPunk::Assets>, SDL_Texture& texture)
    : m_texture(texture)
{
}

Texture::~Texture()
{
    SDL_DestroyTexture(&m_texture);
}

void Texture::draw_at(Gfx::IntRect bounds) const
{
    auto& renderer = Game::the().sdl_renderer();
    SDL_Rect rect { bounds.x(), bounds.y(), bounds.width(), bounds.height() };
    SDL_RenderCopy(&renderer, &m_texture, nullptr, &rect);
}

}
