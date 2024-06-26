/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022, 2024 Qualcomm Innovation Center, Inc. All rights reserved.
 */
#if !defined(_IPA_REG_DUMP_H_)
#define _IPA_REG_DUMP_H_

#include <linux/types.h>
#include <linux/string.h>

#include "ipa_i.h"
#include "gsihal.h"
#include "gsihal_reg.h"

#include "ipa_pkt_cntxt.h"
#include "ipa_hw_common_ex.h"

#define IPA_0_IPA_WRAPPER_BASE 0 /* required by following includes */

#include "ipa_hwio.h"
#include "gsi_hwio.h"
#include "ipa_gcc_hwio.h"

#include "ipa_hwio_def.h"
#include "gsi_hwio_def.h"
#include "ipa_gcc_hwio_def.h"

#define IPA_DEBUG_CMDQ_DPS_SELECT_NUM_GROUPS              0x6
#define IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS              0x4
#define IPA_DEBUG_TESTBUS_RSRC_NUM_EP                     7
#define IPA_DEBUG_TESTBUS_RSRC_NUM_GRP                    3
#define IPA_TESTBUS_SEL_EP_MAX                            0x1F
#define IPA_TESTBUS_SEL_EXTERNAL_MAX                      0x40
#define IPA_TESTBUS_SEL_INTERNAL_MAX                      0xFF
#define IPA_TESTBUS_SEL_INTERNAL_PIPE_MAX                 0x40
#define IPA_DEBUG_CMDQ_ACK_SELECT_NUM_GROUPS              0x9
#define IPA_RSCR_MNGR_DB_RSRC_ID_MAX                      0x3F
#define IPA_RSCR_MNGR_DB_RSRC_TYPE_MAX                    0xA
#define IPA_REG_SAVE_FC_STATE_OFFSET                      7
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_ZEROS            (0x0)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_0            (0x1)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_1            (0x2)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_2            (0x3)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_3            (0x4)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_4            (0x5)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_DB_ENG           (0x9)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_0            (0xB)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_1            (0xC)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_2            (0xD)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_3            (0xE)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_4            (0xF)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_5            (0x10)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_6            (0x11)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_7            (0x12)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_0            (0x13)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_1            (0x14)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_2            (0x15)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_3            (0x16)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_4            (0x17)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_5            (0x18)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_0             (0x1B)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_1             (0x1C)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_0             (0x1F)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_1             (0x20)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_2             (0x21)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_3             (0x22)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_4             (0x23)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_0           (0x27)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_1           (0x28)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_2           (0x29)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_3           (0x2A)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_0            (0x2B)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_1            (0x2C)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_2            (0x2D)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_3            (0x2E)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_0          (0x33)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_1          (0x34)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_2          (0x35)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_3          (0x36)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR              (0x3A)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_SDMA_0           (0x3C)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_SDMA_1           (0x3D)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_2             (0x1D)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_1            (0x3E)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_2            (0x3F)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_5            (0x40)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_5             (0x41)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_3            (0x42)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TLV_0            (0x43)
#define HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_8            (0x44)
#define IPA_DEBUG_TESTBUS_DEF_EXTERNAL                    50
#define IPA_DEBUG_TESTBUS_DEF_INTERNAL                    6
#define IPA_REG_SAVE_GSI_NUM_EE                           3
#define IPA_REG_SAVE_NUM_EXTRA_ENDP_REGS                  22
#define IPA_GSI_OFFSET_WORDS_SCRATCH_FOR_SEQ_LOW          18
#define IPA_GSI_OFFSET_WORDS_SCRATCH_FOR_SEQ_HIGH         19
#define IPA_DEBUG_TESTBUS_RSRC_TYPE_CNT_BIT_MASK          0x7E000
#define IPA_DEBUG_TESTBUS_RSRC_TYPE_CNT_SHIFT             13
#define IPA_REG_SAVE_HWP_GSI_EE                           2
#define GSI_HW_DEBUG_SW_MSK_REG_ARRAY_LENGTH              9
#define GSI_HW_DEBUG_SW_MSK_REG_MAXk                      2

/*
 * A structure used to map a source address to destination address...
 */
struct map_src_dst_addr_s {
	u32  src_addr; /* register offset to copy value from */
	u32 *dst_addr; /* memory address to copy register value to */
	u8 perm; /* r\w permission as parsed from hwio */
};

/* a macro to generate a number of MAX n allowed in a register
 * who has suffix of _n
 */
#define GEN_MAX_n(reg_name) \
  HWIO_ ## reg_name ## _MAXn

/* a macro to generate a number of MAX k allowed in a register
 * who has suffix of _k
 */
#define GEN_MAX_k(reg_name) \
  HWIO_ ## reg_name ## _MAXk

/*
 * A macro to generate the names of scaler (ie. non-vector) registers
 * that reside in the *hwio.h files (said files contain the manifest
 * constants for the registers' offsets in the register memory map).
 */
