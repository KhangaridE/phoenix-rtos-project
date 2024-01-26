/*
 * Phoenix-RTOS
 *
 * Board config for armv7m7-imxrt105x-evk
 *
 * Copyright 2022 Phoenix Systems
 * Author: Lukasz Kosinski
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_


/*
 * libpseudodev and libposixsrv shall be used exclusively, libpseudodev uses
 * less resources, but libposixsrv provides POSIX support and may be resource
 * hungry.
 * NOTICE: Due to low amount of OCRAM on mimxrt1052-evk by default libpseudodev
 * is enabled.
 */

#define PSEUDODEV 1

/* #define BUILTIN_POSIXSRV 1 */


#endif
