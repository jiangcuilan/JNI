// TestC.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "TestC.h"


// ���ǵ���������һ��ʾ��
TESTC_API int nTestC=0;

// ���ǵ���������һ��ʾ����
TESTC_API int fnTestC(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� TestC.h
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
	
	STUDENT *s= stus ;//���� STUDENT *s =&stus[0];
	for (int i = 0; i < 2; i++)
	{
         s[i].age;//����s->age;s++;
		  
		  
		 
	  } 
	return (STUDENT *) stus;
}