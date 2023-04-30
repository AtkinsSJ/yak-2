# Heinous Yak Destruction

A C++ remake of [a flash game](https://github.com/AtkinsSJ/yak/) I made for the Charity Game Jam 2013.

Copyright (c) 2022, Sam Atkins <atkinssj@gmail.com>, available under the BSD 2-Clause license.

Font 04B-03 Copyright 1998-2003 Yuji Oshimoto. http://www.04.jp.org/

Everything in `./cmake` has its own licenses.

## Building

Build uses CMake and Ninja, and requires a fairly recent version of Clang to compile.

Required libraries: `libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev`

Setup is roughly:

```sh
$ cmake -G Ninja -B build

$ ninja -C build

$ build/yak
```
