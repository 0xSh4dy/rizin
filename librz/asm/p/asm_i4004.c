/* radare - LGPL - Copyright 2014 - condret	*/

#include <rz_types.h>
#include <rz_util.h>
#include <rz_asm.h>
#include <rz_lib.h>
#include "../arch/i4004/i4004dis.c"

static int disassemble (RzAsm *a, RzAsmOp *op, const ut8 *buf, int len) {
	return i4004dis (op,buf,len);
}

RzAsmPlugin rz_asm_plugin_i4004 = {
	.name = "i4004",
	.desc = "Intel 4004 microprocessor",
	.arch = "i4004",
	.license = "LGPL3",
	.bits = 4,
	.endian = R_SYS_ENDIAN_NONE,
	.disassemble = &disassemble
};

#ifndef R2_PLUGIN_INCORE
RZ_API RzLibStruct radare_plugin = {
	.type = R_LIB_TYPE_ASM,
	.data = &rz_asm_plugin_i4004,
	.version = R2_VERSION
};
#endif