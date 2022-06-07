#pragma once
#include <iostream>
#include <cstring>
class myString
{
private:
	char* stringg;
	void copy(const myString& otherString);
	void clear();
public:
	myString();
	myString(char* otherString);
	myString(const char* otherString);
	myString(const myString& otherString);
	myString& operator=(const myString& otherString);
	~myString();
	myString& operator=(const char* otherString);
	bool operator!=(const char* otherString);
	bool operator==(const char* otherString);
	bool operator==(const myString& otherString);
	/*myString& operator+=(const myString& otherString);*/
	friend std::ostream& operator << (std::ostream& out, const myString& someString);
	friend std::istream& operator >> (std::istream& in, myString& someString);
};

