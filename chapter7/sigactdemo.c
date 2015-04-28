/*
   =====================================================================================
Filename:  sigactdemo.c
Description:
Version:  1.0
Created:  2015年04月21日 22时02分24秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */


#include<stdio.h>
#include<signal.h>
#define INPUTLEN 100

main()
{
    struct sigaction newhandler;            /*  new settings        */
    sigset_t         blocked;               /*  set of blocked sigs */
    void inthandler();          /*  the handler         */
    char x[INPUTLEN];

    /*  load these two members first */
    newhandler.sa_handler = inthandler;      /*  handler function    */
    newhandler.sa_flags = SA_RESETHAND | SA_RESTART;  /*  options    */

    /*  then build the list of blocked signals */
    sigemptyset(&blocked);                  /*  clear all bits      */
    sigaddset(&blocked, SIGQUIT);       /*  add SIGQUIT to list */

    newhandler.sa_mask = blocked;       /*  store blockmask     */

    if ( sigaction(SIGINT, &newhandler, NULL) == -1 )
        perror("sigaction");
    else
        while( 1 ){
            fgets(x, INPUTLEN, stdin);
            printf("input: %s", x);
        }
}

void inthandler(int s)
{
    printf("Called with signal %d\n", s);
    sleep(s);
    printf("done handling signal %d\n", s);
}
