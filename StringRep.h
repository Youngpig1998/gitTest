#ifndef STRINGREP_H
#define STRINGREP_H


class String;

class StringRep
{
	friend class String;
	StringRep(const char* s);  //���캯��
	~StringRep();   //��������
	size_t count; // ���ü���
	char *rep; //�ַ�ָ��
};





#endif // !STRINGREP_H


