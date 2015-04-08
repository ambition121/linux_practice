/*
   =====================================================================================
Filename:  ioctl1.c
Description:
Version:  1.0
Created:  2015年04月07日 19时50分31秒
Revision:  none
Compiler:  gcc
Author:  Zhangxin (ambition121), zhang_xin0502@163.com
Organization:  Linux
=====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

static void usage()
{
    printf("usage : ipconfig interface \n");
    exit(0);
}

int main(int argc,char **argv)
{
    struct sockaddr_in *addr;
    struct ifreq ifr;
    char *name,*address;
    int sockfd;

    if(argc != 2)  usage();
    else  name = argv[1];

    sockfd = socket(AF_INET,SOCK_DGRAM,0);
    strncpy(ifr.ifr_name,name,IFNAMSIZ-1);

    if(ioctl(sockfd,SIOCGIFADDR,&ifr) == -1)
        perror("ioctl error"),exit(1);

    addr = (struct sockaddr_in *)&(ifr.ifr_addr);
    address = inet_ntoa(addr->sin_addr);
    printf("inet addr: %s ",address);

    if(ioctl(sockfd,SIOCGIFBRDADDR,&ifr) == -1)
        perror("ioctl error"),exit(1);

    addr = (struct sockaddr_in *)&ifr.ifr_broadaddr;
    address = inet_ntoa(addr->sin_addr);
    printf("broad addr: %s ",address);

    if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
        perror("ioctl error"),exit(1);
    addr = (struct sockaddr_in *)&ifr.ifr_addr;
    address = inet_ntoa(addr->sin_addr);
    printf("inet mask: %s ",address);

    printf("\n");
    exit(0);
}
