#include "StringRep.h"
#include <cstring>

StringRep::StringRep(const char* s) : count(1) //¹¹Ôìº¯Êý
{
	if (s == nullptr)
	{
		rep = new char[1];
		rep = '\0';
	}
	else
	{
		rep = new char[strlen(s) + 1];
		strcpy(rep, s);
	}
}




StringRep::~StringRep()
{
	delete[]rep;
}
