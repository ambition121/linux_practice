/*
   =====================================================================================
Filename:  hello1.c
Description:
Version:  1.0
Created:  2015年04月12日 20时42分51秒
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
    initscr() ;     /*  turn on curses*/

    /*  send requests*/
    clear();            /*  clear screensize(*/
    move(10,20);            /*  row10,col20*/
    addstr("Hello, world");     /*  add a string*/
    move(LINES-1,0);        /*  move to LL_ANGLE*/

    refresh();      /*  update the screensize(*/
    getch();        /*  wait for user input(*/

    endwin();       /*  turn off curses*/
    }

