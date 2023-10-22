#pragma once
#include <vector>
#include "../User.h"
#include "../Massage.h"

#define PATH_USER  "history_files/Users.txt"       //путь к файлу с пользователями
#define PATH_MESS  "history_files/Messages.txt"       //путь к файлу с сообщениями

void createUsers(User& us);             //создание файла истории пользователей
void createMessages(Message& mess);     //создание файла истории сообщений
void writeHistory(vector<Message>& msgs);   //перезапись истории сообщений