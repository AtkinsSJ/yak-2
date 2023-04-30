/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "MenuScene.h"
#include <YakPunk/Entity.h>
#include <YakPunk/Game.h>
#include <YakPunk/Graphics/Sprite.h>

ErrorOr<NonnullOwnPtr<MenuScene>> MenuScene::create()
{
    auto menu_scene = TRY(adopt_nonnull_own_or_enomem(new (nothrow) MenuScene));

    auto title_background = TRY(YakPunk::Assets::the().load_texture(TRY("assets/title.png"_string)));
    auto sprite = TRY(YakPunk::Graphics::Sprite::create(move(title_background)));
    auto entity = TRY(YakPunk::Entity::create(0, 0, move(sprite)));
    TRY(menu_scene->add(move(entity)));

    return menu_scene;
}

MenuScene::MenuScene()
    : Scene()
{
}

void MenuScene::update()
{
    Scene::update();
}

void MenuScene::render()
{
    Scene::render();
}
