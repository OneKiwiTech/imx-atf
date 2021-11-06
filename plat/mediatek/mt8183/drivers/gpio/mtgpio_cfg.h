/*
 * Copyright (c) 2019, MediaTek Inc. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MT_GPIO_CFG_H
#define MT_GPIO_CFG_H

#include <stdint.h>
#include <plat/common/common_def.h>

#define IOCFG_0_BASE 0x11F20000
#define IOCFG_1_BASE 0x11E80000
#define IOCFG_2_BASE 0x11E70000
#define IOCFG_3_BASE 0x11E90000
#define IOCFG_4_BASE 0x11D30000
#define IOCFG_5_BASE 0x11D20000
#define IOCFG_6_BASE 0x11C50000
#define IOCFG_7_BASE 0x11F30000

typedef struct {
	int8_t offset;
} PIN_offset;

PIN_offset PULL_offset[] = {
	/* 0 */ {6},
	/* 1 */ {7},
	/* 2 */ {8},
	/* 3 */ {9},
	/* 4 */ {11},
	/* 5 */ {12},
	/* 6 */ {13},
	/* 7 */ {14},
	/* 8 */ {0},
	/* 9 */ {26},
	/* 10 */ {27},
	/* 11 */ {10},
	/* 12 */ {17},
	/* 13 */ {6},
	/* 14 */ {7},
	/* 15 */ {8},
	/* 16 */ {9},
	/* 17 */ {10},
	/* 18 */ {11},
	/* 19 */ {12},
	/* 20 */ {13},
	/* 21 */ {14},
	/* 22 */ {15},
	/* 23 */ {16},
	/* 24 */ {17},
	/* 25 */ {18},
	/* 26 */ {19},
	/* 27 */ {20},
	/* 28 */ {21},
	/* 29 */ {-1},
	/* 30 */ {-1},
	/* 31 */ {-1},
	/* 32 */ {-1},
	/* 33 */ {-1},
	/* 34 */ {-1},
	/* 35 */ {-1},
	/* 36 */ {-1},
	/* 37 */ {-1},
	/* 38 */ {-1},
	/* 39 */ {-1},
	/* 40 */ {-1},
	/* 41 */ {-1},
	/* 42 */ {-1},
	/* 43 */ {8},
	/* 44 */ {9},
	/* 45 */ {10},
	/* 46 */ {11},
	/* 47 */ {12},
	/* 48 */ {13},
	/* 49 */ {14},
	/* 50 */ {0},
	/* 51 */ {1},
	/* 52 */ {2},
	/* 53 */ {3},
	/* 54 */ {4},
	/* 55 */ {5},
	/* 56 */ {6},
	/* 57 */ {7},
	/* 58 */ {8},
	/* 59 */ {9},
	/* 60 */ {10},
	/* 61 */ {0},
	/* 62 */ {1},
	/* 63 */ {2},
	/* 64 */ {3},
	/* 65 */ {4},
	/* 66 */ {5},
	/* 67 */ {6},
	/* 68 */ {7},
	/* 69 */ {8},
	/* 70 */ {9},
	/* 71 */ {10},
	/* 72 */ {11},
	/* 73 */ {12},
	/* 74 */ {13},
	/* 75 */ {14},
	/* 76 */ {15},
	/* 77 */ {16},
	/* 78 */ {17},
	/* 79 */ {18},
	/* 80 */ {19},
	/* 81 */ {20},
	/* 82 */ {21},
	/* 83 */ {22},
	/* 84 */ {23},
	/* 85 */ {24},
	/* 86 */ {25},
	/* 87 */ {26},
	/* 88 */ {27},
	/* 89 */ {24},
	/* 90 */ {1},
	/* 91 */ {-1},
	/* 92 */ {-1},
	/* 93 */ {-1},
	/* 94 */ {-1},
	/* 95 */ {15},
	/* 96 */ {17},
	/* 97 */ {18},
	/* 98 */ {19},
	/* 99 */ {20},
	/* 100 */ {21},
	/* 101 */ {22},
	/* 102 */ {23},
	/* 103 */ {28},
	/* 104 */ {29},
	/* 105 */ {30},
	/* 106 */ {31},
	/* 107 */ {0},
	/* 108 */ {1},
	/* 109 */ {2},
	/* 110 */ {3},
	/* 111 */ {4},
	/* 112 */ {5},
	/* 113 */ {6},
	/* 114 */ {7},
	/* 115 */ {8},
	/* 116 */ {9},
	/* 117 */ {10},
	/* 118 */ {11},
	/* 119 */ {12},
	/* 120 */ {13},
	/* 121 */ {14},
	/* 122 */ {-1},
	/* 123 */ {-1},
	/* 124 */ {-1},
	/* 125 */ {-1},
	/* 126 */ {-1},
	/* 127 */ {-1},
	/* 128 */ {-1},
	/* 129 */ {-1},
	/* 130 */ {-1},
	/* 131 */ {-1},
	/* 132 */ {-1},
	/* 133 */ {-1},
	/* 134 */ {0},
	/* 135 */ {1},
	/* 136 */ {2},
	/* 137 */ {3},
	/* 138 */ {4},
	/* 139 */ {5},
	/* 140 */ {6},
	/* 141 */ {7},
	/* 142 */ {8},
	/* 143 */ {9},
	/* 144 */ {11},
	/* 145 */ {12},
	/* 146 */ {13},
	/* 147 */ {14},
	/* 148 */ {15},
	/* 149 */ {16},
	/* 150 */ {18},
	/* 151 */ {19},
	/* 152 */ {20},
	/* 153 */ {21},
	/* 154 */ {22},
	/* 155 */ {23},
	/* 156 */ {24},
	/* 157 */ {25},
	/* 158 */ {26},
	/* 159 */ {27},
	/* 160 */ {28},
	/* 161 */ {0},
	/* 162 */ {1},
	/* 163 */ {2},
	/* 164 */ {3},
	/* 165 */ {4},
	/* 166 */ {5},
	/* 167 */ {11},
	/* 168 */ {12},
	/* 169 */ {13},
	/* 170 */ {14},
	/* 171 */ {15},
	/* 172 */ {16},
	/* 173 */ {17},
	/* 174 */ {18},
	/* 175 */ {19},
	/* 176 */ {20},
	/* 177 */ {10},
	/* 178 */ {16},
	/* 179 */ {25}
};
#endif /* MT_GPIO_CFG_H */
