/*
 * Include header-files which were needed in TCP/IP.
 * 
 * Copyright (C) 2021, Simpidbit Isaiah.
 *     Author: Simpidbit Isaiah <8155530@gmail.com>
 */

#ifndef NET_H
#define NET_H

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <strings.h>

int wsocket(int domain, int type, int protocal)
{
    int ret = socket(domain, type, protocal);
    if (ret == -1) {
        throw "socket() ERROR!";
    }
    return ret;
}

int winet_pton(int af, const char * src, void * dst)
{
    int ret = inet_pton(af, src, dst);
    if (ret == 0) {
        throw "inet_pton() ERROR: Incorrect address.";
    } else if (ret == -1) {
        throw "inet_pton() ERROR: System error.";
    }
    return ret;
}

int wbind(int socket, const struct sockaddr *address,
          socklen_t address_len)
{
    int ret = bind(socket, address, address_len);
    if (ret == -1) {
        throw "bind() ERROR!";
    }
    return ret;
}

int wlisten(int socket, int backlog)
{
    int ret = listen(socket, backlog);
    if (ret == -1) {
        throw "listen() ERROR!";
    }
    return ret;
}

int wclose(int socket)
{
    int ret = close(socket);
    if (ret == -1) {
        throw "close() ERROR!";
    }
    return ret;
}

#endif
