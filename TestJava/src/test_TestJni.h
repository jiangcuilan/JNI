/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class test_TestJni */

#ifndef _Included_test_TestJni
#define _Included_test_TestJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     test_TestJni
 * Method:    getStringInJni
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test_TestJni_getStringInJni
  (JNIEnv *, jobject, jstring);

/*
 * Class:     test_TestJni
 * Method:    getStringInInDll
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_test_TestJni_getStringInInDll
  (JNIEnv *, jobject, jstring);

/*
 * Class:     test_TestJni
 * Method:    getStudentInJni
 * Signature: (ILjava/lang/String;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInJni__ILjava_lang_String_2
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     test_TestJni
 * Method:    getStudentInDll
 * Signature: (ILjava/lang/String;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInDll__ILjava_lang_String_2
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     test_TestJni
 * Method:    getStudentInJni
 * Signature: (Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInJni__Ltest_Student_2
  (JNIEnv *, jobject, jobject);

/*
 * Class:     test_TestJni
 * Method:    getStudentInDll
 * Signature: (Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentInDll__Ltest_Student_2
  (JNIEnv *, jobject, jobject);

/*
 * Class:     test_TestJni
 * Method:    sumStudentInJni
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumStudentInJni
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     test_TestJni
 * Method:    sumStudentInDll
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumStudentInDll
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     test_TestJni
 * Method:    getStudentsInJni
 * Signature: ([I[Ljava/lang/String;)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentsInJni
  (JNIEnv *, jobject, jintArray, jobjectArray);

/*
 * Class:     test_TestJni
 * Method:    getStudentsInDll
 * Signature: ([I[Ljava/lang/String;)Ljava/util/ArrayList;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getStudentsInDll
  (JNIEnv *, jobject, jintArray, jobjectArray);

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: (Ljava/util/ArrayList;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudent__Ljava_util_ArrayList_2
  (JNIEnv *, jobject, jobject);

/*
 * Class:     test_TestJni
 * Method:    getFirstStudent
 * Signature: ([Ltest/Student;)Ltest/Student;
 */
JNIEXPORT jobject JNICALL Java_test_TestJni_getFirstStudent___3Ltest_Student_2
  (JNIEnv *, jobject, jobjectArray);

/*
 * Class:     test_TestJni
 * Method:    sumAgeCallBack
 * Signature: (Ltest/Student;Ltest/Student;)I
 */
JNIEXPORT jint JNICALL Java_test_TestJni_sumAgeCallBack
  (JNIEnv *, jobject, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