#define GEN_SCALER_REG_OFST(reg_name) \
	(HWIO_ ## reg_name ## _ADDR)

/*
 * A macro designed to generate the rmsk associated with reg_name
 */
#define GEN_SCALER_REG_RMSK(reg_name) \
	(HWIO_ ## reg_name ## _RMSK)

/*
 * A macro designed to generate the attr associated with reg_name
 * this is actually r\w permissions, bits [1][0] ==> [W][R]
 */
#define REG_READ_PERM BIT(0)
#define REG_WRITE_PERM BIT(1)
#define GEN_REG_ATTR(reg_name) \
	(HWIO_ ## reg_name ## _ATTR)

/*
 * A macro to generate the names of vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate access to registers that are
 * addressed via one dimension.
 */
#define GEN_1xVECTOR_REG_OFST(reg_name, row) \
	(HWIO_ ## reg_name ## _ADDR(row))

/*
 * A macro to generate the names of vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate access to registers that are
 * addressed via two dimensions.
 */
#define GEN_2xVECTOR_REG_OFST(reg_name, row, col) \
	(HWIO_ ## reg_name ## _ADDR(row, col))

/*
 * A macro to generate the access to scaler registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate read access from a scaler
 * register..
 */
#define IPA_READ_SCALER_REG(reg_name) \
	HWIO_ ## reg_name ## _IN

/*
 * A macro to generate the access to vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate read access from a one
 * dimensional vector register...
 */
#define IPA_READ_1xVECTOR_REG(reg_name, row) \
	HWIO_ ## reg_name ## _INI(row)

/*
 * A macro to generate the access to vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate read access from a two
 * dimensional vector register...
 */
#define IPA_READ_2xVECTOR_REG(reg_name, row, col) \
	HWIO_ ## reg_name ## _INI2(row, col)

/*
 * A macro to generate the access to scaler registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate write access to a scaler
 * register..
 */
#define IPA_WRITE_SCALER_REG(reg_name, val) \
	HWIO_ ## reg_name ## _OUT(val)

/*
 * Similar to the above, but with val masked by the register's rmsk...
 */
#define IPA_MASKED_WRITE_SCALER_REG(reg_name, val) \
	out_dword(GEN_SCALER_REG_OFST(reg_name), \
			  (GEN_SCALER_REG_RMSK(reg_name) & val), \
			   GEN_REG_ATTR(reg_name))

/*
 * A macro to generate the access to vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate write access to a one
 * dimensional vector register...
 */
#define IPA_WRITE_1xVECTOR_REG(reg_name, row, val) \
	HWIO_ ## reg_name ## _OUTI(row, val)

/*
 * A macro to generate the access to vector registers that reside in
 * the *hwio.h files (said files contain the manifest constants for
 * the registers' offsets in the register memory map). More
 * specifically, this macro will generate write access to a two
 * dimensional vector register...
 */
#define IPA_WRITE_2xVECTOR_REG(reg_name, row, col, val) \
	HWIO_ ## reg_name ## _OUTI2(row, col, val)

 /*
  * Macro that helps generate a mapping between a register's address
  * and where the register's value will get stored (ie. source and
  * destination address mapping) upon dump...
  */
#define GEN_SRC_DST_ADDR_MAP(reg_name, sub_struct, field_name) \
	{ GEN_SCALER_REG_OFST(reg_name), \
	  (u32 *)&ipa_reg_save.sub_struct.field_name , \
	  GEN_REG_ATTR(reg_name) }

/*
 * Macro to get value of bits 18:13, used tp get rsrc cnts from
 * IPA_DEBUG_DATA
 */
#define IPA_DEBUG_TESTBUS_DATA_GET_RSRC_CNT_BITS_FROM_DEBUG_DATA(x) \
	((x & IPA_DEBUG_TESTBUS_RSRC_TYPE_CNT_BIT_MASK) >> \
	 IPA_DEBUG_TESTBUS_RSRC_TYPE_CNT_SHIFT)

/*
 * Macro to get rsrc cnt of specific rsrc type and rsrc grp from test
 * bus collected data
 */
#define IPA_DEBUG_TESTBUS_GET_RSRC_TYPE_CNT(rsrc_type, rsrc_grp) \
	IPA_DEBUG_TESTBUS_DATA_GET_RSRC_CNT_BITS_FROM_DEBUG_DATA( \
		ipa_reg_save.ipa.testbus->ep_rsrc[rsrc_type].entry_ep \
		[rsrc_grp].testbus_data.value)

/*
 * Macro to pluck the gsi version from ram.
 */
#define IPA_REG_SAVE_GSI_VER(reg_name, var_name)	\
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.gsi.gen.var_name,\
		GEN_REG_ATTR(reg_name) }
/*
 * Macro to define a particular register cfg entry for all 3 EE
 * indexed register
 */
#define IPA_REG_SAVE_CFG_ENTRY_GEN_EE(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE), \
		(u32 *)&ipa_reg_save.ipa.gen_ee[IPA_HW_Q6_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE), \
		(u32 *)&ipa_reg_save.ipa.gen_ee[IPA_HW_A7_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE), \
		(u32 *)&ipa_reg_save.ipa.gen_ee[IPA_HW_UC_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_HWP_EE), \
		(u32 *)&ipa_reg_save.ipa.gen_ee[IPA_HW_HWP_EE].var_name, \
		GEN_REG_ATTR(reg_name) }

#define IPA_REG_SAVE_CFG_ENTRY_GSI_FIFO(reg_name, var_name, index) \
	{ GEN_SCALER_REG_OFST(reg_name), \
		(u32 *)&ipa_reg_save.ipa.gsi_fifo_status[index].var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for all pipe
 * indexed register
 */
#define IPA_REG_SAVE_CFG_ENTRY_PIPE_ENDP_EXTRA(reg_name, var_name) \
	{ 0, 0 }

/*
 * Macro to define a particular register cfg entry for all resource
 * group register
 */
#define IPA_REG_SAVE_CFG_ENTRY_SRC_RSRC_GRP(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_grp[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_grp[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_grp[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 3), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_grp[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 4), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_grp[4].var_name, \
	GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for all resource
 * group register
 */
#define IPA_REG_SAVE_CFG_ENTRY_DST_RSRC_GRP(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.ipa.dst_rsrc_grp[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.ipa.dst_rsrc_grp[1].var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for all source
 * resource group count register
 */
#define IPA_REG_SAVE_CFG_ENTRY_SRC_RSRC_CNT_GRP(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_cnt[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_cnt[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_cnt[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 3), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_cnt[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 4), \
		(u32 *)&ipa_reg_save.ipa.src_rsrc_cnt[4].var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for all dest
 * resource group count register
 */
#define IPA_REG_SAVE_CFG_ENTRY_DST_RSRC_CNT_GRP(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.ipa.dst_rsrc_cnt[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.ipa.dst_rsrc_cnt[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.ipa.dst_rsrc_cnt[2].var_name, \
		GEN_REG_ATTR(reg_name) }

#define IPA_REG_SAVE_CFG_ENTRY_GSI_GENERAL_EE(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE), \
		(u32 *)&ipa_reg_save.gsi.gen_ee[IPA_HW_A7_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE), \
		(u32 *)&ipa_reg_save.gsi.gen_ee[IPA_HW_Q6_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_REG_SAVE_HWP_GSI_EE), \
		(u32 *)&ipa_reg_save.gsi.gen_ee[IPA_REG_SAVE_HWP_GSI_EE].\
		var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for all GSI EE
 * register
 */
#define IPA_REG_SAVE_CFG_ENTRY_GSI_CH_CNTXT(reg_name, var_name) \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 0), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 8), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[8].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 9), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[9].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 10), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[10].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 11), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[11].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 12), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[12].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 13), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[13].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 14), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[14].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 15), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[15].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 16), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[16].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 17), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[17].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 18), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[18].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 19), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[19].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 20), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[20].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 21), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[21].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 22), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[22].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 23), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[23].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 24), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[24].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 25), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[25].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 26), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[26].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 27), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[27].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 28), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[28].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 29), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[29].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 30), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.a7[30].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 0), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.uc[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 0), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 8), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[8].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 9), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[9].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 10), \
		(u32 *)&ipa_reg_save.gsi.ch_cntxt.q6[10].var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a debug SW MSK register entry for all (n, k)
 * k bound by GSI_HW_DEBUG_SW_MSK_REG_MAXk
 */
#define IPA_REG_SAVE_GSI_DEBUG_MSK_REG_ENTRY(reg_name, var_name) \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 0, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[0].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 0, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[0].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 1, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[1].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 1, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[1].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 2, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[2].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 2, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[2].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 3, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[3].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 3, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[3].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 4, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[4].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 4, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[4].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 5, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[5].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 5, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[5].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 6, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[6].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 6, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[6].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 7, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[7].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 7, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[7].var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 8, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[8].var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, 8, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.debug_sw_msk.mask_reg[8].var_name[1], \
		GEN_REG_ATTR(reg_name) }

#define IPA_REG_SAVE_CFG_ENTRY_GSI_EVT_CNTXT(reg_name, var_name) \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 0), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 8), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[8].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 9), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[9].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 10), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[10].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 11), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[11].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 12), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[12].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 13), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[13].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 14), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[14].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 15), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[15].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 16), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[16].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 17), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[17].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 18), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[18].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 19), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[19].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 20), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[20].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 21), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[21].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 22), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[22].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 23), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[23].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 24), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[24].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 25), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[25].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 26), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[27].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 28), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[28].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 29), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[29].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 30), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.a7[30].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 0), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.uc[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 0),	\
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[0].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 1), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[1].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 2), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[2].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 3), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[3].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 4), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[4].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 5), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[5].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 6), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[6].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 7), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[7].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 8), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[8].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 9), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[9].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 10), \
		(u32 *)&ipa_reg_save.gsi.evt_cntxt.q6[10].var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * Macro to define a particular register cfg entry for GSI QSB debug
 * registers
 */
#define IPA_REG_SAVE_CFG_ENTRY_GSI_QSB_DEBUG(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.gsi.debug.gsi_qsb_debug.var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.gsi.debug.gsi_qsb_debug.var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.gsi.debug.gsi_qsb_debug.var_name[2], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 3), \
		(u32 *)&ipa_reg_save.gsi.debug.gsi_qsb_debug.var_name[3], \
		GEN_REG_ATTR(reg_name) }

#define IPA_REG_SAVE_RX_SPLT_CMDQ(reg_name, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.ipa.dbg.var_name[0], \
		GEN_REG_ATTR(reg_name)}, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.ipa.dbg.var_name[1], \
		GEN_REG_ATTR(reg_name)}, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.ipa.dbg.var_name[2], \
		GEN_REG_ATTR(reg_name)}, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 3), \
		(u32 *)&ipa_reg_save.ipa.dbg.var_name[3], \
		GEN_REG_ATTR(reg_name) }

/*
 * Macros to save array registers
 */

/*
 * helper macro to save array register of MAXn = 0
 */
#define GEN_SRC_DST_ADDR_MAP_ARR_0(reg_name, sub_struct, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[0], \
		GEN_REG_ATTR(reg_name) }

/*
 * helper macro to save array register of MAXn = 1
 */
#define GEN_SRC_DST_ADDR_MAP_ARR_1(reg_name, sub_struct, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[1], \
		GEN_REG_ATTR(reg_name) }
 /*
 * helper macro to save array register of MAXn = 31
 */
#define GEN_SRC_DST_ADDR_MAP_ARR_31(reg_name, sub_struct, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 0), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[0], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 1), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[1], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 2), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[2], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 3), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[3], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 4), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[4], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 5), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[5], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 6), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[6], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 7), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[7], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 8), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[8], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 9), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[9], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 10), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[10], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 11), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[11], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 12), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[12], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 13), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[13], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 14), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[14], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 15), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[15], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 16), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[16], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 17), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[17], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 18), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[18], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 19), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[19], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 20), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[20], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 21), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[21], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 22), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[22], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 23), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[23], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 24), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[24], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 25), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[25], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 26), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[26], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 27), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[27], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 28), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[28], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 29), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[29], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 30), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[30], \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, 31), \
		(u32 *)&ipa_reg_save.sub_struct.var_name[31], \
		GEN_REG_ATTR(reg_name) }


#define __IPA_CONCATENATE(A, B) A ## B
#define IPA_CONCATENATE(A, B) __IPA_CONCATENATE(A, B)

/*
 * helper macro to save array register
 */
#define GEN_SRC_DST_ADDR_MAP_ARR(reg_name, sub_struct, var_name) \
	IPA_CONCATENATE(GEN_SRC_DST_ADDR_MAP_ARR_, \
	GEN_MAX_n(reg_name))(reg_name, sub_struct, var_name)


/*
 * Macros to save multi EE array registers
 */

/*
 * helper macro to save EE array register of MAXk = 0
 */
#define GEN_SRC_DST_ADDR_MAP_EE_n_REG_k_ARR_0(reg_name, sub_struct, var_name) \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_A7_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_Q6_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_UC_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }

/*
 * helper macro to save EE array register of MAXk = 1
 */
#define GEN_SRC_DST_ADDR_MAP_EE_n_REG_k_ARR_1(reg_name, sub_struct, var_name) \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_A7_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE, 1), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_A7_EE].var_name.arr[1].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_Q6_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE, 1), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_Q6_EE].var_name.arr[1].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 0), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_UC_EE].var_name.arr[0].value, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_2xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE, 1), \
	(u32 *)&ipa_reg_save.sub_struct[IPA_HW_UC_EE].var_name.arr[1].value, \
		GEN_REG_ATTR(reg_name) }

/*
 * helper macro to save EE n reg k array register
 */
#define GEN_SRC_DST_ADDR_MAP_EE_n_REG_k_ARR(reg_name, sub_struct, var_name) \
	IPA_CONCATENATE(GEN_SRC_DST_ADDR_MAP_EE_n_REG_k_ARR_, \
	GEN_MAX_k(reg_name))(reg_name, sub_struct, var_name)

/*
 * helper macro to save EE n array register
 */
#define GEN_SRC_DST_ADDR_MAP_EE_n_ARR(reg_name, sub_struct, var_name) \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_Q6_EE), \
		(u32 *)&ipa_reg_save.sub_struct[IPA_HW_Q6_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_A7_EE), \
		(u32 *)&ipa_reg_save.sub_struct[IPA_HW_A7_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_HW_UC_EE), \
		(u32 *)&ipa_reg_save.sub_struct[IPA_HW_UC_EE].var_name, \
		GEN_REG_ATTR(reg_name) }, \
	{ GEN_1xVECTOR_REG_OFST(reg_name, IPA_REG_SAVE_HWP_GSI_EE), \
		(u32 *)&ipa_reg_save.sub_struct[IPA_REG_SAVE_HWP_GSI_EE].\
		var_name, \
		GEN_REG_ATTR(reg_name) }

