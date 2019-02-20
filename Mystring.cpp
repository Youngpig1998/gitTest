#include "StringRep.h"
#include "Mystring.h"
#include <cstring>
#include <iostream>


String::String(const char* temp) : data(new StringRep(temp))  { }   //����Ĭ��ʵ�εĹ��캯��

String::String(const String& s) : data(s.data) //��������
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

String::~String() //��������
{
	free();
}


//char& String::operator[](size_t i)
//{
//	return *(data + i);
//}

char* String::get_ctr() const { return data->rep; };  //�����ַ���ָ��

size_t String::get_count() const { return data->count; }  // �������ü��� 

void String::free()
{
	data->count -= 1;
	if (data->count == 0)
		delete data;
}

std::ostream& operator<<(std::ostream &os, const String &s) //������������
{
	os << s.get_ctr();
	return os;
}
