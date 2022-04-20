/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "Assets.h"

namespace YakPunk {

Assets* g_assets = nullptr;

ErrorOr<NonnullOwnPtr<Assets>> Assets::create()
{
    VERIFY(!g_assets);
    auto assets = TRY(adopt_nonnull_own_or_enomem(new Assets));
    g_assets = assets;
    return move(assets);
}

Assets::Assets()
{
}

Assets::~Assets()
{
}

Assets& Assets::the()
{
    VERIFY(g_assets);
    return *g_assets;
}

}
