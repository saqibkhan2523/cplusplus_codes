#include<iostream>
#include"item.h"
#include"file.h"
#include<io.h>
#include<string>
#include<string.h>
#include<fstream>
#include<errno.h>
#include"folder.h"
#include<stdlib.h>
#include<dirent.h>
#include<fstream>
#include<boost/filesystem.hpp>

using namespace boost::filesystem;
using namespace std;

void main()
{
	string root = "C:/root";
	char menu = '\0';
	int op;
	string select;				//To select between the creation of file or folder.
	string st = root;				//string to take path input.
	string n;
	item * iptr[2];

	folder fo;					//folder obj.
	file fi;					//file obj.
	LPCSTR const_c;				//const char * to pass to CreatDirectory().

	iptr[0] = & fo;
	iptr[1] = & fi;

	const_c = root.c_str();
	iptr[0] -> create(const_c); // creates root folder.
	current_path(const_c);


	while(menu != 'q' || menu != 'Q')
	{
		cout << "Type file or File to work file or folder or Folder to work with folder: ";
		cin >> select;
		if(select == "folder" || select == "Folder")
		{
			cout << "\n1)Create\n2)Delete\n3)View Content\n4)Change Directory\n5)View total items\n6)View Size\n7)Rename folder\nSelect the operation no. you want to perform: ";
			cin >> op;
			if(op == 1)
			{
				string temp_path;
				cout<<"Enter the name of the folder: ";
				cin>>n;
				temp_path = st + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[0] -> create(const_c);	//calling create folder function.
			}
			if(op == 2)
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();
				fo.content(const_c);
				cout<<"Enter the name of the folder: ";
				cin>>n;
				temp_path = st + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[0] -> deletef(const_c);
			}
			if(op == 3)
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();			//Converting string to const char *.
				fo.content(const_c);
			}
			if(op == 4)
			{
				char w;
			
				cout << "'f' for Move forward or 'b' to go backword: ";
				cin >> w;
				const char * h;
				if(w == 'f')
				{
					string temp_path;
					temp_path = st;
					const_c = temp_path.c_str();			//Converting string to const char *.
					fo.content(const_c);
					cout << "Select folder: ";
					cin >> n;
					temp_path = const_c;
					temp_path = temp_path + "/" + n;
					st = temp_path;
					const_c = temp_path.c_str();			//Converting string to const char *
					fo.changeDir(const_c);
				}
				else if(w == 'b')
				{
					if(!equivalent(const_c,root.c_str()))
					{
						st = st.substr(0, st.find_last_of("/"));
						//cout << st << endl;
						const_c = st.c_str();
						fo.changeDir(const_c);
					}
				}
			}
			if(op == 5)	//Total item.
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();			//Converting string to const char *.
				fo.t_item(const_c);
			}
			if(op == 6)	//Size.
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[0] -> find_S(const_c);
			}
			if(op == 7)// Rename.
			{
				
				string temp_path_old;
				temp_path_old = st;
				const_c = temp_path_old.c_str();
				fo.content(const_c);

				cout<<"Enter the name of the folder: ";
				cin>>n;
				temp_path_old = temp_path_old + "/" + n;
				const_c = temp_path_old.c_str();			//Converting string to const char *.
			
				string new_name;
				LPCSTR new_const_c;
				
				cout << "\nEnter new name of folder: ";
				cin >> new_name;					//Taking path input.
				
				string temp_path_new;
				temp_path_new = st;
				temp_path_new = temp_path_new + "/" + new_name;
				new_const_c = temp_path_new.c_str();			//Converting string to const char *.
				
				iptr[0] -> renameitem(const_c, new_const_c);
			}

		}

		if(select == "file" || select == "File")
		{
			cout << "\n1)Create\n2)Delete\n3)Read\n4)Write\n5)Size of file\n6)Rename file\nSelect the operation no. you want to perform: ";
			cin >> op;
			if(op == 1)
			{
				string temp_path = st;

				cout<<"\nfile.txt\nEnter the name of the of file: ";
				cin>>n;
				temp_path = temp_path + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[1] -> create(const_c);
			}
			if(op == 2)
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();
				fo.content(const_c);

				cout<<"\nfile.txt\nEnter the name of the of file: ";
				cin>>n;
				temp_path = temp_path + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[1] -> deletef(const_c);
			}
			if(op == 3)
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();
				fo.content(const_c);

				cout<<"\nfile.txt\nEnter the name of the of file: ";
				cin>>n;
				temp_path = temp_path + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				fi.read(const_c);
			}
			if(op == 4)
			{
				string temp_path = st;
				cout<<"\nfile.txt\nEnter the name of the of file: ";
				cin>>n;
				temp_path = temp_path + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				fi.write(const_c);
			}
			if(op == 5)
			{
				string temp_path;
				temp_path = st;
				const_c = temp_path.c_str();
				fo.content(const_c);

				cout<<"\nfile.txt\nEnter the name of the of file: ";
				cin>>n;
				temp_path = temp_path + "/" + n;
				const_c = temp_path.c_str();			//Converting string to const char *.
				iptr[1] -> find_S(const_c);
			}
			if(op == 6)
			{
				string temp_path_old;
				temp_path_old = st;
				const_c = temp_path_old.c_str();
				fo.content(const_c);

				cout<<"Enter the name of the file: ";
				cin>>n;
				temp_path_old = temp_path_old + "/" + n;
				const_c = temp_path_old.c_str();			//Converting string to const char *.
			
				string new_name;
				LPCSTR new_const_c;
				
				cout << "\nEnter new name of file: ";
				cin >> new_name;					//Taking path input.
				
				string temp_path_new;
				temp_path_new = st;
				temp_path_new = temp_path_new + "/" + new_name;
				new_const_c = temp_path_new.c_str();			//Converting string to const char *.
				iptr[1] -> renameitem(const_c, new_const_c);

			}
		}

		cout << "\nPress A for Menu and Q to quit: ";
		cin >> menu;
		if(menu == 'Q' || menu == 'q')
		{
			exit(1);
		}
	}
	
}