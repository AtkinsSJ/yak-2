/*
 * Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <cfloat>
#include <cstdint>

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

const s8 s8Min = INT8_MIN;
const s8 s8Max = INT8_MAX;
const s16 s16Min = INT16_MIN;
const s16 s16Max = INT16_MAX;
const s32 s32Min = INT32_MIN;
const s32 s32Max = INT32_MAX;
const s64 s64Min = INT64_MIN;
const s64 s64Max = INT64_MAX;

const u8 u8Max = UINT8_MAX;
const u16 u16Max = UINT16_MAX;
const u32 u32Max = UINT32_MAX;
const u64 u64Max = UINT64_MAX;

const f32 f32Min = -FLT_MAX;
const f32 f32Max = FLT_MAX;
const f64 f64Min = -DBL_MAX;
const f64 f64Max = DBL_MAX;
