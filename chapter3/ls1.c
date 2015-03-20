#include<stdio.h>
#include <sys/types.h>
#include<dirent.h>

void do_ls(char[]);		//处理文件的名字


//char * uid_to_name(uid_t);	//把user的uid转化为user的名字
//char * gid_to_name(gid_t);	//把属组的gid转化为数组的字符串名字

int main(int ac,char *av[])
{
    if(ac == 1)
	do_ls(".");
    else
	while(--ac){
	    printf("%s:\n",*++av);
	    do_ls(*av);
			
		    }
}

void do_ls(char dirname[])
{
    DIR * dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL)
	fprintf(stderr,"ls1: cannot open %s\n",dirname);
	else
	{
	    while((direntp = readdir(dir_ptr)) !=NULL)
		printf("%s\n",direntp->d_name);
		closedir(dir_ptr);
	    }
    }


/*
#include<pwd.h>
char * uid_to_name(uid_t uid)			//打印user name
{
    struct passwd * getpwuid(),* pw_ptr;
    static char numstr[10];

    if((pw_ptr = getpwuid(uid)) == NULL){
	sprintf(numstr,"%d",uid);
	return numstr;
	}
	else
	    return pw_ptr->pw_name;

}
*/