/*
 * helper macro to wrap struct intended for array as regs array
 * in order to create array with max_k == 1 we need to declare
 * it as arr[max_k + 1] -> arr[2]
 */
#define GEN_REGS_ARRAY(struct_name, reg_name) \
	struct IPA_CONCATENATE(struct_name, _arr) { \
		union struct_name arr[GEN_MAX_k(reg_name) + 1]; \
	}

//#define REGS_ARRAY struct struct_name regs[GEN_MAX_k(reg_name)]

/*
 * IPA HW Platform Type
 */
enum ipa_hw_ee_e {
	IPA_HW_A7_EE  = 0, /* A7's execution environment */
	IPA_HW_Q6_EE  = 1, /* Q6's execution environment */
	IPA_HW_UC_EE =  2, /* uC's execution environment */
	IPA_HW_HWP_EE = 3, /* HWP's execution environment */
	IPA_HW_EE_MAX,     /* Max EE to support */
};

#define IPA_MAX_EE_TO_COLLECT IPA_HW_UC_EE

/*
 * General IPA register save data struct (ie. this is where register
 * values, once read, get placed...
 */
struct ipa_gen_regs_s {
	struct ipa_hwio_def_ipa_state_s
		ipa_state;
	struct ipa_hwio_def_ipa_state_rx_active_n_s
		ipa_state_rx_active_n[GEN_MAX_n(IPA_STATE_RX_ACTIVE_n) + 1];
	struct ipa_hwio_def_ipa_state_tx_wrapper_s
		ipa_state_tx_wrapper;
	struct ipa_hwio_def_ipa_state_tx_s
		ipa_state_tx;
	struct ipa_hwio_def_ipa_state_tx_holb_mask_dps_tx_0_s
		ipa_state_tx_holb_mask_dps_tx_0;
	struct ipa_hwio_def_ipa_state_tx_holb_mask_dps_tx_1_s
		ipa_state_tx_holb_mask_dps_tx_1;
	struct ipa_hwio_def_ipa_state_tx_holb_mask_ntf_tx_0_s
		ipa_state_tx_holb_mask_ntf_tx_0;
	struct ipa_hwio_def_ipa_state_tx_holb_mask_ntf_tx_1_s
		ipa_state_tx_holb_mask_ntf_tx_1;
	struct ipa_hwio_def_ipa_state_aggr_active_n_s
		ipa_state_aggr_active_n[GEN_MAX_n(IPA_STATE_AGGR_ACTIVE_n) + 1];
	struct ipa_hwio_def_ipa_state_dfetcher_s
		ipa_state_dfetcher;
	struct ipa_hwio_def_ipa_state_gsi_aos_s
		ipa_state_gsi_aos;
	struct ipa_hwio_def_ipa_state_gsi_if_s
		ipa_state_gsi_if;
	struct ipa_hwio_def_ipa_dpl_timer_lsb_s
		ipa_dpl_timer_lsb;
	struct ipa_hwio_def_ipa_dpl_timer_msb_s
		ipa_dpl_timer_msb;
	struct ipa_hwio_def_ipa_proc_iph_cfg_s
		ipa_proc_iph_cfg;
	struct ipa_hwio_def_ipa_route_s
		ipa_route;
	struct ipa_hwio_def_ipa_spare_reg_1_s
		ipa_spare_reg_1;
	struct ipa_hwio_def_ipa_cons_log_s
		ipa_cons_log;
	struct ipa_hwio_def_ipa_log_buf_hw_cmd_cfg_s
		ipa_log_buf_hw_cmd_cfg;
	struct ipa_hwio_def_ipa_log_buf_hw_cmd_addr_s
		ipa_log_buf_hw_cmd_addr;
	struct ipa_hwio_def_ipa_log_buf_hw_cmd_write_ptr_s
		ipa_log_buf_hw_cmd_write_ptr;
	struct ipa_hwio_def_ipa_log_buf_hw_cmd_ram_ptr_s
		ipa_log_buf_hw_cmd_ram_ptr;
	struct ipa_hwio_def_ipa_comp_hw_version_s
		ipa_comp_hw_version;
	struct ipa_hwio_def_ipa_filt_rout_cache_cfg_s
		ipa_filt_rout_cache_cfg;
	struct ipa_hwio_def_ipa_filt_rout_cache_flush_s
		ipa_filt_rout_cache_flush;
	struct ipa_hwio_def_ipa_state_fetcher_s
		ipa_state_fetcher;
	struct ipa_hwio_def_ipa_state_fetcher_mask_0_s
		ipa_state_fetcher_mask_0;
	struct ipa_hwio_def_ipa_state_fetcher_mask_1_s
		ipa_state_fetcher_mask_1;
	struct ipa_hwio_def_ipa_state_fetcher_mask_2_s
		ipa_state_fetcher_mask_2;
	struct ipa_hwio_def_ipa_ipv4_filter_init_values_s
		ipa_ipv4_filter_init_values;
	struct ipa_hwio_def_ipa_ipv6_filter_init_values_s
		ipa_ipv6_filter_init_values;
	struct ipa_hwio_def_ipa_ipv4_route_init_values_s
		ipa_ipv4_route_init_values;
	struct ipa_hwio_def_ipa_ipv6_route_init_values_s
		ipa_ipv6_route_init_values;
	struct ipa_hwio_def_ipa_log_buf_hw_cmd_noc_master_sel_s
		ipa_log_buf_hw_cmd_noc_master_sel;
	struct ipa_hwio_def_ipa_state_acl_s
		ipa_state_acl;
	struct ipa_hwio_def_ipa_sys_pkt_proc_cntxt_base_s
		ipa_sys_pkt_proc_cntxt_base;
	struct ipa_hwio_def_ipa_sys_pkt_proc_cntxt_base_msb_s
		ipa_sys_pkt_proc_cntxt_base_msb;
	struct ipa_hwio_def_ipa_local_pkt_proc_cntxt_base_s
		ipa_local_pkt_proc_cntxt_base;
	struct ipa_hwio_def_ipa_rsrc_grp_cfg_s
		ipa_rsrc_grp_cfg;
	struct ipa_hwio_def_ipa_rsrc_grp_cfg_ext_s
		ipa_rsrc_grp_cfg_ext;
	struct ipa_hwio_def_ipa_comp_cfg_s
		ipa_comp_cfg;
	struct ipa_hwio_def_ipa_state_prod_dpl_fifo_s
		ipa_state_dpl_fifo;
	struct ipa_hwio_def_ipa_state_nlo_aggr_s
	  ipa_state_nlo_aggr;
	struct ipa_hwio_def_ipa_state_coal_master_s
	  ipa_state_coal_master;
	struct ipa_hwio_def_ipa_state_coal_master_1_s
	  ipa_state_coal_master_1;
	struct ipa_hwio_def_ipa_state_coal_master_1_s
	  ipa_state_coal_master_2;
	struct ipa_hwio_def_ipa_state_coal_master_1_s
	  ipa_state_coal_master_3;
	struct ipa_hwio_def_ipa_coal_evict_lru_s
	  ipa_coal_evict_lru;
	struct ipa_hwio_def_ipa_coal_qmap_cfg_s
	  ipa_coal_qmap_cfg;
	struct ipa_hwio_def_ipa_tag_timer_s
	  ipa_tag_timer;
	struct ipa_hwio_def_ipa_nlo_pp_cfg1_s
	  ipa_nlo_pp_cfg1;
	struct ipa_hwio_def_ipa_nlo_pp_cfg2_s
	  ipa_nlo_pp_cfg2;
	struct ipa_hwio_def_ipa_nlo_min_dsm_cfg_s
	  ipa_nlo_min_dsm_cfg;
	struct ipa_hwio_def_ipa_nlo_vp_aggr_cfg_lsb_n_s
	  ipa_nlo_vp_aggr_cfg_lsb_n[GEN_MAX_n(IPA_NLO_VP_AGGR_CFG_LSB_n) + 1];
	struct ipa_hwio_def_ipa_nlo_vp_limit_cfg_n_s
		ipa_nlo_vp_limit_cfg_n[GEN_MAX_n(IPA_NLO_VP_LIMIT_CFG_n) + 1];
	struct ipa_hwio_def_ipa_nlo_vp_flush_req_s
	  ipa_nlo_vp_flush_req;
	struct ipa_hwio_def_ipa_nlo_vp_flush_cookie_s
	  ipa_nlo_vp_flush_cookie;
	struct ipa_hwio_def_ipa_nlo_vp_flush_ack_s
	  ipa_nlo_vp_flush_ack;
	struct ipa_hwio_def_ipa_nlo_vp_dsm_open_s
	  ipa_nlo_vp_dsm_open;
	struct ipa_hwio_def_ipa_nlo_vp_qbap_open_s
	  ipa_nlo_vp_qbap_open;
	struct ipa_hwio_def_ipa_qsb_max_reads_s
	  ipa_qsb_max_reads;
	struct ipa_hwio_def_ipa_qsb_max_writes_s
	  ipa_qsb_max_writes;
	struct ipa_hwio_def_ipa_idle_indication_cfg_s
	  ipa_idle_indication_cfg;
	struct ipa_hwio_def_ipa_clkon_cfg_s
	  ipa_clkon_cfg;
	struct ipa_hwio_def_ipa_timers_xo_clk_div_cfg_s
	  ipa_timers_xo_clk_div_cfg;
	struct ipa_hwio_def_ipa_timers_pulse_gran_cfg_s
	  ipa_timers_pulse_gran_cfg;
	struct ipa_hwio_def_ipa_qtime_timestamp_cfg_s
	  ipa_qtime_timestamp_cfg;
	struct ipa_hwio_def_ipa_flavor_0_s
	  ipa_flavor_0;
	struct ipa_hwio_def_ipa_flavor_1_s
	  ipa_flavor_1;
	struct ipa_hwio_def_ipa_flavor_2_s
	  ipa_flavor_2;
	struct ipa_hwio_def_ipa_flavor_3_s
	  ipa_flavor_3;
	struct ipa_hwio_def_ipa_flavor_4_s
	  ipa_flavor_4;
	struct ipa_hwio_def_ipa_flavor_5_s
	  ipa_flavor_5;
	struct ipa_hwio_def_ipa_flavor_6_s
	  ipa_flavor_6;
	struct ipa_hwio_def_ipa_flavor_7_s
	  ipa_flavor_7;
	struct ipa_hwio_def_ipa_flavor_8_s
	  ipa_flavor_8;
	struct ipa_hwio_def_ipa_flavor_9_s
	  ipa_flavor_9;
	struct ipa_hwio_def_ipa_flavor_10_s
	  ipa_flavor_10;
	struct ipa_hwio_def_ipa_state_tsp_s
	  ipa_state_tsp;
	struct ipa_hwio_def_ipa_filt_rout_cfg_s
	  ipa_filt_rout_cfg;
	struct ipa_hwio_def_ipa_bus_master_legacy_bursts_s
	  ipa_bus_master_legacy_bursts;
	struct ipa_hwio_def_ipa_cons_log_threshold_cfg_s
	  ipa_cons_log_threshold_cfg;
	struct ipa_hwio_def_ipa_prod_log_s
	  ipa_prod_log;
	struct ipa_hwio_def_ipa_prod_log_threshold_cfg_s
	  ipa_prod_log_threshold_cfg;
	struct ipa_hwio_def_ipa_ram_ingress_policer_db_base_addr_s
	  ipa_ram_ingress_policer_db_base_addr;
	struct ipa_hwio_def_ipa_ram_egress_shaping_prod_db_base_addr_s
	  ipa_ram_egress_shaping_prod_db_base_addr;
	struct ipa_hwio_def_ipa_ram_egress_shaping_tc_db_base_addr_s
	  ipa_ram_egress_shaping_tc_db_base_addr;
	struct ipa_hwio_def_ipa_dpl_timer_ctl_sts_s
	  ipa_dpl_timer_ctl_sts;
	struct ipa_hwio_def_ipa_state_coal_slave_s
	  ipa_state_coal_slave;
	struct ipa_hwio_def_ipa_state_rqos_s
	  ipa_state_rqos;
	struct ipa_hwio_def_ipa_ipv4_nat_exc_suppress_rout_table_indx_s
	  ipa_ipv4_nat_exc_suppress_rout_table_indx;
	struct ipa_hwio_def_ipa_ipv6_conn_track_exc_suppress_rout_table_indx_s
	  ipa_ipv6_conn_track_exc_suppress_rout_table_indx;
	struct ipa_hwio_def_ipa_dpl_timer_sw_adj_lsb_s
	  ipa_dpl_timer_sw_adj_lsb;
	struct ipa_hwio_def_ipa_dpl_timer_sw_adj_msb_s
	  ipa_dpl_timer_sw_adj_msb;
	struct ipa_hwio_def_ipa_tsp_qm_external_baddr_lsb_s
	  ipa_tsp_qm_external_baddr_lsb;
	struct ipa_hwio_def_ipa_tsp_qm_external_baddr_msb_s
	  ipa_tsp_qm_external_baddr_msb;
	struct ipa_hwio_def_ipa_tsp_qm_external_size_s
	  ipa_tsp_qm_external_size;
	struct ipa_hwio_def_ipa_tsp_ingress_policing_cfg_s
	  ipa_tsp_ingress_policing_cfg;
	struct ipa_hwio_def_ipa_tsp_egress_policing_cfg_s
	  ipa_tsp_egress_policing_cfg;
	struct ipa_hwio_def_ipa_stat_tsp_drop_base_s
	  ipa_stat_tsp_drop_base;
	struct ipa_hwio_def_ipa_state_qmngr_queue_nonempty_s
	  ipa_state_qmngr_queue_nonempty;
	struct ipa_hwio_def_ipa_state_prod_dpl_fifo_s
	  ipa_state_prod_dpl_fifo;
};

