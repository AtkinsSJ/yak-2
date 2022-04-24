/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Entity.h"

namespace YakPunk {

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
