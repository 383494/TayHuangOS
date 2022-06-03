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
 * 硬盘驱动主函数
 *
 */



#include <syscall/syscall.h>
#include <debug/logging.h>
#include <ipc/ipc.h>
#include <tool/tostring.h>
#include "disk.h"

void entry(void) {
    linfo ("DISK DRIVER!");

    char buffer[256] = {};

    char mod_name[64] = {};
    int kernel = recv_any_msg (mod_name);

    linfo (mod_name);

    void *mod_addr;
    recv_msg (&mod_addr, kernel);

    lltoa ((qword)mod_addr, buffer, 16);
    linfo (buffer);


    //load_module (mod_name, mod_addr);


    //identify_ide0_disk(false, mod_addr);

    read_sector(0, 1, DISK_SEL_IDE1_MASTER, mod_addr);

    bool status = true;

    send_msg (&status, kernel, 1, 20);

    while (1);
}