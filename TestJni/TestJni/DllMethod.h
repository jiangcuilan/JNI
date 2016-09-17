
#include<iostream>
#include<Windows.h>
#include <IOSTREAM>
struct STUDENT{
	std::string name;
	int age;
};


char* getString(char* jstr );

int sumStudentAge(STUDENT * s1,STUDENT * s2);

STUDENT  getStudent(int age,char* name);

void getStudent(STUDENT *s1);


void  getStudents(int *ages,std::string* names,STUDENT *S);

STUDENT getFirstStudent(STUDENT *S);