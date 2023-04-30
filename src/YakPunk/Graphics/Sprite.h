/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/NonnullOwnPtr.h>
#include <LibGfx/Rect.h>
#include <YakPunk/Graphics/Graphic.h>
#include <YakPunk/Graphics/Texture.h>

namespace YakPunk::Graphics {

class Sprite final : public Graphic {
public:
    static ErrorOr<NonnullOwnPtr<Sprite>> create(NonnullRefPtr<Texture>);
    virtual ~Sprite() = default;

    virtual void render(Gfx::FloatPoint position) const override;

private:
    explicit Sprite(NonnullRefPtr<Texture> texture)
        : Graphic()
        , m_texture(move(texture)) {};

    NonnullRefPtr<Texture> m_texture;
};

}
