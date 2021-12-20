#include"String.h"

#define delimeter cout<<"------------------\n";


//#define CONSTRUCTORS_CHECK
#define CLASS_WORK
//#define INPUT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSRTUCRS_CHECK 
	String str1; //Default constructor 
	str1.print();
	cout << str1 << endl;
	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;

	String str4 = str3;//Вызывается конструктор копирования
	cout << str4 << endl;

	String str5;
	str5 = str3;//Объект уже существует оператор присвоить
	cout << str5 << endl;
#endif // CONSRTUCRS_CHECK 
	
#ifdef CLASS_WORK
	delimeter;
	String str1 = "Hello";
	delimeter;
	String str2 = "World";
	delimeter;
	String str3 = str1 + str2;
	delimeter;
	cout << str3 << endl;
	delimeter;
	str1 += str2;
	cout << str1 << endl;
	delimeter;
	
#endif // CLASS_WORK
#ifdef INPUT_CHECK
	String str;
	cout << "Введите строку: ";// cin >> str;
	getline(cin, str);
	cout << str;
	delimeter;
	str.print();
#endif // INPUT_CHECK

}