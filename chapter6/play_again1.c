/*

   =====================================================================================
Filename:  play_again1.c
Description:
Version:  1.0
Created:  2015年04月10日 11时09分09秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include<stdio.h>
#include<termios.h>

#define QUESTION "Do you want another transaction"

    main()
    {
        int response;

        tty_mode(0);                /*  save tty models*/
        set_crmode();               /*  set chr-by-chr models*/
        response = get_response(QUESTION);  /*  get some answer*/
        tty_mode(1);                /*  restore tty models*/
        return response;
        }
        int get_response(char *question)
        /*
         * purpose: ask a question and wait for a y/n answer
         *  method: use getchar and complain about non y/n answers
         * returns: 0=>yes, 1=>no
         */
        {
        int input;
        printf("%s (y/n)?", question);
        while(1){
        switch( input = getchar() ){
        case 'y': 
        case 'Y': return 0;
        case 'n': 
        case 'N': 
        case EOF: return 1;
        default:
                  printf("nnot understand %c, ", input);
                  printf("Please type y or no\n");
        }
        }
        }

set_crmode()
    /*  
     * purpose: put file descriptor 0 (i.e. stdin) into chr-by-chr mode
     *  method: use bits in termios
     */
{
        struct termios ttystate;

        tcgetattr( 0, &ttystate);       /*  read curr. settings_get_default(*/
        ttystate.c_lflag        &= ~ICANON; /*  no buffering*/
        ttystate.c_cc[VMIN]     =  1;       /*  get 1 char at a times(*/
        tcsetattr( 0 , TCSANOW, &ttystate); /*  install settings_get_default(*/
}

/*  how == 0 => save current mode,  how == 1 => restore mode */
tty_mode(int how)
{
    static struct termios original_mode;
    if ( how == 0 )
        tcgetattr(0, &original_mode);
    else
        return tcsetattr(0, TCSANOW, &original_mode); 
}

