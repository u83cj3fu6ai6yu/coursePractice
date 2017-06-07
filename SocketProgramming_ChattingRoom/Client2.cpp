#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32.lib");
using namespace std;

void print(int sockfd, char* name) {
    char buffersend[100] = "", namebuffersend[100] = "";

    while(1) {
        gets(buffersend);
        strcpy(namebuffersend, name);
        strcat(namebuffersend, " : ");
        strcat(namebuffersend, buffersend);
        send(sockfd, namebuffersend, sizeof(namebuffersend), 0);
        if( !strcmp(buffersend, "bye") )
            break;
    }
}

void receive(int sockfd, char* name) {
    int err;
    char bufferrecv[100] = "";

    while(1) {
        err = recv(sockfd, bufferrecv, sizeof(bufferrecv), 0);
        if(err == 0) {
            printf("recv fail\n");
            break;
        }
        printf("%s\n", bufferrecv);
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
    int sockfd;
    struct sockaddr_in dest;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8000);
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    err = connect(sockfd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
        printf("connect fail with error\n");
        exit(1);
    }

    char name[100] = "";
    printf("What's your name?\n");
    gets(name);
    while(1) {
        /*err = recv(sockfd, bufferrecv, sizeof(bufferrecv), 0);
        if(err == 0) {
            printf("recv fail with error\n");
            closesocket(sockfd);
        }
        printf("receive from server: %s\n", bufferrecv);
        gets(buffersend);
        send(sockfd, buffersend, sizeof(buffersend), 0);*/
        thread sendthread( print, sockfd, name );
        thread recvthread( receive, sockfd, name );
        sendthread.join();
        recvthread.join();
        break;
    }
    closesocket(sockfd);

    return 0;
}
