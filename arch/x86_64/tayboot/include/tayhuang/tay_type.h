// SPDX-License-Identifier: GPL-2.0-only
/* -------------------------------*-TayhuangOS-*-----------------------------------
 *
 *   Copyright (C) 2022, 2022 TayhuangOS Development Team - All Rights Reserved
 *
 * --------------------------------------------------------------------------------
 *
 * Author: Flysong
 *
 * kernel/boot/include/tayhuang/tay_type.h
 *
 * Types are declared here
 */



#pragma once

typedef unsigned char bool;
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long long qword;
typedef word addr_t;
typedef byte b8;
typedef word b16;
typedef dword b32;
typedef qword b64;
typedef b16 sreg_t;
typedef b8 reg8_t;
typedef b16 reg16_t;
typedef b32 reg32_t;
typedef b64 reg64_t;
typedef word id_t;
typedef void *handle_t;
#define true (1)
#define false (0)
#define NULL (0)

#define asmv asm volatile
#define ed_callasm() asmv("addw $2, %sp")
#define cpu_relax() asmv("rep; nop")