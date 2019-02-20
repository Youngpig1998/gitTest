#ifndef STRINGREP_H
#define STRINGREP_H


class String;

class StringRep
{
	friend class String;
	StringRep(const char* s);  //构造函数
	~StringRep();   //析构函数
	size_t count; // 引用计数
	char *rep; //字符指针
};





#endif // !STRINGREP_H


