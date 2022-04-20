/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include <AK/Format.h>
#include <Graphics/Renderer.h>
#include <MenuScene.h>

MenuScene::MenuScene()
    : Scene()
{
    //    m_title_background = Graphics::Renderer::the().load_texture("assets/title.png");
}

MenuScene::~MenuScene()
{
    delete m_title_background;
}

void MenuScene::update()
{
    dbgln("Running menu scene update!");
}

void MenuScene::render()
{
    auto& renderer = Graphics::Renderer::the();
    if (m_title_background)
        renderer.draw_texture(*m_title_background, renderer.window_bounds());
}
