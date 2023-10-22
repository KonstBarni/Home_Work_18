#pragma once
#include <vector>
#include <unordered_map>
#include <exception>
#include <memory>
#include "Massage.h"
#include "User.h"
#include "ClientChat.h"

using namespace std;

struct UserLoginExp : public exception		//исключение ошибки логина
{
	const char* what() const noexcept override { return "This user already exist!"; }
};

struct UserNameExp : public exception		//исключение ошибки имени юзера
{
	const char* what() const noexcept override { return "This user already exist!"; }
};

class Chat
{
	string userSend, messSend;
	bool isChatWork_ = false;						//маркер работы чата
	vector<User> users_;							//вектор юзеров
	unordered_map<string, int> usersHash_;			//хеш таблица юзеров и паролей
	vector<Message>messages_;						//вектор сообщений
	shared_ptr<User> currentUser_ = nullptr;		//указатель активного пользователя
	vector<string> _vectorFromMessage;
	shared_ptr<Client> cltptr;

	void login();							//логин
	void registration(shared_ptr<Client> cltptr);					//регистрация
	void showChat() const;					//показать чат
	void showAllUsersName() const;			//показать всех пользователей
	void addMessage(shared_ptr<Client> cltptr);						//добавить сообщение
	void dellMessage();						//удалить сообщение
	int hashFunction(string& pass);			//хеш-функция для пароля

	vector<User>& getAllUsers() { return users_; }		//возвращает всех пользователей
	vector<Message>& getAllMessages() { return messages_; }			//возвращает сообщения
	shared_ptr<User> getUserByLogin(const string& login) const;		//возвращает пользователя по логину
	shared_ptr<User> getUserByName(const string& name) const;		//возвращает пользователя по имени
	vector<string> messageToVector(string& message, string delimiter);

public:

	void setSPTR(Client cl){cltptr = make_shared<Client>(cl);}	
	bool isChatWork() const { return isChatWork_; }				//маркер работы чата
	void start();												//старт чата
	void showLoginMenu();										//меню логина/регистрации
	void showUserMenu();										//меню пользователя
	shared_ptr<User> getCurrentUser() const { return currentUser_; }	//возвращает активного пользователя
	//string& userToSend(string& lagin, string& password, string& name, bool admin);
	//string& messageToSend(string& from, string& to, string& text);
};