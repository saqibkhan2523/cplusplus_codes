#include<iostream>
#include"item.h"
#include"folder.h"
#include<string>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<windows.h>
#include<boost\filesystem.hpp>
#include <boost/iterator/filter_iterator.hpp>

using namespace std;
using namespace boost::filesystem;

folder::folder()
{

}

bool folder::create(const char * path)
{

	string c = "C:/root";
	if(!(boost::filesystem::exists(path)))
	{
		CreateDirectory(path,NULL);
		return true;
	}
	else
	{
		if(path != c) 
		{
			cout << "Folder already exist" << endl;
			return false;
		}
		else
		{
			return false;
		}
	}
}

bool folder::deletef(const char * path)
{
	if(!boost::filesystem::exists(path))
	{
		cout << "The given folder does not exist" << endl;
		return false;
	}
	else
	{
		if(!(boost::filesystem::is_empty(path)))
		{
			string yes;
			cout << "Folder has subdirectories or files\nPress any key to stop or press 'y' to proceed: ";
			cin >> yes;
			if(yes == "y" || yes == "Y")
			{
				boost::filesystem::remove_all(path);
				return true;
			}
		}
		else if(boost::filesystem::is_empty(path))
		{
			RemoveDirectory(path);
			return true;
		}
	}
}

void folder::content(const char * path)
{
	if(!(exists(path)))
	{
		cout << "File doesn't exist" << endl;
	}
	else
	{
		  copy(directory_iterator(path), directory_iterator(), ostream_iterator<directory_entry>(cout, "\n"));
	}
}

void folder::changeDir(const char * path)
{
	//cout << current_path() << '\n'; // c:\workspace\projects
	current_path(path);
	cout << current_path() << '\n';  // c:\program files
	
}

void folder::find_S(const char * path)
{
	if(exists(path))
	{
		size_t size = 0;
		for(recursive_directory_iterator it(path);it!=recursive_directory_iterator();++it)
		{   
			if(!is_directory(*it))
				size += file_size(*it);
		} 
		cout << "total size: "<< size << " bytes" << endl;
	}
	else
	{
		cout<<"Folder does not exist"<<endl;
	}
}

bool folder::t_item(const char * path)
{   
	if(exists(path))
	{
		int count = 0;
		for(recursive_directory_iterator it(path); it != recursive_directory_iterator(); ++it)
		{
			count++;
		} 
		cout << "Total items" << count << endl;
		return true;
	}
	else
	{
		cout << "Path does not exist";
		return false;
	}
}

void folder::renameitem(const char * old_path, const char * new_path)
{
	if(exists(old_path))
	{
		rename(old_path, new_path);
	}
	else
	{
		cout << "Path does not exist";
	}
}