#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "WorkWithFiles.h"
#include "../User.h"
#include "../Massage.h"
//#include "../Chat.h"

using namespace std;
namespace fs = filesystem;

void createUsers(User& us)      //создание файла с юзерами
{
    fstream file_writer = fstream(PATH_USER, ios::in | ios::app);

    if(!file_writer)
        file_writer = fstream(PATH_USER, ios::in | ios::out | ios::trunc);

    file_writer << us << endl;

    fs::permissions(PATH_USER, fs::perms::group_all | 
        fs::perms::others_all, fs::perm_options::remove);       //удалить права на файл
    
    file_writer.close();
}

void createMessages(Message& mess)    //создание файла с сообщениями
{
    fstream file_writer = fstream(PATH_MESS, ios::in | ios::app);

    if(!file_writer)
        file_writer = fstream(PATH_MESS, ios::in | ios::out | ios::trunc);

    file_writer << mess << endl;

    fs::permissions(PATH_MESS, fs::perms::group_all | 
        fs::perms::others_all, fs::perm_options::remove);       //удалить права на файл
    
    file_writer.close();
}

void writeHistory(vector<Message>& msgs)
{
    fstream file_writer = fstream(PATH_MESS, ios::in | ios::app | ios::trunc);

    if(!file_writer)
        file_writer = fstream(PATH_MESS, ios::in | ios::out | ios::trunc);

    for(auto ms : msgs)
        file_writer << ms << endl;

    fs::permissions(PATH_MESS, fs::perms::group_all | 
        fs::perms::others_all, fs::perm_options::remove);       //удалить права на файл
    
    file_writer.close();
}