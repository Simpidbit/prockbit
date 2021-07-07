/*
 * Implementation functions in class Prockbit
 *
 * Copyright (C) 2021, Simpidbit Isaiah.
 *     Author: Simpidbit Isaiah <8155530@gmail.com>
 */

#include <signal.h>
#include <stdlib.h>
#include <functional>

#include "prockbit.hpp"
#include "net.h"
#include "hashtab.hpp"

Prockbit::Prockbit(char *addr, unsigned short port,
                   int backlog)
    : addr(addr), port(port), backlog(backlog)
{
    // Socket
    this->servfd = wsocket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&this->serv_addr, sizeof(struct sockaddr_in));
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(this->port);
    winet_pton(AF_INET, this->addr, &this->serv_addr.sin_addr);

    wbind(this->servfd, (struct sockaddr *)&this->serv_addr,
          this->serv_addr_len);

    wlisten(this->servfd, this->backlog);

    // Signal register
    auto stop = [this](int) -> void {
        wclose(this->servfd);
        exit(0);
    };
    signal(SIGINT, (void (*)(int))&stop);
}

Prockbit::~Prockbit()
{
    wclose(this->servfd);
}

// Prockbit::serve()
#if defined (__linux) || defined(__linux__)
#include "linux_serve.hpp"      // Linux - epoll
#elif defined(__APPLE__)
#include "apple_serve.hpp"      // Apple - poll
#endif
