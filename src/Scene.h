/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <SDL_render.h>
class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void update() = 0;
    virtual void render() = 0;

private:
};
