#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
std::istream& getline(std::istream& is, String& obj);
class String
{
	int size;//Размер строки Размер строки в байтах
	char* str;//Адрес строки в динамической памяти

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	~String();
	//Operators
	String& operator=(const String& other);
	char& operator[](int i);
	const char& operator[](int i) const;
	String& operator+=(const String& other);
	//Metods

	void print()const;
};