#include "StringRep.h"
#include "Mystring.h"
#include <cstring>
#include <iostream>


String::String(const char* temp) : data(new StringRep(temp))  { }   //含有默认实参的构造函数

String::String(const String& s) : data(s.data) //拷贝构造
{ 
	data->count++;
}  

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;
	free();
	data = rhs.data;
	data->count++;
	return *this;
}

String::~String() //析构函数
{
	free();
}


//char& String::operator[](size_t i)
//{
//	return *(data + i);
//}

char* String::get_ctr() const { return data->rep; };  //返回字符串指针

size_t String::get_count() const { return data->count; }  // 返回引用计数 

void String::free()
{
	data->count -= 1;
	if (data->count == 0)
		delete data;
}

std::ostream& operator<<(std::ostream &os, const String &s) //重载输出运算符
{
	os << s.get_ctr();
	return os;
}
