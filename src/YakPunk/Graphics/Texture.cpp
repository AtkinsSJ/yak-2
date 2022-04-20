/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <SDL_image.h>
#include <YakPunk/Game.h>
#include <YakPunk/Graphics/Texture.h>

namespace YakPunk::Graphics {

ErrorOr<NonnullRefPtr<Texture>> Texture::load(String const& path)
{
    auto* surface = IMG_Load(path.characters());
    if (!surface) {
        warnln("Failed to load image `{}`: {}", path, IMG_GetError());
        return Error::from_string_literal(IMG_GetError());
    }

    auto& renderer = Game::the().sdl_renderer();
    auto* sdl_texture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_FreeSurface(surface);
    if (!sdl_texture) {
        warnln("Failed to create texture from image `{}`: {}", path, SDL_GetError());
        return Error::from_string_literal(SDL_GetError());
    }

    return adopt_ref(*new Texture(*sdl_texture));
}

Texture::Texture(SDL_Texture& texture)
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
