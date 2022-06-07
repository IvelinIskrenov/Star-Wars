#include "myString.h"
#include <cstring>
#include <iostream>

void myString::copy(const myString& otherString)
{
	size_t stringSize = strlen(otherString.stringg);
	stringg = new char[stringSize + 1];
	strcpy_s(stringg, stringSize + 1, otherString.stringg);
}

void myString::clear()
{
	delete[] stringg;
}

myString::myString()
{
	stringg = new char[100];
	stringg[99] = '\0';
}

myString::myString(char* otherString)
{
	size_t stringSize = strlen(otherString);
	stringg = new char[stringSize + 1];
	strcpy_s(stringg, stringSize + 1, otherString);
}

myString::myString(const char* otherString)
{
	size_t stringSize = strlen(otherString);
	stringg = new char[stringSize + 1];
	strcpy_s(stringg, stringSize + 1, otherString);
}

myString::myString(const myString& otherString)
{
	copy(otherString);
}

myString& myString::operator=(const myString& otherString)
{
	if (this != &otherString)
	{
		clear();
		copy(otherString);
	}
	return *this;
}

myString::~myString()
{
	clear();
}

myString& myString::operator=(const char* otherString)
{
	clear();
	size_t stringSize = strlen(otherString);
	stringg = new char[stringSize + 1];
	strcpy_s(stringg, stringSize + 1, otherString);
	return *this;
}

//myString& myString::operator+=(const myString& otherString)
//{
//	strcat(stringg, otherString.stringg);
//	return *this;
//}

bool myString::operator!=(const char* otherString)
{
	if (strcmp(stringg, otherString) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool myString::operator==(const char* otherString)
{
	if (strcmp(stringg, otherString) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myString::operator==(const myString& otherString)
{
	if (strcmp(stringg, otherString.stringg) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//myString& myString::operator+=(const myString& otherString)
//{
//	unsigned lenght = strlen(stringg) + strlen(otherString.stringg) + 1;
//	char* temp = new char[strlen(stringg) + 1];
//	strcpy_s(temp, strlen(stringg) + 1, stringg);
//	clear();
//	stringg = new char[lenght];
//	strcpy_s(stringg, strlen(stringg) + 1, temp);
//	strcat(stringg,otherString.stringg);
//	return *this;
//}

std::ostream& operator<<(std::ostream& out, const myString& someString)
{
	out << someString.stringg;
	return out;
}

std::istream& operator>>(std::istream& in, myString& someString)
{
	in.getline(someString.stringg, 99);
	return in;
}
