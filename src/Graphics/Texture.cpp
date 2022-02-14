/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Texture.h"

namespace Graphics {

Texture::Texture(SDL_Texture& texture)
    : m_texture(texture)
{
}

Texture::~Texture()
{
    SDL_DestroyTexture(&m_texture);
}

}
