#include <iostream>
#include <cstdlib>
#include <memory>
#include <new>
#include "Mystring.h"


using namespace std;


int
main()
{
	// String *pvc = new String("hi"); //�ᱻ�����������������ʽ
	String *pvc;
	void* mem = operator new(sizeof(String));   // �����ڴ�
	pvc = static_cast<String*>(mem);  // ת��
	pvc->String::String("sgjsgjddf"); // ���ù��캯��,��Ϊ���캯����public��
	//new(pvc)String("eiofhsdfnds");  ����Ҳ������placement new
	cout << *pvc << endl;
	cout << pvc->get_count() << endl;


	new(pvc)String("construct again!");// ����placement new�����������ѹ���õ��ڴ����ٴι��������ײ���ʵ�ǵ�����һ���汾��operator new������ʵ�������ڴ棩
	//��Ȼ��ת�ͣ����������д��һ�����ù��캯��
	//pvc->String::String("construct again!");  ��Ȼ����д��Ҳ��ͨ���������Ƽ�������д��
	cout << *pvc << endl;

	// delete pvc; //�ᱻ�����������������ʽ
	pvc->~String(); // ������
	operator delete(pvc);  //���ͷ��ڴ�


	String *ps = new String[3];//array new,��������3��Ĭ�Ϲ��캯��
	String *test = ps;
	for (int i = 0; i < 3; ++i)
		new(test++)String("newobject");  // ���� placement delete ���¹���
	// ��ӡ
	String *test2 = ps;
	for (int i = 0; i < 3; ++i)
		cout << *test2++ << endl;
	delete[]ps;  //   array delete
	

	String s1("hello");
	cout << s1 << endl;
	cout << s1.get_count() << endl;
	{
		String s2(s1);
		cout << s2 << endl;
		cout << s2.get_count() << endl;
	}
	cout << s1 << endl;
	cout << s1.get_count() << endl;

	String s("hfiuwehf");
	cout << s << endl;
	cout << s.get_count() << endl;

	s = s1;

	cout << s << endl;
	cout << s.get_count() << endl;

	system("pause");
	return 0;
}