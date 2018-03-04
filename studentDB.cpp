//studentDB
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "studentDB.h"

struct StudentRecord {
	std::string name;
	std::string surname;
	std::string studentNumber;
	std::string classRecord;
	
};

std::vector<StudentRecord> studentArr;
std::vector<StudentRecord> databaseArr;

void PDYSHA009::addStudent(std::string n, std::string sn, std::string snum, std::string g)
{
	std::cout<<"addStudent() called."<<std::endl;
	//create new student without constructor
	StudentRecord studentTemp;
	studentTemp.name=n;
	studentTemp.surname=sn;
	studentTemp.studentNumber=snum;
	studentTemp.classRecord=g;

	bool found=false;
	readDatabase();
	
	if(studentArr.size()==0 && databaseArr.size()==0)
	{
		studentArr.push_back(studentTemp);
	}
	else{

	for (int i = 0; i < studentArr.size(); i++) {
		if (studentArr[i].studentNumber == snum) {
			studentArr[i].name = studentTemp.name;
			studentArr[i].surname = studentTemp.surname;
			studentArr[i].studentNumber = studentTemp.studentNumber;
			studentArr[i].classRecord = studentTemp.classRecord;

			std::cout<<"student overwritten"<<std::endl;
			found=true;
			break;
		}
	
	}//end of for loop

	for (int i = 0; i < databaseArr.size(); i++) {
		if (databaseArr[i].studentNumber == snum) {
			databaseArr[i].name = studentTemp.name;
			databaseArr[i].surname = studentTemp.surname;
			databaseArr[i].studentNumber = studentTemp.studentNumber;
			databaseArr[i].classRecord = studentTemp.classRecord;

			std::cout<<"student overwritten"<<std::endl;
			found=true;
			break;
		}
	}//end of second for loop

		if(found==false){//if the student was not found then add it
			//add the student to the vector array if not already there
			studentArr.push_back(studentTemp);
			std::cout<<"size "<<studentArr.size()<<std::endl;
			std::cout<<"size "<<databaseArr.size()<<std::endl;
			
		}		
		
	}//end of else
	
	
	
}

void PDYSHA009::readDatabase()
{
	std::cout<<"readDatabase() called."<<std::endl;

	databaseArr.clear();
	StudentRecord studentTemp;
	std::string filename = "Student Database";
	std::string line;

	std::ifstream in(filename.c_str());
	int counter =1;

	if(!in)
		{ std::cout << "Couldn't open file" << filename << std::endl; }

	while(getline(in, line)) {

		if(counter == 1)
		{studentTemp.name=line;
		counter++;}
		else if(counter == 2)
		{studentTemp.surname = line;
		counter++;}
		else if(counter == 3)
		{studentTemp.studentNumber = line;
		counter++;}
		else if(counter == 4)
		{studentTemp.classRecord = line;
		databaseArr.push_back(studentTemp);
		counter++;}
		else if(counter == 5)
		{counter=1;}
		
	}
	
}

void PDYSHA009::saveDatabase()
{
	std::cout<<"saveDatabase() called."<<std::endl;
	if (studentArr.size() == 0 && databaseArr.size()==0) {
		std::cout << "No student records to add to database \n";
	}
	else {
		std::ofstream myfile;

		myfile.open("Student Database");
			std::cout << "Updating changes to database... \n";
			for (int i = 0; i < databaseArr.size(); i++) {

				myfile << databaseArr[i].name << "\n";
				myfile << databaseArr[i].surname << "\n";
				myfile << databaseArr[i].studentNumber << "\n";
				myfile << databaseArr[i].classRecord << "\n";
				myfile << "\n";
			}
			myfile.close();
		//end of updating changes to db file, updated existing record
		//now any new entered records will be written

			readDatabase();
	
			myfile.open("Student Database", std::ofstream::app);
			std::cout << "adding new entries to file... \n";

			for (int i = 0; i < studentArr.size(); i++) {

				myfile << studentArr[i].name << "\n";
				myfile << studentArr[i].surname << "\n";
				myfile << studentArr[i].studentNumber << "\n";
				myfil << studentArr[i].classRecord << "\n";
				myfile << "\n";
			}
			myfile.close();
	}
	studentArr.clear();
	std::cout << std::endl;
}

void PDYSHA009::getStudentData(std::string snum)
{
	std::cout<<"getStudentData called."<<std::endl;
	readDatabase();
	bool found = false;
	for (int i = 0; i < databaseArr.size(); i++) {
		if (databaseArr[i].studentNumber == snum) {
			std::cout <<"name: "<< databaseArr[i].name << "\nsurname: ";
			std::cout << databaseArr[i].surname << "\nstudent number: ";
			std::cout << databaseArr[i].studentNumber << "\nclass record: ";
			std::cout << databaseArr[i].classRecord << "\n";
			found = true;
			break;
		}
	}

	if (found==false) {
		std::cout << "Student not found in database, make sure record has been saved to DB\n";
	}
	std::cout << std::endl;
}

void PDYSHA009::getStudentGrade(std::string snum)
{
	std::cout<<"getStudentGrade() called."<<std::endl;
	readDatabase();
	bool found = false;
	std::string grades;
	for (int i = 0; i < databaseArr.size(); i++) {
		if (databaseArr[i].studentNumber == snum) {
			grades = databaseArr[i].classRecord;
			found = true;
			break;
		}
	}

	if (found==false) {
		std::cout << "Student not found in database, make sure record has been saved to DB \n";
	}
	else {
		int total = 0;
		int counter = 0;
		std::istringstream iss(grades);
		while (!iss.eof()) {
			counter++;
			int n;
			iss >> n;
			total += n;
		}
		std::cout << "student grade average: " << total/counter << std::endl;
	}
	std::cout << std::endl;
}

