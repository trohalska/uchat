#include "server.h"

static void build_fd_sets(t_sock *sock) {
    int i;
    int sd;

    FD_ZERO(&sock->readfds);
    FD_SET(STDIN_FILENO, &sock->readfds);
    FD_SET(sock->master_socket, &sock->readfds);
    sock->max_sd = sock->master_socket;
    for (i = 0; i < MAX_CLIENTS; i++) {
        sd = sock->connection_list[i].socket;
        if (sd > MX_NO_SOCKET)
            FD_SET(sd, &sock->readfds);
        if (sd > sock->max_sd)
            sock->max_sd = sd;
    }
    FD_ZERO(&sock->writefds);
    for (i = 0; i < MAX_CLIENTS; i++)
        // if (sock->connection_list[i].socket > MX_NO_SOCKET
        //     && sock->connection_list[i].send_buffer.current > 0)
        //     FD_SET(sock->connection_list[i].socket, &sock->writefds);
        if (sock->connection_list[i].socket > MX_NO_SOCKET)
            FD_SET(sock->connection_list[i].socket, &sock->writefds);

    FD_ZERO(&sock->exceptfds);
    FD_SET(STDIN_FILENO, &sock->exceptfds);
    FD_SET(sock->master_socket, &sock->exceptfds);
    for (i = 0; i < MAX_CLIENTS; i++)
        if (sock->connection_list[i].socket > MX_NO_SOCKET)
            FD_SET(sock->connection_list[i].socket, &sock->exceptfds);
}


void mx_sockets_loop(t_info *info) {
    int activity;

    while (TRUE) {
        build_fd_sets(info->sock);
        activity = select(info->sock->max_sd + 1, &info->sock->readfds,
                          &info->sock->writefds, &info->sock->exceptfds, NULL);
        // activity = select(info->sock->max_sd + 1, &info->sock->readfds,
        //        NULL, NULL, NULL);
        // switch (activity) {
        //     case -1:
        //         perror("select()");
        //         mx_shutdown_properly(info, EXIT_FAILURE);
        //     case 0:  // should never get here
        //         printf("select() returns 0.\n");
        //         mx_shutdown_properly(info, EXIT_FAILURE);
        //     default:
                mx_loop_handler(info);
        // }
        // mx_shutdown_properly(info);
    }
}