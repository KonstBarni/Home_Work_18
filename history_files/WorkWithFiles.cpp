#include <iostream>
#include <fstream>
#include <filesystem>
#include "WorkWithFiles.h"
#include "../User.h"
#include "../Massage.h"

using namespace std;
namespace fs = filesystem;

void createUsers(User& us)
{
    fstream file_writer = fstream("history_files/Users.txt", ios::in | ios::app);
    if(!file_writer)
        file_writer = fstream("history_files/Users.txt", ios::in | ios::out | ios::trunc);

    file_writer << us << endl;
    file_writer.close();
}
