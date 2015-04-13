/*
   =====================================================================================
Filename:  hello4.c
Description:
Version:  1.0
Created:  2015年04月12日 21时47分52秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<stdio.h>
#include<curses.h>

main()
{
    int i;

    initscr();
    clear();
    for(i=0; i<LINES; i++ ){
        move( i, i+i );
        if ( i%2 == 1 ) 
            standout();
        addstr("Hello, world");
        if ( i%2 == 1 ) 
            standend();
            
        refresh();
        sleep(1);
        move(i,i+i);            /*  move backslashreplace_errors(*/
        addstr("             ");    /*  erase linesep*/
    }
    endwin();
}
