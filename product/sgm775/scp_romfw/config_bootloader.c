/*
 * Arm SCP/MCP Software
 * Copyright (c) 2017-2019, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <fwk_element.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <mod_bootloader.h>
#include <system_mmap.h>
#include <system_mmap_scp.h>
#include <sgm775_sds.h>

static const struct mod_bootloader_config bootloader_module_config = {
    .source_base = TRUSTED_RAM_BASE,
    .source_size = 256 * 1024,
    .destination_base = SCP_RAM_BASE,
    .destination_size = SCP_RAM_SIZE,
    .sds_struct_id = SGM775_SDS_BOOTLOADER,
};

struct fwk_module_config config_bootloader = {
    .data = &bootloader_module_config,
};
