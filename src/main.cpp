/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include "Graphics/Renderer.h"
#include "MenuScene.h"
#include "YakPunk/Game.h"
#include <AK/Format.h>
#include <AK/Types.h>
#include <LibMain/Main.h>

ErrorOr<int> serenity_main(Main::Arguments)
{
    auto game = TRY(YakPunk::Game::create());

    int const scale = 2;

    u32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    SDL_Window* window = SDL_CreateWindow("Heinous Yak Destruction", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256 * scale, 224 * scale, window_flags);
    if (!window) {
        warnln("Unable to create window: {}", SDL_GetError());
        return 1;
    }

    Graphics::Renderer::init(window);
    if (!Graphics::Renderer::the().load_font("assets/04B_03__.TTF"))
        return 1;

    //    Game game;
    //    game.set_scene(new MenuScene);
    //    game.run();

    Graphics::Renderer::free();

    return 0;
}
