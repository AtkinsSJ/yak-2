/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Error.h>
#include <AK/OwnPtr.h>
#include <YakPunk/Graphics/Text.h>
#include <YakPunk/Graphics/Texture.h>
#include <YakPunk/Scene.h>

class MenuScene final : public YakPunk::Scene {
public:
    static ErrorOr<NonnullOwnPtr<MenuScene>> create();
    virtual ~MenuScene() = default;

    virtual void update() override;
    virtual void render() override;

private:
    explicit MenuScene();

    YakPunk::Graphics::Text* m_start_text { nullptr };
    YakPunk::Graphics::Text* m_high_scores_text { nullptr };
    YakPunk::Graphics::Text* m_version_text { nullptr };
};
