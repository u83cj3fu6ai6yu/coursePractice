#include <stdio.h>
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32.lib");
using namespace std;

// receive message from one client and then send to other clients
void retrans(int self, int* clientfd, int* out, int selfnum) {
    int err;
    char buffer[100] = "";

    while(true) {
        err = recv(self, buffer, sizeof(buffer), 0);
        if(err == 0) {
            printf("recv fail\n");
            break;
        }

        for(int i=0; i<20; i++)
            if(out[i] && (self!=clientfd[i]))
                send(clientfd[i], buffer, sizeof(buffer), 0);
        // if receive bye then break so thread of this client will terminate
        if( strstr(buffer, "bye") ) {
            closesocket(self);
            out[selfnum] = 0;
            break;
        }
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
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8000);
    dest.sin_addr.s_addr = htonl(INADDR_ANY);
    // bind
    err = bind(sockfd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
        perror("bind fail\n");
        exit(1);
    }
    // listen
    err = listen(sockfd, 20);
    if(err < 0) {
        perror("listen fail\n");
        exit(1);
    }
    // create at most 20 clients
    int c = 0;
    int clientfd[20] = {};
    struct sockaddr_in client_addr[20];
    int addrlen[20];
    for(int i=0; i<20; i++)
        addrlen[i] = sizeof(client_addr);
    int out[20] = {};
    char name[100] = "What's your name?";
    // accept and wait for client's connect
    while(true) {
        clientfd[c%20] = accept(sockfd, (struct sockaddr*) &client_addr[c%20], &addrlen[c%20]);
        if(clientfd[c%20] == 0) {
            perror("accept fail\n");
            exit(1);
        }
        // set up thread for sending and receiving
        thread recvandsend( retrans, clientfd[c%20], clientfd, out, c%20 );
        recvandsend.detach();
        out[c%20] = 1;
        c++;
    }
    closesocket(sockfd);
}
