#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<Windows.h>

using namespace std;

int months = 12;
int days = 30;
int hours = 24;
int actList = 150;

//This is the "struct" for storing the "tokenized" results in the "year" .
struct activity
{
	//For storing the userid, actid and work as string in "year" .
	string Userid , Actid , Work ;

	//For storing the duration of acitivity in "year" .
	int Duration ;

	//For storing the priority as a float in "year" .
	float Priority ;
} ;

//Prototype of "filing" function.
void filing ( char * temp, string line, int &date, int &month, int &sTime, int &eTime, int &duration, string &userid, string &actid, string &work, float &priority, int months, int  days, int hours );

//Prototype of "tokenization" function.
void tokenization ( char * temp, int &date, int &month, int &sTime, int &eTime, int &duration, string &userid, string &actid, string &work, float &priority );

//Prototype of "extend" function.
activity * extend ( activity * A ) ;

//Prototype of "allocation" function.
activity **** allocation ( activity **** year );

//Prototype of "copying" function.
activity **** copying ( activity **** year, int date, int month, int sTime, int duration, int months, int  days, int hours, string userid, string actid, string work, float priority );

void print( activity **** year );

//Prototype of "cleanTheCalendar" function.
void cleanTheCalendar (activity **** &year );

//Prototype of "listOfUsrActs" function.
void listOfUsrActs( activity **** year);

//Prototype of "listOfTop5" function.
void listOfTop5(activity **** year);

////Prototype of "busietUser" function.
void busietUser ( activity **** year );

////Prototype of "monthStats" function.
void monthStats( activity **** year );

////Prototype of "claendarStats" function.
void claendarStats( activity **** year );

//Prototype of "removeClaendarUser" function.
void removeClaendarUser ( activity **** & year );

//Prototype of "saveTheCalendar" function.
void saveTheCalendar ( activity **** year );

//Prototype of "deallocation" function.
void deallocation ( activity **** year );

//==================== End of prototypes ====================//

//The function of "filing" reads the line form the given file and then sends it to different functions to perform operations accordingly.
void filing ( activity **** year, char * temp, string line, int &date, int &month, int &sTime, int &eTime, int &duration, string &userid, string &actid, string &work, float &priority, int months, int  days, int hours )
{
	//"myfile" is the filing variable being used to read from "file".
	ifstream myfile;

	//This opens the file.
	myfile.open( "file.txt" );

	//The "while loop" runs till the last line in the "file".
	while( !myfile.eof() )
	{
		//Taking input from the "file" in variable "line".
		getline ( myfile, line );

		//FInding the length of the "line" to creat a "temp" of that size.
		int len = line.length();

		//"temp" of the size of "line".
		temp = new char[len]; 
		//cout<<line<<endl;

		//"j" is used to store the "terminator character" after the "loop".
		int j = 0;

		//It runs till the length of "line" and copy the "line" into "temp".
		for(int i = 0; i < len; i++)
		{
			//Copying indx by index.
			temp[i] = line[i];

			j = i;
		}

		//Storing the "terminator character" one index further then "i".
		temp [j+1] = '\0';
		//cout << temp << endl;

		//"tokenization" function call.
		tokenization( temp, date, month, sTime, eTime, duration, userid, actid, work, priority );

		//"copying" function call.
		copying( year, date, month, sTime, duration, months, days, hours, userid, actid, work, priority );
	}

	//Closing the file.
	myfile.close ();
}

//It is being called in the "filing" function to "tokenize" the readed line and return the values by refrence.
void tokenization(char* temp, int &date, int &month, int &sTime, int &eTime, int &duration, string &userid, string &actid, string &work, float &priority)
{
	//"tokenizing" "date" that is till "/" and then converting it into integaer.
	date = atoi(strtok(temp, "/"));
	//cout << "date :" << date << endl ;
	
	//"tokenizing" "month" that is till "," and then converting it into integaer.
	month = atoi(strtok(NULL, ","));
	//cout << "month :" << month << endl ;
	
	//"tokenizing" "sTime" that is till "," and then converting it into integaer.
	sTime = atoi(strtok(NULL, ","));
	//cout << "Stime :" << sTime<< endl ;

	//"tokenizing" "eTime" that is till "," and then converting it into integaer.
	eTime = atoi(strtok(NULL, ","));

	//Calculating the "duration" by subtacting "sTime" from "eTime".
	duration = eTime - sTime;
	//cout << "duration :" << duration << endl ;

	//"tokenizing" "userid" that is till ",".
	userid = strtok (NULL, ",");
	//cout << "userid :" << userid << endl ;
	
	//"tokenizing" "actid" that is till ",".
	actid = strtok (NULL, ",");
	//cout << "actid :" << actid << endl ;
	
	//"tokenizing" "work" that is till ",".
	work = strtok (NULL, ",");
	//cout << "work :" << work << endl ;
	
	//"tokenizing" "priority" that is till "\n (next line)" and then converting it into float.
	priority = atof (strtok(NULL, "\n"));
	//cout << "priority :" << priority << endl ;
}

