
#include "../lib/jni.h"
#include "CommUtils.h"
#include<iostream>
#include<Windows.h>
#include <IOSTREAM>

// ����jvm��c++�����ĵı��벻һ���������Ҫת�롣 utf8/16ת����gb2312
char* jstringToChar(JNIEnv *env, jstring jstr) {
	
    int length = (env)->GetStringLength(jstr);
    const jchar* jcstr = (env)->GetStringChars(jstr, 0);
    char* rtn = (char*) malloc(length * 2 + 1);
    int size = 0;
    size = WideCharToMultiByte( CP_ACP, 0, (LPCWSTR) jcstr, length, rtn,(length * 2 + 1), NULL, NULL);
    if (size <= 0)
        return NULL;
    (env)->ReleaseStringChars(jstr, jcstr);
    rtn[size] = 0;
    return rtn;
}

// ����jvm��c++�����ĵı��벻һ���������Ҫת�롣gb2312ת����utf8/16
jstring charTojstring(JNIEnv* env, const char* str) {
    jstring rtn = 0;
    int slen = strlen(str);
    unsigned short * buffer = 0;
    if (slen == 0)
        rtn = (env)->NewStringUTF(str);
    else {
        int length = MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, NULL, 0);
        buffer = (unsigned short *) malloc(length * 2 + 1);
        if (MultiByteToWideChar( CP_ACP, 0, (LPCSTR) str, slen, (LPWSTR) buffer, length) > 0)
            rtn = (env)->NewString((jchar*) buffer, length);
        // �ͷ��ڴ�
        free(buffer);
    }
    return rtn;
}
