/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
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
    auto assets = TRY(adopt_nonnull_own_or_enomem(new (nothrow) Assets));
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

    auto* surface = IMG_Load(path.to_deprecated_string().characters());
    if (!surface) {
        warnln("Failed to load image `{}`: {}", path, IMG_GetError());
        return Error::from_string_view({ IMG_GetError(), strlen(IMG_GetError()) });
    }
    int width = surface->w;
    int height = surface->h;

    auto& renderer = Game::the().sdl_renderer();
    auto* sdl_texture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_FreeSurface(surface);
    if (!sdl_texture) {
        warnln("Failed to create texture from image `{}`: {}", path, SDL_GetError());
        return Error::from_string_view({ SDL_GetError(), strlen(SDL_GetError()) });
    }

    auto texture = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Graphics::Texture({}, *sdl_texture, width, height)));
    m_textures.set(path, texture);
    return texture;
}

ErrorOr<NonnullRefPtr<Graphics::Font>> Assets::load_font(String const& path)
{
    auto existing_font = m_fonts.find(path);
    if (existing_font != m_fonts.end())
        return existing_font->value;

    auto* sdl_font = TTF_OpenFont(path.to_deprecated_string().characters(), 16);
    if (!sdl_font) {
        warnln("Failed to load font file `{}`: {}", path, TTF_GetError());
        return Error::from_string_view({ TTF_GetError(), strlen(TTF_GetError()) });
    }

    auto font = TRY(adopt_nonnull_ref_or_enomem(new (nothrow) Graphics::Font({}, *sdl_font)));
    m_fonts.set(path, font);
    return font;
}

}
