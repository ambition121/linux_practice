/**********************************************************
 * Author        : Zhangxin
 * Email         : zhang_xin0502@163.com
 * Last modified : 2015-05-24 10:28
 * Filename      : services.c
 * Description   :这个程序是打印端口信息的 
 * *******************************************************/
#include<stdio.h>
#include<netdb.h>
int main(void)
{
	int stayopen = 1;
	struct servent *sp;
	setservent(stayopen);//打开服务数据库，准备扫描
	while(1){			//扫描
		sp = getservent();
		if(sp != (struct servent *)0)
			/*servent结构体
			 *char *s_name 服务程序到名字
			 *char *s_aliases 服务程序别名
			 *int s_port 端口号，端口号按网络字节顺序
			 *char *s_proto 协议名
			 * */
			printf("server name=%12s,port=%6d,proto=%4s\n",sp->s_name,ntohs(sp->s_port),sp->s_proto);
		else
			break;
	}
	endservent();//关闭服务数据库
	sp = getservbyname("telnet","tcp");//查看telnet服务的端口号
	if(sp != (struct servent *)0)
		printf("telent's port is:%d\n",ntohs(sp->s_port));
	else
		printf("failed\n");
}
