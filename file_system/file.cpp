#include<iostream>
#include"item.h"
#include"file.h"
#include<string>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<windows.h>
#include<boost\filesystem.hpp>

using namespace std;

file::file()
{

}

bool file::create(const char * path)
{
	if(!(boost::filesystem::exists(path)))
	{
		ofstream out(path,fstream::out);
		return true;
	}
	else
	{
		cout << "File already exist" << endl;
		return false;
	}
}

bool file::deletef(const char * path )
{
	if(!(boost::filesystem::exists(path)))
	{
		cout << "The given file does not exist" << endl;
		return false;
	}
	else
	{
		remove(path);
		return true;
	}
}

void file::read(const char * path)
{
	if(!(boost::filesystem::exists(path)))
	{
		cout << "File doesn't exist" << endl;
	}
	else
	{
		cout << endl;
		string data;
		ifstream r;
		r.open(path);
		while(!r.eof())
		{
			getline(r,data);
			cout << data << endl;
		}
		r.close();
	}
}

void file::write(const char * path)
{
	if(!(boost::filesystem::exists(path)))
	{
		cout << "File doesn't exist" << endl;
	}
	else
	{
		string data;
		char quit = '\0';
		ofstream r;
		//ifstream q;
		r.open(path);
	//	q.open(path);
		while(quit != 'q' || quit != 'Q')
		{
			cout << "Write the data: ";
			cin >> data;
			r << data;
			cout << "Press q or Q to quit: ";
			cin >> quit;
			if(quit != 'q' || quit != 'Q')
				break;
		}
		r.close();
	}
}

void file::find_S(const char * path)
{
	if(boost::filesystem::exists(path))
	{
		size_t size = 0;
		size = boost::filesystem::file_size(path);
		cout << "Your file size: " << size <<" bytes" << endl;
	}
	else
	{
		cout<<"File does not exist"<<endl;
	}

}

void file::renameitem(const char * old_path, const char * new_path)
{
	if(boost::filesystem::exists(old_path))
	{
		rename(old_path, new_path);
	}
	else
	{
		cout << "file does not exist";
	}
}