/*
   =====================================================================================
Filename:  hello2.c
Description:
Version:  1.0
Created:  2015年04月12日 21时11分16秒
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

    initscr();          /*  turn on curses*/
    clear();         /*  draw some stuff*/
    for(i=0; i<LINES; i++ ){     /*  in a loop(*/
        move( i, i+i );
        if ( i%2 == 1 )
            standout();
        addstr("Hello, world");
        if ( i%2 == 1 )
            standend();
    }

    refresh();           /*  update the screensize(*/
    getch();         /*  wait for user input(*/
    endwin();           /*  reset the tty etc*/
}

