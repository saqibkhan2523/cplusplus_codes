#ifndef item_H
#define item_H
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;

class item
{
protected:
	string name;
	const char * address;
	size_t size;


public:
	item();
	void setaddress(const char * );
	const char * getaddress();
	void setsize(size_t );

	virtual bool create(const char *) = 0;
	virtual bool deletef(const char *) = 0;
	virtual void find_S(const char *) = 0;
	virtual void renameitem(const char *, const char *) = 0;
};
#endif