/*
 * General IPA register save data struct
 */
struct ipa_reg_save_gen_ee_s {
	struct ipa_hwio_def_ipa_irq_stts_ee_n_s
	  ipa_irq_stts_ee_n;
	struct ipa_hwio_def_ipa_irq_en_ee_n_s
	  ipa_irq_en_ee_n;
	struct ipa_hwio_def_ipa_fec_fatal_addr_ee_n_s
	  ipa_fec_fatal_addr_ee_n;
	struct ipa_hwio_def_ipa_fec_fatal_attr_ee_n_s
	  ipa_fec_fatal_attr_ee_n;
	struct ipa_hwio_def_ipa_snoc_fec_ee_n_s
	  ipa_snoc_fec_ee_n;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_holb_drop_irq_info_ee_n_reg_k_u,
		IPA_HOLB_DROP_IRQ_INFO_EE_n_REG_k)
		ipa_holb_drop_irq_info_ee_n_reg_k;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_suspend_irq_info_ee_n_reg_k_u,
		IPA_SUSPEND_IRQ_INFO_EE_n_REG_k)
		ipa_suspend_irq_info_ee_n_reg_k;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_suspend_irq_en_ee_n_reg_k_u,
		IPA_SUSPEND_IRQ_EN_EE_n_REG_k)
		ipa_suspend_irq_en_ee_n_reg_k;
};

/*
 * statistics IPA register save data struct
 */

struct ipa_reg_save_stat_ee_s {
	struct ipa_hwio_def_ipa_stat_quota_base_n_s
		ipa_stat_quota_base_n;
	struct ipa_hwio_def_ipa_stat_tethering_base_n_s
		ipa_stat_tethering_base_n;
	struct ipa_hwio_def_ipa_stat_drop_cnt_base_n_s
		ipa_stat_drop_cnt_base_n;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_stat_quota_mask_ee_n_reg_k_u,
		IPA_STAT_QUOTA_MASK_EE_n_REG_k)
		ipa_stat_quota_mask_ee_n_reg_k;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_stat_tethering_mask_ee_n_reg_k_u,
		IPA_STAT_TETHERING_MASK_EE_n_REG_k)
		ipa_stat_tethering_mask_ee_n_reg_k;
	GEN_REGS_ARRAY(ipa_hwio_def_ipa_stat_drop_cnt_mask_ee_n_reg_k_u,
		IPA_STAT_DROP_CNT_MASK_EE_n_REG_k)
		ipa_stat_drop_cnt_mask_ee_n_reg_k;
};

/*
 * Pipe Endp IPA register save data struct
 */
struct ipa_reg_save_pipe_endp_s {
	struct ipa_hwio_def_ipa_endp_init_ctrl_n_s
	  ipa_endp_init_ctrl_n;
	struct ipa_hwio_def_ipa_endp_init_ctrl_scnd_n_s
	  ipa_endp_init_ctrl_scnd_n;
	struct ipa_hwio_def_ipa_endp_init_cfg_n_s
	  ipa_endp_init_cfg_n;
	struct ipa_hwio_def_ipa_endp_init_nat_n_s
	  ipa_endp_init_nat_n;
	struct ipa_hwio_def_ipa_endp_init_hdr_n_s
	  ipa_endp_init_hdr_n;
	struct ipa_hwio_def_ipa_endp_init_hdr_ext_n_s
	  ipa_endp_init_hdr_ext_n;
	struct ipa_hwio_def_ipa_endp_init_hdr_metadata_mask_n_s
	  ipa_endp_init_hdr_metadata_mask_n;
	struct ipa_hwio_def_ipa_endp_init_hdr_metadata_n_s
	  ipa_endp_init_hdr_metadata_n;
	struct ipa_hwio_def_ipa_endp_init_mode_n_s
	  ipa_endp_init_mode_n;
	struct ipa_hwio_def_ipa_endp_init_aggr_n_s
	  ipa_endp_init_aggr_n;
	struct ipa_hwio_def_ipa_endp_init_hol_block_en_n_s
	  ipa_endp_init_hol_block_en_n;
	struct ipa_hwio_def_ipa_endp_init_hol_block_timer_n_s
	  ipa_endp_init_hol_block_timer_n;
	struct ipa_hwio_def_ipa_endp_init_deaggr_n_s
	  ipa_endp_init_deaggr_n;
	struct ipa_hwio_def_ipa_endp_status_n_s
	  ipa_endp_status_n;
	struct ipa_hwio_def_ipa_endp_init_rsrc_grp_n_s
	  ipa_endp_init_rsrc_grp_n;
	struct ipa_hwio_def_ipa_endp_init_seq_n_s
	  ipa_endp_init_seq_n;
	struct ipa_hwio_def_ipa_endp_gsi_cfg_tlv_n_s
	  ipa_endp_gsi_cfg_tlv_n;
	struct ipa_hwio_def_ipa_endp_gsi_cfg_aos_n_s
	  ipa_endp_gsi_cfg_aos_n;
	struct ipa_hwio_def_ipa_endp_gsi_cfg1_n_s
	  ipa_endp_gsi_cfg1_n;
	struct ipa_hwio_def_ipa_filter_cache_cfg_n_s
		ipa_filter_cache_cfg_n;
	struct ipa_hwio_def_ipa_router_cache_cfg_n_s
		ipa_router_cache_cfg_n;
	struct ipa_hwio_def_ipa_endp_init_nat_exc_suppress_n_s
		ipa_endp_init_nat_exc_suppress_n;
};

