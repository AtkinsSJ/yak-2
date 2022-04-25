/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/NonnullOwnPtrVector.h>
#include <YakPunk/Entity.h>
#include <YakPunk/Forward.h>

namespace YakPunk {

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void update();
    virtual void render();

    Entity& add(Entity*);

private:
    NonnullOwnPtrVector<Entity> m_entities;
};

}
