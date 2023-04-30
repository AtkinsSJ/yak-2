/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/NonnullOwnPtr.h>
#include <AK/Vector.h>
#include <YakPunk/Entity.h>
#include <YakPunk/Forward.h>

namespace YakPunk {

class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    virtual void update();
    virtual void render();

    ErrorOr<void> add(NonnullOwnPtr<Entity>);

private:
    Vector<NonnullOwnPtr<Entity>> m_entities;
};

}
