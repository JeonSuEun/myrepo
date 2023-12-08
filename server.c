#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

#define MAX_BUFFER_SIZE 1024

void handle_file_transfer(SOCKET client_socket) {
    char buffer[MAX_BUFFER_SIZE];
    int recv_size;

    // 파일 이름 수신
    recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
    if (recv_size > 0) {
        buffer[recv_size] = '\0';
        printf("Received file name: %s", buffer);

        // 파일 열기
        FILE* file = fopen(buffer, "rb");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        // 파일 크기 전송
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        send(client_socket, (char*)&file_size, sizeof(file_size), 0);

        // 파일 전송
        while (1) {
            size_t read_size = fread(buffer, 1, sizeof(buffer), file);
            if (read_size > 0) {
                send(client_socket, buffer, (int)read_size, 0);
            }

            if (read_size < sizeof(buffer)) {
                break;  // 파일의 끝에 도달하면 전송 종료
            }
        }

        fclose(file);
    }
}

int main() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        fprintf(stderr, "Failed to initialize Winsock\n");
        return 1;
    }

    // 서버 설정 코드
    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        perror("Error creating socket");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Error binding socket");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        perror("Error listening on socket");
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    printf("Server is listening on port 12345...\n");

    while (1) {
        SOCKET client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == INVALID_SOCKET) {
            perror("Error accepting connection");
            closesocket(server_socket);
            WSACleanup();
            return 1;
        }

        // 파일 전송 함수 호출
        handle_file_transfer(client_socket);

        closesocket(client_socket);
    }

    closesocket(server_socket);
    WSACleanup();

    return 0;
}
