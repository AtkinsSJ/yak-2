/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
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
    static ErrorOr<NonnullOwnPtr<Entity>> create(float x = 0, float y = 0, OwnPtr<Graphics::Graphic> graphic = nullptr);
    virtual ~Entity() = default;

    virtual void update();
    virtual void render() const;

private:
    explicit Entity(float x = 0, float y = 0, OwnPtr<Graphics::Graphic> graphic = nullptr)
        : m_position(x, y)
        , m_graphic(move(graphic))
    {
    }

    Gfx::FloatPoint m_position;
    OwnPtr<Graphics::Graphic> m_graphic;
};

}
