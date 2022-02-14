
/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Scene.h"
#include <SDL.h>

class MenuScene final : public Scene {
public:
    explicit MenuScene(SDL_Renderer& renderer);

    virtual void update() override;
    virtual void render() override;

private:
    SDL_Texture* m_title_background;
};