/*
 * Pipe IPA register save data struct
 */
struct ipa_reg_save_pipe_s {
	u8				active;
	struct ipa_reg_save_pipe_endp_s endp;
};

/*
 * HWP IPA register save data struct
 */
struct ipa_reg_save_hwp_s {
	struct ipa_hwio_def_ipa_uc_qmb_sys_addr_s
	  ipa_uc_qmb_sys_addr;
	struct ipa_hwio_def_ipa_uc_qmb_local_addr_s
	  ipa_uc_qmb_local_addr;
	struct ipa_hwio_def_ipa_uc_qmb_length_s
	  ipa_uc_qmb_length;
	struct ipa_hwio_def_ipa_uc_qmb_trigger_s
	  ipa_uc_qmb_trigger;
	struct ipa_hwio_def_ipa_uc_qmb_bus_attrib_s
	  ipa_uc_qmb_bus_attrib;
};

/*
 * IPA TESTBUS entry struct
 */
struct ipa_reg_save_ipa_testbus_entry_s {
	union ipa_hwio_def_ipa_testbus_sel_u testbus_sel;
	union ipa_hwio_def_ipa_debug_data_u testbus_data;
};

/* IPA TESTBUS global struct */
struct ipa_reg_save_ipa_testbus_global_s {
	struct ipa_reg_save_ipa_testbus_entry_s
	global[IPA_TESTBUS_SEL_INTERNAL_MAX + 1]
	[IPA_TESTBUS_SEL_EXTERNAL_MAX + 1];
};

/* IPA TESTBUS per EP struct */
struct ipa_reg_save_ipa_testbus_ep_s {
	struct ipa_reg_save_ipa_testbus_entry_s
	entry_ep[IPA_TESTBUS_SEL_INTERNAL_PIPE_MAX + 1]
	[IPA_TESTBUS_SEL_EXTERNAL_MAX + 1];
};

/* IPA TESTBUS per EP struct */
struct ipa_reg_save_ipa_testbus_ep_rsrc_s {
	struct ipa_reg_save_ipa_testbus_entry_s
	  entry_ep[IPA_DEBUG_TESTBUS_RSRC_NUM_GRP];
};

/* IPA TESTBUS save data struct */
struct ipa_reg_save_ipa_testbus_s {
	struct ipa_reg_save_ipa_testbus_global_s global;
	struct ipa_reg_save_ipa_testbus_ep_s
	  ep[IPA_TESTBUS_SEL_EP_MAX + 1];
	struct ipa_reg_save_ipa_testbus_ep_rsrc_s
	  ep_rsrc[IPA_DEBUG_TESTBUS_RSRC_NUM_EP];
};

/*
 * Debug IPA register save data struct
 */
struct ipa_reg_save_dbg_s {
	struct ipa_hwio_def_ipa_debug_data_s
	  ipa_debug_data;
	struct ipa_hwio_def_ipa_rx_splt_cmdq_cmd_n_s
	  ipa_rx_splt_cmdq_cmd_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_cfg_n_s
	 ipa_rx_splt_cmdq_cfg_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_wr_0_n_s
	  ipa_rx_splt_cmdq_data_wr_0_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_wr_1_n_s
	  ipa_rx_splt_cmdq_data_wr_1_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_wr_2_n_s
	  ipa_rx_splt_cmdq_data_wr_2_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_wr_3_n_s
	  ipa_rx_splt_cmdq_data_wr_3_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_rd_0_n_s
	  ipa_rx_splt_cmdq_data_rd_0_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_rd_1_n_s
	  ipa_rx_splt_cmdq_data_rd_1_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_rd_2_n_s
	  ipa_rx_splt_cmdq_data_rd_2_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_data_rd_3_n_s
	  ipa_rx_splt_cmdq_data_rd_3_n[IPA_RX_SPLT_CMDQ_MAX];
	struct ipa_hwio_def_ipa_rx_splt_cmdq_status_n_s
	  ipa_rx_splt_cmdq_status_n[IPA_RX_SPLT_CMDQ_MAX];

	union ipa_hwio_def_ipa_rx_hps_cmdq_cfg_wr_u
		ipa_rx_hps_cmdq_cfg_wr;
	union ipa_hwio_def_ipa_rx_hps_cmdq_cfg_rd_u
		ipa_rx_hps_cmdq_cfg_rd;

