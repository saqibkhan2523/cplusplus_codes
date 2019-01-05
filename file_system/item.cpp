#include<iostream>
#include<string>
#include<string.h>
#include"item.h"
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<windows.h>


using namespace std;

item::item()
{

}

void item::setaddress(const char * add)
{
	address = add;
}

const char * item::getaddress()
{
	return  address;
}
void item::setsize(size_t s)
{
	size = s;
}

