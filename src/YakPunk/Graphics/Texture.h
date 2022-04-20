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

class Texture final : public RefCounted<Texture> {
public:
    Texture(Badge<Assets>, SDL_Texture&);
    ~Texture();

    void draw_at(Gfx::IntRect bounds) const;

private:
    SDL_Texture& m_texture;
};

}
