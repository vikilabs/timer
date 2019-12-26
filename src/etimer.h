/* This code is free ( free means free, Do whatever useful  ;-) )
 *
 *      Author : Viki (a) Vignesh Natarajan
 *      Lab    : vikilabs.org   
 */

/* Simple Timer Libray
 */

#ifndef ETIMER_H
#define ETIMER_H
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

typedef struct{
    uint8_t started;
    uint8_t initialized;
    time_t s_time;
}etimer_t;

extern int8_t init_timer(etimer_t *timer);

/* 1. Start timer 
 * 2. Do nothing if timer is already running
 * 
 * prerequisite:
 *      init_timer() before calling start timer
 */
extern int8_t start_timer(etimer_t *timer);
extern int8_t stop_timer(etimer_t *timer);

/* Get elapsed time between the timer start and current time
 */
extern double get_elapsed_time_now(etimer_t *timer);

extern int8_t restart_timer(etimer_t *timer);

#endif
