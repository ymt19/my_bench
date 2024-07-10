#include "multicast.h"
#include <stdio.h>

int main(void) {
    sender_socket_t *sock;

    sock = sender_socket();

    send_multicast(sock, "abc", 3);

    send_multicast(sock, "abcd", 4);

    sender_close(sock);

    fprintf(stderr, "EXIT_SUCCESS\n");
}