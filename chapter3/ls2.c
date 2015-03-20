#include<stdio.h>
#include <sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>


void do_ls(char[]);		//处理文件的名字


void dostat(char * );
void show_file_info(char *,struct stat *);
void mode_to_letters(int,char[]);//设置权限
char * uid_to_name(uid_t);	//把user的uid转化为user的名字
char * gid_to_name(gid_t);	//把属组的gid转化为数组的字符串名字

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

void do_ls(char dirname[])			//执行ls到功能，出现文件名
{
    DIR * dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname)) == NULL)
	fprintf(stderr,"ls1: cannot open %s\n",dirname);
    else
    {
	while((direntp = readdir(dir_ptr)) !=NULL)
	    dostat(direntp->d_name);
	closedir(dir_ptr);
    }
}


void dostat(char * filename)
{
    struct stat info;
    if(stat(filename,&info) == -1)
	perror(filename);
    else
	show_file_info(filename,&info);

}


void show_file_info(char * filename,struct stat *info_p)
{
    char *uid_to_name(uid_t), *gid_to_name(gid_t),  *ctime(), *filemode();
    void mode_to_letters();
    char modestr[11];

    mode_to_letters(info_p->st_mode,modestr);

    printf("%s",modestr);
    printf("%4d ",(int)info_p->st_nlink);
    printf("%-8s ",uid_to_name(info_p->st_uid));
    printf("%-8s ",gid_to_name(info_p->st_gid));
    printf("%8ld",(long)info_p->st_size);
    printf("%.12s",4+ctime(&info_p->st_mtime));
    printf(" %s\n",filename);
}


void mode_to_letters(int mode,char str[])	//设置ls-l后的权限显示
{
    strcpy(str,"----------");
    if(S_ISDIR(mode))str[0] = 'd';		//是否为根目录
    if(S_ISCHR(mode))str[0] = 'c';		//是否为设备文件里的串行端口设备
    if(S_ISBLK(mode))str[0] = 'b';		//是否为设备端口文件里面到可供存储到接口设备

    //与掩码 与 运算判断其权限
    if(mode&S_IRUSR)str[1] = 'r';		//文件所有者到权限，可读，可写，可执行
    if(mode&S_IWUSR)str[2] = 'w';
    if(mode&S_IXUSR)str[3] = 'x';

    if(mode&S_IRGRP)str[4] = 'r';		//属组用户到权限，可读，可写，可执行
    if(mode&S_IWGRP)str[5] = 'w';
    if(mode&S_IXGRP)str[6] = 'x';

    if(mode&S_IROTH)str[7] = 'r';		//其他非本组用户到权限，可读，可写，可执行
    if(mode&S_IWOTH)str[8] = 'w';
    if(mode&S_IXOTH)str[9] = 'x';

}



//#include<pwd.h>
char * uid_to_name(uid_t uid)			//打印user name
{
    struct passwd * getpwuid(),* pw_ptr;
    static char numstr[10];

    if((pw_ptr = getpwuid(uid)) == NULL){	//如果uid不合法，那么getpwuid返回空指针
	sprintf(numstr,"%d",uid);		//不合法就把整数uid打印到numstr中，返回不合法到uid
	return numstr;
    }
    else
	return pw_ptr->pw_name;		//如果合法就返回uid所对应到名字

}


//#include<grp.h>
char * gid_to_name(gid_t gid)                   //打印属组名
{
    struct group * getgrgid(),* grp_ptr;
    static char numstr[10];

    if((grp_ptr = getgrgid(gid)) == NULL){       //如果gid不合法，那么getgrgid返回空指针
	sprintf(numstr,"%d",gid);               //不合法就把整数gid打印到numstr中，返回不合法到gid
	return numstr;
    }
    else
	return grp_ptr->gr_name;             //如果合法就返回gid所对应到名字

}

