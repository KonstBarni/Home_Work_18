#include <iostream>
#include "ServerChat.h"
#include "Chat.h"

int main()
{
    system("chcp 1251");

    std::string serverMessage, clientMessage;

    Server server;
    Chat chat;
    chat.readMessagHistory();
    chat.readUsersHistory();
    server.createSocket();
    server.bindSocket();
    server.dataReceivingServer();

    while (true) {
        clientMessage = server.readData();
        if (clientMessage == "exit") {
            break;
        }
        serverMessage = chat.messageProcessing(clientMessage);
        server.writeData(serverMessage);
    }

    server.closeSocket();

    return 0;
}