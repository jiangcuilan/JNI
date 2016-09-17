
#include "DllMethod.h"
#include<iostream>
#include<Windows.h>
#include <IOSTREAM>

char* getString(char* jstr) {
	return jstr;
}
int sumStudentAge(STUDENT *s1,STUDENT *s2){
	if(s1&&s2) return s1->age+s2->age;
	return 0;
}

STUDENT  getStudent(int age,char* name){

	STUDENT s1;
	s1.age=age;
	s1.name=name;
	return s1;
}

void getStudent(STUDENT *s1){
	if(s1)
	  s1->age=s1->age+10;
}

void getStudents(int *ages,std::string* names,STUDENT *s){
	int age;
	std::string name;
	
	 for(int i=0;i<2;i++){	 
		 s[i].age=ages[i];
		 s[i].name=names[i];
	 }
	
	////或者 STUDENT *s =&stus[0];
	//for (int i = 0; i < 2; i++)
	//{
 //       //或者s->age;s++;
	//	 printf("name222 = %s\n", s[i].name.c_str());
	//	 printf("age222 = %d\n",s[i].age);
 //    } 



}
STUDENT getFirstStudent(STUDENT *s){
	
	STUDENT newS;
	if(s){
		newS.age=s[0].age;
		newS.name=s[0].name;
	}
	return newS;
}