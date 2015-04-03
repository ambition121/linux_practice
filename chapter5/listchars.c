/*
 =====================================================================================
        Filename:  listchars.c
     	Description:
        Version:  1.0
        Created:  2015年04月03日 16时32分27秒
        Revision:  none
        Compiler:  gcc
        Author:  Zhangxin (ambition121), zhang_xin0502@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include<stdio.h>
main()
{
    int c,n=0;
    while((c = getchar()) != 'Q')
        printf("char %3d is %c code %d\n",n++,c,c);
    }

