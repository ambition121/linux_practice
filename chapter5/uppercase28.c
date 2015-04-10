/*
 =====================================================================================
        Filename:  uppercase28.c
     	Description:
        Version:  1.0
        Created:  2015年04月03日 19时12分14秒
        Revision:  none
        Compiler:  gcc
        Author:  Zhangxin (ambition121), zhang_xin0502@163.com
    	Organization:  Linux
 =====================================================================================
 */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
#include<stdio.h>
#include<termios.h>
#include<stdlib.h>

int
main ()
{
    struct termios info;
    int rv;

    rv = tcgetattr(0,&info);
    if (rv == -1){
        exit(1);
        }
        if(info.c_oflag & OLCUC)
            printf("OLCOC is on,since its bit is 1\n");
        else
            printf("OLCOC is off,since its bit is 0\n");
}				/* ----------  end of function main  ---------- */

