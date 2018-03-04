//studentDB.h
#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace PDYSHA009
{
	void addStudent(std::string, std::string, std::string, std::string);
	void readDatabase();
	void saveDatabase();
	void getStudentData(std::string);
	void getStudentGrade(std::string);
	
}

#endif
