#ifndef folder_H;
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"item.h"
#include<vector>

using namespace std;

class folder :public item
{
private:
	item * folp;
public:
	folder();

	bool create(const char * );
	bool deletef(const char * );
	void content(const char *);
	void changeDir(const char *);
	void find_S(const char *);
	bool t_item(const char*);
	void renameitem(const char *, const char *);
};
#endif