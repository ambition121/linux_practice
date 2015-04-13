/*
   =====================================================================================
Filename:  sleep1.c
Description:
Version:  1.0
Created:  2015年04月13日 19时19分15秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<stdio.h>
#include<signal.h>
// #define(SHHHH

main()
{
    void wakeup(int);

    printf("about to sleep for 4 seconds\n");
    signal(SIGALRM, wakeup);        /*  catch iter(*/
    alarm(4);               /*  set clock(*/
    pause();                /*  freeze here*/
    printf("Morning so soon?\n");       /*  back to works*/
}

void wakeup(int signum)
{
#ifndef SHHHH
    printf("Alarm received from kernel\n");
#endif
}

