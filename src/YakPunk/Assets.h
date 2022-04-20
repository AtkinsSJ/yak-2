/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Error.h>
#include <AK/HashMap.h>
#include <AK/OwnPtr.h>
#include <AK/RefPtr.h>
#include <AK/String.h>
#include <YakPunk/Forward.h>
#include <YakPunk/Graphics/Texture.h>

namespace YakPunk {

class Assets {
public:
    static ErrorOr<NonnullOwnPtr<Assets>> create();
    static Assets& the();
    ~Assets();

    // FIXME: I'd rather return ErrorOr<Texture&>, but ErrorOr can't hold a reference.
    ErrorOr<NonnullRefPtr<Graphics::Texture>> load_texture(String const& path);

private:
    Assets();

    HashMap<String, NonnullRefPtr<Graphics::Texture>> m_textures;
};

}
