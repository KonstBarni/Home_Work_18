#pragma once
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include "User.h"
#include "Massage.h"

#define PATH_USER  "history_files/Users.txt"       //путь к файлу с пользователями
#define PATH_MESS  "history_files/Messages.txt"       //путь к файлу с сообщениями

using namespace std;

#define MESSAGE_LENGTH 1024
#define PORT 7777

class Server
{

public:

    struct sockaddr_in serveraddress, client;
    socklen_t length;
    int sockert_file_descriptor, connection, bind_status, connection_status;
    char message[MESSAGE_LENGTH];

    void createSocket();
    void bindSocket();
    void closeSocket();
    void dataReceivingServer();
    char* readData();
    void writeData(string serverMessage);
    void transformUser(string& mess);
    void transformMess(char* mess);
    
};