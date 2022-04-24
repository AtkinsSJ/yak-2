/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Error.h>
#include <AK/OwnPtr.h>
#include <AK/String.h>
#include <AK/Types.h>
#include <LibGfx/Size.h>
#include <YakPunk/Assets.h>
#include <YakPunk/Scene.h>

struct SDL_Renderer;
struct SDL_Window;

namespace YakPunk {

class Game {
public:
    static ErrorOr<NonnullOwnPtr<Game>> create(String const& window_title, int window_width, int window_height);
    static Game& the();
    ~Game();

    float scale() const { return m_scale; }
    void set_scale(float scale) { m_scale = scale; }

    template<typename T>
    ErrorOr<void> set_scene()
    {
        m_scene = TRY(T::create());
        return {};
    }

    void run();

    SDL_Renderer& sdl_renderer() { return m_renderer; }
    Gfx::IntSize window_size() const;

private:
    Game(SDL_Window&, SDL_Renderer&, NonnullOwnPtr<Assets>);

    SDL_Window& m_window;
    SDL_Renderer& m_renderer;
    NonnullOwnPtr<Assets> m_assets;

    OwnPtr<Scene> m_scene {};
    float m_scale { 1 };
};

}
