#include <stdio.h>
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32.lib");
using namespace std;

// send message to server
void print(int sockfd, char* name, int* key) {
    char buffersend[100] = "", namebuffersend[100] = "";

    while(1) {
        gets(buffersend);
        strcpy(namebuffersend, name);
        strcat(namebuffersend, " : ");
        strcat(namebuffersend, buffersend);
        send(sockfd, namebuffersend, sizeof(namebuffersend), 0);
        // when send bye then break so thread will terminate
        if( !strcmp(buffersend, "bye") ) {
            *key = 1;
            break;
        }
    }
}
// receive message from server
void receive(int sockfd, char* name, int* key) {
    int err;
    char bufferrecv[100] = "";

    while(1) {
        err = recv(sockfd, bufferrecv, sizeof(bufferrecv), 0);
        if(*key)
            break;
        if(err == 0) {
            perror("recv fail\n");
            break;
        }
        printf("%s\n", bufferrecv);
    }
}

int main() {
    // initialize DLL
    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(err != 0) {
        perror("WSAStartup failed\n");
        exit(1);
    }
    // create a socket
    int sockfd;
    struct sockaddr_in dest;
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8000);
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");
    // connect
    err = connect(sockfd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
        perror("connect fail with error\n");
        exit(1);
    }
    // ask client name
    char name[100] = "";
    printf("What's your name?\n");
    gets(name);
    int key = 0;
    // set up thread for sending and receiving
    thread sendthread( print, sockfd, name, &key);
    thread recvthread( receive, sockfd, name, &key);
    sendthread.join();
    recvthread.join();

    closesocket(sockfd);
}
