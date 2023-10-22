#include <iostream>
#include "Chat.h"
#include "ClientChat.h"

int main()
{
    std::string clientMessage, serverMessage, sendServ;
    Chat chat;
    Client client;
    bool sendMess = false;
    pair <string, bool> workMess;
    shared_ptr<Client> cl = make_shared<Client> (client);

    chat.start();
    client.createSocket();
	client.connectionToServer();

    while (chat.isChatWork())
    {
        chat.setSPTR(client);
        chat.showLoginMenu();

        clientMessage = "Message to server";
		//client.writeData(clientMessage);
		if (clientMessage == "exit") {
			break;
		}
		serverMessage = client.readData();
		//chat.messageProcessing(serverMessage);

        while (chat.getCurrentUser())
        {
            chat.showUserMenu();
        }

    }
    client.closeSocket();

    return 0;
}