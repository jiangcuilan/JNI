// TestC.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "TestC.h"


// 这是导出变量的一个示例
TESTC_API int nTestC=0;

// 这是导出函数的一个示例。
TESTC_API int fnTestC(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 TestC.h
CTestC::CTestC()
{
	return;
}
int StudentO::sumAge(STUDENT* st1, STUDENT* st2){
	if(st1 && st2) return st1->age + st2->age;
	return 0;
}
STUDENT* StudentO::getStudent(int age,std::string& name){
	STUDENT* student=new STUDENT();
	student->age=age;
	student->name=name;
	return student;
}
int sumStudentAge(STUDENT* st1, STUDENT* st2){
	if(st1 && st2) return st1->age + st2->age;
	return 0;
}
TESTC_API STUDENT* getStudent(int* ages, std::string  *names ){
	int age;
	std::string name;
	STUDENT stus[2];
	 for(int i=0;i<2;i++){	 
		 stus[i].age=ages[i];
		 stus[i].name=names[i];
	 }
	
	STUDENT *s= stus ;//或者 STUDENT *s =&stus[0];
	for (int i = 0; i < 2; i++)
	{
         s[i].age;//或者s->age;s++;
		  
		  
		 
	  } 
	return (STUDENT *) stus;
}