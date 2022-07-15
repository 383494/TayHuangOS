/*
 * SPDX-License-Identifier: GPL-3.0-only
 * -------------------------------*-TayhuangOS-*-----------------------------------
 *
 *    Copyright (C) 2022, 2022 TayhuangOS Development Team - All Rights Reserved
 *
 * --------------------------------------------------------------------------------
 *
 * 作者: theflysong
 *
 * main.c
 *
 * video主函数
 *
 */



#include <debug/logging.h>

#include <assert.h>

#include <syscall/syscall.h>
#include <syscall/ipc.h>

#include <memory/malloc.h>

#include <tayhuang/services.h>

#include <global.h>

PUBLIC video_info_struct video_info;

PUBLIC void kmod_main(void) {
    set_logging_name("Video");
    check_ipc();
    recv_msg(&video_info);

    void *buffer = malloc(512);

    while (true) {
        set_allow(ANY_TASK);

        check_ipc();
        recv_msg(buffer);
        
        void *buf = buffer;
        int cmdid = ARG_READ(buf, int);

        text_execute(cmdid, buf);
    }

    while (true);
}