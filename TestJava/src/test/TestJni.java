package test;

import java.util.ArrayList;
import java.util.List;

public class TestJni {
	static {
		LibraryUtil.initLibrary();
	}

	public static void main(String[] args) {
		TestJni jni = new TestJni();
		System.out.println("getStringInJni:" + jni.getStringInJni("hanmeimei"));
		System.out.println("getStringInDll:" + jni.getStringInDll("lilei"));

		Student newS = jni.getStudentInJni(5, "hanjiacheng0");
		System.out.println("getStudentInJniByAgeAndName:" + newS.getName() + "," + newS.getAge());
		newS = jni.getStudentInDll(5, "hanjiacheng1");
		System.out.println("getStudentInDllByAgeAndName:" + newS.getName() + "," + newS.getAge());

		Student s1 = new Student(30, "hanliangliang");
		newS = jni.getStudentInJni(s1);
		System.out.println("getStudentInJniByStudent:" + newS.getName() + "," + newS.getAge());
		newS = jni.getStudentInDll(s1);
		System.out.println("getStudentInDllByStudent:" + newS.getName() + "," + newS.getAge());

		Student s2 = new Student(5, "hanjiacheng");
		int age = jni.sumStudentAgeInJni(s1, s2);
		System.out.println("sumStudentInJni:" + age);
		age = jni.sumStudentAgeInDll(s1, s2);
		System.out.println("sumStudentInDll:" + age);

		ArrayList<Student> students = jni.getStudentsInJni(new int[] { 10, 20 }, new String[] { "a1", "a2" });
		for (int i = 0; i < students.size(); i++) {
			System.out.println("getStudentsInJniByAgeAndName:"+students.get(i).getAge() + ":" + students.get(i).getName());
		}
		students = jni.getStudentsInDll(new int[] { 10, 20 }, new String[] { "a1", "a2" });
		for (int i = 0; i < students.size(); i++) {
			System.out.println("getStudentsInDllByAgeAndName:"+students.get(i).getAge() + ":" + students.get(i).getName());
		}

		s1=jni.getFirstStudentInJni(students);
		System.out.println("getFirstStudentInJniByList:"+s1.getAge() + ":" + s1.getName());	
		
		s1=jni.getFirstStudentInDll(students);
		System.out.println("getFirstStudentInDllByList:"+s1.getAge() + ":" + s1.getName());	

		
		Student [] students2={new Student(10, "a111"),new Student(10, "a222")};
		s1=jni.getFirstStudentInJni(students2);
		System.out.println("getFirstStudentInJniByArray:"+s1.getAge() + ":" + s1.getName());
		
		s1=jni.getFirstStudentInDll(students2);
		System.out.println("getFirstStudentInDllByArray:"+s1.getAge() + ":" + s1.getName());	
	
		s1 = new Student(30, "hanliangliang");
		s2 = new Student(5, "hanjiacheng");
		
		System.out.println(jni.sumAgeCallBack(s1, s2));
		
        new Thread(new Runnable(){
            public void run(){
            	List<Student> students=jni.getStudentsInDll(new int[] { 10, 20 }, new String[] { "a1", "a2" });
        		
        		System.out.println(jni.sumAgeCallBack(students.get(0), students.get(1)));
            }
        }).start();
        
		
        new Thread(new Runnable(){
            public void run(){
            	List<Student> students=jni.getStudentsInDll(new int[] { 100, 200 }, new String[] { "a11", "a22" });
        		
        		System.out.println(jni.sumAgeCallBack(students.get(0), students.get(1)));
            }
        }).start();
		
		/*
		
		students = jni.getStudentsInJni(new int[] { 10, 20 }, new String[] { "a11", "a22" });
		s1=jni.getFirstStudentInJni(students);
		System.out.println("getFirstStudent:"+s1.getAge() + ":" + s1.getName());
		
		Student [] students2={new Student(10, "a111"),new Student(10, "a222")};
		s1=jni.getFirstStudentInJni(students2);
		System.out.println("getFirstStudent:"+s1.getAge() + ":" + s1.getName());*/
		
		/*
		 * Student newstudent=jni.setStudent(student);
		 * System.out.println(newstudent.getAge());
		 * System.out.println(newstudent.getName());
		 * System.out.println(jni.sumAge(student, student2)); List<Student>
		 * students=jni.createStudent(new int[]{10,20}, new
		 * String[]{"a1","a2"}); for(int i=0;i<students.size();i++){
		 * System.out.println(students.get(i).getAge()+":"+students.get(i).
		 * getName()); }
		 */

	}

	// 传入字符串获取字符串
	public native String getStringInJni(String str);

	// 传入字符串获取字符串
	public native String getStringInDll(String str);

	// 传入int和string获取对象
	public native Student getStudentInJni(int age, String name);

	// 传入int和string获取对象
	public native Student getStudentInDll(int age, String name);

	// 传入对象获取对象
	public native Student getStudentInJni(Student student);

	// 传入对象获取对象
	public native Student getStudentInDll(Student student);

	// 传入两个对象，将年龄相加
	public native int sumStudentAgeInJni(Student s1, Student s2);

	// 传入两个对象，将年龄相加
	public native int sumStudentAgeInDll(Student s1, Student s2);

	// 传入int和String在jni中返回对象
	public native ArrayList<Student> getStudentsInJni(int[] age, String[] name);

	// 传入int和String在jni中返回对象
	public native ArrayList<Student> getStudentsInDll(int[] age, String[] name);

	// 传入对象获取第一个对象
	public native Student getFirstStudentInJni(ArrayList<Student> students);
	// 传入对象获取第一个对象
	public native Student getFirstStudentInDll(ArrayList<Student> students);
	// 传入对象数组获取第一个对象
	public native Student getFirstStudentInJni(Student[] students);
	// 传入对象数组获取第一个对象
	public native Student getFirstStudentInDll(Student[] students);
	

	

	


	// 通过回调加年龄
	public native int sumAgeCallBack(Student s1, Student s2);
	
	
	
	public int sumAge(Student s1,Student s2){
		if(s1!=null&&s2!=null)
			return s1.getAge()+s2.getAge();
		return 0;
	}
}
