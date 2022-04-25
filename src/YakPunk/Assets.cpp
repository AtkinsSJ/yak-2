/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Assets.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <YakPunk/Game.h>

namespace YakPunk {

Assets* g_assets = nullptr;

ErrorOr<NonnullOwnPtr<Assets>> Assets::create()
{
    VERIFY(!g_assets);
    auto assets = TRY(adopt_nonnull_own_or_enomem(new Assets));
    g_assets = assets;
    return assets;
}

Assets::Assets()
{
}

Assets::~Assets()
{
    VERIFY(g_assets);
    g_assets = nullptr;
}

Assets& Assets::the()
{
    VERIFY(g_assets);
    return *g_assets;
}

ErrorOr<NonnullRefPtr<Graphics::Texture>> Assets::load_texture(String const& path)
{
    auto existing_texture = m_textures.find(path);
    if (existing_texture != m_textures.end())
        return existing_texture->value;

    auto* surface = IMG_Load(path.characters());
    if (!surface) {
        warnln("Failed to load image `{}`: {}", path, IMG_GetError());
        return Error::from_string_literal(IMG_GetError());
    }
    int width = surface->w;
    int height = surface->h;

    auto& renderer = Game::the().sdl_renderer();
    auto* sdl_texture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_FreeSurface(surface);
    if (!sdl_texture) {
        warnln("Failed to create texture from image `{}`: {}", path, SDL_GetError());
        return Error::from_string_literal(SDL_GetError());
    }

    auto texture = adopt_ref(*new Graphics::Texture({}, *sdl_texture, width, height));
    m_textures.set(path, texture);
    return texture;
}

ErrorOr<NonnullRefPtr<Graphics::Font>> Assets::load_font(String const& path)
{
    auto existing_font = m_fonts.find(path);
    if (existing_font != m_fonts.end())
        return existing_font->value;

    auto* sdl_font = TTF_OpenFont(path.characters(), 16);
    if (!sdl_font) {
        warnln("Failed to load font file `{}`: {}", path, TTF_GetError());
        return Error::from_string_literal(TTF_GetError());
    }

    auto font = adopt_ref(*new Graphics::Font({}, *sdl_font));
    m_fonts.set(path, font);
    return font;
}

}
