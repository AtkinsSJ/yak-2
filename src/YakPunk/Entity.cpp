/*
 * Copyright (c) 2022-2023, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Entity.h"

namespace YakPunk {

ErrorOr<NonnullOwnPtr<Entity>> Entity::create(float x, float y, OwnPtr<Graphics::Graphic> graphic)
{
    return adopt_nonnull_own_or_enomem(new (nothrow) Entity(x, y, move(graphic)));
}

void Entity::update()
{
    if (m_graphic)
        m_graphic->update();
}

void Entity::render() const
{
    if (m_graphic)
        m_graphic->render(m_position);
}

}
