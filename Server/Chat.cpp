#include "Chat.h"
#include "history_files/WorkWithFiles.h"

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

void Chat::transformUser(string& message)
{
    string user, login, name, password;
    bool admin;
    user = message;
    int pos = 0;
    int delim = user.find("#");
    pos = delim + 1;
    delim = user.find('#', pos);
    login = user.substr(pos, delim - pos );
    pos = delim + 1;
    delim = user.find('#', pos);
    name = user.substr(pos, delim - pos );
    pos = delim + 1;
    delim = user.find('#', pos);
    password = user.substr(pos, delim - pos );
    pos = delim + 1;

    if(user[pos] == 't')
        admin = true;
        
    User us(login, name, password, admin);

    users.push_back(us);
    createUsers(us);
    cout<< "User wos add: " << us << endl;
}

void Chat::transformMess(string& message)
{
    string user, from, to, text;
    bool admin;
    user = message;
    int pos = 0;
    int delim = user.find("#");
    pos = delim + 1;
    delim = user.find('#', pos);
    from = user.substr(pos, delim - pos );
    pos = delim + 1;
    delim = user.find('#', pos);
    to = user.substr(pos, delim - pos );
    pos = delim + 1;
    delim = user.find('#', pos);
    text = user.substr(pos);
    pos = delim + 1;

    Message mess(from, to, text);

    messages.push_back(mess);
    createMessages(mess);
    cout <<"Message wos add: " << mess << endl;
}

Chat::~Chat(){}