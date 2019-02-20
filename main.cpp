#include <iostream>
#include <cstdlib>
#include <memory>
#include <new>
#include "Mystring.h"


using namespace std;


int
main()
{
	// String *pvc = new String("hi"); //会被编译器编译成如下形式
	String *pvc;
	void* mem = operator new(sizeof(String));   // 分配内存
	pvc = static_cast<String*>(mem);  // 转型
	pvc->String::String("sgjsgjddf"); // 调用构造函数,因为构造函数是public的
	//new(pvc)String("eiofhsdfnds");  这里也可以用placement new
	cout << *pvc << endl;
	cout << pvc->get_count() << endl;


	new(pvc)String("construct again!");// 调用placement new，它可以在已构造好的内存上再次构造对象，其底层其实是调用另一个版本的operator new（但其实不分配内存）
	//，然后转型，再像下面的写法一样调用构造函数
	//pvc->String::String("construct again!");  虽然这种写法也能通过，但不推荐用这种写法
	cout << *pvc << endl;

	// delete pvc; //会被编译器编译成如下形式
	pvc->~String(); // 先析构
	operator delete(pvc);  //再释放内存


	String *ps = new String[3];//array new,这里会调用3次默认构造函数
	String *test = ps;
	for (int i = 0; i < 3; ++i)
		new(test++)String("newobject");  // 调用 placement delete 重新构造
	// 打印
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