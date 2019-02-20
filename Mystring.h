#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class StringRep;

// ί��delegation  ���߽�Composition by reference ί�еĻ�����Ϊ���е���ָ����һ�����ָ�룬�����������ڲ�ͬ��
//ί��˼����һ���ǳ����������ģʽ��pImpl(�ֽ�Handle/body)��һ����������ƽӿڣ����а���һ��ָ������ʵ�ֵ��ࡣָ��
//����ָ���κε�ʵ��,��ʵ�ֿ��Ըı�
//����Ҳ������COW(Copy On Write)����
class String
{
public:
	String(const char*  = nullptr);//����Ĭ��ʵ�εĹ��캯��
	String(const String&);//��������
	String& operator=(const String&);  // ������ֵ
	~String();//��������
	char* get_ctr() const;  //�����ַ���ָ��
	size_t get_count() const; // �������ü���  
	//char& operator[](size_t i);

private:
	void free(); //��������
	StringRep* data;
};

std::ostream& operator<<(std::ostream&, const String&);


#endif

