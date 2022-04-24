/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Font.h"

namespace YakPunk::Graphics {

Font::Font(Badge<Assets>, TTF_Font& font)
    : m_font(font)
{
}

Font::~Font()
{
    TTF_CloseFont(&m_font);
}

}
