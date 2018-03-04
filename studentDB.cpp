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

	if(!in)
		{ std::cout << "Couldn't open " << filename << std::endl; }

	while(getline(in, line)) {

		if (line.find("Student #") != std::string::npos) {
			continue;
		}
		else {
			if (line.find("Name") != std::string::npos) {
				size_t name_found = line.find_last_of(":");
				studentTemp.name = line.substr(name_found+2);
			}

			if (line.find("Surname") != std::string::npos) {
				size_t surname_found = line.find_last_of(":");
				studentTemp.surname = line.substr(surname_found+2);
			}

			if (line.find("Student Number") != std::string::npos) {
				size_t studentnum_found = line.find_last_of(":");
				studentTemp.studentNumber = line.substr(studentnum_found+2);
			}

			if (line.find("Class Record") != std::string::npos) {
				size_t classrec_found = line.find_last_of(":");
				studentTemp.classRecord = line.substr(classrec_found+2);
				databaseArr.push_back(studentTemp);
			}
		}
		
	}//std::cout << databaseArr.size() << std::endl;
	
}

void PDYSHA009::saveDatabase()
{
	std::cout<<"saveDatabase called."<<std::endl;
	if (studentArr.size() == 0 && databaseArr.size()==0) {
		//std::cout<<"size"<<studentArr.size()<<std::endl;
		std::cout << "No student record to add to database \n";
	}
	else {

				
		
		std::ofstream myfile;

		myfile.open("Student Database");
			std::cout << "Updating changes to database... \n";
			for (int i = 0; i < databaseArr.size(); i++) {
				myfile << "Student #" << i+1 << "\n";
				myfile << "Name: " << databaseArr[i].name << "\n";
				myfile << "Surname: " << databaseArr[i].surname << "\n";
				myfile << "Student Number: " << databaseArr[i].studentNumber << "\n";
				myfile << "Class Record: " << databaseArr[i].classRecord << "\n";
				myfile << "\n";
			}
			myfile.close();
		//end of database update

			readDatabase();
			std::cout<<"new entries"<<studentArr.size()<<std::endl;
			int number_of_students = databaseArr.size();
			myfile.open("Student Database", std::ofstream::app);
			std::cout << "adding new entries to file... \n";

			for (int i = 0; i < studentArr.size(); i++) {
				myfile << "Student #" << ++number_of_students << "\n";
				myfile << "Name: " << studentArr[i].name << "\n";
				myfile << "Surname: " << studentArr[i].surname << "\n";
				myfile << "Student Number: " << studentArr[i].studentNumber << "\n";
				myfile << "Class Record: " << studentArr[i].classRecord << "\n";
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
		else {
			found = false;
		}
	}
	if (found==false) {
		std::cout << "Student not found on database! \n";
	}
	std::cout << std::endl;
}

void PDYSHA009::getStudentGrade(std::string snum)
{
	std::cout<<"getStudentGrade called."<<std::endl;
	readDatabase();
	bool found = false;
	std::string grades;
	for (int i = 0; i < databaseArr.size(); i++) {
		if (databaseArr[i].studentNumber == snum) {
			grades = databaseArr[i].classRecord;
			//std::cout << databaseRec[i].classRecord << "\n";
			found = true;
			break;
		}
		else {
			found = false;
		}
	}
	if (found==false) {
		std::cout << "Student not found on database! \n";
	}
	else {
		int total = 0;
		int count = 0;
		std::istringstream iss(grades);
		while (!iss.eof()) {
			count++;
			int n;
			iss >> n;
			total += n;
			//std::cout << "value=" << n << std::endl;
		}
		std::cout << "Average grade of student is " << total/count << std::endl;
	}
	std::cout << std::endl;
}

