/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGfx/Point.h>

namespace YakPunk {

class Entity {
public:
    Entity(float x = 0, float y = 0)
        : m_position(x, y)
    {
    }
    virtual ~Entity() = default;

    virtual void update() {};
    virtual void render() const;

private:
    Gfx::FloatPoint m_position;
};

}
