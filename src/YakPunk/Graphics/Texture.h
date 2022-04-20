/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once
#include <SDL.h>

namespace YakPunk::Graphics {

class Texture {
    friend class Renderer;

public:
    explicit Texture(SDL_Texture&);
    ~Texture();

private:
    SDL_Texture& m_texture;
};

}
