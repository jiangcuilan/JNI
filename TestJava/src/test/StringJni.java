package test;

import java.util.ArrayList;
import java.util.List;

public class StringJni {
 
	static{
	     LibraryUtil.initLibrary(); 
	}
	
	public native static String get();  
	public native Student setStudent(Student student);
	public native Student getStudent();
	public native Student getStudent(int age,String name);
	public native int sumAge(Student s1,Student s2);	
	public native ArrayList<Student> createStudent(int[] age,String[] name);
	public native Student getFirstStudent(ArrayList<Student> students);
	public native Student getFirstStudent(Student[] students);
	public static void main(String[] args) {   
		 StringJni jni=new StringJni();
		 Student student=new Student(20, "jiangcuilan");
		 Student student2=new Student(20, "张三");
/*		 Student newstudent=jni.setStudent(student);
		 System.out.println(newstudent.getAge());
		 System.out.println(newstudent.getName());*/
		 System.out.println(jni.sumAge(student, student2));
		List<Student> students=jni.createStudent(new int[]{10,20}, new String[]{"a1","a2"});
		for(int i=0;i<students.size();i++){
			System.out.println(students.get(i).getAge()+":"+students.get(i).getName());
		}
		 
	 }   
}
