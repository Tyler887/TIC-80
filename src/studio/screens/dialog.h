// MIT License

// Copyright (c) 2017 Vadim Grigoruk @nesbox // grigoruk@gmail.com

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "studio/studio.h"

typedef struct Dialog Dialog;

struct Dialog
{
    tic_mem* tic;

    bool init;
    DialogCallback callback;
    void* data;
    const char** text;
    s32 rows;
    s32 ticks;

    u32 focus;

    tic_point pos;

    struct
    {
        tic_point start;
        bool active;
    } drag;
    
    void(*tick)(Dialog* Dialog);
    void (*scanline)(tic_mem* tic, s32 row, void* data);
    void(*escape)(Dialog* Dialog);
};

void initDialog(Dialog* dialog, tic_mem* tic, const char** text, s32 rows, DialogCallback callback, void* data);
void freeDialog(Dialog* dialog);
