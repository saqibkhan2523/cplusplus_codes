#include"Employee.h"

//#include"Manager.h"
//#include"Worker.h"
//#include"List.h"
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;


//print all user
void printall(List &l)
{

	l.reset();
	Employee * temp=l.getNext();

	for(int i=0; temp!=nullptr; ++i)
	{
	
		temp->print();

		temp=l.getNext();
		cout<<endl;
		
	
	}//end of for loop
	

}//print all user

//add manager
void addManager(List &l,string name,string department,double salary,string id,string department2,int ne)
{
	l.insertInOrder(new Manager(name,department,salary,id,department2,ne));


}//end of add manager
//add worker
void addWorker(List &l,string name,string department,double salary,string id,int h)
{
	l.insertInOrder(new Worker(name,department,salary,id,h));


}//end of add worker

//find and print 
void findAndprint(List &l,string name)
{
	l.reset();
	Employee *temp=l.getNext();
	Employee *found=nullptr;
	
	for(int i=0; temp!=nullptr; ++i)
	{
	
		if(temp->getName()==name)
			found=temp;
			
		temp=l.getNext();
	
	
	}//end of for loop

	if(found!=nullptr)
	{
	found->print();
	}//end of if

	else
	{
	
		cout<<"not found"<<endl;
	}

}//end of find and print


//main function
int main()
{

	Employee * e1=new Manager("pakistan","finishing",1000202,"234234234","finishing",23);
	Employee * e2=new Manager("asim","packing",10000,"354048901","sfas",1);
	List l;
	
	l.insertAtStart(e1);
	
	l.insertAtStart(e2);
	

	printall(l);	
	

	_getch();
return -1;
}//end of main