/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Badge.h>
#include <AK/RefCounted.h>
#include <SDL_ttf.h>
#include <YakPunk/Forward.h>

namespace YakPunk::Graphics {

// FIXME: This doesn't need to be refcounted if we make the Assets class smarter.
class Font final : public RefCounted<Font> {
public:
    Font(Badge<Assets>, TTF_Font&);
    ~Font();

private:
    TTF_Font& m_font;
};

}
