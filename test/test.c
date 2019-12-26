#include "etimer.h"
int main()
{
    etimer_t timer;
    init_timer(&timer);
    start_timer(&timer);
    sleep(1);
    printf("Elapsed Time = %lf\n", get_elapsed_time_now(&timer));
    stop_timer(&timer);
    printf("Elapsed Time = %lf\n", get_elapsed_time_now(&timer));
    return 0;
}