//The "allocation" function receieves the "year" from "main" as a "4D-pointer" and other three parameters "(month, day, hour)"  of type "int and allocate it to the array.
activity **** allocation(activity **** year)
{
	//Allocation of the slot "months".
	year = new activity *** [months];

	//Loop running till "months".
	for(int i = 0; i < months; i++)
	{
		//For months with "31 days".
		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			//Allocation of "31 days".
			year[i] = new activity ** [days+1];

			//Loop till "31 days".
			for(int j = 0; j < days+1; j++)
			{
				//Allocation of "24 hours".
				year [i][j] = new activity * [hours];

				//Loop till "24 hours".
				for(int k = 0; k < hours; k++)
				{
					//Allocation of the last slot.
					year [i][j][k] = new activity [actList];

					//Loop till "actList".
					for(int l = 0; l < actList; l++)
					{
						year [i][j][k][l].Userid = "-1";
						year [i][j][k][l].Actid = "-1";
						year [i][j][k][l].Work = "-1";
						year [i][j][k][l].Duration = 0;
						year [i][j][k][l].Priority = 0.0;
					}
				}
			}
		}

		//For months with "30 days".
		else if(i == 3 || i == 5 || i == 8 || i == 10)
		{
			//Allocation of the "30 days".
			year[i] = new activity ** [days];

			//Loop till "30 days".
			for(int j = 0; j < days; j++)
			{
				//Allocation of "24 hours".
				year [i][j] = new activity * [hours];

				//Loop till "24 hours".
				for(int k = 0; k < hours; k++)
				{
					//Allocation of last slot.
					year [i][j][k] = new activity [actList];

					//Loop till "actList".
					for(int l = 0; l < actList; l++)
					{
						year [i][j][k][l].Userid = "-1";
						year [i][j][k][l].Actid = "-1";
						year [i][j][k][l].Work = "-1";
						year [i][j][k][l].Duration = 0;
						year [i][j][k][l].Priority = 0.0;
					}
				}
			}
		}

		//For month of 28 days.
		else
		{
			//Allocation of "28 days".
			year[i] = new activity ** [days-2];

			//Loop till "28 days".
			for(int j = 0; j < days-2; j++)
			{
				//Allocation of "24 hours".
				year [i][j] = new activity * [hours];

				//Loop till "24 hours".
				for(int k = 0; k < hours; k++)
				{
					//Allocation of last slot.
					year [i][j][k] = new activity [actList];

					//Loop till "actList".
					for(int l = 0; l < actList; l++)
					{
						year [i][j][k][l].Userid = "-1";
						year [i][j][k][l].Actid = "-1";
						year [i][j][k][l].Work = "-1";
						year [i][j][k][l].Duration = 0;
						year [i][j][k][l].Priority = 0.0;
					}
				}
			}
		}
	}

	//Returning the "year".
	return year;
}

//This is the "copying" function that is being called in "filing" it copies the "tokenized" paramerters "(Userid, Actid, Work, and Priority)" to the "year" according to "month", "date", "sTime", "eTime".
activity **** copying(activity **** year, int date, int month, int sTime, int duration, int months, int  days, int hours, string userid, string actid, string work, float priority)
{
	//Count increases till terminating character "-1" is found.
	int listIndex;
	
	//Loop till the terminating character "-1" is found.
	for(listIndex = 0; year [month-1][date-1][sTime][listIndex].Userid != "-1"; listIndex++)
	{
		
	}

	//Storing the tokenized values in "year".
	year [month-1][date-1][sTime][listIndex].Userid = userid;
	year [month-1][date-1][sTime][listIndex].Actid = actid;
	year [month-1][date-1][sTime][listIndex].Work = work;
	year [month-1][date-1][sTime][listIndex].Duration = duration;
	year [month-1][date-1][sTime][listIndex].Priority = priority;

	//cout << year [month-1][date-1][sTime][listIndex].Userid << endl;
	//cout << year [month-1][date-1][sTime][listIndex].Actid << endl;
	//cout << year [month-1][date-1][sTime][listIndex].Work << endl;
	//cout << year [month-1][date-1][sTime][listIndex].Duration << endl;
	//cout << year [month-1][date-1][sTime][listIndex].Priority << endl;

	//Returning the year.
	return year;
}

//The "extend" function is called in "copying" function when ever a new line is being copied.
/*activity * extend (activity * A)
{
	int count=1;
	for(int i=0; A->Userid !="-1"; i++)
	{
		count++;
	}
	//count++;
	//cout<<count<<endl;
	activity * A1 = new activity [count];
	for(int i=1; i<count; i++)
	{
		A1[i] = A[i-1];
	}

	delete [] A;

	return A1;

}*/