	struct ipa_hwio_def_ipa_rx_hps_cmdq_cmd_s
	  ipa_rx_hps_cmdq_cmd;
	struct ipa_hwio_def_ipa_stat_filter_ipv4_base_s
		ipa_stat_filter_ipv4_base;
	struct ipa_hwio_def_ipa_stat_filter_ipv6_base_s
		ipa_stat_filter_ipv6_base;
	struct ipa_hwio_def_ipa_stat_router_ipv4_base_s
		ipa_stat_router_ipv4_base;
	struct ipa_hwio_def_ipa_stat_router_ipv6_base_s
		ipa_stat_router_ipv6_base;
	union ipa_hwio_def_ipa_rx_hps_cmdq_data_rd_0_u
		ipa_rx_hps_cmdq_data_rd_0_arr[
		IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_rx_hps_cmdq_data_rd_1_u
		ipa_rx_hps_cmdq_data_rd_1_arr[
		IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_rx_hps_cmdq_data_rd_2_u
		ipa_rx_hps_cmdq_data_rd_2_arr[
		IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_rx_hps_cmdq_data_rd_3_u
		ipa_rx_hps_cmdq_data_rd_3_arr[
		IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_rx_hps_cmdq_count_u
	  ipa_rx_hps_cmdq_count_arr[IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_rx_hps_cmdq_status_u
	  ipa_rx_hps_cmdq_status_arr[IPA_DEBUG_CMDQ_HPS_SELECT_NUM_GROUPS];
	struct ipa_hwio_def_ipa_rx_hps_cmdq_status_empty_s
	  ipa_rx_hps_cmdq_status_empty;
	struct ipa_hwio_def_ipa_rsrc_mngr_contexts_s
		ipa_rsrc_mngr_contexts;
	struct ipa_hwio_def_ipa_snoc_monitoring_cfg_s
		ipa_snoc_monitoring_cfg;
	struct ipa_hwio_def_ipa_pcie_snoc_monitor_cnt_s
		ipa_pcie_snoc_monitor_cnt;
	struct ipa_hwio_def_ipa_ddr_snoc_monitor_cnt_s
		ipa_ddr_snoc_monitor_cnt;
	struct ipa_hwio_def_ipa_gsi_snoc_monitor_cnt_s
		ipa_gsi_snoc_monitor_cnt;
	struct ipa_hwio_def_ipa_ram_sniffer_hw_base_addr_s
		ipa_ram_sniffer_hw_base_addr;
	struct ipa_hwio_def_ipa_bresp_db_cfg_s
		ipa_bresp_db_cfg;
	struct ipa_hwio_def_ipa_bresp_db_data_s
		ipa_bresp_db_data;
	struct ipa_hwio_def_ipa_bresp_db_data_1_s
		ipa_bresp_db_data_1;
	struct ipa_hwio_def_ipa_endp_gsi_cons_bytes_tlv_s
		ipa_endp_gsi_cons_bytes_tlv;
	struct ipa_hwio_def_ipa_ram_gsi_tlv_base_addr_s
		ipa_ram_gsi_tlv_base_addr;
	struct ipa_hwio_def_ipa_rx_hps_clients_min_depth_0_s
	  ipa_rx_hps_clients_min_depth_0;
	struct ipa_hwio_def_ipa_rx_hps_clients_max_depth_0_s
	  ipa_rx_hps_clients_max_depth_0;
	struct ipa_hwio_def_ipa_hps_dps_cmdq_cmd_s
	  ipa_hps_dps_cmdq_cmd;
	union ipa_hwio_def_ipa_hps_dps_cmdq_data_rd_0_u
		ipa_hps_dps_cmdq_data_rd_0_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_hps_dps_cmdq_count_u
		ipa_hps_dps_cmdq_count_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_hps_dps_cmdq_status_u
		ipa_hps_dps_cmdq_status_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	struct ipa_hwio_def_ipa_hps_dps_cmdq_status_empty_n_s
		ipa_hps_dps_cmdq_status_empty_n[
			GEN_MAX_n(IPA_HPS_DPS_CMDQ_STATUS_EMPTY_n) + 1];
	struct ipa_hwio_def_ipa_dps_tx_cmdq_cmd_s
	  ipa_dps_tx_cmdq_cmd;
	union ipa_hwio_def_ipa_dps_tx_cmdq_data_rd_0_u
		ipa_dps_tx_cmdq_data_rd_0_arr[
		IPA_DEBUG_CMDQ_DPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_dps_tx_cmdq_count_u
		ipa_dps_tx_cmdq_count_arr[IPA_DEBUG_CMDQ_DPS_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_dps_tx_cmdq_status_u
	ipa_dps_tx_cmdq_status_arr[IPA_DEBUG_CMDQ_DPS_SELECT_NUM_GROUPS];
	struct ipa_hwio_def_ipa_dps_tx_cmdq_status_empty_s
	  ipa_dps_tx_cmdq_status_empty;

	struct ipa_hwio_def_ipa_ackmngr_cmdq_cmd_s
	  ipa_ackmngr_cmdq_cmd;
	union ipa_hwio_def_ipa_ackmngr_cmdq_data_rd_u
		ipa_ackmngr_cmdq_data_rd_arr[
		IPA_DEBUG_CMDQ_ACK_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_ackmngr_cmdq_count_u
	  ipa_ackmngr_cmdq_count_arr[IPA_DEBUG_CMDQ_ACK_SELECT_NUM_GROUPS];
	union ipa_hwio_def_ipa_ackmngr_cmdq_status_u
		ipa_ackmngr_cmdq_status_arr[
		IPA_DEBUG_CMDQ_ACK_SELECT_NUM_GROUPS];
	struct ipa_hwio_def_ipa_ackmngr_cmdq_status_empty_n_s
	  ipa_ackmngr_cmdq_status_empty_n[
			GEN_MAX_n(IPA_ACKMNGR_CMDQ_STATUS_EMPTY_n) + 1];
	struct ipa_hwio_def_ipa_prod_ackmngr_cmdq_cmd_s
	  ipa_prod_ackmngr_cmdq_cmd;
	union ipa_hwio_def_ipa_prod_ackmngr_cmdq_data_rd_u
		ipa_prod_ackmngr_cmdq_data_rd_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_prod_ackmngr_cmdq_count_u
		ipa_prod_ackmngr_cmdq_count_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_prod_ackmngr_cmdq_status_u
		ipa_prod_ackmngr_cmdq_status_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	struct ipa_hwio_def_ipa_prod_ackmngr_cmdq_status_empty_n_s
		ipa_prod_ackmngr_cmdq_status_empty_n[GEN_MAX_n(
			IPA_PROD_ACKMNGR_CMDQ_STATUS_EMPTY_n) + 1];
	struct ipa_hwio_def_ipa_ntf_tx_cmdq_cmd_s
	  ipa_ntf_tx_cmdq_cmd;
	union ipa_hwio_def_ipa_ntf_tx_cmdq_data_rd_0_u
		ipa_ntf_tx_cmdq_data_rd_0_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_ntf_tx_cmdq_count_u
		ipa_ntf_tx_cmdq_count_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	union ipa_hwio_def_ipa_ntf_tx_cmdq_status_u
		ipa_ntf_tx_cmdq_status_arr[IPA_TESTBUS_SEL_EP_MAX + 1];
	struct ipa_hwio_def_ipa_ntf_tx_cmdq_status_empty_n_s
		ipa_ntf_tx_cmdq_status_empty_n[GEN_MAX_n(
			IPA_NTF_TX_CMDQ_STATUS_EMPTY_n) + 1];
	union ipa_hwio_def_ipa_rsrc_mngr_db_rsrc_read_u
		ipa_rsrc_mngr_db_rsrc_read_arr[IPA_RSCR_MNGR_DB_RSRC_TYPE_MAX +
					       1][IPA_RSCR_MNGR_DB_RSRC_ID_MAX
						  + 1];
	union ipa_hwio_def_ipa_rsrc_mngr_db_list_read_u
		ipa_rsrc_mngr_db_list_read_arr[IPA_RSCR_MNGR_DB_RSRC_TYPE_MAX +
					       1][IPA_RSCR_MNGR_DB_RSRC_ID_MAX
						  + 1];
};

/* Source Resource Group IPA register save data struct */
struct ipa_reg_save_src_rsrc_grp_s {
	struct ipa_hwio_def_ipa_src_rsrc_grp_01_rsrc_type_n_s
	  ipa_src_rsrc_grp_01_rsrc_type_n;
	struct ipa_hwio_def_ipa_src_rsrc_grp_23_rsrc_type_n_s
	  ipa_src_rsrc_grp_23_rsrc_type_n;
	struct ipa_hwio_def_ipa_src_rsrc_grp_45_rsrc_type_n_s
	  ipa_src_rsrc_grp_45_rsrc_type_n;
	struct ipa_hwio_def_ipa_src_rsrc_grp_67_rsrc_type_n_s
		ipa_src_rsrc_grp_67_rsrc_type_n;
	struct ipa_hwio_def_ipa_src_rsrc_type_amount_n_s
		ipa_src_rsrc_type_amount;
};

/* Source Resource Group IPA register save data struct */
struct ipa_reg_save_dst_rsrc_grp_s {
	struct ipa_hwio_def_ipa_dst_rsrc_grp_01_rsrc_type_n_s
	  ipa_dst_rsrc_grp_01_rsrc_type_n;
	struct ipa_hwio_def_ipa_dst_rsrc_grp_23_rsrc_type_n_s
	  ipa_dst_rsrc_grp_23_rsrc_type_n;
	struct ipa_hwio_def_ipa_dst_rsrc_grp_45_rsrc_type_n_s
	  ipa_dst_rsrc_grp_45_rsrc_type_n;
	struct ipa_hwio_def_ipa_dst_rsrc_grp_67_rsrc_type_n_s
		ipa_dst_rsrc_grp_67_rsrc_type_n;
	struct ipa_hwio_def_ipa_dst_rsrc_type_amount_n_s
		ipa_dst_rsrc_type_amount;
};

/* Source Resource Group Count IPA register save data struct */
struct ipa_reg_save_src_rsrc_cnt_s {
	struct ipa_hwio_def_ipa_src_rsrc_grp_0123_rsrc_type_cnt_n_s
	  ipa_src_rsrc_grp_0123_rsrc_type_cnt_n;
	struct ipa_hwio_def_ipa_src_rsrc_grp_4567_rsrc_type_cnt_n_s
	  ipa_src_rsrc_grp_4567_rsrc_type_cnt_n;
};

/* Destination Resource Group Count IPA register save data struct */
struct ipa_reg_save_dst_rsrc_cnt_s {
	struct ipa_hwio_def_ipa_dst_rsrc_grp_0123_rsrc_type_cnt_n_s
	  ipa_dst_rsrc_grp_0123_rsrc_type_cnt_n;
	struct ipa_hwio_def_ipa_dst_rsrc_grp_4567_rsrc_type_cnt_n_s
	  ipa_dst_rsrc_grp_4567_rsrc_type_cnt_n;
};

/* GSI fw version data */
struct ipa_reg_save_gsi_fw_version_s {
	u32 raw_version;
	u32 hw_version;
	u32 flavor;
	u32 fw_version;
};

/* GSI General register save data struct */
struct ipa_reg_save_gsi_gen_s {
	struct gsi_hwio_def_gsi_cfg_s
	  gsi_cfg;
	struct gsi_hwio_def_gsi_ree_cfg_s
	  gsi_ree_cfg;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_inst_ram_n_s
	  ipa_gsi_top_gsi_inst_ram_n;
};

/* GSI General EE register save data struct */
struct ipa_reg_save_gsi_gen_ee_s {
	struct gsi_hwio_def_gsi_manager_ee_qos_n_s
	  gsi_manager_ee_qos_n;
	struct gsi_hwio_def_ee_n_gsi_status_s
	  ee_n_gsi_status;
	struct gsi_hwio_def_ee_n_cntxt_type_irq_s
	  ee_n_cntxt_type_irq;
	struct gsi_hwio_def_ee_n_cntxt_type_irq_msk_s
	  ee_n_cntxt_type_irq_msk;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_gsi_ch_irq_k_u,
		EE_n_CNTXT_SRC_GSI_CH_IRQ_k)
		ee_n_cntxt_src_gsi_ch_irq_k;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_ev_ch_irq_k_u,
		EE_n_CNTXT_SRC_EV_CH_IRQ_k)
		ee_n_cntxt_src_ev_ch_irq_k;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_gsi_ch_irq_msk_k_u,
		EE_n_CNTXT_SRC_GSI_CH_IRQ_MSK_k)
		ee_n_cntxt_src_gsi_ch_irq_msk_k;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_ev_ch_irq_msk_k_u,
		EE_n_CNTXT_SRC_EV_CH_IRQ_MSK_k)
		ee_n_cntxt_src_ev_ch_irq_msk_k;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_ieob_irq_k_u,
		EE_n_CNTXT_SRC_IEOB_IRQ_k)
		ee_n_cntxt_src_ieob_irq_k;
	GEN_REGS_ARRAY(gsi_hwio_def_ee_n_cntxt_src_ieob_irq_msk_k_u,
		EE_n_CNTXT_SRC_IEOB_IRQ_MSK_k)
		ee_n_cntxt_src_ieob_irq_msk_k;
	struct gsi_hwio_def_ee_n_cntxt_gsi_irq_stts_s
	  ee_n_cntxt_gsi_irq_stts;
	struct gsi_hwio_def_ee_n_cntxt_glob_irq_stts_s
	  ee_n_cntxt_glob_irq_stts;
	struct gsi_hwio_def_ee_n_error_log_s
	  ee_n_error_log;
	struct gsi_hwio_def_ee_n_cntxt_scratch_0_s
	  ee_n_cntxt_scratch_0;
	struct gsi_hwio_def_ee_n_cntxt_scratch_1_s
	  ee_n_cntxt_scratch_1;
	struct gsi_hwio_def_ee_n_cntxt_intset_s
	  ee_n_cntxt_intset;
	struct gsi_hwio_def_ee_n_cntxt_msi_base_lsb_s
	  ee_n_cntxt_msi_base_lsb;
	struct gsi_hwio_def_ee_n_cntxt_msi_base_msb_s
	  ee_n_cntxt_msi_base_msb;
};

/* GSI QSB debug register save data struct */
struct ipa_reg_save_gsi_qsb_debug_s {
	struct gsi_hwio_def_gsi_debug_qsb_log_last_misc_idn_s
	  qsb_log_last_misc[GSI_HW_QSB_LOG_MISC_MAX];
};

static u32 ipa_reg_save_gsi_ch_test_bus_selector_array[] = {
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_ZEROS,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_4,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_DB_ENG,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_4,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_5,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_6,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_7,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_4,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_EVE_5,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_4,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MOQA_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TMR_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_RD_WR_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_SDMA_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_SDMA_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IE_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_1,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_2,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_MCS_5,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_IC_5,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_CSR_3,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_TLV_0,
	HWIO_GSI_DEBUG_TEST_BUS_SELECTOR_REE_8,
};

/*
 * GSI QSB debug bus register save data struct
 */
struct ipa_reg_save_gsi_test_bus_s {
	u32 test_bus_selector[
		ARRAY_SIZE(ipa_reg_save_gsi_ch_test_bus_selector_array)];
	struct
	  gsi_hwio_def_gsi_test_bus_reg_s
	  test_bus_reg[ARRAY_SIZE(ipa_reg_save_gsi_ch_test_bus_selector_array)];
};

/* GSI debug MCS registers save data struct */
struct ipa_reg_save_gsi_mcs_regs_s {
	struct
	  gsi_hwio_def_gsi_debug_sw_rf_n_read_s
		mcs_reg[HWIO_GSI_DEBUG_SW_RF_n_READ_MAXn + 1];
};

struct ipa_reg_save_gsi_mcs_prof_regs_s {
        struct gsi_hwio_def_gsi_mcs_profiling_bp_cnt_lsb_s
	       gsi_top_gsi_mcs_profiling_bp_cnt_lsb;
	struct gsi_hwio_def_gsi_mcs_profiling_bp_cnt_msb_s
	       gsi_top_gsi_mcs_profiling_bp_cnt_msb;
	struct gsi_hwio_def_gsi_mcs_profiling_bp_and_pending_cnt_lsb_s
	       gsi_top_gsi_mcs_profiling_bp_and_pending_cnt_lsb;
	struct gsi_hwio_def_gsi_mcs_profiling_bp_and_pending_cnt_msb_s
	       gsi_top_gsi_mcs_profiling_bp_and_pending_cnt_msb;
	struct gsi_hwio_def_gsi_mcs_profiling_mcs_busy_cnt_lsb_s
	       gsi_top_gsi_mcs_profiling_mcs_busy_cnt_lsb;
	struct gsi_hwio_def_gsi_mcs_profiling_mcs_busy_cnt_msb_s
	       gsi_top_gsi_mcs_profiling_mcs_busy_cnt_msb;
	struct gsi_hwio_def_gsi_mcs_profiling_mcs_idle_cnt_lsb_s
	       gsi_top_gsi_mcs_profiling_mcs_idle_cnt_lsb;
	struct gsi_hwio_def_gsi_mcs_profiling_mcs_idle_cnt_msb_s
	       gsi_top_gsi_mcs_profiling_mcs_idle_cnt_msb;
};

/* GSI debug counters save data struct */
struct ipa_reg_save_gsi_debug_cnt_s {
	struct
	  gsi_hwio_def_gsi_debug_countern_s
		cnt[HWIO_GSI_DEBUG_COUNTERn_MAXn + 1];
};

/* GSI IRAM pointers (IEP) save data struct */
struct ipa_reg_save_gsi_iram_ptr_regs_s {
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ch_cmd_s
	  ipa_gsi_top_gsi_iram_ptr_ch_cmd;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ee_generic_cmd_s
	  ipa_gsi_top_gsi_iram_ptr_ee_generic_cmd;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ch_db_s
	  ipa_gsi_top_gsi_iram_ptr_ch_db;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ev_db_s
	  ipa_gsi_top_gsi_iram_ptr_ev_db;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_new_re_s
	  ipa_gsi_top_gsi_iram_ptr_new_re;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ch_dis_comp_s
	  ipa_gsi_top_gsi_iram_ptr_ch_dis_comp;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_ch_empty_s
	  ipa_gsi_top_gsi_iram_ptr_ch_empty;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_event_gen_comp_s
	  ipa_gsi_top_gsi_iram_ptr_event_gen_comp;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_timer_expired_s
	  ipa_gsi_top_gsi_iram_ptr_timer_expired;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_write_eng_comp_s
	  ipa_gsi_top_gsi_iram_ptr_write_eng_comp;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_read_eng_comp_s
	  ipa_gsi_top_gsi_iram_ptr_read_eng_comp;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_uc_gp_int_s
	  ipa_gsi_top_gsi_iram_ptr_uc_gp_int;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_iram_ptr_int_mod_stoped_s
		ipa_gsi_top_gsi_iram_ptr_int_mod_stoped;
};

/* GSI Debug SW registers save data struct */
struct gsi_hwio_gsi_top_gsi_debug_sw_msk_regs_entry_rd_s{
	struct gsi_hwio_def_gsi_debug_sw_msk_reg_n_sec_k_rd_s
		regs[GSI_HW_DEBUG_SW_MSK_REG_MAXk];
};

struct gsi_hwio_gsi_top_gsi_debug_sw_msk_regs_rd_s{
	struct gsi_hwio_gsi_top_gsi_debug_sw_msk_regs_entry_rd_s
		mask_reg[GSI_HW_DEBUG_SW_MSK_REG_ARRAY_LENGTH];
};

/* GSI SHRAM pointers save data struct */
struct ipa_reg_save_gsi_shram_ptr_regs_s {
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_ch_cntxt_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_ch_cntxt_base_addr;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_ev_cntxt_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_ev_cntxt_base_addr;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_re_storage_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_re_storage_base_addr;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_re_esc_buf_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_re_esc_buf_base_addr;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_ee_scrach_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_ee_scrach_base_addr;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_shram_ptr_func_stack_base_addr_s
	  ipa_gsi_top_gsi_shram_ptr_func_stack_base_addr;
};

/* GSI debug register save data struct */
struct ipa_reg_save_gsi_debug_s {
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_debug_busy_reg_s
	  ipa_gsi_top_gsi_debug_busy_reg;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_debug_pc_from_sw_s
	  ipa_gsi_top_gsi_debug_pc_from_sw;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_debug_sw_stall_s
	  ipa_gsi_top_gsi_debug_sw_stall;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_debug_pc_for_debug_s
	  ipa_gsi_top_gsi_debug_pc_for_debug;
	struct ipa_hwio_def_ipa_0_gsi_top_gsi_debug_qsb_log_err_trns_id_s
	  ipa_gsi_top_gsi_debug_qsb_log_err_trns_id;
	struct ipa_reg_save_gsi_qsb_debug_s		gsi_qsb_debug;
	struct ipa_reg_save_gsi_test_bus_s		gsi_test_bus;
	struct ipa_reg_save_gsi_mcs_regs_s		gsi_mcs_regs;
	struct ipa_reg_save_gsi_mcs_prof_regs_s		gsi_mcs_prof_regs;
	struct ipa_reg_save_gsi_debug_cnt_s		gsi_cnt_regs;
	struct ipa_reg_save_gsi_iram_ptr_regs_s		gsi_iram_ptrs;
	struct ipa_reg_save_gsi_shram_ptr_regs_s	gsi_shram_ptrs;
	struct gsi_hwio_gsi_top_gsi_debug_sw_msk_regs_rd_s
	       debug_sw_msk;
};

/* GSI MCS channel scratch registers save data struct */
struct ipa_reg_save_gsi_mcs_channel_scratch_regs_s {
	struct gsi_hwio_def_gsi_shram_n_s
	  scratch_for_seq_low;
	struct gsi_hwio_def_gsi_shram_n_s
	  scratch_for_seq_high;
};

/* GSI Channel Context register save data struct */
struct ipa_reg_save_gsi_ch_cntxt_per_ep_s {
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_0_s
	  ee_n_gsi_ch_k_cntxt_0;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_1_s
	  ee_n_gsi_ch_k_cntxt_1;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_2_s
	  ee_n_gsi_ch_k_cntxt_2;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_3_s
	  ee_n_gsi_ch_k_cntxt_3;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_4_s
	  ee_n_gsi_ch_k_cntxt_4;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_5_s
	  ee_n_gsi_ch_k_cntxt_5;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_6_s
	  ee_n_gsi_ch_k_cntxt_6;
	struct gsi_hwio_def_ee_n_gsi_ch_k_cntxt_7_s
	  ee_n_gsi_ch_k_cntxt_7;
	struct gsi_hwio_def_ee_n_gsi_ch_k_re_fetch_read_ptr_s
	  ee_n_gsi_ch_k_re_fetch_read_ptr;
	struct gsi_hwio_def_ee_n_gsi_ch_k_re_fetch_write_ptr_s
	  ee_n_gsi_ch_k_re_fetch_write_ptr;
	struct gsi_hwio_def_ee_n_gsi_ch_k_qos_s
	  ee_n_gsi_ch_k_qos;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_0_s
	  ee_n_gsi_ch_k_scratch_0;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_1_s
	  ee_n_gsi_ch_k_scratch_1;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_2_s
	  ee_n_gsi_ch_k_scratch_2;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_3_s
	  ee_n_gsi_ch_k_scratch_3;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_4_s
	  ee_n_gsi_ch_k_scratch_4;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_5_s
	  ee_n_gsi_ch_k_scratch_5;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_6_s
	  ee_n_gsi_ch_k_scratch_6;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_7_s
	  ee_n_gsi_ch_k_scratch_7;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_8_s
	  ee_n_gsi_ch_k_scratch_8;
	struct gsi_hwio_def_ee_n_gsi_ch_k_scratch_9_s
	  ee_n_gsi_ch_k_scratch_9;
	struct gsi_hwio_def_gsi_map_ee_n_ch_k_vp_table_s
	  gsi_map_ee_n_ch_k_vp_table;
	struct ipa_reg_save_gsi_mcs_channel_scratch_regs_s
	  mcs_channel_scratch;
	union ipa_hwio_def_fc_stats_state_u
	  fc_stats_state;
};

/* GSI Event Context register save data struct */
struct ipa_reg_save_gsi_evt_cntxt_per_ep_s {
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_0_s
	  ee_n_ev_ch_k_cntxt_0;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_1_s
	  ee_n_ev_ch_k_cntxt_1;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_2_s
	  ee_n_ev_ch_k_cntxt_2;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_3_s
	  ee_n_ev_ch_k_cntxt_3;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_4_s
	  ee_n_ev_ch_k_cntxt_4;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_5_s
	  ee_n_ev_ch_k_cntxt_5;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_6_s
	  ee_n_ev_ch_k_cntxt_6;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_7_s
	  ee_n_ev_ch_k_cntxt_7;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_8_s
	  ee_n_ev_ch_k_cntxt_8;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_9_s
	  ee_n_ev_ch_k_cntxt_9;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_10_s
	  ee_n_ev_ch_k_cntxt_10;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_11_s
	  ee_n_ev_ch_k_cntxt_11;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_12_s
	  ee_n_ev_ch_k_cntxt_12;
	struct gsi_hwio_def_ee_n_ev_ch_k_cntxt_13_s
	  ee_n_ev_ch_k_cntxt_13;
	struct gsi_hwio_def_ee_n_ev_ch_k_scratch_0_s
	  ee_n_ev_ch_k_scratch_0;
	struct gsi_hwio_def_ee_n_ev_ch_k_scratch_1_s
	  ee_n_ev_ch_k_scratch_1;
	struct gsi_hwio_def_gsi_debug_ee_n_ev_k_vp_table_s
	  gsi_debug_ee_n_ev_k_vp_table;
};

/* GSI FIFO status register save data struct */
struct ipa_reg_save_gsi_fifo_status_s {
	union ipa_hwio_def_ipa_gsi_fifo_status_ctrl_u
		gsi_fifo_status_ctrl;
	union ipa_hwio_def_ipa_gsi_tlv_fifo_status_u
		gsi_tlv_fifo_status;
	union ipa_hwio_def_ipa_gsi_aos_fifo_status_u
		gsi_aos_fifo_status;
};

/* GSI Channel Context register save top level data struct */
struct ipa_reg_save_gsi_ch_cntxt_s {
	struct ipa_reg_save_gsi_ch_cntxt_per_ep_s
		a7[IPA_HW_REG_SAVE_GSI_NUM_CH_CNTXT_A7];
	struct ipa_reg_save_gsi_ch_cntxt_per_ep_s
		uc[IPA_HW_REG_SAVE_GSI_NUM_CH_CNTXT_UC];
	struct ipa_reg_save_gsi_ch_cntxt_per_ep_s
		q6[IPA_HW_REG_SAVE_GSI_NUM_CH_CNTXT_Q6];
};

/* GSI Event Context register save top level data struct */
struct ipa_reg_save_gsi_evt_cntxt_s {
	struct ipa_reg_save_gsi_evt_cntxt_per_ep_s
		a7[IPA_HW_REG_SAVE_GSI_NUM_EVT_CNTXT_A7];
	struct ipa_reg_save_gsi_evt_cntxt_per_ep_s
		uc[IPA_HW_REG_SAVE_GSI_NUM_EVT_CNTXT_UC];
	struct ipa_reg_save_gsi_evt_cntxt_per_ep_s
		q6[IPA_HW_REG_SAVE_GSI_NUM_EVT_CNTXT_Q6];
};

/* Top level IPA register save data struct */
struct ipa_regs_save_hierarchy_s {
	struct ipa_gen_regs_s
		gen;
	struct ipa_reg_save_gen_ee_s
		gen_ee[IPA_HW_EE_MAX];
	struct ipa_reg_save_stat_ee_s
		stat_ee[IPA_HW_EE_MAX];
	struct ipa_reg_save_hwp_s
		hwp;
	struct ipa_reg_save_dbg_s
		dbg;
	struct ipa_reg_save_ipa_testbus_s
		*testbus;
	struct ipa_reg_save_pipe_s
		pipes[IPA_HW_PIPE_ID_MAX];
	struct ipa_reg_save_src_rsrc_grp_s
		src_rsrc_grp[IPA_HW_SRC_RSRP_TYPE_MAX];
	struct ipa_reg_save_dst_rsrc_grp_s
		dst_rsrc_grp[IPA_HW_DST_RSRP_TYPE_MAX];
	struct ipa_reg_save_src_rsrc_cnt_s
		src_rsrc_cnt[IPA_HW_SRC_RSRP_TYPE_MAX];
	struct ipa_reg_save_dst_rsrc_cnt_s
		dst_rsrc_cnt[IPA_HW_DST_RSRP_TYPE_MAX];
	u32 *ipa_iu_ptr;
	u32 *ipa_sram_ptr;
	u32 *ipa_mbox_ptr;
	u32 *ipa_hram_ptr;
	u32 *ipa_seq_ptr;
	u32 *ipa_gsi_ptr;
};

/* Top level GSI register save data struct */
struct gsi_regs_save_hierarchy_s {
	struct ipa_reg_save_gsi_fw_version_s	fw_ver;
	struct ipa_reg_save_gsi_gen_s		gen;
	struct ipa_reg_save_gsi_gen_ee_s	gen_ee[IPA_REG_SAVE_GSI_NUM_EE];
	struct ipa_reg_save_gsi_ch_cntxt_s	ch_cntxt;
	struct ipa_reg_save_gsi_evt_cntxt_s	evt_cntxt;
	struct ipa_reg_save_gsi_debug_s		debug;
};

/* Source resources for a resource group */
struct ipa_reg_save_src_rsrc_cnts_s {
	u8 pkt_cntxt;
	u8 descriptor_list;
	u8 data_descriptor_buffer;
	u8 hps_dmars;
	u8 reserved_acks;
};

/* Destination resources for a resource group */
struct ipa_reg_save_dst_rsrc_cnts_s {
	u8 reserved_sectors;
	u8 dps_dmars;
};

/* Resource count structure for a resource group */
struct ipa_reg_save_rsrc_cnts_per_grp_s {
	/* Resource group number */
	u8 resource_group;
	/* Source resources for a resource group */
	struct ipa_reg_save_src_rsrc_cnts_s src;
	/* Destination resources for a resource group */
	struct ipa_reg_save_dst_rsrc_cnts_s dst;
};

/* Top level resource count structure */
struct ipa_reg_save_rsrc_cnts_s {
	/* Resource count structure for PCIE group */
	struct ipa_reg_save_rsrc_cnts_per_grp_s pcie;
	/* Resource count structure for DDR group */
	struct ipa_reg_save_rsrc_cnts_per_grp_s ddr;
};

/*
 * Top level IPA and GSI registers save data struct
 */
struct regs_save_hierarchy_s {
	struct ipa_regs_save_hierarchy_s
		ipa;
	struct gsi_regs_save_hierarchy_s
		gsi;
	bool
		pkt_ctntx_active[IPA_HW_PKT_CTNTX_MAX];
	union ipa_hwio_def_ipa_ctxh_ctrl_u
		pkt_ctntxt_lock;
	enum ipa_hw_pkt_cntxt_state_e
		pkt_cntxt_state[IPA_HW_PKT_CTNTX_MAX];
	struct ipa_pkt_ctntx_s
		pkt_ctntx[IPA_HW_PKT_CTNTX_MAX];
	struct ipa_reg_save_rsrc_cnts_s
		rsrc_cnts;
	struct ipa_reg_save_gsi_fifo_status_s
		gsi_fifo_status[IPA_HW_PIPE_ID_MAX];
};

/*
 * The following section deals with handling IPA registers' memory
 * access relative to pre-defined memory protection schemes
 * (ie. "access control").
 *
 * In a nut shell, the intent of the data stuctures below is to allow
 * higher level register accessors to be unaware of what really is
 * going on at the lowest level (ie. real vs non-real access).  This
 * methodology is also designed to allow for platform specific "access
 * maps."
 */

/*
 * Function for doing an actual read
 */
static inline u32
act_read(void __iomem *addr)
{
	u32 val = ioread32(addr);

	return val;
}

/*
 * Function for doing an actual write
 */
static inline void
act_write(void __iomem *addr, u32 val)
{
	iowrite32(val, addr);
}

/*
 * Function that pretends to do a read
 */
static inline u32
nop_read(void __iomem *addr)
{
	return IPA_MEM_INIT_VAL;
}

/*
 * Function that pretends to do a write
 */
static inline void
nop_write(void __iomem *addr, u32 val)
{
}

/*
 * The following are used to define struct reg_access_funcs_s below...
 */
typedef u32 (*reg_read_func_t)(
	void __iomem *addr);
typedef void (*reg_write_func_t)(
	void __iomem *addr,
	u32 val);

/*
 * The following in used to define io_matrix[] below...
 */
struct reg_access_funcs_s {
	reg_read_func_t  read;
	reg_write_func_t write;
};

/*
 * The following will be used to appropriately index into the
 * read/write combos defined in io_matrix[] below...
 */
#define AA_COMBO 0 /* actual read, actual write */
#define AN_COMBO 1 /* actual read, no-op write  */
#define NA_COMBO 2 /* no-op read,  actual write */
#define NN_COMBO 3 /* no-op read,  no-op write  */

/*
 * The following will be used to dictate registers' access methods
 * relative to the state of secure debug...whether it's enabled or
 * disabled.
 *
 * NOTE: The table below defines all access combinations.
 */
static struct reg_access_funcs_s io_matrix[] = {
	{ act_read, act_write }, /* the AA_COMBO */
	{ act_read, nop_write }, /* the AN_COMBO */
	{ nop_read, act_write }, /* the NA_COMBO */
	{ nop_read, nop_write }, /* the NN_COMBO */
};

/*
 * The following will be used to define and drive IPA's register
 * access rules.
 */
struct reg_mem_access_map_t {
	u32 addr_range_begin;
	u32 addr_range_end;
	struct reg_access_funcs_s *access[2];
};

#endif /* #if !defined(_IPA_REG_DUMP_H_) */
