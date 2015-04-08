/*
 =====================================================================================
        Filename:  rotate.c
     	Description:
        Version:  1.0
        Created:  2015年04月08日 11时28分41秒
        Revision:  none
        Compiler:  gcc
        Author:  Zhangxin (ambition121), zhang_xin0502@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include<stdio.h>
#include<ctype.h>

#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ()
{
    int c;
    while((c = getchar()) != EOF){
        if(c =='z')
            c = 'a';
        else if(islower(c))
            c++;
            putchar(c);
        }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

