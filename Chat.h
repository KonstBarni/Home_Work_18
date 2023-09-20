#pragma once
#include <vector>
#include <unordered_map>
#include <exception>
#include <memory>
#include "Massage.h"

#define PATH_USER  "history_files/Users.txt"       //путь к файлу с пользователями
#define PATH_MESS  "history_files/Messages.txt"       //путь к файлу с сообщениями

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
	bool isChatWork_ = false;						//маркер работы чата
	vector<User> users_;							//вектор юзеров
	unordered_map<string, int> usersHash_;			//хеш таблица юзеров и паролей
	vector<Message>messages_;						//вектор сообщений
	shared_ptr<User> currentUser_ = nullptr;		//указатель активного пользователя

	void login();							//логин
	void registration();					//регистрация
	void showChat() const;					//показать чат
	void showAllUsersName() const;			//показать всех пользователей
	void addMessage();						//добавить сообщение
	void dellMessage();						//удалить сообщение
	int hashFunction(string& pass);			//хеш-функция для пароля

	vector<User>& getAllUsers() { return users_; }		//возвращает всех пользователей
	vector<Message>& getAllMessages() { return messages_; }			//возвращает сообщения
	shared_ptr<User> getUserByLogin(const string& login) const;		//возвращает пользователя по логину
	shared_ptr<User> getUserByName(const string& name) const;		//возвращает пользователя по имени

public:
	
	bool isChatWork() const { return isChatWork_; }				//маркер работы чата
	void start();												//старт чата
	void showLoginMenu();										//меню логина/регистрации
	void showUserMenu();										//меню пользователя
	shared_ptr<User> getCurrentUser() const { return currentUser_; }	//возвращает активного пользователя
	void readUsersHistory();
	void readMessagHistory();

};