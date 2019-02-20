#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class StringRep;

// 委托delegation  或者叫Composition by reference 委托的话，因为含有的是指向另一个类的指针，所以生命周期不同步
//委托思想中一个非常有名的设计模式是pImpl(又叫Handle/body)，一个类用于设计接口，其中包含一个指向用于实现的类。指针
//可以指向任何的实现,即实现可以改变
//这里也运用了COW(Copy On Write)技术
class String
{
public:
	String(const char*  = nullptr);//含有默认实参的构造函数
	String(const String&);//拷贝构造
	String& operator=(const String&);  // 拷贝赋值
	~String();//析构函数
	char* get_ctr() const;  //返回字符串指针
	size_t get_count() const; // 返回引用计数  
	//char& operator[](size_t i);

private:
	void free(); //用于析构
	StringRep* data;
};

std::ostream& operator<<(std::ostream&, const String&);


#endif

