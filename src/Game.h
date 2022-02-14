/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include "Scene.h"

class Game {
public:
    Game() = default;
    ~Game() = default;

    void run();

    void set_scene(Scene* scene);

private:
    Scene* m_scene { nullptr };
};
