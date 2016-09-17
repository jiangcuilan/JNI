
#include "../lib/jni.h"
#include "test_TestJni.h"
#include "DllMethod.h"
#include "CommUtils.h"
#include<iostream>
#include<Windows.h>
#include <IOSTREAM>

/*
 * Class:     test_TestJni
 * Method:    getStringInJni
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test_TestJni_getStringInJni
	(JNIEnv * env, jobject, jstring name){
		return env->NewStringUTF(strcat(jstringToChar(env,name),"您好！"));
}

/*
 * Class:     test_TestJni
 * Method:    getStringInInDll
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test_TestJni_getStringInDll
	(JNIEnv * env, jobject, jstring name){
		return env->NewStringUTF(getString(jstringToChar(env,name)));
}

/*
 * Class:     test_TestJni
 * Method:    getStudentInJni
 * Signature: (ILjava/lang/String;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInJni__ILjava_lang_String_2
	(JNIEnv * env, jobject, jint age, jstring name){
	   jclass student=  env->FindClass("Ltest/Student;");
	   jmethodID init=  env->GetMethodID(student,"<init>","(ILjava/lang/String;)V");
	   jobject newStudent=env->NewObject(student,init,age,name);
	   return newStudent;

}

/*
 * Class:     test_TestJni
 * Method:    getStudentInDll
 * Signature: (ILjava/lang/String;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInDll__ILjava_lang_String_2
	(JNIEnv * env, jobject, jint age, jstring name){

	   STUDENT newS=getStudent(age,jstringToChar(env,name));
	   jclass student=  env->FindClass("Ltest/Student;");
	   jmethodID init=  env->GetMethodID(student,"<init>","(ILjava/lang/String;)V");
	   //jobject newStudent=env->NewObject(student,init,newS->age,charTojstring(env,newS->name.c_str()));
	   //delete newS;
	   jobject newStudent=env->NewObject(student,init,newS.age,charTojstring(env,newS.name.c_str()));
	   return newStudent;
}

/*
 * Class:     test_TestJni
 * Method:    getStudentInJni
 * Signature: (Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInJni__Ltest_Student_2
	(JNIEnv * env, jobject, jobject obj){
		
		jclass student=env->GetObjectClass(obj);
		jfieldID name=env->GetFieldID(student,"name","Ljava/lang/String;");
		jfieldID age=env->GetFieldID(student,"age","I");
		jint ageValue=env->GetIntField(obj,age);
		jstring nameValue=(jstring)env->GetObjectField(obj,name);
		jmethodID init=env->GetMethodID(student,"<init>","(ILjava/lang/String;)V");
		jobject newStudent=env->NewObject(student,init,ageValue,nameValue);
		return newStudent;

}

/*
 * Class:     test_TestJni
 * Method:    getStudentInDll
 * Signature: (Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInDll__Ltest_Student_2
	(JNIEnv * env, jobject, jobject obj){

		jclass student=env->GetObjectClass(obj);
		jfieldID name=env->GetFieldID(student,"name","Ljava/lang/String;");
		jfieldID age=env->GetFieldID(student,"age","I");
		jint ageValue=env->GetIntField(obj,age);
		jstring nameValue=(jstring)env->GetObjectField(obj,name);
		STUDENT ss1;
		ss1.age=ageValue;
		ss1.name=jstringToChar(env,nameValue);
		getStudent(&ss1);
		jmethodID init=env->GetMethodID(student,"<init>","(ILjava/lang/String;)V");
		//jobject newStudent=env->NewObject(student,init,newS->age,charTojstring(env,newS->name.c_str()));
		//delete newS;
		  jobject newStudent=env->NewObject(student,init,ss1.age,charTojstring(env,ss1.name.c_str()));
		return newStudent;

}

/*
 * Class:     test_TestJni
 * Method:    sumStudentInJni
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumStudentAgeInJni
	(JNIEnv * env, jobject, jobject s1, jobject s2){
		jclass student=env->GetObjectClass(s1);	
		jfieldID nameField=env->GetFieldID(student,"name","Ljava/lang/String;");
		jfieldID ageField=env->GetFieldID(student,"age","I");
		jint ageV1=env->GetIntField(s1,ageField);
		jint ageV2=env->GetIntField(s2,ageField);		
		return ageV1+ageV2;
}

/*
 * Class:     test_TestJni
 * Method:    sumStudentInDll
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumStudentAgeInDll
	(JNIEnv * env, jobject, jobject s1, jobject s2){

		jclass student=env->GetObjectClass(s1);	
		jfieldID nameField=env->GetFieldID(student,"name","Ljava/lang/String;");
		jfieldID ageField=env->GetFieldID(student,"age","I");
		jstring nameV1=(jstring)env->GetObjectField(s1,nameField);
		jint ageV1=env->GetIntField(s1,ageField);
		jstring nameV2=(jstring)env->GetObjectField(s2,nameField);
		jint ageV2=env->GetIntField(s2,ageField);
		//使用栈空间，不需要delete
		STUDENT ss1;
		ss1.age=ageV1;	
		//使用堆空间需要delete
		STUDENT * newS2=new STUDENT();
		newS2->age=ageV2;	
		
		jint sum=sumStudentAge(&ss1,newS2);
		delete newS2;
		//三个不能delete，报错
		/*
		delete nameV2;
		delete nameV1;
		delete student;
		*/
		return sum;	


}

