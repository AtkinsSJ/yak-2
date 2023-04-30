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
    auto title_background = TRY(YakPunk::Assets::the().load_texture(TRY("assets/title.png"_string)));
    return adopt_nonnull_own_or_enomem(new MenuScene(move(title_background)));
}

MenuScene::MenuScene(NonnullRefPtr<YakPunk::Graphics::Texture> title_background)
    : Scene()
    , m_title_background(move(title_background))
{
    add(new YakPunk::Entity(0, 0, new YakPunk::Graphics::Sprite(m_title_background)));
}

void MenuScene::update()
{
    Scene::update();
}

void MenuScene::render()
{
    Scene::render();
}
