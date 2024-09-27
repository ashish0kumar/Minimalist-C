#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        AF_INET,
        htons(8080),  // Use htons to set the port in network byte order
        INADDR_ANY     // Listen on all interfaces
    };

    if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(s, 10);

    int client_fd = accept(s, 0, 0);
    if (client_fd < 0) {
        perror("accept failed");
        exit(1);
    }

    char buffer[256] = {0};
    recv(client_fd, buffer, 256, 0);

    // Assume the request is in the format "GET /file.html HTTP/1.1"
    char* f = buffer + 5; // Skip "GET "
    *strchr(f, ' ') = 0;  // Terminate string at the first space

    int opened_fd = open(f, O_RDONLY);
    if (opened_fd < 0) {
        perror("file open failed");
        close(client_fd);
        close(s);
        exit(1);
    }

    // Prepare the HTTP response headers
    const char *http_header = "HTTP/1.1 200 OK\r\n"
                              "Content-Type: text/html\r\n"
                              "Content-Length: %ld\r\n"
                              "Connection: close\r\n"
                              "\r\n";

    // Get the size of the file
    off_t file_size = lseek(opened_fd, 0, SEEK_END);
    lseek(opened_fd, 0, SEEK_SET); // Reset the file pointer

    // Create the header
    char header[256];
    int header_length = snprintf(header, sizeof(header), http_header, file_size);
    if (header_length < 0 || header_length >= sizeof(header)) {
        perror("snprintf failed");
        close(opened_fd);
        close(client_fd);
        close(s);
        exit(1);
    }

    // Send the HTTP response headers
    send(client_fd, header, header_length, 0);

    // Send the file content
    sendfile(client_fd, opened_fd, 0, file_size);

    close(opened_fd);
    close(client_fd);
    close(s);
}
