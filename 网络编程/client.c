#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main(){
    //创建套接字
    int sock=socket(AF_INET,SOCK_STREAM,0);
    //向服务器(特定的IP和端口)发起请求
    struct sockaddr_in serv_addr;//使用IPv4地址
    memset(&serv_addr,0,sizeof(serv_addr));//具体的IP地址
    serv_addr.sin_port=htons(1234);//端口
    connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    //读取服务器传回的数据
    char buffer[40];
    read(sock,buffer,sizeof(buffer)-1);
    printf("Message from server: %s\n",buffer);
    //关闭套接字
    close(sock);
    return 0;
}