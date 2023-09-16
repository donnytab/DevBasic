#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8081);

    bind(sock, (sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(sock, SOMAXCONN);
    
    struct sockaddr_in clt_addr;
    socklen_t clt_addr_len = sizeof(clt_addr);
    bzero(&clt_addr, sizeof(clt_addr));

    int clt = accept(sock, (sockaddr*)&clt_addr, &clt_addr_len);

    return 0;
}