/*
 * Class:     test_TestJni
 * Method:    getStudentsInJni
 * Signature: ([I[Ljava/lang/String;)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentsInJni
	(JNIEnv * env, jobject, jintArray ages, jobjectArray names){

        jclass listClass=env->FindClass("Ljava/util/ArrayList;");
		jmethodID initList=env->GetMethodID(listClass,"<init>","()V");
		jobject studentList=env->NewObject(listClass,initList);
		jmethodID addList=env->GetMethodID(listClass,"add","(Ljava/lang/Object;)Z");
		jclass studentClass=env->FindClass("Ltest/Student;");
		jmethodID initStudent=env->GetMethodID(studentClass,"<init>","(ILjava/lang/String;)V");
		jint length=env->GetArrayLength(names);
		jint * ageList=env->GetIntArrayElements(ages,false);//JNI_FALSE返回的就是Java虚拟机中数组对象的指针地址，而JNI_TRUE返回的是Java虚拟机中数据对象的一份拷贝后的指针地址	
		jobject newStudent;
		for (jint i = 0; i < length; i++)
		{		
		  
		   newStudent=env->NewObject(studentClass,initStudent,ageList[i],(jstring)env->GetObjectArrayElement(names,i));		  
		   env->CallBooleanMethod(studentList,addList,newStudent);
		}
		env->ReleaseIntArrayElements(ages,ageList,0);	
		return studentList;
}

/*
 * Class:     test_TestJni
 * Method:    getStudentsInDll
 * Signature: ([I[Ljava/lang/String;)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentsInDll
	(JNIEnv * env, jobject, jintArray ages, jobjectArray names){
		
		jclass listClass=env->FindClass("Ljava/util/ArrayList;");
		jmethodID initList=env->GetMethodID(listClass,"<init>","()V");
		jobject studentList=env->NewObject(listClass,initList);
		jmethodID addList=env->GetMethodID(listClass,"add","(Ljava/lang/Object;)Z");
		jclass studentClass=env->FindClass("Ltest/Student;");
		jmethodID initStudent=env->GetMethodID(studentClass,"<init>","(ILjava/lang/String;)V");
		jint length=env->GetArrayLength(names);
		//定义一个结构体数组
		
		STUDENT  studentArray[2];
		jint * ageArray=env->GetIntArrayElements(ages,false);//JNI_FALSE返回的就是Java虚拟机中数组对象的指针地址，而JNI_TRUE返回的是Java虚拟机中数据对象的一份拷贝后的指针地址	
		std::string  nameArray[2];
		
		for (jint i = 0; i < length; i++){		  
		    nameArray[i]=jstringToChar(env,(jstring)env->GetObjectArrayElement(names,i));		  
		}
		
	    getStudents((int*)ageArray,nameArray,studentArray);	
		jobject student;

		for (jint i = 0; i < length; i++){		  
		   student =env->NewObject(studentClass,initStudent,studentArray[i].age,charTojstring(env,studentArray[i].name.c_str()));   
		   env->CallBooleanMethod(studentList,addList,student);	  
		}	
		
		env->ReleaseIntArrayElements(ages,ageArray,0);	
		env->DeleteLocalRef(student);

		return studentList;	


}

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: (Ljava/util/ArrayList;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudentInJni__Ljava_util_ArrayList_2
	(JNIEnv * env, jobject, jobject students){

        jclass listClass = env->GetObjectClass(students);      
        jmethodID getList = env->GetMethodID(listClass,"get","(I)Ljava/lang/Object;");
        return  env->CallObjectMethod(students,getList,0);       
       


}

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: ([Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudentInJni___3Ltest_Student_2
	(JNIEnv * env, jobject, jobjectArray students){		
		return (jobject)env->GetObjectArrayElement(students,0);
}

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: (Ljava/util/ArrayList;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudentInDll__Ljava_util_ArrayList_2
	(JNIEnv * env, jobject, jobject students){

        jclass listClass = env->GetObjectClass(students);      
        jmethodID getList = env->GetMethodID(listClass,"get","(I)Ljava/lang/Object;");
		//获取数组的长度
        jmethodID getSize = env->GetMethodID(listClass,"size","()I");  
		jint len = env->CallIntMethod(students,getSize); 

		jclass studentClass=env->FindClass("Ltest/Student;");
		jmethodID initStudent=env->GetMethodID(studentClass,"<init>","(ILjava/lang/String;)V");
		jfieldID nameField=env->GetFieldID(studentClass,"name","Ljava/lang/String;");
		jfieldID ageField=env->GetFieldID(studentClass,"age","I");
         
	    STUDENT studentArray[2];
	    jobject student;
	    for(int i=0;i<len;i++){
          student= env->CallObjectMethod(students,getList,i);
		  studentArray[i].age=env->GetIntField(student,ageField);
		  studentArray[i].name=jstringToChar(env,(jstring)env->GetObjectField(student,nameField));
	    }
       STUDENT firstStudent=getFirstStudent(studentArray);
	   student=env->NewObject(studentClass,initStudent,firstStudent.age,charTojstring(env,firstStudent.name.c_str()));
	   return student;


}

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: ([Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudentInDll___3Ltest_Student_2
	(JNIEnv * env, jobject, jobjectArray students){	
		jclass studentClass=env->FindClass("Ltest/Student;");
		jfieldID nameField=env->GetFieldID(studentClass,"name","Ljava/lang/String;");
		jfieldID ageField=env->GetFieldID(studentClass,"age","I");
		jmethodID initStudent=env->GetMethodID(studentClass,"<init>","(ILjava/lang/String;)V");
		STUDENT studentArray[2];
		
		int length=   env->GetArrayLength(students);
		jobject student;
		for(int i=0;i<length;i++){
		  student=env->GetObjectArrayElement(students,i);
		  studentArray[i].age=env->GetIntField(student,ageField);
		  studentArray[i].name=jstringToChar(env,(jstring)env->GetObjectField(student,nameField));
		}
		STUDENT firstStudent=getFirstStudent(studentArray);
		student=env->NewObject(studentClass,initStudent,firstStudent.age,charTojstring(env,firstStudent.name.c_str()));
		return student;
}

/*
 * Class:     test_TestJni
 * Method:    sumAgeCallBack
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumAgeCallBack
	(JNIEnv * env, jobject testJni, jobject s1, jobject s2){
    jclass testJniClass = env->GetObjectClass(testJni);   
    jmethodID callback = env->GetMethodID(testJniClass,"sumAge","(Ltest/Student;Ltest/Student;)I");  
    int sum= env->CallIntMethod(testJni,callback,s1,s2); 
	return sum;

}


