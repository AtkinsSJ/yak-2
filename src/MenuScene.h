/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <Graphics/Text.h>
#include <Graphics/Texture.h>
#include <YakPunk/Scene.h>

class MenuScene final : public YakPunk::Scene {
public:
    MenuScene();
    virtual ~MenuScene();

    virtual void update() override;
    virtual void render() override;

private:
    Graphics::Texture* m_title_background;

    Graphics::Text* m_start_text { nullptr };
    Graphics::Text* m_high_scores_text { nullptr };
    Graphics::Text* m_version_text { nullptr };
};
