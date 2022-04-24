/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/OwnPtr.h>
#include <LibGfx/Point.h>
#include <YakPunk/Forward.h>
#include <YakPunk/Graphics/Graphic.h>

namespace YakPunk {

class Entity {
public:
    explicit Entity(float x = 0, float y = 0, Graphics::Graphic* graphic = nullptr)
        : m_position(x, y)
        , m_graphic(adopt_own_if_nonnull(graphic))
    {
    }
    virtual ~Entity() = default;

    virtual void update();
    virtual void render() const;

private:
    Gfx::FloatPoint m_position;
    OwnPtr<Graphics::Graphic> m_graphic;
};

}
