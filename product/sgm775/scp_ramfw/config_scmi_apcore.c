/*
 * Arm SCP/MCP Software
 * Copyright (c) 2018-2019, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <fwk_element.h>
#include <fwk_macros.h>
#include <fwk_module.h>
#include <mod_scmi_apcore.h>
#include <sgm775_core.h>
#include <sgm775_pik.h>

static const struct mod_scmi_apcore_reset_register_group
    reset_reg_group_table[] = {
        {
            .base_register =
                (uintptr_t)&PIK_CLUS0->STATIC_CONFIG[0].RVBARADDR_LW,
            .register_count = SGM775_CORE_PER_CLUSTER_MAX,
        },
    };

const struct fwk_module_config config_scmi_apcore = {
    .data = &((struct mod_scmi_apcore_config){
        .reset_register_width = MOD_SCMI_APCORE_REG_WIDTH_64,
        .reset_register_group_count =
            FWK_ARRAY_SIZE(reset_reg_group_table),
        .reset_register_group_table = &reset_reg_group_table[0],
    }),
};
