#pragma once
#include "Print.h"
#include <string>
#include<iostream>
using namespace std;
class Book :public Print {
protected:
	int pages;
	string publisher;
public:
	Book(void);
	Book(string, string, int, string);
	Book(const Book&);
	int getpages() { return pages; };
	string getpublisher() { return publisher; };
	void set_pages(int);
	void set_publisher(string);
	Book& operator=(const Book&);
	~Book(void);
	void show();
	void input();
};