/*
   =====================================================================================
Filename:  sigdemo3.c
Description:
Version:  1.0
Created:  2015年04月13日 21时30分31秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<stdio.h>
#include<signal.h>

#define INPUTLEN 100

main(int ac, char *av[])
{
    void inthandler(int);
    void quithandler(int);
    char input[INPUTLEN];
    int nchars;

    signal( SIGINT,  inthandler );      /*  set handler */
    signal( SIGQUIT, quithandler );     /*  set handler */

    do {
        printf("\nType a message\n");
        nchars = read(0, input, (INPUTLEN-1));
        if ( nchars == -1 )
            perror("read returned an error");
        else {
            input[nchars] = '\0';
            printf("You typed: %s", input);
        }
    } 
    while( strncmp( input , "quit" , 4 ) != 0 );
}

void inthandler(int s)
{
  //  void (*prev_qhandler)();
    printf(" Received signal %d .. waiting\n", s );
    sleep(4);
//    prev_qhandler = signal(SIGQUIT,SIG_IGN);
 //   signal(SIGQUIT,prev_qhandler);
    printf("  Leaving inthandler \n");
}

void quithandler(int s)
{
    printf(" Received signal %d .. waiting\n", s );
    sleep(3);
    printf("  Leaving quithandler \n");
}

