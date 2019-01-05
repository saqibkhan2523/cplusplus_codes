#ifndef file_H;
#include<iostream>
#include"item.h"
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

class file: public item
{
private:

public:
	file();
	bool create(const char * );
	bool deletef(const char * );
	void read(const char *);
	void renameitem(const char *, const char *);

	void find_S(const char *);
	void write(const char *);

};
#endif