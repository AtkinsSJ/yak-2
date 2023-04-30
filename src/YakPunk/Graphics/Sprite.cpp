/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Sprite.h"

namespace YakPunk::Graphics {

ErrorOr<NonnullOwnPtr<Sprite>> Sprite::create(NonnullRefPtr<YakPunk::Graphics::Texture> texture)
{
    return adopt_nonnull_own_or_enomem(new (nothrow) Sprite(move(texture)));
}

void Sprite::render(Gfx::FloatPoint position) const
{
    m_texture->draw_at(position);
}

}
