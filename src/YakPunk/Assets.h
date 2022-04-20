/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Error.h>
#include <AK/OwnPtr.h>

namespace YakPunk {

class Assets {
public:
    static ErrorOr<NonnullOwnPtr<Assets>> create();
    static Assets& the();
    ~Assets();

private:
    Assets();
};

}
