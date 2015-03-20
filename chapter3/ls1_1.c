#include<stdio.h>
#include <sys/types.h>
#include<dirent.h>

void do_ls(char[],int);		//处理文件的名字



int main(int ac,char *av[])
{
/*    if(ac == 1)
	do_ls(".");
    else
	while(--ac){
	    printf("%s:\n",*++av);
	    do_ls(*av);
			
		    }*/
    int a_flag=0;
    int anyfiles=0;
    while(--ac){
	if(strcmp("-a",*++av) == 0)
	    a_flag=1;
	else{
	    
	    do_ls(*av,a_flag);
	    anyfiles=1;
	    }
	
	}
	if(!anyfiles)
	    do_ls(".",a_flag);
}




void do_ls(char dirname[],int a)
{
    DIR * dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL)
	fprintf(stderr,"ls1: cannot open %s\n",dirname);
	else
	{
	    while((direntp = readdir(dir_ptr)) !=NULL)
/*		printf("%s\n",direntp->d_name);
		closedir(dir_ptr); */

		{
		    if(a=1)
			printf("%s\n",direntp->d_name);
			else if((direntp->d_name)[0] !='.')
			    printf("%s\n",direntp->d_name);
		    }
		    closedir(dir_ptr);
	    }
    }
