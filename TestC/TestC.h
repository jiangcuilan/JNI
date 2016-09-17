// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TESTC_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TESTC_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#include <string>
#ifdef TESTC_EXPORTS
#define TESTC_API __declspec(dllexport)
#else
#define TESTC_API __declspec(dllimport)
#endif

// 此类是从 TestC.dll 导出的
class TESTC_API CTestC {
public:
	CTestC(void);
	// TODO: 在此添加您的方法。
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
