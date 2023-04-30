/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Scene.h"
#include <YakPunk/Entity.h>

namespace YakPunk {

void Scene::update()
{
    for (auto& entity : m_entities)
        entity->update();
}

void Scene::render()
{
    for (auto& entity : m_entities)
        entity->render();
}

ErrorOr<void> Scene::add(NonnullOwnPtr<Entity> entity)
{
    return m_entities.try_append(move(entity));
}

}
