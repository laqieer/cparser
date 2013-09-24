/*
 * This file is part of cparser.
 * Copyright (C) 2012 Matthias Braun <matze@braunis.de>
 */
#ifndef LANG_FEATURES_H
#define LANG_FEATURES_H

#include <stdbool.h>
#include "type.h"

#define BITS_PER_BYTE    8

typedef enum lang_features_t {
	_C89  = 1U << 0,
	_C99  = 1U << 1,
	_C11  = 1U << 2,
	_CXX  = 1U << 3,
	_GNUC = 1U << 4,
	_MS   = 1U << 5,
	_ALL  = 0xFF
} lang_features_t;

typedef struct c_dialect_t {
	atomic_type_kind_t wchar_atomic_kind;
	bool               freestanding   : 1;
	bool               char_is_signed : 1;
	bool               strict         : 1;
	bool               intmax_predefs : 1;
	bool               c89            : 1;
	bool               c99            : 1;
	bool               c11            : 1;
	bool               cpp            : 1;
	bool               gnu            : 1;
	bool               ms             : 1;
	lang_features_t    features;
} c_dialect_t;

extern c_dialect_t dialect;

/**
 * whether architecture shift instructions usually perform modulo bit_size
 * on the shift amount, if yes this equals to the machine_size.
 */
extern unsigned int architecture_modulo_shift;

/** byte-order: true = big-endian, false = little-endian */
extern bool byte_order_big_endian;

/** a hack that adds a call to __main into the main function, necessary on
 * mingw */
extern bool enable_main_collect2_hack;

#endif
