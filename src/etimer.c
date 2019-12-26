/* This code is free ( free means free, Do whatever useful  ;-) )
 *
 *      Author : Viki (a) Vignesh Natarajan
 *      Lab    : vikilabs.org   
 */

/* Simple Timer Libray
 */
#include "etimer.h"

int8_t init_timer(etimer_t *timer)
{
    if(!timer)
        return -1;
    
    if(timer->initialized == 1)
        return -1;
    
    memset(timer, 0x0, sizeof(etimer_t));
    timer->initialized = 1;
    return 0;
}


/* 1. Start timer 
 * 2. Do nothing if timer is already running
 * 
 * prerequisite:
 *      init_timer() before calling start timer
 */
int8_t start_timer(etimer_t *timer)
{
    if(!timer)
        return -1;

    if(!timer->initialized)
        return -1;
  
    if(timer->started) /*timer already started*/
        return -1;

    time(&timer->s_time);
    timer->started = 1;
    return 0;
}

int8_t stop_timer(etimer_t *timer)
{
    if(!timer)
        return -1;

    if(!timer->initialized)
        return -1;
  
    if(!timer->started) /*timer not started / already stopped */
        return -1;

    timer->started = 0;
    return 0;
}

/* Get elapsed time between the timer start and current time
 */
double get_elapsed_time_now(etimer_t *timer)
{
    time_t end_time;

    if(!timer)
        return 0.0;

    if(!timer->initialized)
        return 0.0;

    if(!timer->started)
        return 0.0;

    time(&end_time);
    return difftime(end_time, timer->s_time);
}


/* 1. restart timer 
 * 2. Do nothing if timer is already running
 * 
 * prerequisite:
 *      init_timer() before calling start timer
 */
int8_t restart_timer(etimer_t *timer)
{
    if(!timer)
        return -1;

    if(!timer->initialized)
        return -1;
  
    timer->started = 0;

    time(&timer->s_time);
    timer->started = 1;
    return 0;
}



