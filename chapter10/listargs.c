/**********************************************************
 * Author        : Zhangxin
 * Email         : zhang_xin0502@163.com
 * Last modified : 2015-05-14 15:50
 * Filename      : listargs.c
 * Description   : 
 * *******************************************************/
#include<stdio.h>
main(int ac ,char *av[])
{
	int i;
	printf("Number of args:%d,Args are:\n",ac);
	for(i=0;i<ac;i++)
		printf("args[%d]%s\n",i,av[i]);
	fprintf(stderr,"this message is sent to stderr.\n");
}
