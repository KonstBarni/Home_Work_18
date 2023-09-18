#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include "Chat.h"
#include "autocomplite/Functions.h"
#include "history_files/WorkWithFiles.h"

using namespace std;

void Chat::start()			//маркер работы чата
{
	isChatWork_ = true;
}

int Chat::hashFunction(string& password)   //хеш функция
{
    int sum = 0, i = 0, mem_size = 10, offset = 3;
    for(; i < password.size(); i++) {
        sum = sum*25 + password[i]; // метод умноженя
    }
    // второе хеширование
    int f2 = sum % (mem_size * 2);
    // проба
    return (sum % mem_size + offset*offset) % mem_size; // квадратичны метод хеширования
}

shared_ptr<User> Chat::getUserByLogin(const string& login) const	//возвращает пользователя по логину
{
	for (auto& user : users_)
	{
		if (user.getUserLogin() == login)
			return make_shared<User>(user);
	}
	return nullptr;
}

shared_ptr<User> Chat::getUserByName(const string& name) const		//возвращает пользователя по имени
{
	for (auto& user : users_)
	{
		if (name == user.getUserName())
			return make_shared<User>(user);
	}
	return nullptr;
}

void Chat::login()		//функция логина в чат
{
	string login, password;
	char operation;

	do
	{
		cout << "login: ";
		cin >> login;
		cout << "password: ";
		cin >> password;

		currentUser_ = getUserByLogin(login);

		unordered_map <string, int>::iterator it = usersHash_.find(login);

		if (currentUser_ == nullptr || it == usersHash_.end() || (hashFunction(password) != it->second))	//проверка
		{																					//на соответствие
			currentUser_ = nullptr;															//логина и пароля		

			cout << "login failed" << endl << "(q) for exit or (any key) for repeat: ";
			cin >> operation;

			if (operation == 'q')				//выход из цикла
				break;
		}
	} while (!currentUser_);
}

void Chat::registration()				//функция регистрации
{
	string login, password, name;
	bool admin;
	char adminKey{};

	cout << "login: ";
	cin >> login;
	cout << "password: ";
	cin >> password;
	cout << "name: ";
	cin >> name;
	cout << "Вы администратор?  [Y/N]  ";
	cin >> adminKey;

	if (adminKey == 'Y' || adminKey == 'y')			//проверка ввода админа
		admin = true;

	if (getUserByLogin(login) || login == "all")	//ловит исключение по логину
	{
		throw UserLoginExp();
	}

	if (getUserByName(name) || name == "all")		//ловит исключение по имени
	{
		throw UserNameExp();
	}

	User user = User(login, password, name, admin);
	users_.push_back(user);							//кладет пользователя в вектор
	currentUser_ = make_shared<User>(user);			//делает пользователя активным
	usersHash_.insert({login, hashFunction(password)});				//добавляет в хеш таблицу
	createUsers(user);
}

void Chat::showChat() const			//показать сообщения чата
{
	string from, to;
	unsigned short count{0};

	cout << "Start Chat" << endl;

	for (auto& mess : messages_)
	{
		count++;					
		if ((currentUser_-> getUserName() == mess.getTo()) ||
		(currentUser_ -> getUserName() == mess.getFrom()) || (mess.getTo() == "all"))  //условие приватности
		{
		 	from = (currentUser_->getUserName() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getUserName();

		 	if (mess.getTo() == "all")
		 	{
		 		to = "(all)";
		 	}
		 	else
		 	{
		 		to = (currentUser_->getUserLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getUserName();
		 	}

			cout << "Message "<< count << " from " << from << " to " << to << endl << "text: " << mess.getText() << endl;
		}
	}
}

void Chat::showLoginMenu() 			//меню логина/регистрации
{
	currentUser_ = nullptr;

	char operation;

	do
	{
		cout << "(1)Registration" << endl << "(2)Login" << endl << "(q)Quit program" << endl;
		cin >> operation;

		switch (operation)
		{
		case '1':
			try
			{
				registration();
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}
			break;
		case '2':
			login();
			break;
		case 'q':
			isChatWork_ = false;
			break;
		default:
			cout << "1 or 2" << endl;
			break;
		}
	} while (!currentUser_ && isChatWork_);
}

void Chat::showUserMenu()		//меню пользователя
{
	char operation;
	cout << "Hi, " << currentUser_->getUserName() << endl;

	while (currentUser_)
	{
		if (currentUser_-> getAdmin())			//проверка на админа
			cout << "Menu: (1) Show chat | (2) Add message | (3) Users |(d) Dell message | (q) Logout" << endl;
		else
			cout << "Menu: (1) Show chat | (2) Add message | (3) Users | (q) Logout" << endl;

		cin >> operation;

		switch (operation)
		{
		case '1':
			showChat();
			break;
		case '2':
			addMessage();
			break;
		case '3':
			showAllUsersName();
			break;
		case 'd':
			dellMessage();
			break;
		case 'q':
			currentUser_ = nullptr;
			break;
		default:
			cout << "unknown choice" << endl;
			break;
		}
	}
}

void Chat::showAllUsersName() const			//показать всех пользователей
{
	cout << "All Users" << endl;
	for (auto& user : users_)
	{
		if (currentUser_->getUserLogin() == user.getUserLogin())
			cout << user.getUserName() << "(me)" <<" ";
		else
			cout << user.getUserName() << " ";
	}
	cout << endl;
}

void Chat::addMessage()			//добавить сообщение
{
	string from, to, text;

	cout << "To (name or all): " << endl;
	cin >> to;
	//cout << "Text: " << endl;
	//cin.ignore();
	//getline(cin, text);

	text = fullMess();
	from = currentUser_->getUserName();

	if (to == "all" || getUserByName(to))					//проверка правильности ввода кому
		messages_.push_back(Message{from, to, text });
	else
		cout << "error send message: cann't find " << to << endl;
		return;
}

 void Chat::dellMessage()				//удаление сообщения
 {
	try 
	{
		int numMes{};
		cout << "Enter the number of the message to delete: ";
		cin >> numMes;

		if(cin.fail())										//проверка на не цифру
			cin.clear();
		
		if (numMes < 1 || numMes > messages_.size()) 		//при выходе за диапазон, ловим исключение
		{
			throw invalid_argument("Bad input, try again");
		}
		messages_.erase(messages_.begin() + numMes-1);		//получаем итератор от начала, удаляем нужное сообщение
		cout << "Message successfully deleted\n";
	}
	catch (const exception& ex) 
	{
		cout << "error: " << ex.what() << endl;
	}
}
