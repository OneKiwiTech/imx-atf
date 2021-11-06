/*
 * Copyright 2019-2020 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _PIE_H_
#define _PIE_H_

struct pie {
	uint32_t addr;
	uint16_t data;
};

static const struct pie pie_udimm[] = {
	{0x90000, 0x10},
	{0x90001, 0x400},
	{0x90002, 0x10e},
	{0x90003, 0x0},
	{0x90004, 0x0},
	{0x90005, 0x8},
	{0x90029, 0xb},
	{0x9002a, 0x480},
	{0x9002b, 0x109},
	{0x9002c, 0x8},
	{0x9002d, 0x448},
	{0x9002e, 0x139},
	{0x9002f, 0x8},
	{0x90030, 0x478},
	{0x90031, 0x109},
	{0x90032, 0x2},
	{0x90033, 0x10},
	{0x90034, 0x139},
	{0x90035, 0xb},
	{0x90036, 0x7c0},
	{0x90037, 0x139},
	{0x90038, 0x44},
	{0x90039, 0x633},
	{0x9003a, 0x159},
	{0x9003b, 0x14f},
	{0x9003c, 0x630},
	{0x9003d, 0x159},
	{0x9003e, 0x47},
	{0x9003f, 0x633},
	{0x90040, 0x149},
	{0x90041, 0x4f},
	{0x90042, 0x633},
	{0x90043, 0x179},
	{0x90044, 0x8},
	{0x90045, 0xe0},
	{0x90046, 0x109},
	{0x90047, 0x0},
	{0x90048, 0x7c8},
	{0x90049, 0x109},
	{0x9004a, 0x0},
	{0x9004b, 0x1},
	{0x9004c, 0x8},
	{0x9004d, 0x0},
	{0x9004e, 0x45a},
	{0x9004f, 0x9},
	{0x90050, 0x0},
	{0x90051, 0x448},
	{0x90052, 0x109},
	{0x90053, 0x40},
	{0x90054, 0x633},
	{0x90055, 0x179},
	{0x90056, 0x1},
	{0x90057, 0x618},
	{0x90058, 0x109},
	{0x90059, 0x40c0},
	{0x9005a, 0x633},
	{0x9005b, 0x149},
	{0x9005c, 0x8},
	{0x9005d, 0x4},
	{0x9005e, 0x48},
	{0x9005f, 0x4040},
	{0x90060, 0x633},
	{0x90061, 0x149},
	{0x90062, 0x0},
	{0x90063, 0x4},
	{0x90064, 0x48},
	{0x90065, 0x40},
	{0x90066, 0x633},
	{0x90067, 0x149},
	{0x90068, 0x10},
	{0x90069, 0x4},
	{0x9006a, 0x18},
	{0x9006b, 0x0},
	{0x9006c, 0x4},
	{0x9006d, 0x78},
	{0x9006e, 0x549},
	{0x9006f, 0x633},
	{0x90070, 0x159},
	{0x90071, 0xd49},
	{0x90072, 0x633},
	{0x90073, 0x159},
	{0x90074, 0x94a},
	{0x90075, 0x633},
	{0x90076, 0x159},
	{0x90077, 0x441},
	{0x90078, 0x633},
	{0x90079, 0x149},
	{0x9007a, 0x42},
	{0x9007b, 0x633},
	{0x9007c, 0x149},
	{0x9007d, 0x1},
	{0x9007e, 0x633},
	{0x9007f, 0x149},
	{0x90080, 0x0},
	{0x90081, 0xe0},
	{0x90082, 0x109},
	{0x90083, 0xa},
	{0x90084, 0x10},
	{0x90085, 0x109},
	{0x90086, 0x9},
	{0x90087, 0x3c0},
	{0x90088, 0x149},
	{0x90089, 0x9},
	{0x9008a, 0x3c0},
	{0x9008b, 0x159},
	{0x9008c, 0x18},
	{0x9008d, 0x10},
	{0x9008e, 0x109},
	{0x9008f, 0x0},
	{0x90090, 0x3c0},
	{0x90091, 0x109},
	{0x90092, 0x18},
	{0x90093, 0x4},
	{0x90094, 0x48},
	{0x90095, 0x18},
	{0x90096, 0x4},
	{0x90097, 0x58},
	{0x90098, 0xb},
	{0x90099, 0x10},
	{0x9009a, 0x109},
	{0x9009b, 0x1},
	{0x9009c, 0x10},
	{0x9009d, 0x109},
	{0x9009e, 0x5},
	{0x9009f, 0x7c0},
	{0x900a0, 0x109},
	{0x900a1, 0x0},
	{0x900a2, 0x8140},
	{0x900a3, 0x10c},
	{0x900a4, 0x10},
	{0x900a5, 0x8138},
	{0x900a6, 0x104},
	{0x900a7, 0x8},
	{0x900a8, 0x448},
	{0x900a9, 0x109},
	{0x900aa, 0xf},
	{0x900ab, 0x7c0},
	{0x900ac, 0x109},
	{0x900ad, 0x47},
	{0x900ae, 0x630},
	{0x900af, 0x109},
	{0x900b0, 0x8},
	{0x900b1, 0x618},
	{0x900b2, 0x109},
	{0x900b3, 0x8},
	{0x900b4, 0xe0},
	{0x900b5, 0x109},
	{0x900b6, 0x0},
	{0x900b7, 0x7c8},
	{0x900b8, 0x109},
	{0x900b9, 0x8},
	{0x900ba, 0x8140},
	{0x900bb, 0x10c},
	{0x900bc, 0x0},
	{0x900bd, 0x478},
	{0x900be, 0x109},
	{0x900bf, 0x0},
	{0x900c0, 0x1},
	{0x900c1, 0x8},
	{0x900c2, 0x8},
	{0x900c3, 0x4},
	{0x900c4, 0x0},
	{0x90006, 0x8},
	{0x90007, 0x7c8},
	{0x90008, 0x109},
	{0x90009, 0x0},
	{0x9000a, 0x400},
	{0x9000b, 0x106},
	{0xd00e7, 0x400},
	{0x90017, 0x0},
	{0x90026, 0x2a},
};

static const struct pie pie_rdimm[] = {
	{0x90000, 0x10},
	{0x90001, 0x400},
	{0x90002, 0x10e},
	{0x90003, 0x0},
	{0x90004, 0x0},
	{0x90005, 0x8},
	{0x40000, 0x10},
	{0x40020, 0x0},
	{0x40040, 0x0},
	{0x40060, 0x0},
	{0x40001, 0x70a},
	{0x40021, 0x7005},
	{0x40041, 0x0},
	{0x40061, 0x2001},
	{0x40002, 0x4010},
	{0x40022, 0x0},
	{0x40042, 0x0},
	{0x40062, 0x0},
	{0x90029, 0x10},
	{0x9002a, 0x400},
	{0x9002b, 0x16e},
	{0x9002c, 0x8},
	{0x9002d, 0x370},
	{0x9002e, 0x169},
	{0x9002f, 0x8},
	{0x90030, 0x7aa},
	{0x90031, 0x6a},
	{0x90032, 0x10},
	{0x90033, 0x7b2},
	{0x90034, 0x6a},
	{0x90035, 0x0},
	{0x90036, 0x48a},
	{0x90037, 0x6a},
	{0x90038, 0x9},
	{0x90039, 0x480},
	{0x9003a, 0x16a},
	{0x9003b, 0x4},
	{0x9003c, 0x790},
	{0x9003d, 0x16a},
	{0x9003e, 0xc},
	{0x9003f, 0x408},
	{0x90040, 0x169},
	{0x90041, 0xa},
	{0x90042, 0x0},
	{0x90043, 0x68},
	{0x90044, 0x0},
	{0x90045, 0x408},
	{0x90046, 0x169},
	{0x90047, 0x1},
	{0x90048, 0x480},
	{0x90049, 0x16a},
	{0x9004a, 0xb},
	{0x9004b, 0x480},
	{0x9004c, 0x109},
	{0x9004d, 0x8},
	{0x9004e, 0x448},
	{0x9004f, 0x139},
	{0x90050, 0x78},
	{0x90051, 0x8},
	{0x90052, 0x139},
	{0x90053, 0x2},
	{0x90054, 0x10},
	{0x90055, 0x139},
	{0x90056, 0xb},
	{0x90057, 0x7c0},
	{0x90058, 0x139},
	{0x90059, 0x44},
	{0x9005a, 0x633},
	{0x9005b, 0x159},
	{0x9005c, 0x14f},
	{0x9005d, 0x630},
	{0x9005e, 0x159},
	{0x9005f, 0x47},
	{0x90060, 0x633},
	{0x90061, 0x149},
	{0x90062, 0x4f},
	{0x90063, 0x633},
	{0x90064, 0x179},
	{0x90065, 0x8},
	{0x90066, 0xe0},
	{0x90067, 0x109},
	{0x90068, 0x0},
	{0x90069, 0x7c8},
	{0x9006a, 0x109},
	{0x9006b, 0x0},
	{0x9006c, 0x1},
	{0x9006d, 0x8},
	{0x9006e, 0x0},
	{0x9006f, 0x45a},
	{0x90070, 0x9},
	{0x90071, 0x0},
	{0x90072, 0x448},
	{0x90073, 0x109},
	{0x90074, 0x40},
	{0x90075, 0x633},
	{0x90076, 0x179},
	{0x90077, 0x1},
	{0x90078, 0x618},
	{0x90079, 0x109},
	{0x9007a, 0x40c0},
	{0x9007b, 0x633},
	{0x9007c, 0x149},
	{0x9007d, 0x8},
	{0x9007e, 0x4},
	{0x9007f, 0x48},
	{0x90080, 0x4040},
	{0x90081, 0x633},
	{0x90082, 0x149},
	{0x90083, 0x0},
	{0x90084, 0x4},
	{0x90085, 0x48},
	{0x90086, 0x40},
	{0x90087, 0x633},
	{0x90088, 0x149},
	{0x90089, 0x10},
	{0x9008a, 0x4},
	{0x9008b, 0x18},
	{0x9008c, 0x0},
	{0x9008d, 0x4},
	{0x9008e, 0x78},
	{0x9008f, 0x549},
	{0x90090, 0x633},
	{0x90091, 0x159},
	{0x90092, 0xd49},
	{0x90093, 0x633},
	{0x90094, 0x159},
	{0x90095, 0x94a},
	{0x90096, 0x633},
	{0x90097, 0x159},
	{0x90098, 0x441},
	{0x90099, 0x633},
	{0x9009a, 0x149},
	{0x9009b, 0x42},
	{0x9009c, 0x633},
	{0x9009d, 0x149},
	{0x9009e, 0x1},
	{0x9009f, 0x633},
	{0x900a0, 0x149},
	{0x900a1, 0x0},
	{0x900a2, 0xe0},
	{0x900a3, 0x109},
	{0x900a4, 0xa},
	{0x900a5, 0x10},
	{0x900a6, 0x109},
	{0x900a7, 0x9},
	{0x900a8, 0x3c0},
	{0x900a9, 0x149},
	{0x900aa, 0x9},
	{0x900ab, 0x3c0},
	{0x900ac, 0x159},
	{0x900ad, 0x18},
	{0x900ae, 0x10},
	{0x900af, 0x109},
	{0x900b0, 0x0},
	{0x900b1, 0x3c0},
	{0x900b2, 0x109},
	{0x900b3, 0x18},
	{0x900b4, 0x4},
	{0x900b5, 0x48},
	{0x900b6, 0x18},
	{0x900b7, 0x4},
	{0x900b8, 0x58},
	{0x900b9, 0xb},
	{0x900ba, 0x10},
	{0x900bb, 0x109},
	{0x900bc, 0x1},
	{0x900bd, 0x10},
	{0x900be, 0x109},
	{0x900bf, 0x5},
	{0x900c0, 0x7c0},
	{0x900c1, 0x109},
	{0x900c2, 0x3},
	{0x900c3, 0x370},
	{0x900c4, 0x169},
	{0x900c5, 0x3},
	{0x900c6, 0x8},
	{0x900c7, 0x139},
	{0x900c8, 0x0},
	{0x900c9, 0x400},
	{0x900ca, 0x16e},
	{0x900cb, 0x8},
	{0x900cc, 0x478},
	{0x900cd, 0x109},
	{0x900ce, 0x0},
	{0x900cf, 0x8140},
	{0x900d0, 0x10c},
	{0x900d1, 0x10},
	{0x900d2, 0x8138},
	{0x900d3, 0x10c},
	{0x900d4, 0x8},
	{0x900d5, 0x7c8},
	{0x900d6, 0x101},
	{0x900d7, 0x7a},
	{0x900d8, 0x8},
	{0x900d9, 0x109},
	{0x900da, 0x8},
	{0x900db, 0x448},
	{0x900dc, 0x109},
	{0x900dd, 0xf},
	{0x900de, 0x7c0},
	{0x900df, 0x109},
	{0x900e0, 0x47},
	{0x900e1, 0x630},
	{0x900e2, 0x109},
	{0x900e3, 0x8},
	{0x900e4, 0x618},
	{0x900e5, 0x109},
	{0x900e6, 0x8},
	{0x900e7, 0xe0},
	{0x900e8, 0x109},
	{0x900e9, 0x0},
	{0x900ea, 0x8},
	{0x900eb, 0x109},
	{0x900ec, 0x0},
	{0x900ed, 0x7c8},
	{0x900ee, 0x109},
	{0x900ef, 0x8},
	{0x900f0, 0x8140},
	{0x900f1, 0x10c},
	{0x900f2, 0x0},
	{0x900f3, 0x478},
	{0x900f4, 0x109},
	{0x900f5, 0x0},
	{0x900f6, 0x1},
	{0x900f7, 0x8},
	{0x900f8, 0x8},
	{0x900f9, 0x4},
	{0x900fa, 0x8},
	{0x900fb, 0x8},
	{0x900fc, 0x7c8},
	{0x900fd, 0x101},
	{0x90006, 0x0},
	{0x90007, 0x0},
	{0x90008, 0x8},
	{0x90009, 0x0},
	{0x9000a, 0x0},
	{0x9000b, 0x0},
	{0xd00e7, 0x400},
	{0x90017, 0x0},
	{0x90026, 0x3a},
};

static const struct pie pie_lrdimm[] = {
	{0x90000, 0x10},
	{0x90001, 0x400},
	{0x90002, 0x10e},
	{0x90003, 0x0},
	{0x90004, 0x0},
	{0x90005, 0x8},
	{0x90029, 0xb},
	{0x9002a, 0x480},
	{0x9002b, 0x109},
	{0x9002c, 0x8},
	{0x9002d, 0x448},
	{0x9002e, 0x139},
	{0x9002f, 0x78},
	{0x90030, 0x8},
	{0x90031, 0x139},
	{0x90032, 0x2},
	{0x90033, 0x10},
	{0x90034, 0x139},
	{0x90035, 0xb},
	{0x90036, 0x7c0},
	{0x90037, 0x139},
	{0x90038, 0x44},
	{0x90039, 0x633},
	{0x9003a, 0x159},
	{0x9003b, 0x14f},
	{0x9003c, 0x630},
	{0x9003d, 0x159},
	{0x9003e, 0x47},
	{0x9003f, 0x633},
	{0x90040, 0x149},
	{0x90041, 0x4f},
	{0x90042, 0x633},
	{0x90043, 0x179},
	{0x90044, 0x8},
	{0x90045, 0xe0},
	{0x90046, 0x109},
	{0x90047, 0x0},
	{0x90048, 0x7c8},
	{0x90049, 0x109},
	{0x9004a, 0x0},
	{0x9004b, 0x1},
	{0x9004c, 0x8},
	{0x9004d, 0x0},
	{0x9004e, 0x45a},
	{0x9004f, 0x9},
	{0x90050, 0x0},
	{0x90051, 0x448},
	{0x90052, 0x109},
	{0x90053, 0x40},
	{0x90054, 0x633},
	{0x90055, 0x179},
	{0x90056, 0x1},
	{0x90057, 0x618},
	{0x90058, 0x109},
	{0x90059, 0x40c0},
	{0x9005a, 0x633},
	{0x9005b, 0x149},
	{0x9005c, 0x8},
	{0x9005d, 0x4},
	{0x9005e, 0x48},
	{0x9005f, 0x4040},
	{0x90060, 0x633},
	{0x90061, 0x149},
	{0x90062, 0x0},
	{0x90063, 0x4},
	{0x90064, 0x48},
	{0x90065, 0x40},
	{0x90066, 0x633},
	{0x90067, 0x149},
	{0x90068, 0x10},
	{0x90069, 0x4},
	{0x9006a, 0x18},
	{0x9006b, 0x0},
	{0x9006c, 0x4},
	{0x9006d, 0x78},
	{0x9006e, 0x549},
	{0x9006f, 0x633},
	{0x90070, 0x159},
	{0x90071, 0xd49},
	{0x90072, 0x633},
	{0x90073, 0x159},
	{0x90074, 0x94a},
	{0x90075, 0x633},
	{0x90076, 0x159},
	{0x90077, 0x441},
	{0x90078, 0x633},
	{0x90079, 0x149},
	{0x9007a, 0x42},
	{0x9007b, 0x633},
	{0x9007c, 0x149},
	{0x9007d, 0x1},
	{0x9007e, 0x633},
	{0x9007f, 0x149},
	{0x90080, 0x0},
	{0x90081, 0xe0},
	{0x90082, 0x109},
	{0x90083, 0xa},
	{0x90084, 0x10},
	{0x90085, 0x109},
	{0x90086, 0x9},
	{0x90087, 0x3c0},
	{0x90088, 0x149},
	{0x90089, 0x9},
	{0x9008a, 0x3c0},
	{0x9008b, 0x159},
	{0x9008c, 0x18},
	{0x9008d, 0x10},
	{0x9008e, 0x109},
	{0x9008f, 0x0},
	{0x90090, 0x3c0},
	{0x90091, 0x109},
	{0x90092, 0x18},
	{0x90093, 0x4},
	{0x90094, 0x48},
	{0x90095, 0x18},
	{0x90096, 0x4},
	{0x90097, 0x58},
	{0x90098, 0xb},
	{0x90099, 0x10},
	{0x9009a, 0x109},
	{0x9009b, 0x1},
	{0x9009c, 0x10},
	{0x9009d, 0x109},
	{0x9009e, 0x5},
	{0x9009f, 0x7c0},
	{0x900a0, 0x109},
	{0x900a1, 0x3},
	{0x900a2, 0x8},
	{0x900a3, 0x139},
	{0x900a4, 0x0},
	{0x900a5, 0x400},
	{0x900a6, 0x16e},
	{0x900a7, 0x8},
	{0x900a8, 0x478},
	{0x900a9, 0x109},
	{0x900aa, 0x0},
	{0x900ab, 0x8140},
	{0x900ac, 0x10c},
	{0x900ad, 0x10},
	{0x900ae, 0x8138},
	{0x900af, 0x10c},
	{0x900b0, 0x8},
	{0x900b1, 0x7c8},
	{0x900b2, 0x101},
	{0x900b3, 0x7a},
	{0x900b4, 0x8},
	{0x900b5, 0x109},
	{0x900b6, 0x8},
	{0x900b7, 0x448},
	{0x900b8, 0x109},
	{0x900b9, 0xf},
	{0x900ba, 0x7c0},
	{0x900bb, 0x109},
	{0x900bc, 0x47},
	{0x900bd, 0x630},
	{0x900be, 0x109},
	{0x900bf, 0x8},
	{0x900c0, 0x618},
	{0x900c1, 0x109},
	{0x900c2, 0x8},
	{0x900c3, 0xe0},
	{0x900c4, 0x109},
	{0x900c5, 0x0},
	{0x900c6, 0x8},
	{0x900c7, 0x109},
	{0x900c8, 0x0},
	{0x900c9, 0x7c8},
	{0x900ca, 0x109},
	{0x900cb, 0x8},
	{0x900cc, 0x8140},
	{0x900cd, 0x10c},
	{0x900ce, 0x0},
	{0x900cf, 0x478},
	{0x900d0, 0x109},
	{0x900d1, 0x0},
	{0x900d2, 0x1},
	{0x900d3, 0x8},
	{0x900d4, 0x8},
	{0x900d5, 0x4},
	{0x900d6, 0x8},
	{0x900d7, 0x8},
	{0x900d8, 0x7c8},
	{0x900d9, 0x101},
	{0x90006, 0x0},
	{0x90007, 0x0},
	{0x90008, 0x8},
	{0x90009, 0x0},
	{0x9000a, 0x0},
	{0x9000b, 0x0},
	{0xd00e7, 0x400},
	{0x90017, 0x0},
	{0x90026, 0x2e},
};

#endif
