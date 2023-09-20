#pragma once
#include <vector>
#include "../User.h"
#include "../Massage.h"

void createUsers(User& us);             //создание файла истории пользователей
void createMessages(Message& mess);     //создание файла истории сообщений
void writeHistory(vector<Message>& msgs);   //перезапись истории сообщений