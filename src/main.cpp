/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Game.h"
#include "MenuScene.h"
#include "YakPunk/Game.h"
#include <LibMain/Main.h>

ErrorOr<int> serenity_main(Main::Arguments)
{
    int const scale = 2;
    auto game = TRY(YakPunk::Game::create("Heinous Yak Destruction", 256 * scale, 224 * scale));

    //    Game game;
    //    game.set_scene(new MenuScene);
    //    game.run();

    return 0;
}
