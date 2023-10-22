#pragma once
#include "ServerChat.h"

class Chat
{
private:
    vector<User> users;
    vector<Message> messages;

public:

    void addUsers(User& us);
    void addMessages(Message& mes);
    void readUsersHistory();
	void readMessagHistory();
    string messageProcessing(string& clientMessage);

    ~Chat();
};