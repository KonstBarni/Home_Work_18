#include "Chat.h"

void Chat::addUsers(User& us){users.push_back(us);}

void Chat::addMessages(Message& mes){messages.push_back(mes);}

void Chat::readUsersHistory()		//чтение итории пользователей из файла
{
	fstream read_user;
    read_user.open(PATH_USER, fstream::in | fstream::out);

	//если файл истории есть, он будет считан

    if(!read_user)
        cout<<"History Users file  not exist!" << endl;

    read_user.seekg(0, ios_base::beg);

    while(true)
    {
        if(read_user.eof())
            break;
        User us;
        read_user >> us;
        addUsers(us);	
    }
	read_user.close();

}

void Chat::readMessagHistory()		//чтение истории сообщений из файла
{
	fstream read_mess;
    read_mess.open(PATH_MESS, fstream::in | fstream::out);

	//если файл истории есть, он будет считан

    if(!read_mess)
        cout<<"History Users file  not exist!" << endl;

    read_mess.seekg(0, ios_base::beg);

    while(true)
    {
        if(read_mess.eof())
            break;
        Message mess;
        read_mess >> mess;
		addMessages(mess);
    }
	read_mess.close();
}

string Chat::messageProcessing(string& clientMessage)
{
    string outMessage;

    //_vectorFromMessage = messageToVector(clientMessage, ":");

    // if (_vectorFromMessage[0] == "loginUser") {
    //     outMessage = loginUser();
    // }
    // else if (_vectorFromMessage[0] == "registerUser") {
    //     outMessage = registerUser();
    // }
    // else if (_vectorFromMessage[0] == "showChat") {
    //     outMessage = showChat();
    // }
    // else if (_vectorFromMessage[0] == "addMessage") {
    //     outMessage = addMessage();
    // }
    // else if (_vectorFromMessage[0] == "showUsers") {
    //     outMessage = showUsers();
    // }

    return outMessage;
}

Chat::~Chat(){}