/*
   =====================================================================================
Filename:  mesg23.c
Description:
Version:  1.0
Created:  2015年04月09日 09时32分59秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */


#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>

main( int ac, char *av[] )
  {

    struct stat settings;
    int    perms;

    if ( fstat(0, &settings) == -1 ){
    perror("Cannot stat stdin");
    exit(0);
    }
    perms = (settings.st_mode & 07777); /*  ALLPERMS in stat.h */

    /*
     * if no args, report setting
     */ 
    if ( ac == 1 ){
    printf("is %c\n", (perms&S_IWGRP)?'y':'n');
    exit(0);
    }

    /*  
     * Has args - check them and update if ok
     */

    if ( ac == 2 && av[1][0] == 'n' ){
        perms &= ~S_IWGRP;
        printf("off \n");}
    else if ( ac == 2 && av[1][0] == 'y' ){
        perms |=  S_IWGRP;
        printf("on \n");}
    else {
        fprintf(stderr,"usage: mesg [y|n]\n");
        exit(2);
    }

    if ( fchmod(0, perms) == -1 ){
        perror("Cannot change mesg status");
        exit(3);
    }

    return 0;
 }

