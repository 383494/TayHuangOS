/*
 * SPDX-License-Identifier: GPL-3.0-only
 * -------------------------------*-TayhuangOS-*-----------------------------------
 *
 *    Copyright (C) 2022, 2022 TayhuangOS Development Team - All Rights Reserved
 *
 * --------------------------------------------------------------------------------
 *
 * 作者: Flysong
 *
 * main.c
 *
 * setup主函数
 *
 */



#include <syscall/syscall.h>
#include <debug/logging.h>
#include <ipc/ipc.h>
#include <tool/tostring.h>
#include <disk.h>
#include <fs/fat32.h>
#include <printf.h>

void kmod_main(void) {
    set_logging_name("SETUP");

    char buffer[256] = {};

    char mod_name[64] = {};

    int kernel = 0;
    while (recv_any_msg(&kernel) == -1); //获取内核进程pid


    sprintf (buffer, "Kernel PID: %d", kernel);
    linfo (buffer);

    char context[8192];
    get_context(DISK_SEL_IDE1_MASTER, (void**)context); //获取文件系统上下文

    while (true) {
        recv_msg (mod_name, kernel); //获取模块名

        sprintf (buffer, "Module Name: %s", mod_name);
        linfo (buffer);

        void *mod_addr;
        recv_msg (&mod_addr, kernel); //获取加载地址

        sprintf (buffer, "Module Load Address: %P", mod_addr);
        linfo (buffer);

        bool status = false;
        int times = 5;
        while (times --) {
            status = loadfile(context, mod_name, mod_addr); //加载文件
            if (status) break;
        }

        send_msg (&status, kernel, 1, 20); //通知内核
    }

    while (1);
}