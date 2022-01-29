// SPDX-License-Identifier: GPL-2.0-only
/* -------------------------------*-TayhuangOS-*-----------------------------------
 *
 *   Copyright (C) 2022, 2022 TayhuangOS Development Team - All Rights Reserved
 *
 * --------------------------------------------------------------------------------
 *
 * Author: Flysong
 *
 * kernel/boot/stage3/vedio.c
 *
 * Vedio functions are implemented here
 */



#include "vedio.h"

PUBLIC struct DP_INFO DPINFO;

PUBLIC void init_vedio(int screen_width, int screen_height, int type, char* framebuffer) {
    DPINFO.screen_width = screen_width;
    DPINFO.screen_height = screen_height;
    DPINFO.type = type;
    DPINFO.framebuffer = framebuffer;
}

PUBLIC void draw_pixel(int pos_x, int pos_y, color_rgb color) {
    if (DPINFO.type != DPM_GRAPHIC)
        return;
    int position = pos_y * DPINFO.screen_width + pos_x;
    *(DPINFO.framebuffer + position * 3) = color.b;
    *(DPINFO.framebuffer + position * 3 + 1) = color.g;
    *(DPINFO.framebuffer + position * 3 + 2) = color.r;
}

PUBLIC void draw_character(int pos_x, int pos_y, char ch, byte color) {
    if (DPINFO.type != DPM_CHARACTER)
        return;
    int position = pos_y * DPINFO.screen_width + pos_x;
    *(DPINFO.framebuffer + position * 2) = ch;
    *(DPINFO.framebuffer + position * 2 + 1) = color;
}