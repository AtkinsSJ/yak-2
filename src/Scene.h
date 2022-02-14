/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <SDL_render.h>
class Scene {
public:
    Scene(SDL_Renderer& renderer)
        : m_renderer(renderer)
    {
    }
    virtual ~Scene() = default;

    virtual void update() = 0;
    virtual void render() = 0;

protected:
    SDL_Renderer& renderer() { return m_renderer; }
    SDL_Renderer const& renderer() const { return m_renderer; }

private:
    SDL_Renderer& m_renderer;
};
