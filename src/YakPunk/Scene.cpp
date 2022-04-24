/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Scene.h"
#include <YakPunk/Entity.h>

namespace YakPunk {

void Scene::update()
{
    for (auto& entity : m_entities)
        entity.update();
}

void Scene::render()
{
    for (auto& entity : m_entities)
        entity.render();
}

Entity& Scene::add(Entity* entity)
{
    m_entities.append(adopt_own(*entity));
    return *entity;
}

}
