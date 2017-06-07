#include <iostream>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib");
using namespace std;



int main() {
    int fd;
    struct sockaddr_in dest;
    char buffer[100] = "Hi client";
    char buffer1[10];

    int err;
    WSADATA wsaData;
    err = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if(err != 0) {
        cout<<"WSAStartup failed with error: "<<err<<endl;
        return 1;
    }

    // create the socket
    fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(8000);
    dest.sin_addr.s_addr = htonl(INADDR_ANY);

    // assign a port # to socket
    err = bind(fd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
        cerr<<("bind");
        exit(1);
    }

    err = listen(fd, 20);
    if(err < 0) {
        cerr<<("listen");
        exit(1);
    }

    while(1) {
        int clientfd;
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);

        // wait and accept connection
        clientfd = accept(fd, (struct sockaddr*) &client_addr, &addrlen);


        // send message to client
        send(clientfd, buffer, sizeof(buffer), 0);
        err = recv(clientfd, buffer1, sizeof(buffer1), 0);
        if(err == 0) {
            cerr<<"fail to recv";
        }
        cout<<"receive from client: "<<buffer1<<endl;

        closesocket(clientfd);
    }

    closesocket(fd);
    return 0;
}
