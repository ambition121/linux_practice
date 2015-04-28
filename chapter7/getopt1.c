/*
   =====================================================================================
Filename:  getopt1.c
Description:
Version:  1.0
Created:  2015年04月17日 21时02分14秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    int ch;
    opterr=0;
    while((ch=getopt(argc,argv,"a:b::cde"))!=-1)
    {
        printf("optind:%d \n",optind);
        printf("optarg:%s \n",optarg);
        printf("optarg:%s \n",argv[optind]);
        printf("ch:%c \n",ch);
        switch(ch)
        {
            case 'a':
                printf("option a:'%s'\n",optarg);
                break;
            case 'b':
                printf("option b:'%s'\n",optarg);
                break;
            case 'c':
                printf("option c\n");
                break;
            case 'd':
                printf("option d\n");
                break;
            case 'e':
                printf("option e\n");
                break;
            default:
                printf("other option:%c\n",ch);
        }
        printf("optopt+%c\n",optopt);
    }
    return 0;
}
