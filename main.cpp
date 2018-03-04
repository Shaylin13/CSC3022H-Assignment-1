//main.cpp
//pre processor directive check what it does NB.
#include <stdio.h>
#include <string>
#include <iostream>

#include "studentDB.h"

int main()
{
	using namespace std;
	//dont have to initialise string, already set to "".
	string option;
	//flag to end the event loop.
	bool end=false;

	//variables to hold user input when creating student.
	string name;
	string surname;
	string studentNumber;
	string grade;

	//student number used for getData and getGrade
	std::string snumTemp;

	

 while(end==false)
 //event loop to take in input from user until end selected.
 {
	cout<<"enter key:\nq to exit\n1 to add new student\n2 to read database\n3 to save database\n4 display student data\n5 to display student average"<<endl;
	cin>>option;

	//1) add new student option
	if(option=="1")
	{
		cout<<"add student selected"<<endl;
		cout<<"enter name"<<endl;
		cin>>name;
		cout<<"enter surname"<<endl;
		cin>>surname;
		cout<<"enter Student Number"<<endl;
		cin>>studentNumber;
		cout<<"enter Class Record"<<endl;
		cin>>grade;

		PDYSHA009::addStudent(name,surname,studentNumber,grade);

	}

	//read database file
	if(option=="2")
	{
		cout<<"read database selected"<<endl;
		PDYSHA009::readDatabase();
	}

	//save database to file
	if(option=="3")
	{
		cout<<"save database selected"<<endl;
		PDYSHA009::saveDatabase();
	}

	//display input students data
	if(option=="4")
	{
		cout<<"display student data selected"<<endl;
		cout<<"enter student number to seach for"<<endl;
		cin>>snumTemp;
		PDYSHA009::getStudentData(snumTemp);
	}

	//display input students grade average
	if(option=="5")
	{
		cout<<"display student grade average selected"<<endl;
		cout<<"enter student number to seach for"<<endl;
		cin>>snumTemp;
		PDYSHA009::getStudentGrade(snumTemp);
	}

	//exit program
	if(option=="q")
	{
		end=true;
	}
 }//end of while loop - checks end flag

		
	cout<<"\nprogram end"<<endl;
	//arbitrary return value.
	return 0;
}
