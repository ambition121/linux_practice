/*
   =====================================================================================
Filename:  play_again0.c
Description:
Version:  1.0
Created:  2015年04月09日 11时16分24秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<stdio.h>
#include<termios.h>

#define QUESTION "Do you want another transaction"

    int get_response( char * );

    int main()
    {
    int response;

        response = get_response(QUESTION);  /*  get some answer*/
        return response;
        }
        int get_response(char *question)
        /*
         * purpose: ask a question and wait for a y/n answer
         *  method: use getchar and ignore non y/n answers
         * returns: 0=>yes, 1=>no
         */
        {
        printf("%s (y/n)?", question);
        while(1){
        switch( getchar() ){
        case 'y': 
        case 'Y': return 0;
        case 'n': 
        case 'N': 
        case EOF: return 1;
        }
    }
}


