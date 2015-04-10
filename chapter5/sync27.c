/*
 =====================================================================================
        Filename:  sync27.c
     	Description:
        Version:  1.0
        Created:  2015年04月10日 09时42分29秒
        Revision:  none
        Compiler:  gcc
        Author:  Zhangxin (ambition121), zhang_xin0502@163.com
    	Organization:  Linux
 =====================================================================================
 */

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int curflags;
    curflags = fcntl(0,F_GETFL);

    if(curflags == -1)
        perror("getflags");
        
    else
    {
        curflags &= ~O_SYNC;
        if ( fcntl(0, F_SETFL, curflags) == -1 )
            perror("setflags");
        else
           printf("O_SYNC is on \n");
        }
    
    }

