#pragma once
#include "User.h"

using namespace std;

class Message
{
	string _from, _to, _text;	//не константы потому что нужны для конструктора копирования и поератора присв-ия

public:
	Message(const string& from, const string& to, const string& text)
		: _from(from), _to(to), _text(text) {};

	Message& operator=(const Message& other)
    {
        if(&other != this)
        {
        	_from = other._from;
			_to = other._to;
			_text = other._text;
        }
        return *this;
    }

	Message(const Message &other)
	{
		_from = other._from;
		_to = other._to;
		_text = other._text;
	}

	const string& getFrom() const { return _from; }
	const string& getTo() const { return _to; }
	const string& getText() const { return _text; }
};