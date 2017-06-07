#include<stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32.lib");
using namespace std;

void print(int clientfd) {
    char buffersend[100] = "";

    while(1) {
        gets(buffersend);
        send(clientfd, buffersend, sizeof(buffersend), 0);
        if( !strcmp(buffersend, "bye") )
            break;
    }
}

void receive(int clientfd, char* temp) {
    int err;
    char bufferrecv[100] = "";

    while(1) {
        err = recv(clientfd, bufferrecv, sizeof(bufferrecv), 0);
        if(err == 0) {
            printf("recv fail with error\n");
            break;
        }
        printf("receive from %s : %s\n", temp, bufferrecv);
        if( !strcmp(bufferrecv, "bye") )
            break;
    }
}

int main() {

    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(err != 0) {
        printf("WSAStartup failed with error\n");
        return 1;
    }

    // create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8000);
    dest.sin_addr.s_addr = htonl(INADDR_ANY);

    // assign a port # to socket
    err = bind(sockfd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
        printf("bind fail with error\n");
        exit(1);
    }

    err = listen(sockfd, 20);
    if(err < 0) {
        printf("listen fail with error\n");
        exit(1);
    }
    while(1) {

        int clientfd;
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);
        char temp[100] = "What's your name?";

        // wait and accept connection
        clientfd = accept(sockfd, (struct sockaddr*) &client_addr, &addrlen);
        if(clientfd == 0) {
            printf("accept fail with error\n");
            exit(1);
        }
        send(clientfd, temp, sizeof(temp), 0);
        err = recv(clientfd, temp, sizeof(temp), 0);
        if(err == 0) {
            printf("recv fail with error\n");
            break;
        }
        while(1) {
            thread sendthread( print, clientfd );
            thread recvthread( receive, clientfd, temp );
            sendthread.join();
            recvthread.join();
            closesocket(clientfd);
            break;
        }
    }
    closesocket(sockfd);
    return 0;
}
