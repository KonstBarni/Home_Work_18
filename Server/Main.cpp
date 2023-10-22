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
        if(clientMessage[0] == 'U'&& clientMessage[1]=='#')
            chat.transformUser(clientMessage);
        
        if(clientMessage[0] == 'M'&& clientMessage[1]=='#')
            chat.transformMess(clientMessage);

        if (clientMessage == "exit") {
            cout << "Client wos disconected!" << endl;
            server.dataReceivingServer();
        }

        if(clientMessage == "stop")
            break;

        serverMessage = "Ok";
        server.writeData(serverMessage);
    }

    server.closeSocket();

    return 0;
}