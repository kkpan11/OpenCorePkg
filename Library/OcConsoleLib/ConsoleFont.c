/** @file
  Default console font.

  Copyright (c) 2020-2023, Vitaly Cheptsov, Mike Beaton. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-3-Clause
**/

#include "OcConsoleLibInternal.h"

#include <Uefi.h>

/*
 * ISO Latin-1 Font
 *
 * Copyright (c) 2000
 * Ka-Ping Yee <ping@lfw.org>
 *
 * This font may be freely used for any purpose.
 */

#define PAGE0_CHAR_MIN       (32)
#define PAGE0_CHAR_MAX       (127)  ///< Use one over
#define PAGE0_FONT_HEAD      (1)
#define PAGE0_FONT_TAIL      (1)
#define PAGE0_LEFT_TO_RIGHT  (FALSE)

STATIC UINT8  mIsoFontDataPage0[(PAGE0_CHAR_MAX - PAGE0_CHAR_MIN) * (ISO_CHAR_HEIGHT - PAGE0_FONT_HEAD - PAGE0_FONT_TAIL)] = {
  /*  32 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  33 */ 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  34 */ 0x00, 0x6c, 0x6c, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  35 */ 0x00, 0x00, 0x36, 0x36, 0x7f, 0x36, 0x36, 0x7f, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00,
  /*  36 */ 0x08, 0x08, 0x3e, 0x6b, 0x0b, 0x0b, 0x3e, 0x68, 0x68, 0x6b, 0x3e, 0x08, 0x08, 0x00,
  /*  37 */ 0x00, 0x00, 0x33, 0x13, 0x18, 0x08, 0x0c, 0x04, 0x06, 0x32, 0x33, 0x00, 0x00, 0x00,
  /*  38 */ 0x00, 0x1c, 0x36, 0x36, 0x1c, 0x6c, 0x3e, 0x33, 0x33, 0x7b, 0xce, 0x00, 0x00, 0x00,
  /*  39 */ 0x00, 0x18, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  40 */ 0x00, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x18, 0x18, 0x30, 0x00, 0x00,
  /*  41 */ 0x00, 0x0c, 0x18, 0x18, 0x30, 0x30, 0x30, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x00, 0x00,
  /*  42 */ 0x00, 0x00, 0x00, 0x00, 0x36, 0x1c, 0x7f, 0x1c, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  43 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  44 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x00, 0x00,
  /*  45 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  46 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  47 */ 0x00, 0x60, 0x20, 0x30, 0x10, 0x18, 0x08, 0x0c, 0x04, 0x06, 0x02, 0x03, 0x00, 0x00,
  /*  48 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x6b, 0x6b, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  49 */ 0x00, 0x18, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  50 */ 0x00, 0x3e, 0x63, 0x60, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /*  51 */ 0x00, 0x3e, 0x63, 0x60, 0x60, 0x3c, 0x60, 0x60, 0x60, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  52 */ 0x00, 0x30, 0x38, 0x3c, 0x36, 0x33, 0x7f, 0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00,
  /*  53 */ 0x00, 0x7f, 0x03, 0x03, 0x3f, 0x60, 0x60, 0x60, 0x60, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  54 */ 0x00, 0x3c, 0x06, 0x03, 0x03, 0x3f, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  55 */ 0x00, 0x7f, 0x60, 0x30, 0x30, 0x18, 0x18, 0x18, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00,
  /*  56 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  57 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x7e, 0x60, 0x60, 0x60, 0x30, 0x1e, 0x00, 0x00, 0x00,
  /*  58 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  59 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x0c, 0x00, 0x00,
  /*  60 */ 0x00, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x00, 0x00, 0x00,
  /*  61 */ 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  62 */ 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, 0x00,
  /*  63 */ 0x00, 0x3e, 0x63, 0x60, 0x30, 0x30, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  64 */ 0x00, 0x3c, 0x66, 0x73, 0x7b, 0x6b, 0x6b, 0x7b, 0x33, 0x06, 0x3c, 0x00, 0x00, 0x00,
  /*  65 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  66 */ 0x00, 0x3f, 0x63, 0x63, 0x63, 0x3f, 0x63, 0x63, 0x63, 0x63, 0x3f, 0x00, 0x00, 0x00,
  /*  67 */ 0x00, 0x3c, 0x66, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x66, 0x3c, 0x00, 0x00, 0x00,
  /*  68 */ 0x00, 0x1f, 0x33, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x33, 0x1f, 0x00, 0x00, 0x00,
  /*  69 */ 0x00, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /*  70 */ 0x00, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00,
  /*  71 */ 0x00, 0x3c, 0x66, 0x03, 0x03, 0x03, 0x73, 0x63, 0x63, 0x66, 0x7c, 0x00, 0x00, 0x00,
  /*  72 */ 0x00, 0x63, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  73 */ 0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00,
  /*  74 */ 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x33, 0x1e, 0x00, 0x00, 0x00,
  /*  75 */ 0x00, 0x63, 0x33, 0x1b, 0x0f, 0x07, 0x07, 0x0f, 0x1b, 0x33, 0x63, 0x00, 0x00, 0x00,
  /*  76 */ 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /*  77 */ 0x00, 0x63, 0x63, 0x77, 0x7f, 0x7f, 0x6b, 0x6b, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  78 */ 0x00, 0x63, 0x63, 0x67, 0x6f, 0x6f, 0x7b, 0x7b, 0x73, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  79 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  80 */ 0x00, 0x3f, 0x63, 0x63, 0x63, 0x63, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00,
  /*  81 */ 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x6f, 0x7b, 0x3e, 0x30, 0x60, 0x00,
  /*  82 */ 0x00, 0x3f, 0x63, 0x63, 0x63, 0x63, 0x3f, 0x1b, 0x33, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  83 */ 0x00, 0x3e, 0x63, 0x03, 0x03, 0x0e, 0x38, 0x60, 0x60, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  84 */ 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  85 */ 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /*  86 */ 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x08, 0x00, 0x00, 0x00,
  /*  87 */ 0x00, 0x63, 0x63, 0x6b, 0x6b, 0x6b, 0x6b, 0x7f, 0x36, 0x36, 0x36, 0x00, 0x00, 0x00,
  /*  88 */ 0x00, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x36, 0x36, 0x63, 0x63, 0x00, 0x00, 0x00,
  /*  89 */ 0x00, 0xc3, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
  /*  90 */ 0x00, 0x7f, 0x30, 0x30, 0x18, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0x7f, 0x00, 0x00, 0x00,
  /*  91 */ 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c, 0x00, 0x00, 0x00,
  /*  92 */ 0x00, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x18, 0x10, 0x30, 0x20, 0x60, 0x00, 0x00,
  /*  93 */ 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c, 0x00, 0x00, 0x00,
  /*  94 */ 0x08, 0x1c, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  95 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00,
  /*  96 */ 0x00, 0x0c, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*  97 */ 0x00, 0x00, 0x00, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /*  98 */ 0x00, 0x03, 0x03, 0x03, 0x3b, 0x67, 0x63, 0x63, 0x63, 0x67, 0x3b, 0x00, 0x00, 0x00,
  /*  99 */ 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x03, 0x03, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 100 */ 0x00, 0x60, 0x60, 0x60, 0x6e, 0x73, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 101 */ 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x63, 0x7f, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 102 */ 0x00, 0x3c, 0x66, 0x06, 0x1f, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00,
  /* 103 */ 0x00, 0x00, 0x00, 0x00, 0x6e, 0x73, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x60, 0x63, 0x3e,
  /* 104 */ 0x00, 0x03, 0x03, 0x03, 0x3b, 0x67, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 105 */ 0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 106 */ 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x33, 0x1e,
  /* 107 */ 0x00, 0x03, 0x03, 0x03, 0x63, 0x33, 0x1b, 0x0f, 0x1f, 0x33, 0x63, 0x00, 0x00, 0x00,
  /* 108 */ 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 109 */ 0x00, 0x00, 0x00, 0x00, 0x35, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x6b, 0x00, 0x00, 0x00,
  /* 110 */ 0x00, 0x00, 0x00, 0x00, 0x3b, 0x67, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 111 */ 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 112 */ 0x00, 0x00, 0x00, 0x00, 0x3b, 0x67, 0x63, 0x63, 0x63, 0x67, 0x3b, 0x03, 0x03, 0x03,
  /* 113 */ 0x00, 0x00, 0x00, 0x00, 0x6e, 0x73, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x60, 0xe0, 0x60,
  /* 114 */ 0x00, 0x00, 0x00, 0x00, 0x3b, 0x67, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00,
  /* 115 */ 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x0e, 0x38, 0x60, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 116 */ 0x00, 0x00, 0x0c, 0x0c, 0x3e, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 117 */ 0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 118 */ 0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x08, 0x00, 0x00, 0x00,
  /* 119 */ 0x00, 0x00, 0x00, 0x00, 0x63, 0x6b, 0x6b, 0x6b, 0x3e, 0x36, 0x36, 0x00, 0x00, 0x00,
  /* 120 */ 0x00, 0x00, 0x00, 0x00, 0x63, 0x36, 0x1c, 0x1c, 0x1c, 0x36, 0x63, 0x00, 0x00, 0x00,
  /* 121 */ 0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x0c, 0x0c, 0x06, 0x03,
  /* 122 */ 0x00, 0x00, 0x00, 0x00, 0x7f, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x7f, 0x00, 0x00, 0x00,
  /* 123 */ 0x00, 0x70, 0x18, 0x18, 0x18, 0x18, 0x0e, 0x18, 0x18, 0x18, 0x18, 0x70, 0x00, 0x00,
  /* 124 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00,
  /* 125 */ 0x00, 0x0e, 0x18, 0x18, 0x18, 0x18, 0x70, 0x18, 0x18, 0x18, 0x18, 0x0e, 0x00, 0x00,
  /* 126 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//
// We can omit this page, since it contains some but not all accented characters, and
// a console font with any required i18n support can be loaded as needed.
//
#if (ISO_FONT_MAX_PAGE == 2)

/*
 * Second page of ISO Latin-1 font.
 */
#define PAGE1_CHAR_MIN       (160 - 0x80)
#define PAGE1_CHAR_MAX       (256 - 0x80)
#define PAGE1_FONT_HEAD      (0)
#define PAGE1_FONT_TAIL      (1)
#define PAGE1_LEFT_TO_RIGHT  (FALSE)

STATIC UINT8  mIsoFontDataPage1[(PAGE1_CHAR_MAX - PAGE1_CHAR_MIN) * (ISO_CHAR_HEIGHT - PAGE1_FONT_HEAD - PAGE1_FONT_TAIL)] = {
  /* 160 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 161 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00,
  /* 162 */ 0x00, 0x00, 0x00, 0x08, 0x08, 0x3e, 0x6b, 0x0b, 0x0b, 0x0b, 0x6b, 0x3e, 0x08, 0x08, 0x00,
  /* 163 */ 0x00, 0x00, 0x1c, 0x36, 0x06, 0x06, 0x1f, 0x06, 0x06, 0x07, 0x6f, 0x3b, 0x00, 0x00, 0x00,
  /* 164 */ 0x00, 0x00, 0x00, 0x00, 0x66, 0x3c, 0x66, 0x66, 0x66, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x00,
  /* 165 */ 0x00, 0x00, 0xc3, 0xc3, 0x66, 0x66, 0x3c, 0x7e, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00, 0x00,
  /* 166 */ 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
  /* 167 */ 0x00, 0x3c, 0x66, 0x0c, 0x1e, 0x33, 0x63, 0x66, 0x3c, 0x18, 0x33, 0x1e, 0x00, 0x00, 0x00,
  /* 168 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 169 */ 0x00, 0x00, 0x3c, 0x42, 0x99, 0xa5, 0x85, 0xa5, 0x99, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00,
  /* 170 */ 0x00, 0x1e, 0x30, 0x3e, 0x33, 0x3b, 0x36, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 171 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x36, 0x1b, 0x1b, 0x36, 0x6c, 0x00, 0x00, 0x00, 0x00,
  /* 172 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 173 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 174 */ 0x00, 0x00, 0x3c, 0x42, 0x9d, 0xa5, 0x9d, 0xa5, 0xa5, 0x42, 0x3c, 0x00, 0x00, 0x00, 0x00,
  /* 175 */ 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 176 */ 0x00, 0x00, 0x1c, 0x36, 0x36, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 177 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00,
  /* 178 */ 0x00, 0x1e, 0x33, 0x18, 0x0c, 0x06, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 179 */ 0x00, 0x1e, 0x33, 0x18, 0x30, 0x33, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 180 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 181 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x76, 0x6e, 0x06, 0x06, 0x03,
  /* 182 */ 0x00, 0x00, 0x7e, 0x2f, 0x2f, 0x2f, 0x2e, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00, 0x00,
  /* 183 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 184 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x1e,
  /* 185 */ 0x00, 0x0c, 0x0e, 0x0c, 0x0c, 0x0c, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 186 */ 0x00, 0x1e, 0x33, 0x33, 0x33, 0x33, 0x1e, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 187 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x36, 0x6c, 0x6c, 0x36, 0x1b, 0x00, 0x00, 0x00, 0x00,
  /* 188 */ 0x00, 0x10, 0x1c, 0x18, 0x18, 0x18, 0x00, 0x7f, 0x00, 0x18, 0x1c, 0x1a, 0x3e, 0x18, 0x00,
  /* 189 */ 0x00, 0x10, 0x1c, 0x18, 0x18, 0x18, 0x00, 0x7f, 0x00, 0x1c, 0x36, 0x18, 0x0c, 0x3e, 0x00,
  /* 190 */ 0x00, 0x1c, 0x36, 0x18, 0x36, 0x1c, 0x00, 0x7f, 0x00, 0x18, 0x1c, 0x1a, 0x3e, 0x18, 0x00,
  /* 191 */ 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x06, 0x06, 0x03, 0x63, 0x3e, 0x00,
  /* 192 */ 0x0c, 0x18, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 193 */ 0x18, 0x0c, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 194 */ 0x08, 0x14, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 195 */ 0x6e, 0x3b, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 196 */ 0x36, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 197 */ 0x1c, 0x36, 0x3e, 0x63, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 198 */ 0x00, 0x00, 0xfe, 0x33, 0x33, 0x33, 0xff, 0x33, 0x33, 0x33, 0x33, 0xf3, 0x00, 0x00, 0x00,
  /* 199 */ 0x00, 0x00, 0x3c, 0x66, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x66, 0x3c, 0x18, 0x30, 0x1e,
  /* 200 */ 0x0c, 0x18, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /* 201 */ 0x18, 0x0c, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /* 202 */ 0x08, 0x14, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /* 203 */ 0x36, 0x00, 0x7f, 0x03, 0x03, 0x03, 0x3f, 0x03, 0x03, 0x03, 0x03, 0x7f, 0x00, 0x00, 0x00,
  /* 204 */ 0x0c, 0x18, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00,
  /* 205 */ 0x30, 0x18, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00,
  /* 206 */ 0x18, 0x24, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00,
  /* 207 */ 0x66, 0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00,
  /* 208 */ 0x00, 0x00, 0x1e, 0x36, 0x66, 0x66, 0x6f, 0x66, 0x66, 0x66, 0x36, 0x1e, 0x00, 0x00, 0x00,
  /* 209 */ 0x6e, 0x3b, 0x63, 0x63, 0x67, 0x6f, 0x6f, 0x7b, 0x7b, 0x73, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 210 */ 0x06, 0x0c, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 211 */ 0x30, 0x18, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 212 */ 0x08, 0x14, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 213 */ 0x6e, 0x3b, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 214 */ 0x36, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 215 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 216 */ 0x00, 0x20, 0x3e, 0x73, 0x73, 0x6b, 0x6b, 0x6b, 0x6b, 0x67, 0x67, 0x3e, 0x02, 0x00, 0x00,
  /* 217 */ 0x0c, 0x18, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 218 */ 0x18, 0x0c, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 219 */ 0x08, 0x14, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 220 */ 0x36, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 221 */ 0x30, 0x18, 0xc3, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00,
  /* 222 */ 0x00, 0x00, 0x0f, 0x06, 0x3e, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x06, 0x0f, 0x00, 0x00, 0x00,
  /* 223 */ 0x00, 0x00, 0x1e, 0x33, 0x33, 0x1b, 0x33, 0x63, 0x63, 0x63, 0x63, 0x3b, 0x00, 0x00, 0x00,
  /* 224 */ 0x00, 0x0c, 0x18, 0x30, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 225 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 226 */ 0x00, 0x08, 0x1c, 0x36, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 227 */ 0x00, 0x00, 0x6e, 0x3b, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 228 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 229 */ 0x00, 0x1c, 0x36, 0x1c, 0x00, 0x3e, 0x60, 0x7e, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 230 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0xdb, 0xd8, 0xfe, 0x1b, 0xdb, 0x76, 0x00, 0x00, 0x00,
  /* 231 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x63, 0x03, 0x03, 0x03, 0x63, 0x3e, 0x18, 0x30, 0x1e,
  /* 232 */ 0x00, 0x0c, 0x18, 0x30, 0x00, 0x3e, 0x63, 0x63, 0x7f, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 233 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x3e, 0x63, 0x63, 0x7f, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 234 */ 0x00, 0x08, 0x1c, 0x36, 0x00, 0x3e, 0x63, 0x63, 0x7f, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 235 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x3e, 0x63, 0x63, 0x7f, 0x03, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 236 */ 0x00, 0x06, 0x0c, 0x18, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 237 */ 0x00, 0x18, 0x0c, 0x06, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 238 */ 0x00, 0x08, 0x1c, 0x36, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 239 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x38, 0x00, 0x00, 0x00,
  /* 240 */ 0x00, 0x00, 0x2c, 0x18, 0x34, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00, 0x00, 0x00,
  /* 241 */ 0x00, 0x00, 0x6e, 0x3b, 0x00, 0x3b, 0x67, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00,
  /* 242 */ 0x00, 0x06, 0x0c, 0x18, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 243 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 244 */ 0x00, 0x08, 0x1c, 0x36, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 245 */ 0x00, 0x00, 0x6e, 0x3b, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 246 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x3e, 0x63, 0x63, 0x63, 0x63, 0x63, 0x3e, 0x00, 0x00, 0x00,
  /* 247 */ 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x7e, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  /* 248 */ 0x00, 0x00, 0x00, 0x00, 0x20, 0x3e, 0x73, 0x6b, 0x6b, 0x6b, 0x67, 0x3e, 0x02, 0x00, 0x00,
  /* 249 */ 0x00, 0x06, 0x0c, 0x18, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 250 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 251 */ 0x00, 0x08, 0x1c, 0x36, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 252 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x73, 0x6e, 0x00, 0x00, 0x00,
  /* 253 */ 0x00, 0x30, 0x18, 0x0c, 0x00, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x0c, 0x0c, 0x06, 0x03,
  /* 254 */ 0x00, 0x00, 0x0f, 0x06, 0x06, 0x3e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x06, 0x06, 0x0f,
  /* 255 */ 0x00, 0x00, 0x36, 0x36, 0x00, 0x63, 0x63, 0x36, 0x36, 0x1c, 0x1c, 0x0c, 0x0c, 0x06, 0x03
};
#endif

/*
 * EFI mandated https://github.com/tianocore/edk2/blob/2f88bd3a1296c522317f1c21377876de63de5be7/MdePkg/Include/Protocol/SimpleTextOut.h#L34-L98
 * unicode box drawing, block element and arrow characters (which are used e.g. by memtest86).
 * Unicode font pages derived from https://github.com/farsil/ibmfonts
 * SPDX-License-Identifier: CC-BY-SA-4.0
 * (Exported as hex using `gbdfed` from ib8x16u.bdf, sparse info generated with `head`, `tail`, `nl` and additional hand editing.)
 */

#define PAGE67_CHAR_MIN       (0x10)
#define PAGE67_CHAR_MAX       (0x14)
#define PAGE67_FONT_HEAD      (0)
#define PAGE67_FONT_TAIL      (2)
#define PAGE67_LEFT_TO_RIGHT  (TRUE)

STATIC UINT8  mGlyphsPage67[(PAGE67_CHAR_MAX - PAGE67_CHAR_MIN) * (ISO_CHAR_HEIGHT - PAGE67_FONT_HEAD - PAGE67_FONT_TAIL)] = {
  /* 0x2190 */ 0x00, 0x00, 0x30, 0x30, 0x60, 0x60, 0xFE, 0xFE, 0x60, 0x60, 0x30, 0x30, 0x00, 0x00,
  /* 0x2191 */ 0x18, 0x18, 0x3C, 0x3C, 0x7E, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2192 */ 0x00, 0x00, 0x18, 0x18, 0x0C, 0x0C, 0xFE, 0xFE, 0x0C, 0x0C, 0x18, 0x18, 0x00, 0x00,
  /* 0x2193 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x7E, 0x3C, 0x3C, 0x18, 0x18
};

#define PAGE74_CHAR_MIN           (0x00)
#define PAGE74_CHAR_MAX           (0x6D)
#define PAGE74_SPARSE_CHAR_COUNT  (40)
#define PAGE74_LEFT_TO_RIGHT      (TRUE)

STATIC UINT8  mGlyphsPage74[PAGE74_SPARSE_CHAR_COUNT * ISO_CHAR_HEIGHT] = {
  /* 0x2500 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2502 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x250C */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2510 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2514 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2518 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x251C */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2524 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x252C */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2534 */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x253C */ 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2550 */ 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2551 */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2552 */ 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2553 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2554 */ 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x30, 0x30, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2555 */ 0x00, 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2556 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2557 */ 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x06, 0x06, 0xF6, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2558 */ 0x18, 0x18, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2559 */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x255A */ 0x36, 0x36, 0x36, 0x36, 0x37, 0x37, 0x30, 0x30, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x255B */ 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x255C */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x255D */ 0x36, 0x36, 0x36, 0x36, 0xF6, 0xF6, 0x06, 0x06, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x255E */ 0x18, 0x18, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x1F, 0x1F, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x255F */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2560 */ 0x36, 0x36, 0x36, 0x36, 0x37, 0x37, 0x30, 0x30, 0x37, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2561 */ 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2562 */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xF6, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2563 */ 0x36, 0x36, 0x36, 0x36, 0xF6, 0xF6, 0x06, 0x06, 0xF6, 0xF6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2564 */ 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x2565 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2566 */ 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xF7, 0xF7, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x2567 */ 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2568 */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x2569 */ 0x36, 0x36, 0x36, 0x36, 0xF7, 0xF7, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /* 0x256A */ 0x18, 0x18, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  /* 0x256B */ 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xFF, 0xFF, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  /* 0x256C */ 0x36, 0x36, 0x36, 0x36, 0xF7, 0xF7, 0x00, 0x00, 0xF7, 0xF7, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36
};

STATIC UINT8  mOffsetsPage74[PAGE74_CHAR_MAX - PAGE74_CHAR_MIN] = {
  1,    /* 0x2500 */
  0,
  2,    /* 0x2502 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  3,    /* 0x250C */
  0,
  0,
  0,
  4,    /* 0x2510 */
  0,
  0,
  0,
  5,    /* 0x2514 */
  0,
  0,
  0,
  6,    /* 0x2518 */
  0,
  0,
  0,
  7,    /* 0x251C */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  8,    /* 0x2524 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  9,    /* 0x252C */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  10,   /* 0x2534 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  11,   /* 0x253C */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  12,   /* 0x2550 */
  13,   /* 0x2551 */
  14,   /* 0x2552 */
  15,   /* 0x2553 */
  16,   /* 0x2554 */
  17,   /* 0x2555 */
  18,   /* 0x2556 */
  19,   /* 0x2557 */
  20,   /* 0x2558 */
  21,   /* 0x2559 */
  22,   /* 0x255A */
  23,   /* 0x255B */
  24,   /* 0x255C */
  25,   /* 0x255D */
  26,   /* 0x255E */
  27,   /* 0x255F */
  28,   /* 0x2560 */
  29,   /* 0x2561 */
  30,   /* 0x2562 */
  31,   /* 0x2563 */
  32,   /* 0x2564 */
  33,   /* 0x2565 */
  34,   /* 0x2566 */
  35,   /* 0x2567 */
  36,   /* 0x2568 */
  37,   /* 0x2569 */
  38,   /* 0x256A */
  39,   /* 0x256B */
  40    /* 0x256C */
};

#define PAGE75_CHAR_MIN           (0x08)
#define PAGE75_CHAR_MAX           (0x45)
#define PAGE75_SPARSE_CHAR_COUNT  (6)
#define PAGE75_LEFT_TO_RIGHT      (TRUE)

STATIC UINT8  mGlyphsPage75[PAGE75_SPARSE_CHAR_COUNT * ISO_CHAR_HEIGHT] = {
  /* 0x2588 */ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /* 0x2591 */ 0x22, 0x22, 0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22, 0x88, 0x88,
  /* 0x25B2 */ 0x00, 0x00, 0x18, 0x18, 0x3C, 0x3C, 0x7E, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
  /* 0x25BA */ 0x80, 0x80, 0xE0, 0xE0, 0xF8, 0xF8, 0xFE, 0xFE, 0xF8, 0xF8, 0xE0, 0xE0, 0x80, 0x80, 0x00, 0x00,
  /* 0x25BC */ 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x7E, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  /* 0x25C4 */ 0x02, 0x02, 0x0E, 0x0E, 0x3E, 0x3E, 0xFE, 0xFE, 0x3E, 0x3E, 0x0E, 0x0E, 0x02, 0x02, 0x00, 0x00,
};

STATIC UINT8  mOffsetsPage75[PAGE75_CHAR_MAX - PAGE75_CHAR_MIN] = {
  1, /* 0x2588 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2, /* 0x2591 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  3, /* 0x25B2 */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4, /* 0x25BA */
  0,
  5, /* 0x25BC */
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  6, /* 0x25C4 */
};

STATIC OC_CONSOLE_FONT_PAGE  mFontPages[] = {
  { mIsoFontDataPage0, NULL,           PAGE0_CHAR_MIN,  PAGE0_CHAR_MAX,  PAGE0_FONT_HEAD,  PAGE0_FONT_TAIL,  PAGE0_LEFT_TO_RIGHT  },
 #if (ISO_FONT_MAX_PAGE == 2)
  { mIsoFontDataPage1, NULL,           PAGE1_CHAR_MIN,  PAGE1_CHAR_MAX,  PAGE1_FONT_HEAD,  PAGE1_FONT_TAIL,  PAGE1_LEFT_TO_RIGHT  },
 #endif
  { mGlyphsPage67,     NULL,           PAGE67_CHAR_MIN, PAGE67_CHAR_MAX, PAGE67_FONT_HEAD, PAGE67_FONT_TAIL, PAGE67_LEFT_TO_RIGHT },
  { mGlyphsPage74,     mOffsetsPage74, PAGE74_CHAR_MIN, PAGE74_CHAR_MAX, 0,                0,                PAGE74_LEFT_TO_RIGHT },
  { mGlyphsPage75,     mOffsetsPage75, PAGE75_CHAR_MIN, PAGE75_CHAR_MAX, 0,                0,                PAGE75_LEFT_TO_RIGHT }
};

#define FONT_PAGE_MIN  (0)
#define FONT_PAGE_MAX  (76)

STATIC UINT16  mFontPageOffsets[FONT_PAGE_MAX - FONT_PAGE_MIN] = {
  1, // 0
 #if (ISO_FONT_MAX_PAGE == 1)
  0, // 1
 #else
  2, // 1
 #endif
  0, // 2
  0, // 3
  0, // 4
  0, // 5
  0, // 6
  0, // 7
  0, // 8
  0, // 9
  0, // 10
  0, // 11
  0, // 12
  0, // 13
  0, // 14
  0, // 15
  0, // 16
  0, // 17
  0, // 18
  0, // 19
  0, // 20
  0, // 21
  0, // 22
  0, // 23
  0, // 24
  0, // 25
  0, // 26
  0, // 27
  0, // 28
  0, // 29
  0, // 30
  0, // 31
  0, // 32
  0, // 33
  0, // 34
  0, // 35
  0, // 36
  0, // 37
  0, // 38
  0, // 39
  0, // 40
  0, // 41
  0, // 42
  0, // 43
  0, // 44
  0, // 45
  0, // 46
  0, // 47
  0, // 48
  0, // 49
  0, // 50
  0, // 51
  0, // 52
  0, // 53
  0, // 54
  0, // 55
  0, // 56
  0, // 57
  0, // 58
  0, // 59
  0, // 60
  0, // 61
  0, // 62
  0, // 63
  0, // 64
  0, // 65
  0, // 66
 #if (ISO_FONT_MAX_PAGE == 1)
  2, // 67
 #else
  3, // 67
 #endif
  0, // 68
  0, // 69
  0, // 70
  0, // 71
  0, // 72
  0, // 73
 #if (ISO_FONT_MAX_PAGE == 1)
  3, // 74
  4  // 75
 #else
  4, // 74
  5  // 75
 #endif
};

STATIC OC_CONSOLE_FONT_PAGE  mMinimalFontPages[1] = {
  { mIsoFontDataPage0, NULL, PAGE0_CHAR_MIN, PAGE0_CHAR_MAX, PAGE0_FONT_HEAD, PAGE0_FONT_TAIL, PAGE0_LEFT_TO_RIGHT }
};

//
// Pages 0 & 1 of ISO Latin, plus box drawing and block elements.
//
GLOBAL_REMOVE_IF_UNREFERENCED OC_CONSOLE_FONT  gDefaultConsoleFont = {
  mFontPages,
  mFontPageOffsets,
  FONT_PAGE_MIN,
  FONT_PAGE_MAX
};

//
// Font with just page 0 of ISO Latin.
//
GLOBAL_REMOVE_IF_UNREFERENCED OC_CONSOLE_FONT  gMinimalConsoleFont = {
  mMinimalFontPages,
  NULL,
  0,
  0
};

//
// Font range info, mainly for debugging and testing.
//
GLOBAL_REMOVE_IF_UNREFERENCED OC_CONSOLE_FONT_RANGE  gEfiRequiredUnicodeChars[] = {
  { 0x2500, 1    }, /* BOXDRAW_HORIZONTAL            */
  { 0x2502, 1    }, /* BOXDRAW_VERTICAL              */
  { 0x250c, 1    }, /* BOXDRAW_DOWN_RIGHT            */
  { 0x2510, 1    }, /* BOXDRAW_DOWN_LEFT             */
  { 0x2514, 1    }, /* BOXDRAW_UP_RIGHT              */
  { 0x2518, 1    }, /* BOXDRAW_UP_LEFT               */
  { 0x251c, 1    }, /* BOXDRAW_VERTICAL_RIGHT        */
  { 0x2524, 1    }, /* BOXDRAW_VERTICAL_LEFT         */
  { 0x252c, 1    }, /* BOXDRAW_DOWN_HORIZONTAL       */
  { 0x2534, 1    }, /* BOXDRAW_UP_HORIZONTAL         */
  { 0x253c, 1    }, /* BOXDRAW_VERTICAL_HORIZONTAL   */
  { 0x2550, 0x1D }, /* BOXDRAW_DOUBLE_HORIZONTAL - BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL */
  { 0x2588, 1    }, /* BLOCKELEMENT_FULL_BLOCK       */
  { 0x2591, 1    }, /* BLOCKELEMENT_LIGHT_SHADE      */
  { 0x25b2, 1    }, /* GEOMETRICSHAPE_UP_TRIANGLE    */
  { 0x25ba, 1    }, /* GEOMETRICSHAPE_RIGHT_TRIANGLE */
  { 0x25bc, 1    }, /* GEOMETRICSHAPE_DOWN_TRIANGLE  */
  { 0x25c4, 1    }, /* GEOMETRICSHAPE_LEFT_TRIANGLE  */
  { 0x2190, 4    }, /* ARROW_LEFT - ARROW_DOWN       */
  { 0,      0    }
};

GLOBAL_REMOVE_IF_UNREFERENCED OC_CONSOLE_FONT_RANGE  gExtendedUnicodeChars[] = {
  { 0x0020, 0x60 },
  { 0x00A0, 0x60 },
  { 0x0100, 0x80 },
  { 0x0192, 1    },
  { 0x01A1, 1    },
  { 0x01B7, 1    },
  { 0x01FA, 6    },
  { 0x0218, 4    },
  { 0x0251, 1    },
  { 0x0278, 1    },
  { 0x02C6, 1    },
  { 0x02C7, 1    },
  { 0x02C9, 1    },
  { 0x02D8, 6    },
  { 0x037E, 1    },
  { 0x0384, 7    },
  { 0x038C, 1    },
  { 0x038E, 0x14 },
  { 0x03A3, 0x2C },
  { 0x03D0, 1    },
  { 0x03F4, 1    },
  { 0x0400, 0x60 },
  { 0x0490, 2    },
  { 0x05BE, 1    },
  { 0x05D0, 0x1B },
  { 0x05F0, 5    },
  { 0x1D1B, 1    },
  { 0x1D26, 1    },
  { 0x1D28, 1    },
  { 0x1E80, 6    },
  { 0x1E9F, 1    },
  { 0x1EF2, 2    },
  { 0x2010, 5    },
  { 0x2017, 0xC  },
  { 0x2026, 2    },
  { 0x2030, 1    },
  { 0x2032, 2    },
  { 0x2035, 1    },
  { 0x2039, 2    },
  { 0x203C, 1    },
  { 0x203E, 3    },
  { 0x2044, 1    },
  { 0x2054, 1    },
  { 0x2074, 8    },
  { 0x207F, 1    },
  { 0x2081, 0xB  },
  { 0x20A3, 2    },
  { 0x20A7, 1    },
  { 0x20AA, 1    },
  { 0x20AC, 1    },
  { 0x2105, 1    },
  { 0x2113, 1    },
  { 0x2116, 1    },
  { 0x2122, 1    },
  { 0x2126, 1    },
  { 0x212E, 1    },
  { 0x2150, 2    },
  { 0x2153, 0xC  },
  { 0x2190, 6    },
  { 0x21A8, 1    },
  { 0x2202, 1    },
  { 0x2205, 1    },
  { 0x2206, 1    },
  { 0x2208, 1    },
  { 0x220F, 1    },
  { 0x2211, 2    },
  { 0x2215, 1    },
  { 0x2219, 2    },
  { 0x221E, 2    },
  { 0x2229, 1    },
  { 0x222B, 1    },
  { 0x2248, 1    },
  { 0x2260, 2    },
  { 0x2264, 2    },
  { 0x2299, 1    },
  { 0x2300, 1    },
  { 0x2302, 1    },
  { 0x2310, 1    },
  { 0x2320, 2    },
  { 0x2500, 1    },
  { 0x2502, 1    },
  { 0x250C, 1    },
  { 0x2510, 1    },
  { 0x2514, 1    },
  { 0x2518, 1    },
  { 0x251C, 1    },
  { 0x2524, 1    },
  { 0x252C, 1    },
  { 0x2534, 1    },
  { 0x253C, 1    },
  { 0x2550, 0x1D },
  { 0x2580, 2    },
  { 0x2584, 1    },
  { 0x2588, 1    },
  { 0x258C, 1    },
  { 0x2590, 4    },
  { 0x25A0, 2    },
  { 0x25AA, 3    },
  { 0x25B2, 1    },
  { 0x25BA, 1    },
  { 0x25BC, 1    },
  { 0x25C4, 1    },
  { 0x25CA, 1    },
  { 0x25CB, 1    },
  { 0x25CF, 1    },
  { 0x25D8, 2    },
  { 0x25E6, 1    },
  { 0x263A, 3    },
  { 0x2640, 1    },
  { 0x2642, 1    },
  { 0x2660, 1    },
  { 0x2663, 1    },
  { 0x2665, 2    },
  { 0x266A, 2    },
  { 0x2713, 1    },
  { 0xFB01, 2    },
  { 0xFFFD, 1    },
  { 0,      0    }
};
