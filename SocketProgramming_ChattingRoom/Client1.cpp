#include <iostream>
#include <winsock2.h>
using namespace std;

int main() {
    int fd;
    struct sockaddr_in dest;
    char buffer[128] = "";
    char buffer1[100] = "Hi server";

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
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    err = connect(fd, (struct sockaddr*) &dest, sizeof(dest));
    if(err < 0) {
            cerr<<"fail to connect";
            exit(1);
        }

    // receive message from server
    send(fd, buffer1, sizeof(buffer1), 0);
    recv(fd, buffer, sizeof(buffer), 0);
    cout<<"receive from server: "<<buffer<<endl;

    closesocket(fd);

    return 0;
}
