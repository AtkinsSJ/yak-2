/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <AK/RefCounted.h>
#include <AK/String.h>
#include <SDL.h>

namespace YakPunk::Graphics {

class Texture final : public RefCounted<Texture> {
public:
    static ErrorOr<NonnullRefPtr<Texture>> load(String const& path);
    ~Texture();

    void draw_at(SDL_Rect bounds) const;

private:
    explicit Texture(SDL_Texture&);
    SDL_Texture& m_texture;
};

}
