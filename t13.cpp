//
// Created by 封心 on 2022/6/15.
//
#include <WinSock2.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32")

using namespace std;

DWORD g_dwErr;//用于取得错误信息
const int MAX_SIZE = 40960;//保存数组的大小
int main() {
    /* 初始化 */
    WSADATA wsdata;
    WSAStartup(MAKEWORD(2, 2), &wsdata);

    const char *hostname = "www.weather.com.cn";
    struct hostent *host = gethostbyname(hostname);

    /* 初始化一个连接服务器的结构体 */
    sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80);

    /* 此处也可以不用这么做，不需要用gethostbyname，把网址ping一下，得出IP也是可以的 */
    serveraddr.sin_addr.S_un.S_addr = *((int *) *host->h_addr_list);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        cout << "socket error" << endl;
        return -1;
    }
    cout << "socket succeed" << endl;

    if (::connect(sock, (struct sockaddr *) &serveraddr, sizeof(sockaddr_in)) == -1) {
        g_dwErr = GetLastError();
        cout << "connect error" << endl;
        closesocket(sock);
        return -1;
    }
    cout << "connect succeed" << endl;

    /* GET请求 */
    const char *bufSned = "GET http://www.weather.com.cn/data/sk/101190101.html\r\n";

    /* 发送GET请求 */
    if (send(sock, bufSned, strlen(bufSned), 0) > 0) {
        cout << "send succeed" << endl;
    } else {
        g_dwErr = GetLastError();
        cout << "send error, 错误编号： " << g_dwErr << endl;
        closesocket(sock);
        return -1;
    }

    char BufRecv[MAX_SIZE] = {};
    string HtmlData;

    /* 开始接收数据 */
    while ((recv(sock, BufRecv, MAX_SIZE, 0)) > 0) {
        /* 把数组拼接成string类型，方便下面的处理 */
        HtmlData += BufRecv;
    }

    printf("BufRecv=%s\n", BufRecv);

    closesocket(sock);
    return 0;
}

