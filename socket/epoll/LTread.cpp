#include <sys/epoll.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
    struct epoll_event ev, events[5]; // ev用于注册事件，数组用于返回要处理的事件
    char buf[256];

    int epfd = epoll_create(1);
    ev.data.fd = STDIN_FILENO;
    ev.events = EPOLLIN; // 使用默认LT模式

    epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev);

    while(true) {
        int nfds = epoll_wait(epfd, events, 5, -1);
        for(int i = 0; i < nfds; ++i) {
            if (events[i].data.fd == STDIN_FILENO) {
                read(STDIN_FILENO, buf, sizeof(buf));  // 将缓冲中的内容读出
                cout << "LT DEMO!" << endl;
            }
        }
    }
    return 0;
}
