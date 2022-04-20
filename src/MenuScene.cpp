/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <AK/Format.h>
#include <MenuScene.h>
#include <YakPunk/Game.h>
#include <YakPunk/Graphics/Renderer.h>

ErrorOr<NonnullOwnPtr<MenuScene>> MenuScene::create()
{
    auto title_background = TRY(YakPunk::Graphics::Texture::load("assets/title.png"));
    return adopt_nonnull_own_or_enomem(new MenuScene(move(title_background)));
}

MenuScene::MenuScene(NonnullRefPtr<YakPunk::Graphics::Texture> title_background)
    : Scene()
    , m_title_background(move(title_background))
{
}

void MenuScene::update()
{
}

void MenuScene::render()
{
    auto window_size = YakPunk::Game::the().window_size();
    m_title_background->draw_at({ 0, 0, window_size.width(), window_size.height() });
}
