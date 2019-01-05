#include<iostream>
#include<string>
using namespace std;



//employee classs that is base class
class employee
{
protected:
	string name;
	string designation;
	double salary;
	string ID;

public:

	//constructor of employee class
	employee(string n,string d,double s,string id):name(n),designation(d),salary(s),ID(id)
	{}

	//function which return the name of an employee
	string getName()
	{
	
	return name;
	}//end of function

	
//print function of employee which is virtual function
virtual void print()
{

cout<<"Name  "<<name<<endl;
cout<<"Designation  "<<designation<<endl;
cout<<"Salary   "<<salary<<endl;
cout<<"ID number "<<ID<<endl;


}//end of print function of employee



};


//manager class which is inherited from Employee class
class manager:public employee
{
private:
	string department;
	int noE;
public:

	//constructor for class Manager
	manager(string n,string d,double s,string id,string dep,int e):Employee(n,d,s,id),department(dep),noE(e)
	{}



	//overridden function that print
	void print()
	{
		Employee::print();
		cout<<"Department  "<<department<<endl;
		cout<<"Number of employee  "<<noE<<endl;
	
	}//end of print function
	

};



//worker class
class worker:public employee{

private:
	int hours;

public:

	//constructor of worker class
	worker(string n,string d,double s,string id,int h):Employee(n,d,s,id),hours(h){}

	//print function which is overridden function
	void print()
	{
	Employee::print();
	cout<<"Total hours of worker are "<<hours<<endl;
	
	}//end of print function of worker class
};



//List class
class List{

	//make a node which will be for only list class
	struct Node{
		Employee *data;
		Node * next;
	
	};//end of struct 

	//data members of List class
	Node *head,*tail;
	int size;
	Node *current;

	//a utility function to create node
	Node *createNode()
	{
	
		Node *temp=new Node;
		temp->next=nullptr;

	return temp;
	}//end of createNode

public:
	//methods of list class
	
	//default constructor of list class
	//it initialize both head and tail to null ptr
	List():head(nullptr),tail(nullptr),size(0),current(nullptr){}

	
	
	//copy constructor of List class
	List(List & obj)
	{
	
		//poointing cur 1 to head of old list
		Node* cur1=obj.head;
		head=createNode();
		head->data=obj.head->data;
		Node *cur2=head;
		cur1=cur1->next;
		size=obj.size;
		for(int i=1; i<size; ++i)
		{

			Node* temp=createNode();
			temp->data=cur1->data;
			cur2->next=temp;
		}//end of for
		tail=cur2->next;
	
	}//end of copy constructor


	//assignment operator
	void operator=(List &obj)
	{
		this->~List();

		//poointing cur 1 to head of old list
		Node* cur1=obj.head;
		head=createNode();
		head->data=obj.head->data;
		Node *cur2=head;
		cur1=cur1->next;
		size=obj.size;
		for(int i=1; i<size; ++i)
		{

			Node* temp=createNode();
			temp->data=cur1->data;
			cur2->next=temp;
		}//end of for
		tail=cur2->next;
		

	
	}//end of operator 
	
	//function to insert a node at start of list
	bool insertAtStart(Employee *e)
	{

	if(size==0)
	{
	head=tail=createNode();
	head->data=e;
	size++;
	
	
	return true;
	}//end of if(size==0)

	else
	{
		Node* temp=createNode();
		temp->next=head;
		head=temp;
		head->data=e;
		size++;
		
	return true;
	}

	return false;
}//end of function



	//function to inset a node at end of list
	bool insertAtEnd(Employee *e)
	{
	

		//situation when list is empty
	if(size==0)
	{
	head=tail=createNode();
	head->data=e;
	size++;
	
	return true;
	}//end of if(size==0)


	//situation when list is not empty
	else
	{
	
		Node*temp=createNode();
		tail->next=temp;
		tail=temp;
		tail->data=e;
		size++;
	
	}//end of else
	
	}//end of insertAtend function