//This function is being called in the "print" function to print days of the month.
void printDays(int j, int &count,bool & flag)
{
	
	if(flag == true)
	{
		
		if(count == 7)
		{
			cout<<endl;
			if(j+1<=9)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout<<j+1<<"  ";			
			}
			else
			{
				
				cout<<j+1<<" ";
			}
			count =0;
		}
		else
		{
			if(j+1<=9)
			{ 
				
				cout<<j+1<<"  ";				
			}
			else
			{
				cout<<j+1<<" ";
			}	
		}
		count ++;
		
	}
	if (flag == false)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	if(count == 7)
		{
			cout<<endl;
			if(j+1<=9)
			{
				
				cout<<j+1<<"  ";			
			}
			else
			{
				
				cout<<j+1<<" ";
			}
			count =0;
		}
		else
		{
			if(j+1<=9)
			{ 
				
				cout<<j+1<<"  ";				
			}
			else
			{
				cout<<j+1<<" ";
			}	
		}
	count ++;
	}
		
	//	flag=false;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void print( activity **** year )
{
	bool flag;

	for(int i = 0; i < months; i++)
	{
		//For months with "31 days".
		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			if(i == 0)
			{
				cout<<"    JAUNARY    "<<endl;
				cout<<"W  T  F  S  S  M  T"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						
						if(year[i][j][k][0].Userid=="-1")
						{
						
							flag=false;

						}
						else 
						{
							flag=true;
							
						}
					}
					printDays(j,count,flag);
					flag=false;
				}
			}
			else if(i == 2)
			{
				cout<<endl;
				cout<<"    MARCH    "<<endl;
				cout<<"S  S  M  T  W  T  F"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}
			}
			else if(i == 4)
			{
				cout<<endl;
				cout<<"    MAY    "<<endl;
				cout<<"T  F  S  S  M  T  W"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			else if(i == 6)
			{
				cout<<endl;
				cout<<"    JULY    "<<endl;
				cout<<"T  W  T  F  S  S  M"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			else if(i == 7)
			{
				cout<<endl;
				cout<<"    AUGUST    "<<endl;
				cout<<"F  S  S  M  T  W  T"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			else if(i == 9)
			{
				cout<<endl;
				cout<<"    OCTOBER    "<<endl;
				cout<<"W  T  F  S  S  M  T"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			else if(i == 11)
			{
				cout<<endl;
				cout<<"    DECEMBER    "<<endl;
				cout<<"M  T  W  T  F  S  S"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days+1; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
		}

		//For months with "30 days".
		else if(i == 3 || i == 5 || i == 8 || i == 10)
		{
			if(i == 3)
			{
				cout<<endl;
				cout<<"    APRIL    "<<endl;
				cout<<"T  W  T  F  S  S  M"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			else if(i == 5)
			{
				cout<<endl;
				cout<<"    JUNE    "<<endl;
				cout<<"S  M  T  W  T  F  S"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			if(i == 8)
			{
				cout<<endl;
				cout<<"    SEPTEMBER    "<<endl;
				cout<<"M  T  W  T  F  S  S"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
			if(i == 10)
			{
				cout<<endl;
				cout<<"    NOVEMBER    "<<endl;
				cout<<"S  S  M  T  W  T  F"<<endl;
				//Loop till "31 days".
				int count=0;
				for(int j = 0; j < days; j++)
				{	
					for(int k=0; k<hours;k++)
					{
						for(int l=0;l<actList;l++)
						{
							if(year[i][j][k][l].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						}
					}
					printDays(j,count,flag);
				}			
			}
		}

		//For month of 28 days.
		else
		{
			cout<<endl;
			cout<<"    FEBRURAY    "<<endl;
			cout<<"S  S  M  T  W  T  F"<<endl;
			//Loop till "31 days".
			int count=0;
			for(int j = 0; j < days-2; j++)		
			{	
				for(int k=0; k<hours;k++)
					{
						
						
							if(year[i][j][k][0].Userid != "-1")
							{
								flag = true;
							}
							else
							{
								flag = false;
							}
						
					}
					printDays(j,count,flag);
			}			
		}
	}
	Sleep(5000);
	system("cls");
}

//This function of "cleanTheCalendar" removes the multiple user in one slot and stores the user with the higher priority.
void cleanTheCalendar ( activity **** &year )
{
	//Loop for all months.
	for(int i = 0; i < months; i++)
	{
		//For the months with "31 days".
		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			//Loop till "31 days".
			for(int j = 0; j < days+1; j++)
			{
				//Loop till "24 hours".
				for(int k = 0; k < hours; k++)
				{
					//Loops for comparison both "l" and "m".
					for(int l = 0; year [i][j][k][l].Userid != "-1"; l++)
					{
						for(int m = 0; year [i][j][k][m].Userid != "-1"; m++)
						{
							//"l" is not equal to "m" and both users are same.
							if(l != m && year [i][j][k][l].Userid == year [i][j][k][m].Userid)
							{
								//If priority of "l" is higher then priority of "m" then "m" is deleted.
								if(year[i][j][k][l].Priority > year[i][j][k][m].Priority)
								{
									year [i][j][k][m].Userid = "-1";
									year [i][j][k][m].Actid = "-1";
									year [i][j][k][m].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year [i][j][k][m].Priority = 0.0;
								}
								//If priority of "m" is higher then priority of "l" then "l" is deleted.
								else
								{
									year[i][j][k][l].Userid = "-1";
									year[i][j][k][l].Actid = "-1";
									year[i][j][k][l].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year[i][j][k][l].Priority = 0.0;
								}
							}
						}
					}
				}
			}
		}

		//For months with 30 days.
		else if(i==3 || i==5 || i==8 || i==10)
		{
			//Loop till "30 days".
			for(int j = 0; j < days; j++)
			{
				//Loop till "24 hours".
				for(int k=0; k < hours; k++)
				{
					//Loops for comparison both "l" and "m".
					for(int l=0; year[i][j][k][l].Userid != "-1"; l++)
					{
						for(int m=0; year[i][j][k][m].Userid != "-1"; m++)
						{
							//"l" is not equal to "m" and both users are same.
							if(l!=m && year[i][j][k][l].Userid == year[i][j][k][m].Userid)
							{
								//If priority of "l" is higher then priority of "m" then "m" is deleted.
								if(year[i][j][k][l].Priority > year[i][j][k][m].Priority)
								{
									year[i][j][k][m].Userid = "-1";
									year[i][j][k][m].Actid = "-1";
									year[i][j][k][m].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year[i][j][k][m].Priority = 0.0;
								}

								//If priority of "m" is higher then priority of "l" then "l" is deleted.
								else
								{
									year[i][j][k][l].Userid = "-1";
									year[i][j][k][l].Actid = "-1";
									year[i][j][k][l].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year[i][j][k][l].Priority = 0.0;
								}
							}
						}
					}
				}
			}
		}

		//For months with 28 days.
		else
		{
			//Loop till "28 days".
			for(int j = 0;j < days-2; j++)
			{
				//Loop till "24 hours".
				for(int k=0; k<hours; k++)
				{
					//Loops for comparison both "l" and "m".
					for(int l=0; year[i][j][k][l].Userid != "-1"; l++)
					{
						for(int m=0; year[i][j][k][m].Userid != "-1"; m++)
						{
							//"l" is not equal to "m" and both users are same.
							if(l!=m && year[i][j][k][l].Userid == year[i][j][k][m].Userid)
							{
								//If priority of "l" is higher then priority of "m" then "m" is deleted.
								if(year[i][j][k][l].Priority > year[i][j][k][m].Priority)
								{
									year[i][j][k][m].Userid = "-1";
									year[i][j][k][m].Actid = "-1";
									year[i][j][k][m].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year[i][j][k][m].Priority = 0.0;
								}

								//If priority of "m" is higher then priority of "l" then "l" is deleted.
								else
								{
									year[i][j][k][l].Userid = "-1";
									year[i][j][k][l].Actid = "-1";
									year[i][j][k][l].Work = "-1";
									year[i][j][k][l].Duration = 0;
									year[i][j][k][l].Priority = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}

	//Printing out the message in the console.
	cout<<"Different activities of the same user\nin the same slot are removed except for the highest priority.\n\n"<<endl;

	Sleep(5000);
	system("cls");
}

//This function of "listOfUsrActs" takes a time period and user id as input and list all the activites during that time period.
void listOfUsrActs( activity **** year)
{
	//User whose activities are to be listed during a time period.
	string usrid;

	//Starting and ending date of the time period.
	int sdate;
	int edate;

	//For counting ht enumber of activities of the givien user in the given time time period.
	int count = 0;

	//Month of the time period.
	int mnth;

	//Asking for the inputs for the parameters.
	cout<<"ENter the user (user0-user99) whose activities you wish to see: ";
	cin>>usrid;

	cout<<"Enter the month of the time period: ";
	cin>>mnth;

	cout<<"Enter the starting date of the time period: ";
	cin>>sdate;

	cout<<"Enter the ending date of the time period: ";
	cin>>edate;
	
	cout << "The activities of the given user in the given time period are: "<<endl;

	//The loop searches for the time period and list all the activities of the user suring that time period.
	for(int i = sdate - 1; i < edate - 1; i++ )
	{
		for(int j=0; j<hours; j++)
		{
			for(int k=0; k <actList; k++)
			{
				if(year[mnth-1][i][j][k].Userid==usrid)
				{
					cout<<++count<<") "<<year[mnth-1][i][j][k].Work<<endl;
				}
			}
		}
	}

	Sleep(5000);
	system("cls");
}

void listOfTop5(activity **** year)
{
	//User whose activities are to be listed during a time period.
	string usrid;

	struct count
	{
		string w;
		float p;
	};

	//Starting and ending date of the time period.
	int sdate;
	int edate;

	//For counting ht enumber of activities of the givien user in the given time time period.
	count count2[5];
	for(int s=0; s<5;s++)
	{
		count2[s].w="\0";
		count2[s].p=0.0;
	}

	int check=0;

	int count=0;
	int check2=0;

	//Month of the time period.
	int mnth;

	//Asking for the inputs for the parameters.
	cout<<"Enter the user (user0-user99) whose activities you wish to see: ";
	cin>>usrid;

	cout<<"Enter the month of the time period: ";
	cin>>mnth;

	cout<<"Enter the starting date of the time period: ";
	cin>>sdate;

	cout<<"Enter the ending date of the time period: ";
	cin>>edate;
	
	cout << "The activities of the given user in the given time period are: "<<endl;
	for(int i = sdate - 1; i < edate - 1; i++ )
	{
		for(int j=0; j<hours; j++)
		{
			for(int k=0; k <actList; k++)
			{	
				for(int l=0; l<actList;l++)
				{
					if(k!=l && year[mnth-1][i][j][k].Userid == usrid && year[mnth-1][i][j][l].Userid == usrid)
					{
						count2[check].w=year[mnth-1][i][j][k].Work;
						if(year[mnth-1][i][j][k].Priority < year[mnth-1][i][j][l].Priority)
						{
							count2[check].w=year[mnth-1][i][j][l].Work;
							check++;
						}
						else
						{
							check++;
						}
					}
				}
			}
		}
	}
	count<<check;
	for(int o=0;o<5;o++)
	{
		if(count2[o].w != "\0")
		{
			cout<<++count<<") "<<count2[o].w<<endl;
		}
	}
}

void busietUser ( activity **** year )
{
	struct two
	{
		string usr;
		int count;
	};

	two bUsr[100];

	for(int i=0;i<100;i++)
	{
		bUsr[i].usr="-1";
		bUsr[i].count=0;
	}

	//Starting and ending date of the time period.
	int sdate;
	int edate;

	//For counting ht enumber of activities of the givien user in the given time time period.
	int count = 0;

	//Month of the time period.
	int mnth;

	cout<<"Enter the month of the time period: ";
	cin>>mnth;

	cout<<"Enter the starting date of the time period: ";
	cin>>sdate;

	cout<<"Enter the ending date of the time period: ";
	cin>>edate;

	//The loop searches for the time period and list all the activities of the user suring that time period.
	for(int i = sdate - 1; i < edate - 1; i++ )
	{
		for(int j=0; j<hours; j++)
		{
			for(int k=0; k <actList; k++)
			{
				for(int l=0;l<100;i++)
				{
					if(bUsr[l].usr!=year[mnth-1][i][j][k].Userid && bUsr[l].usr=="-1")
					{
						bUsr[l].usr=year[mnth-1][i][j][k].Userid;
					}
					if(bUsr[l].usr==year[mnth-1][i][j][k].Userid)
					{
						bUsr[l].count++;
					}
				}
			}
		}
	}

	int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp;             // holding variable
     for(i = 1; (i < 100) && flag; i++)
     {
         cout<<bUsr[i].usr<<endl;
		 cout<<bUsr[i].count<<endl;
     }
	 if(bUsr[0].usr!="-1")
	 {
		 cout<<"The busiest user in the given time is: "<<bUsr[0].usr<<" with "<<bUsr[0].count<<" activities "<<endl;
	 }
	 else
	 {
		 cout<<"No user in the given time!"<<endl;
	 }
	 system("pause");
	Sleep(5000);
	system("cls");

	
}

////This function calculates the stats of the whole month number of activities, busiest user, etc...
void monthStats( activity **** year )
{
	int mnth;
	cout << "Enter the month: ";
	cin >> mnth;

	int wrk = 0;
	float avgact;
	int bDay = 0;
	int bDayActs = 0;
	int bDayCount = 0;

	if(mnth - 1 == 0 || mnth - 1 == 2 || mnth - 1 == 4 || mnth - 1 == 6 || mnth - 1 == 7 || mnth - 1 == 9 || mnth - 1 == 11)
	{
		for(int i = 0; i < days + 1; i++)
		{
			bDayCount = 0;
			for(int j = 0; j < hours; j++)
			{
				for(int k = 0; k < actList; k++)
				{
					if(year[mnth-1][i][j][k].Userid != "-1")
					{
						wrk++;
						bDayCount++;
					}
				}
			}
			
			if(bDayActs < bDayCount)
			{
				bDayActs = bDayCount;
				bDay = i;
			}
		}
		avgact = wrk / 31;
	}
	else if(mnth - 1 == 3 || mnth - 1 == 5 || mnth - 1 == 8 || mnth - 1 == 10)
	{
		for(int i = 0; i < days; i++)
		{
			bDayCount = 0;
			for(int j = 0; j < hours; j++)
			{
				for(int k = 0; k < actList; k++)
				{
					if(year[mnth-1][i][j][k].Userid != "-1")
					{
						wrk++;
						bDayCount++;
					}
				}
			}
			
			if(bDayActs < bDayCount)
			{
				bDayActs = bDayCount;
				bDay = i;
			}
		}
		avgact = wrk / 30;
	}
	else
	{
		for(int i = 0; i < days - 2; i++)
		{
			bDayCount = 0;
			for(int j = 0; j < hours; j++)
			{
				for(int k = 0; k < actList; k++)
				{
					if(year[mnth-1][i][j][k].Userid != "-1")
					{
						wrk++;
						bDayCount++;
					}
				}
			}
			
			if(bDayActs < bDayCount)
			{
				bDayActs = bDayCount;
				bDay = i;
			}
		}
		avgact = wrk / 28;
	}
	cout << "Total number of activities in the month: " << wrk << endl;
	cout << "Average number of activities per day: " << avgact << endl;
	cout << "The busiest day of the month is: " << bDay << endl;
	cout << "Total number of activities of the busiest day: " << bDayActs << endl;

	Sleep(5000);
	system("cls");

}

//This function calculates the stats of the whole year number of activities, busiest user, etc...
void claendarStats( activity **** year )
{
	int wrk = 0;
	float avgact;
	int bMonth = 0;
	int bMonthActs = 0;
	int bMonthCount = 0;

	for(int i = 0; i < months; i++)
	{
		bMonthCount = 0;

		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			for(int j = 0; j < days + 1 ; j++)
			{
				for(int k = 0; k < hours ; k++)
				{
					for(int l = 0; l < actList ; l++)
					{
						if(year[i][j][k][l].Userid != "-1")
						{
							wrk++;
							bMonthCount++;
						}
					}
				}	
			}
		}
		else if(i == 3 || i == 5 || i == 8 || i == 10)
		{
			for(int j = 0; j < days; j++)
			{
				bMonthCount = 0;
				for(int k = 0; k < hours; k++)
				{
					for(int l = 0; l < actList; l++)
					{
						if(year[i][j][k][l].Userid != "-1")
						{
							wrk++;
							bMonthCount++;
						}
					}
				}		
			}
		}
		else
		{
			for(int j = 0; j < days - 2; j++)
			{
				bMonthCount = 0;
				for(int k = 0; k < hours; k++)
				{
					for(int l = 0; l < actList; l++)
					{
						if(year[i][j][k][l].Userid != "-1")
						{
							wrk++;
							bMonthCount++;
						}
					}
				}		
			}
		}
		if(bMonthActs < bMonthCount)
		{
			bMonthActs = bMonthCount;
			bMonth = i;
		}
	}

	avgact = wrk / months;
	cout << "Total number of activities in the year: " << wrk << endl;
	cout << "Average number of activities per month: " << avgact << endl;
	cout << "The busiest month of the year is: " << bMonth << endl;
	cout << "Total number of activities of the busiest month: " << bMonthActs << endl;

	Sleep(5000);
	system("cls");
}

//This functions takes the user id as input and removes all the activities of that user.
void removeClaendarUser(activity **** & year)
{
	//Taking input of the user id from user whose activities are to be removed.
	string usrid;

	//Asking for the "usrid" from user.
	cout<<"Enter the user ID that you want to remove: ";

	//Taking input.
	cin>>usrid;

	//This loop runs for the number of months.
	for(int i=0; i < months; i++)
	{
		//For the months with 31 days.
		if(i==0 || i==2 || i==4 || i==6 || i==7 || i==9 || i==11)
		{
			//Loop till "31 days".
			for(int j=0;j < days+1; j++)
			{
				//Loop till "24 hours".
				for(int k=0; k<hours; k++)
				{
					//Checking if the "year[i][j][k][l].Userid" is not equal to terminating character "-1".
					for(int l=0; year[i][j][k][l].Userid !="-1"; l++)
					{
						//If "usrid" is equal to "year[i][j][k][l].Userid" then it terminates the data in it.
						if(year[i][j][k][l].Userid == usrid)
						{
							//Terminating the data.
							year[i][j][k][l].Userid = "-1";
							year[i][j][k][l].Actid = "-1";
							year[i][j][k][l].Work = "-1";
							year[i][j][k][l].Duration = 0;
							year[i][j][k][l].Priority = 0.0;
						}
					}
				}
			}	
		}

		//For months with 30 days.
		else if(i==3 || i==5 || i==8 || i==10)
		{
			//Loop till "30 days".
			for(int j=0;j < days; j++)
			{
				//Loop till "24 hours".
				for(int k=0; k<hours; k++)
				{
					//Checking if the "year[i][j][k][l].Userid" is not equal to terminating character "-1".
					for(int l=0; year[i][j][k][l].Userid != "-1"; l++)
					{
						//If "usrid" is equal to "year[i][j][k][l].Userid" then it terminates the data in it.
						if(year[i][j][k][l].Userid == usrid)
						{	
							//Terminating the data.
							year[i][j][k][l].Userid = "-1";
							year[i][j][k][l].Actid = "-1";
							year[i][j][k][l].Work = "-1";
							year[i][j][k][l].Duration = 0;
							year[i][j][k][l].Priority = 0.0;
						}
					}
				}
			}
		}

		//For month with 28 days.
		else
		{
			//Loop till "28 days".
			for(int j=0;j<days-2; j++)
			{
				//Loop till "24 hours".
				for(int k=0; k<hours; k++)
				{
					//Checking if the "year[i][j][k][l].Userid" is not equal to terminating character "-1".
					for(int l=0; year[i][j][k][l].Userid != "-1"; l++)
					{
						//If "usrid" is equal to "year[i][j][k][l].Userid" then it terminates the data in it.
						if(year[i][j][k][l].Userid == usrid)
						{
							//Terminating the data.
							year[i][j][k][l].Userid = "-1";
							year[i][j][k][l].Actid = "-1";
							year[i][j][k][l].Work = "-1";
							year[i][j][k][l].Duration = 0;
							year[i][j][k][l].Priority = 0.0;
						}
					}
				}
			}
		}
	}

	//Displaying the message of removing the activity of the entered user.
	cout<<"All the activities of "<<usrid<<" has been removed from calendar."<<endl;

	Sleep(5000);
	system("cls");
}

//This function print the activities in the output file.
void saveTheCalendar(activity **** year)
{
	//"myfile" is the filing variable being used to write in "output".
	ofstream myfile;

	//Opening the output file.
	myfile.open("output.txt");
	
	//Loop runs for the number of months.
	for(int i = 0; i < months; i++)
	{
		//For the months with 31 days.
		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			//Loop runs for the number of days.
			for(int j = 0; j < days+1; j++)
			{
				//Loop runs for the number of hours.
				for(int k=0;k<hours;k++)
				{
					//Loop runs for the last slot.
					for(int l=0;year[i][j][k][l].Userid != "-1"; l++)
					{
						//Writing on the "output" file.
						myfile<<"User ID: "<<year[i][j][k][l].Userid<<"    ";
						myfile<<"Act ID: "<<year[i][j][k][l].Actid<<"    ";
						myfile<<"Work: "<<year[i][j][k][l].Work<<"    ";
						myfile<<"Priority: "<<year[i][j][k][l].Priority<<"    ";
						myfile<<endl;
					}
				}
			}
		}

		//For the months with 30 days.
		else if(i == 3 || i == 5 || i == 8 || i == 10)
		{
			//Loop runs for the number of days.
			for(int j = 0; j < days; j++)
			{
				//Loop runs for the number of hours.
				for(int k=0;k<hours;k++)
				{
					//Loop runs for the last slot.
					for(int l=0;year[i][j][k][l].Userid != "-1"; l++)
					{
						//Writing on the "output" file.
						myfile<<"User ID: "<<year[i][j][k][l].Userid<<"    ";
						myfile<<"Act ID: "<<year[i][j][k][l].Actid<<"    ";
						myfile<<"Work: "<<year[i][j][k][l].Work<<"    ";
						myfile<<"Priority: "<<year[i][j][k][l].Priority<<"    ";
						myfile<<endl;	
					}
				}
			}
		}

		//For the month with 28 days.
		else
		{
			//Loop runs for the number of days.
			for(int j = 0; j < days-2; j++)
			{
				//Loop runs for the number of hours.
				for(int k=0;k<hours;k++)
				{
					//Loop runs for the last slot.
					for(int l=0;year[i][j][k][l].Userid != "-1"; l++)
					{
						//Writing on the "output" file.
						myfile<<"User ID: "<<year[i][j][k][l].Userid<<"    ";
						myfile<<"Act ID: "<<year[i][j][k][l].Actid<<"    ";
						myfile<<"Work: "<<year[i][j][k][l].Work<<"    ";
						myfile<<"Priority: "<<year[i][j][k][l].Priority<<"    ";
						myfile<<endl;
					}
				}
			}
		}
	}

	//Closing the "output" file.
	myfile.close();

	cout << "The calendar has been saved into the folder of the project by the name 'output'" << endl;

	Sleep(5000);
	system("cls");
}

//This function "deallocation" the "year" to avoid "memory leak".
void deallocation(activity **** year, int months, int  days, int hours)
{
	//This "loop" runs for the number of "months".
	for(int i = 0; i < months; i++)
	{
		//This "if" statements checks the "months" of 31 "days".
		if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
		{
			//This "loop" runs for the number of "days".
			for(int j = 0; j < days+1; j++)
			{
				//This "loop" runs for the number of "hours".
				for(int k = 0; k < hours; k++)
				{
					//It "deletes" the "hours" array.
					delete [] year [i] [j] [k];
				}

				//It "deletes" the "days" array.
				delete [] year [i] [j];
			}

			//It "deletes" the "month" array.
			delete [] year [i];
		}
		//This "else-if" statements checks the "months" of 30 "days".
		else if(i == 3 || i == 5 || i == 8 || i == 10)
		{
			//This "loop" runs for the number of "days".
			for(int j = 0; j < days; j++)
			{
				//This "loop" runs for the number of "hours".
				for(int k = 0; k < hours; k++)
				{
					//It "deletes" the "hours" array.
					delete [] year [i] [j] [k];
				}

				//It "deletes" the "days" array.
				delete [] year [i] [j];
			}

			//It "deletes" the "month" array.
			delete [] year [i];
		}

		//This "else" statements checks the "month" of 28 "days".
		else
		{
			//This "loop" runs for the number of "days".
			for(int j = 0; j < days-2; j++)
			{
				//This "loop" runs for the number of "hours"
				for(int k = 0; k < hours; k++)
				{
					//It "deletes" the "hours" array.
					delete [] year [i] [j] [k];
				}

				//It "deletes" the "days" array.
				delete [] year [i] [j];
			}

			//It "deletes" the "month" array.
			delete [] year [i];
		}
	}

	//This deletes the 4-D pointer of "year".
	delete [] year;

	cout << "Deallocation  has been done!!!"<<endl;

	Sleep(5000);
	system("cls");
}

//This is the "main" function
void main()
{
	//To read the line from "file".
	string line;

	//These variables stores the "tokenized" values in "tokenization" function.
	int date;
	int month;
	int sTime;
	int eTime;
	int duration;
	string userid;
	string actid;
	string work;

	//These are used in the "allocation" function.
	float priority;
	int months = 12;
	int days = 30;
	int hours = 24;

	//the 4-D pointer initialized with "nullptr" to avoid error.
	activity **** year = nullptr;

	//The "allocation" function returns the 4-D pointer.
	year = allocation(year);

	//This is the "char pointer" to store the data from the "line" read from the "file" for "strtok".
	char * temp = nullptr;

	//The "filing" function is being called in the "main" function.
	filing(year, temp, line, date, month, sTime, eTime, duration, userid, actid, work, priority, months, days, hours);

	//This "delete" the "temp" created above to avoid "memory leak".
	delete [] temp;
	
	//Printing the calendar at the start of the programme.
	print( year );
	
	char option = '\0';
	int function;

	cout<<"0) Clean the Calendar\n1) List all activities of a given user during a time period\n2) List the top 5 activities of a given user during a time period\n3) List the five busiest users in given time period (users with most activities)\n4) Print activity stats for a given month\n5) Print Calendar Stats (for the whole year)\n6) Remove a user from the calendar (remove all activities of this user)\n7) Save the calendar\nEnter the desired function number: ";
	cin>>function;

	while(option != 'q')
	{
		if(function < 0 || function > 8)
		{
			cout<<"Invalid function number!"<<endl;
		}
		else
		{
			if(function == 0)
			{
				//This function deletes the different activities of the same user in the same slot except for the activity with highest priority
				cleanTheCalendar(year);
			}
			else if(function == 1)
			{
				//This function of "listOfUsrActs" takes a time period and user id as input and list all the activites during that time period.
				listOfUsrActs(year);
			}
			else if(function == 2)
			{
				listOfTop5( year );
			}
			else if(function == 3)
			{
				busietUser ( year );
			}
			else if(function == 4)
			{
				monthStats( year );
			}
			else if(function == 5)
			{
				claendarStats( year );
			}
			else if(function == 6)
			{
				//This functions takes the user id as input and removes all the activities of that user.
				removeClaendarUser(year);
			}
			else if(function == 7)
			{
				//This function print the activities in the output file.
				saveTheCalendar(year);
			}
			else if(function == 8)
			{
				//This function prints the calendar.
				print(year);
			}
		}

		cout << "Press 'q' to quit of 'a' to go again: ";
		cin >> option;
		Sleep(500);
		system("cls");

		if(option == 'a')
		{
			cout << "0) Clean the Calendar\n1) List all activities of a given user during a time period\n2) List the top 5 activities of a given user during a time period\n3) List the five busiest users in given time period (users with most activities)\n4) Print activity stats for a given month\n5) Print Calendar Stats (for the whole year)\n6) Remove a user from the calendar (remove all activities of this user)\n7) Save the calendar\nEnter the desired function number: ";
			cin >> function;
		}
		else if(option == 'q')
		{
			break;
		}
		else
		{
			cout<<"Wrong input! Enter 'q' to quit of 'a' to go again: ";
			cin >> option;
		}
	}

	//The "deallocation" function is being called in "main" function.
	deallocation(year, months, days, hours);
} 