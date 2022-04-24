/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

namespace YakPunk::Graphics {

class Graphic {
public:
    virtual ~Graphic() = default;

    virtual void update() { }
    virtual void render(Gfx::FloatPoint position) const = 0;
};

}
