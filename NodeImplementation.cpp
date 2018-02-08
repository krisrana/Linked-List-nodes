#include <iostream>//header file for Input/output stream
#include <string>//header file for string
#include <fstream>//header file for file stream.
#include <iomanip>//header file for output manipulation
#include "Node.h"//header file for class Node
using namespace std;//standard namespace
/*	constructor
 *	@brief  construtor sets all members to null
 *  @param  none.
 *  @return none.
 */
template<class T>
Node<T>::Node()
{
	//member set to zero or null respectively 
	id = 0;
	name = "";
	hour = 0;
	rate = 0;
	next = NULL;
}//end constructor

/*	setnode()
 *	@brief use this pointer to instaintiate members
 *  @param int empid, string name, template type hour and rate.
 *  @param empid = id, name = Name, hour = Hour, rate=Rate
 *  @return none.
 */
template<class T>
void Node<T>::setnode(int EmpId,string Name,T Hour, T Rate)
{
	//use of this pointer
	this-> id = EmpId;
	this-> name = Name;
	this->hour = Hour;
	this->rate = Rate;
}//end of setnode()

/*	getid()
 *	@brief this is a getter function it purpose is to have access
 			to private member id. since its getter function and 
 			accessor method it is constant function.
 *  @param none.
 *  @return int value for given id.
 */
template<class T>
int Node<T>::getid()const
{
	return id;
}//end of getid()

/*	getname()
 *	@brief this is a getter function it purpose is to have access
 			to private member name. since its getter function and 
 			accessor method it is constant function.
 *  @param none.
 *  @return string value for given name.
 */
template<class T>
string Node<T>::getname()const
{
	return name;
}//end of getname()

/*	gethour()
 *	@brief this is a getter function it purpose is to have access
 			to private member hour. since its getter function and 
 			accessor method it is constant function.
 *  @param none.
 *  @return Template type value for given hour.
 */
template<class T>
T Node<T>::gethour()const
{
	return hour;
}//end of gethour()

/*	getrate()
 *	@brief this is a getter function it purpose is to have access
 			to private member rate. since its getter function and 
 			accessor method it is constant function.
 *  @param none.
 *  @return Template type value for given rate.
 */
template<class T>
T Node<T>::getrate()const
{
	return rate;
}//end of getrate()

/*	nextNode()
 *	@brief This function points the next to the nextnode in the list
 			since its name nextNode.
 *  @param none.
 *  @return Node pointer to nextNode() by the value in next.
 */
template<class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}//end of nextNode()

/*	setnext()
 *	@brief This sets the next to point at the next of nextNode.
 *  @param Node pointer to next, given name link.
 *  @return none.
 */
template<class T>
void Node<T>::setnext(Node* link)
{
	next = link;
}//end of setnext()

/*	getnode()
 *	@brief this is a getter function it purpose is to have access
 			to the private member and print the current value they hold.
		since its getter function and accessor method it is constant function.
 *  @param none.
 *  @return none.
 */
template<class T>
void Node<T>::getnode() const
{
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Id Number: "<<id<<setw(20)<<"Name : "<<name<<endl;
	cout<<"Hour: "<<hour<<setw(27)<<"Rate: "<<rate<<endl;
}//end of getnode()

/*	getfile()
 *	@brief This function is a getter function since it is constant, the purpose
 	of this funciton is to output the data of each node to a file. it outputs
 	the current value of id, name, hour and rate to an outputfile.
 *  @param file stream type fout via reference.
 *  @return none.
 */
template<class T>
void Node<T>::getfile(ofstream & fout) const
{
	fout<<"--------------------------------------------------------------"<<endl;
	fout<<"Id Number: "<<id<<setw(20)<<"Name : "<<name<<endl;
	fout<<"Hour: "<<hour<<setw(32)<<"Rate: "<<rate<<endl;
}//end of getfile()

//end of NodeImplementation
