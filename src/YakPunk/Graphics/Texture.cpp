/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Texture.h"
#include <SDL_image.h>
#include <YakPunk/Game.h>

namespace YakPunk::Graphics {

Texture::Texture(Badge<YakPunk::Assets>, SDL_Texture& texture, int width, int height)
    : m_texture(texture)
    , m_size(width, height)
{
}

Texture::~Texture()
{
    SDL_DestroyTexture(&m_texture);
}

void Texture::draw_at(Gfx::FloatPoint position) const
{
    auto& game = Game::the();
    auto& renderer = game.sdl_renderer();
    auto scale = game.scale();
    SDL_FRect rect { position.x() * scale, position.y() * scale, (float)width() * scale, (float)height() * scale };
    SDL_RenderCopyF(&renderer, &m_texture, nullptr, &rect);
}

void Texture::draw_at(Gfx::FloatRect bounds) const
{
    auto& game = Game::the();
    auto& renderer = game.sdl_renderer();
    auto scale = game.scale();
    SDL_FRect rect { bounds.x() * scale, bounds.y() * scale, bounds.width() * scale, bounds.height() * scale };
    SDL_RenderCopyF(&renderer, &m_texture, nullptr, &rect);
}

}
