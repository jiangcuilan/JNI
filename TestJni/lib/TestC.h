// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TESTC_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TESTC_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#include <string>
#ifdef TESTC_EXPORTS
#define TESTC_API __declspec(dllexport)
#else
#define TESTC_API __declspec(dllimport)
#endif

// �����Ǵ� TestC.dll ������
class TESTC_API CTestC {
public:
	CTestC(void);
	// TODO: �ڴ�������ķ�����
};
struct STUDENT{
	std::string name;
	int age;
};
TESTC_API class StudentO{
	 int sumAge(STUDENT* st1, STUDENT* st2);
	 STUDENT* getStudent(int age,std::string& name);
};

TESTC_API int sumStudentAge(STUDENT* st1, STUDENT* st2);


TESTC_API STUDENT* getStudent(int* ages, std::string  *names );

extern TESTC_API int nTestC;

TESTC_API int fnTestC(void);
