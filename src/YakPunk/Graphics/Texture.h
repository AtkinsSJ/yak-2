/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Badge.h>
#include <AK/RefCounted.h>
#include <AK/String.h>
#include <LibGfx/Rect.h>
#include <SDL.h>
#include <YakPunk/Forward.h>

namespace YakPunk::Graphics {

// FIXME: This doesn't need to be refcounted if we make the Assets class smarter.
class Texture final : public RefCounted<Texture> {
public:
    Texture(Badge<Assets>, SDL_Texture&, int width, int height);
    ~Texture();

    int width() const { return m_size.width(); }
    int height() const { return m_size.height(); }

    void draw_at(Gfx::FloatPoint position) const;
    void draw_at(Gfx::FloatRect bounds) const;

private:
    SDL_Texture& m_texture;
    Gfx::IntSize m_size;
};

}
