#include <stdio.h>
#include <winsock2.h>
#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

#define MAX_BUFFER_SIZE 1024

void send_file(SOCKET server_socket, const char* file_path) {
    char buffer[MAX_BUFFER_SIZE];
    int recv_size;

    // ���� �̸� ����
    send(server_socket, file_path, strlen(file_path), 0);

    // ���� ũ�� ����
    long file_size;
    recv_size = recv(server_socket, (char*)&file_size, sizeof(file_size), 0);
    if (recv_size <= 0) {
        perror("Error receiving file size");
        return;
    }

    printf("File size: %ld bytes\n", file_size);

    // ���� ����
    FILE* file = fopen(file_path, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // ���� ������ ����
    while (file_size > 0) {
        recv_size = recv(server_socket, buffer, sizeof(buffer), 0);
        if (recv_size <= 0) {
            perror("Error receiving file data");
            fclose(file);
            return;
        }

        fwrite(buffer, 1, recv_size, file);
        file_size -= recv_size;
    }

    fclose(file);
}

int main() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        fprintf(stderr, "Failed to initialize Winsock\n");
        return 1;
    }

    SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        perror("Error creating socket");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // ���� IP �ּ�
    server_addr.sin_port = htons(12345);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("Error connecting to server");
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    // Ŭ���̾�Ʈ���� ���� ���� �Լ� ȣ�� (��: "test.txt" ������ ������ ����)
    send_file(client_socket, "test.txt");

    closesocket(client_socket);
    WSACleanup();

    return 0;
}
