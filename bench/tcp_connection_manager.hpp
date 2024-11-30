#pragma once

#include "configuration.hpp"
#include "transaction.hpp"
#include <queue>
#include <thread>

class tcp_connection_manager
{
public:
    tcp_connection_manager(configuration *_config, std::queue<transaction> *_requests);
    ~tcp_connection_manager();
    void run();
private:
    configuration *config;
    std::queue<transaction> *requests;

    std::thread worker;
    int connect_fd[10];
    int listen_fd;

    void sender();
    void receiver();
};