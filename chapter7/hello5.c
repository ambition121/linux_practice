/*
   =====================================================================================
Filename:  hello5.c
Description:
Version:  1.0
Created:  2015年04月13日 19时00分52秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<curses.h>
#include<stdio.h>
#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

main()
{
//    char  message = "Hello";
//    char blank  = "     ";
    int dir = +1;
    int pos = LEFTEDGE ;

    initscr();
    clear();
    while(1){
        move(ROW,pos);
        addstr("hello");      /*  draw string.Formatter(*/
        move(LINES-1,COLS-1);       /*  park the cursors*/
        refresh();          /*  show string.Formatter(*/
        sleep(1);
        move(ROW,pos);          /*  erase string.Formatter(*/
        addstr("         ");
        pos += dir;         /*  advance position(*/
        if ( pos >= RIGHTEDGE )     /*  check for bounce*/
            dir = -1;
        if ( pos <= LEFTEDGE )
            dir = +1;
    }
}
