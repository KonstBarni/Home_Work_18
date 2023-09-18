#include <fstream>
#include "User.h"

std::fstream& operator >>(std::fstream& is, User& obj)
{
	is >> obj.login_;
	is >> obj.name_;
	is >> obj.password_;
	is >> obj.admin_;
	return is;
}

std::ostream& operator <<(std::ostream& os, const User& obj)
{
	os << obj.login_;
	os << ' ';
	os << obj.name_;
	os << ' ';
	os << obj.password_;
	os << ' ';
	os << obj.admin_;
	os << '\n';
	return os;
}