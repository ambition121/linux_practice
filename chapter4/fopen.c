#include<stdio.h>
#include<stdlib.h>//为了使用exit()
int main()
{
    char    ch;
    FILE    *fp=NULL;
    char fname[50];//用于存放文件名
    printf("输入文件名：\n");
    scanf("%s",fname);
    fp=fopen(fname,"r");//只供读取
    if(fp==NULL)//如果失败了
    {
	printf("错误！\n");
	exit(1);//中止程序
    }
    while((ch=getc(fp))!=EOF)
	putchar(ch);
    fclose(fp);//关闭文件
    return 0;
}
