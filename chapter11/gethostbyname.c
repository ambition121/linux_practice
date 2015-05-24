#include<stdio.h>
#include<netdb.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	char *host,**names,**addrs,myname[1024];
	struct hostent *hostinfo;


	/*设置主机为命令行参数指定的名字或程序运行所在机器的名字*/
	if(argc > 1)
		host = argv[1];
	else{
		gethostname(myname,255);//得到本机到标准主机名
		host = myname;
	}
	
	hostinfo = gethostbyname(host);//获取主机地址信息返回到hostent结构体
	if(!hostinfo){
		fprintf(stderr,"cann't get the information of the host:%s\n",host);
		exit(1);
	}
	/*获取正式名和别名*/
	printf("results for host %s:\n",host);
	printf("official name:%s\n",hostinfo->h_name);
	printf("\t Aliases:");
	names = hostinfo->h_aliases;
	while(*names){	//如果不止一个别名
		printf("%s\n",*names);
		names++;
	}
	/*输出ip地址*/
//	addrs = hostinfo->h_addr_list;
	//while(*addrs){
//		printf("\taddress:%s\n",inet_ntoa(*(struct in_addr*)addrs));
	//	addrs++;
	//}
		exit(0);
}
