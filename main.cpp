/*
     Name:      Krishna rana
     Course:    CIS 260 ME1
     Date:      05/08/2017
     Program:   project 5 - class project
     Description:	This program has node's, which consists of:  id number (5 digits), Name (a string),
	 				 and hours & rate both are of the same type (both are: integers, floats or doubles).
		 This data is provided in the attached file. The program must read the data from either one of the
		 files and place it in the linked list in descending order based on the id number. Each Node of the
		 list contains the data above, and a pointer to the next node.

	 
*/
#include "linkListImplementation.cpp"//file for class linklist.
#include "NodeImplementation.cpp"//file for class Node.
#include <iostream>//header file for Input/output stream
#include <string>//header file for string
#include <fstream>//Standard Input/output streams libary
#include <cstdlib>//general purpose function are defined in this header
using namespace std;//standard namespace
//function prototype
template<class T>
void menu(linkList<T> &, ofstream&);
//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has calls and parameters of other function in the program.
int main()
{
	//Local Definations/ Declarlations
	//file stream for outputfile.
	ofstream fout ("Employee_Data.txt");
	//Initialization of class object with template type
	linkList<float>list;
	list.add();
	//function call
	menu(list, fout);
	
	fout.close();
	return 0;
}
//menu() Function Defination
//This function has the menu choices to run the program based on user input.
//menu() has class linklist as a parameter and function type is void, it does not return
//anything.
template<class T>
void menu(linkList<T> & list, ofstream& fout)
{
	//Local Definations/ Declarlations
	char input;
	//condition runs once for menu choice from user.
	do{
		//system has clear screen
		system("CLS");
		cout<<"\t\t\tMain Menu\n\n";
		cout<<"\t\t1- (D)isplay\n";
		cout<<"\t\t2- (R)emove\n";
		cout<<"\t\t3- (P)eek \n";
		cout<<"\t\t4- (G)ross\n";
		cout<<"\t\t5- (N)et\n";
		cout<<"\t\t6- (C)lear\n";
		cout<<"\t\t7- (E)xit\n";
		cout<<"\n\t\tPlease input your choice: ";
		cin>>input;//user input
		input = toupper(input);//toupper capitalize the input
		cin.ignore();
		//swtich case to run functions based on user input
		switch(input)
		{
			case '1':
			case 'D':list.display();//case R will remove last entry
				cin.get();
				break;
			case '2':
			case 'R':list.remove();//case R will remove last entry
				cin.get();
				break;
			case '3':
			case 'P':list.peek();//case D will display with assistance from print().
				cin.get();
				break;
			case '4':
			case 'G':list.gross();//will clear the whole list to NULL.
				cin.get();
				break;
			case '5':
			case 'N':list.net();
				cin.get();
				break;
			case '6':
			case 'C':list.clear(fout);
				cin.get();
				break;
		}
	//other inputs are ignored
	}while((input !='7') && (input != 'E'));
}