	//function inset a node in order with repspect to name of the employee
	bool insertInOrder(Employee *e)
	{
	
		//situation when list is empty
		if(size==0)
		{
		insertAtStart(e);
		size++;
		
		}//end of if
		//lit is not empty
		else
		{
		
		Node* cur=head;
		Node* prev=nullptr;
		while(cur!=nullptr&&cur->data->getName()<e->getName())
		{
		
			prev=cur;
			cur=cur->next;

		}//end of while function
		
		if(cur=nullptr)
		{
		
			insertAtEnd(e);
			size++;
		}//end of if
		//when data found at start of list
		else if(prev=nullptr)
		{
		insertAtStart(e);
		size++;
		}//end of else if

		else
		{
		
		Node* temp=createNode();
		temp->data=e;
		prev->next=temp;
		temp->next=cur;
		size++;
		
		}//end of else
		
		}//end of else

	}//end of insertInOrder function





	//delete at start
	bool deleteAtStart()
	{
	
		//when list is empty
		if(size==0)
		{
			cout<<"nothing to delete"<<endl;
		
			return false;
		
		}//end of if(size==0)
		else if(size==1)
		{
		
		delete head;
		head =tail=nullptr;
		size--;
		return true;
		
		}//end of if(size==1)
		
		else  //when size more than 1
		{
		
			Node *temp= head;
			head=head->next;
			delete temp;
			size--;
			return true;
		
		}//end of else when size more than 1

		


	
	}//end of delete at start


	//delete at end of lis
	bool deleteAtEnd()
	{
		if(size==0)//when list is empty
		{
		
			cout<<"There is nothing to deleted "<<endl;
			return false;

		}//end of if(size==0)
	
		else if(size==1)//case 2 when there is one object in the list
		{
		
			delete tail;
			head=tail=nullptr;
			size--;
			return true;
		
		}//end of else if(size==1)

		else//when list have more than 1 element
		{
		
			Node* cur=head;
			while(cur->next!=tail)
			{
			
				cur=cur->next;
			}
			delete tail;
			tail=cur;
			size--;
			return true;
		
		}//end of else
	
	
	
	}//end of delete at End



	//delete in order function
	//deleta all user of given name

	bool deleteInOrder(string n)
	{
	
		if(size==0)
		{
			cout<<"Nothing to delete "<<endl;
			return false;

		}
		int count=0;
	while(0==0)
	{
		count++;
	if(size==0)//when list is emty
	{
	
		
		return true;
	
	}//end of if
	
	else //when list is not empty
	{

		Node* cur=head;
		Node* prev=nullptr;
		//while loop to gothrough in list
		while(cur!=nullptr&&cur->data->getName()!=n)
		{
		
			prev=cur;
			cur=cur->next;

		}//end of while function
		
		
		 if(cur==nullptr)//when name found at end of the list
		{
		
			if(count>1)
			{
				cout<<"name not found"<<endl;
			return false;
			}
			return true;

		}//end if(cur==nullptr)
		 
		else if (prev==nullptr)//when found at start of list
		{
		
		 deleteAtStart();
		}//end of else when 

		else //else 
		{
		
			
			prev->next=cur->next;
			delete cur;
			size--;
		
		}//end of else
	}//end of else whne list is not empty
	}//end of while
	}//end of deleteInOrder


	//function which reset the tiversing in the list 
	//and push you to 0 that is head of list
	bool reset()
	{
	current =head;
	
	return true;
	}//end of reset

	//a function get next which give the current indexed data 
	Employee * getNext()
	{
		if(current!=nullptr)
		{
		Node *temp=current;
		current=current->next;
		
		return temp->data;
		}
		else
		{
		return nullptr;
		
		}
	
	
	
	
	
	
	
	}//end of getnext

	//destroctor of list class
	~List()
	{
	
	for(int i=0; i<size; ++i)
	{
		deleteAtStart();

	}//end of for
	}//end of destroctor

};