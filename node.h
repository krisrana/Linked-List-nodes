#include <iostream>//header file for Input/output stream
#include <string>//header file for string
#include <fstream>//header file for file stream.
//gaurds
#ifndef NODE_H
#define NODE_H
using namespace std;//standard namespace
template<class T>//template called T.
//class Node defination
class Node
{
	//private member
	private:
		int id;
		string name;
		T hour;
		T rate;
		Node* next;
	//public member
	public:
		//member functions
		Node();
		void setnode(int EmpId,string Name,T Hour, T Rate);
		void setnext(Node *link);
		int getid()const;
		string getname()const;
		void getnode() const;
		void getfile(ofstream&) const;
		T gethour()const;
		T getrate()const;
		Node* nextNode();
		virtual ~Node(){ }
};
//gaurds
#endif
