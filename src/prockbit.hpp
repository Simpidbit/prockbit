/*
 * Copyright (C) 2021, Simpidbit Isaiah.
 *     Author: Simpidbit Isaiah <8155530@gmail.com>
 */

#ifndef PROCKBIT_H
#define PROCKBIT_H

#include "net.h"
#include "hashtab.hpp"

class Prockbit
{
public:
    Prockbit(char *addr = (char *)"127.0.0.1",
             unsigned short port = 8080,
             int backlog = 32);
    ~Prockbit();
    void serve();

    char *addr;
    int port;

private:
    // Linux socket
    int servfd;
    struct sockaddr_in serv_addr;
    socklen_t serv_addr_len;
    int backlog;
};

#endif
