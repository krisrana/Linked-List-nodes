#include <iostream>//header file for Input/output stream
#include <string>//header file for string
#include <fstream>//header file for file stream.
#include <iomanip>//header file for output manipulation
#include <cstdlib>//general purpose function are defined in this header
#include "linkList.h"//header file for class linklist.
using namespace std;//standard namespace
/*	constructor
 *	@brief  construtor to set head to NULL
 *  @param  none.
 *  @return none.
 */
template<class T>
linkList<T>::linkList()
{
	head = NULL;
}//end of constructor

/*	isEmpty()
 *	@brief  This is an accessor method, the purpose of this
 		method is to set head to NULL as an condition. which
 		allow other function to use it as an condition parameter.
 *  @param  none.
 *  @return boolean type by setting head to null.
 */
template<class T>
bool linkList<T>::isEmpty()const
{
	return head == NULL;
}//end of isEmpty()

/*	add()
 *	@brief  This method adds information from the file automatically to the 
 		linked list in descending order with the help of location function.
 *  @param  none.
 *  @return none.
 */
template<class T>
void linkList<T>::add() 
{  
	//file accessed by file stream
	ifstream fin("data2.txt");
	//local declaration
	int id;
	T hour, rate;
	string name;
		//giving base case for the while loop
		while(!fin.eof())
		{	fin >> id;
			//getting information from file
			fin.ignore();
			getline(fin,name);
			fin>>hour;
			fin>>rate;
		
			//seting information from file to linked list by dynamic allocation
			Node<T>* newNode = new Node<T>();
			newNode->setnode(id,name,hour,rate);
			newNode->setnext(NULL);
			//call to location()
			location(newNode);
		}
	//closing file
	fin.close();
}//end of add()

/*	location
 *	@brief This is a method the points the pointer where the action takes place
 		its points the location where the data from file will go based on id.
 		so it pointing to the location the id and data has to be added and sends
 		that pointer to add().
 *  @param  Node pointer of template type named newNode
 *  @return Node pointer of template type
 */

template<class T>
Node<T>* linkList<T>::location(Node<T>* newNode)
{
	//local declaration
	Node<T>* curr = head;
	Node<T>* prev = head;
	//locating the location for node to be entered at 
	if(isEmpty())
	{
		head = newNode;
		return NULL;
	}
	else
	{
		if(newNode->getid() > head->getid())
		{		
			newNode->setnext(head);
			head = newNode;
		}
		else
		{
			while(newNode->getid() < curr->getid() && curr->nextNode() != NULL)
			{
				prev = curr;
				curr = curr->nextNode();
			}
				if (curr->nextNode() == NULL)
				{
					if(newNode->getid() > curr->getid())
					{
						newNode -> setnext(curr);
						prev->setnext(newNode);
					}
					else
					{	
						curr->setnext(newNode);
					}
				}
				else
				{
					newNode->setnext(curr);
					prev->setnext(newNode);
				} 
		}
	}
}//end of location()

/*	remove()
 *	@brief  This method removes a selected node from the list based on the given id.
 			it searches the ordered list and find the given id with its data and deletes it.
 			its uses delete to delete dynamicallly allocation node.
 			if the id does not exist in list it will given an appropriate message.
 *  @param  none.
 *  @return boolean, returns success if its removes.
 */
template<class T>
bool linkList<T>::remove()
{
	//local declaration
	int iddel;
	bool success = true;
	Node<T>* prev = head;
	Node<T>* curr = head;
	//users prompt
   	cout<<"Enter ID to delete the node: "; cin>>iddel;
	//searching for the given id in list
	if(head->getid() == iddel)
	{	
		//if id is in the first location
		head = head->nextNode();
		curr = NULL;
		delete(prev);
		cout<<iddel<<" Node is removed from the list"<<endl;
		cin.get();
	}
	else
	{	
		//if id is in the middle location
		while(curr->nextNode() != NULL && curr->getid() != iddel)
		{
			prev = curr;
			curr = curr->nextNode();
		}
			if(curr->nextNode() != NULL)
			{
				prev->setnext(curr->nextNode());
				delete(curr);
				cout<<iddel<<" Node is removed from the list"<<endl;
				cin.get();
			}
			//if id is in the last location
			else if (curr->getid() == iddel)
			{
				prev->nextNode() == NULL;
				delete(curr);
				cout<<iddel<<" Node is removed from the list"<<endl;
				cin.get();
			}
			//if id is not in list.
			else
			{
				cout<<iddel<<" is not in the list"<<endl;
				cin.get();
			}
	}
	return success;
}//end of remove()

