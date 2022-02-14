/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "MenuScene.h"
#include <SDL_image.h>

MenuScene::MenuScene(SDL_Renderer& renderer)
    : Scene(renderer)
{
    SDL_Surface* title_surface = IMG_Load("assets/title.png");

    m_title_background = SDL_CreateTextureFromSurface(&this->renderer(), title_surface);
}

void MenuScene::update()
{
}

void MenuScene::render()
{
    SDL_RenderCopy(&renderer(), m_title_background, nullptr, nullptr);
}
