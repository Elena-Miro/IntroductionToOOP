#include"String.h"

int String::get_size()const   //Scope operator
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};//Память для строки обязательно зануляем
	cout << "Constructor:\t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)//Побитовое копирование Deep copy
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}
String::~String()
{
	delete[]str;
	cout << "Destructor:\t" << this << endl;

}
//Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;//не являются ли this и other одним и тем же объектом
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
char& String:: operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i) const//если пишем в конце const то и в начале
{
	return str[i];
}
String& String:: operator+=(const String& other)
{
	return *this = *this + other;
}
//Metods

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);//убираем 1 детерминрующий ноль
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;


}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	/*is.getline(obj.get_str(), 80);
	int size = strlen(obj.get_str()) + 1;
	String str(size);//Создаем объект
	for (int i = 0; i < size; i++)
	{
		str[i] = obj[i];
	}
	obj = str;//Присваивает значения объекта obj
	return is;*/
	//return is >> obj.get_str();
	const int SIZE = 10240;
	char buffer[SIZE] = {};
	is >> buffer;//is=cin ввод с клавиатуры
	obj = buffer;
	return is;
}
std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 10240;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}