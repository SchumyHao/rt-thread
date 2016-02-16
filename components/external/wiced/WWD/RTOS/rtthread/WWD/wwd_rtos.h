/*
 * Copyright 2014, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/** @file
 *  Definitions for the RT-Thread implementation of the Wiced RTOS
 *  abstraction layer.
 *
 */

#ifndef INCLUDED_WWD_RTOS_H_
#define INCLUDED_WWD_RTOS_H_

#include "rtthread.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern unsigned int SystemCoreClock;
#define configCPU_CLOCK_HZ               ((unsigned long)SystemCoreClock)

#define RTOS_HIGHER_PRIORTIY_THAN(x)     (x < RTOS_HIGHEST_PRIORITY ? x+1 : RTOS_HIGHEST_PRIORITY)
#define RTOS_LOWER_PRIORTIY_THAN(x)      (x > RTOS_LOWEST_PRIORITY ? x-1 : RTOS_LOWEST_PRIORITY)
#define RTOS_LOWEST_PRIORITY             (RT_THREAD_PRIORITY_MAX-1)
#define RTOS_HIGHEST_PRIORITY            (0)
#define RTOS_DEFAULT_THREAD_PRIORITY     (1)

#define RTOS_USE_DYNAMIC_THREAD_STACK

#define malloc_get_current_thread( ) rt_thread_self()
typedef rt_thread_t malloc_thread_handle;

#ifdef DEBUG
#define WWD_THREAD_STACK_SIZE        (732)   /* Stack checking requires a larger stack */
#else /* ifdef DEBUG */
#define WWD_THREAD_STACK_SIZE        (544)
#endif /* ifdef DEBUG */

/******************************************************
 *             Structures
 ******************************************************/

typedef rt_sem_t     /*@abstract@*/ /*@only@*/ host_semaphore_type_t;
typedef rt_thread_t  /*@abstract@*/ /*@only@*/ host_thread_type_t;
typedef rt_mq_t      /*@abstract@*/ /*@only@*/ host_queue_type_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef INCLUDED_WWD_RTOS_H_ */
