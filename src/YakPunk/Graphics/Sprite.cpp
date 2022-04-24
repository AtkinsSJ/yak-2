/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Sprite.h"

namespace YakPunk::Graphics {

void Sprite::render(Gfx::FloatPoint position) const
{
    m_texture->draw_at(position.to_rounded<int>());
}

}
