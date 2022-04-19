/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <AK/Error.h>
#include <AK/Types.h>

namespace YakPunk {

class Game {
public:
    static ErrorOr<Game> create();
    ~Game();

private:
    Game() = default;
};

}
