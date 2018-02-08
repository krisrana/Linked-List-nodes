#include "node.h"//header file for Node class
#include <iostream>//header file for Input/output stream
#include <string>//header file for string
#include <fstream>//header file for file stream.
//gaurds
#ifndef LINKLIST_H
#define LINKLIST_H
using namespace std;//standard namespace
template<class T>//template called T.
//class linkList defination
class linkList
{
	//private member
	private:
		Node<T>* head;
		bool isEmpty()const;
		void print(Node<T>*)const;
		void printToFile(Node<T>*, ofstream&)const;
		Node<T>* location(Node<T>*);
	//public member
	public:
		//member functions
		linkList();
		void add();
		void display();
		bool remove();
		void peek()const;
		void gross();
		void net();	
		void clear(ofstream&);
		virtual ~linkList(){ }//virtual destructor
};
//gaurds
#endif

