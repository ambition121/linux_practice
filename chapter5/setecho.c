/*
 =====================================================================================
        Filename:  setecho.c
     	Description:
        Version:  1.0
        Created:  2015年04月03日 19时35分34秒
        Revision:  none
        Compiler:  gcc
        Author:  Zhangxin (ambition121), zhang_xin0502@163.com
    	Organization:  Linux
 =====================================================================================
 */



#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
   
#include<stdio.h>
#include<termios.h>

#define oops(s,x){perror(s);exit(x);}
   int
main ( int argc, char *argv[] )
{
    struct termios info;
    if(argc == 1)
        exit(0);

    if(tcgetattr(0,&info) == -1)
        oops("tcgetattr",1);

    if(argv[1][0] == 'y')
        info.c_lflag |= ECHO;

    else

        info.c_lflag &= ~ECHO;

    if(tcsetattr(0,TCSANOW,&info) == -1)
        oops("tcsetattr",2);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
