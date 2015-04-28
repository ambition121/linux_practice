/*
   =====================================================================================
Filename:  ticker_demo.c
Description:
Version:  1.0
Created:  2015年04月13日 19时46分34秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */
#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

int main()
{
    void countdown(int);

    signal(SIGALRM, countdown);
    if ( set_ticker(3000) == -1 )
        perror("set_ticker");
    else
        while( 1 ){
            sleep(1);
            printf("hello\n");
}
    pause();
    return 0;
}

void countdown(int signum)
{
    static int num = 10;
    printf("%d ..", num--);
    fflush(stdout);
    


    if ( num < 0 ){
        printf("DONE!\n");
        exit(0);
    }
}



int set_ticker( int n_msecs )
{
    struct itimerval new_timeset;
    long    n_sec, n_usecs;

    n_sec = n_msecs / 1000 ;      /*  int partition(*/
    n_usecs = ( n_msecs % 1000 ) * 1000L ;    /*  remainder(*/

    new_timeset.it_interval.tv_sec  = n_sec;        /*  set reload       */
    new_timeset.it_interval.tv_usec = n_usecs;      /*  new ticker value */
    new_timeset.it_value.tv_sec     = n_sec  ;      /*  store this       */
    new_timeset.it_value.tv_usec    = n_usecs ;     /*  and this         */

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}