/*	peek()
 *	@brief  This method is an accessor method so it is constant, the purpose of
 		this method is to show data of the selected node based on the given name.
 		it searches the list for the given name and print it on display.
 		if the name does not exist in the list it will give an appropriate message.
 *  @param  none.
 *  @return none.
 */
template<class T>
void linkList<T>::peek()const
{	
	//local declaration
	string namesearch;
	Node<T>* curr = head;
	//users prompt	
	cout<<"Enter the name to search information: ";
	getline(cin,namesearch);
	//search for a given name in the ordered list
	while(curr != NULL)
	{
		//if name found, display data
		if(curr->getname() == namesearch)
		{
			curr->getnode();
			return;
		}
		curr = curr->nextNode();
	}
	//if name not found, display message
	cout<<namesearch<<" Not found in the list";
}//end of peek()

/*	gross()
 *	@brief  This method calculates the gross of the hour and rate.
 		and than displays it on the screen.
 *  @param  none.
 *  @return none.
 */
template<class T>
void linkList<T>::gross()
{
	//local declaration
	Node<T>* curr = head;
	float gross;
	
	//setprecision(2) prints answers in 2 decimal spaces.
	cout << fixed << showpoint << setprecision(2);
	
	while(curr!= NULL)
	{	
		gross = curr->gethour() * curr->getrate();
		curr->getnode();
		cout<<"Gross for Hour "<<curr->gethour()<<" X Rate "<<curr->getrate()<<setw(5)<<" =  $"<<gross<<endl;
		curr = curr->nextNode();
	}
}//end of gross()

/*	net()
 *	@brief  The method calcuates the net of gross after taking 20% tax off.
 		and than displays it on the screen.
 *  @param  none.
 *  @return none.
 */
template<class T>
void linkList<T>::net()
{	
	//local declaration
	Node<T>* curr = head;
	float net;
	
	//setprecision(2) prints answers in 2 decimal spaces.
	cout << fixed << showpoint << setprecision(2);
	
	while(curr!= NULL)
	{	
		net = curr->gethour() * curr->getrate() * 0.2;
		curr->getnode();
		cout<<"Net of 20% for Hour "<<curr->gethour()<<" X Rate "<<curr->getrate()<<setw(5)<<" =  $"<<net<<endl;
		curr = curr->nextNode();
	}
}//end of net()

/*	display()
 *	@brief  This function prints the data of each node with the current
 		value each node holds on screen whenever it is called.
 *  @param  none.
 *  @return none.
 */
template<class T>
void linkList<T>::display()
{	
	print(head);
}

/*	print()
 *	@brief  This is an accessor method it only prints data on the screen,
 			since this is an accessor function it is constant. it is also an recursive function.
 *  @param  Node pointer of template type called temp
 *  @return none.
 */
template<class T>
void linkList<T>::print(Node<T>* temp)const
{	

		//if list had nothing to display
		if(head == NULL)
		{
			cout<<"\t*********list is empty*********"<<endl;
		}
		//when list reaches the end of its list.
		else if(temp == NULL)
		{
			cout<<"\t**********End of list**********"<<endl;
		}
		//recursive call to print data untill head(temp) is NUll
		else
		{			
			temp->getnode();
			print(temp->nextNode());
		}
}//end of print()

/*	printToFile()
 *	@brief  This is an accessor method it prints data to an outputfile when clear is called.
 			since this is an accessor function it is constant. it is also an recursive function.
 *  @param  Node pointer of template type called temp, and file stream type parameter called fout
 		passed via reference.
 *  @return none.
 */
template<class T>
void linkList<T>::printToFile(Node<T>* temp, ofstream& fout)const
{	
		//if list had nothing to display
		if(head == NULL)
		{
			cout<<"\t*********list is empty*********"<<endl;
		}
		//when list reaches the end of its list.
		else if(temp == NULL)
		{
			fout<<"\t**********End of list**********"<<endl;
		}
		//recursive call to print data untill head(temp) is NUll
		else
		{			
			temp->getfile(fout);
			printToFile(temp->nextNode(),fout);
		}
}//end of print()

/*	clear()
 *	@brief  This method clear the linked list by de-allocating by delete, but before it
 *          does that it calls print() to print all data once before delete
 *  @param  file stream type member fout passed via reference.
 *  @return none.
 */
template<class T>
void linkList<T>::clear(ofstream& fout)
{
	cout<<"Printing to file.........\n";
	//system("pause");
	cout<<"De-allocation of Nodes\nIn process\n Deleting......";
	printToFile(head, fout);
	Node<T>*temp = head;
	while(head != NULL)
	{
		temp = head;
		head = head->nextNode();
		delete temp;
	}
}

//end of linkListImplementation.
