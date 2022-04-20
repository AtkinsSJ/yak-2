/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include <LibMain/Main.h>
#include <MenuScene.h>
#include <YakPunk/Game.h>

ErrorOr<int> serenity_main(Main::Arguments)
{
    int const scale = 2;
    auto game = TRY(YakPunk::Game::create("Heinous Yak Destruction", 256 * scale, 224 * scale));

    TRY(game->set_scene<MenuScene>());
    game->run();

    return 0;
}
