/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <AK/Error.h>
#include <AK/OwnPtr.h>
#include <AK/String.h>
#include <AK/Types.h>
#include <YakPunk/Scene.h>

struct SDL_Renderer;
struct SDL_Window;

namespace YakPunk {

class Game {
public:
    static ErrorOr<NonnullOwnPtr<Game>> create(String const& window_title, int window_width, int window_height);
    static Game& the();
    ~Game();

    template<typename T>
    ErrorOr<void> set_scene()
    {
        m_scene = TRY(T::create());
        return {};
    }

    void run();

    SDL_Renderer& sdl_renderer() { return m_renderer; }

private:
    Game(SDL_Window&, SDL_Renderer&);

    SDL_Window& m_window;
    SDL_Renderer& m_renderer;

    OwnPtr<Scene> m_scene {};
};

}
