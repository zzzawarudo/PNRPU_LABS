#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;
class Print :public object {
protected:
	string name;
	string author;
public:
	Print(void);
	virtual ~Print(void);
	void show();
	void input();
	Print(string, string);
	Print(const Print&);
	string getname() { return name; };
	string getauthor() { return author; };
	void setname(string);
	void setauthor(string);
	Print& operator=(const  Print&);
};