#pragma warning(disable:4326)
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;//Отфильтровывает 0
		this->denominator = denominator;
	}
	
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		denominator = 1e+9;//Экспонента системы счисления
		numerator = (decimal - integer) * denominator;
		reduce();
	}

	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator,int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	//Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer+(double)numerator/denominator;
	}

	Fraction& to_improper()//Переводит дробь в правильную
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//Переводит дробь в неправильную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& reduce()
	{
		if (numerator == 0) return *this;
		int more, less;
		int rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // GCD - greatest common divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		return Fraction(this->denominator, this->numerator);
	}
	
	
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
		).to_proper().reduce();
	/*result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	//result.to_proper();
	//result.reduce();
	//return result;
}
Fraction operator/(Fraction left,Fraction right)
{
	return left * right.inverted();
}
Fraction operator+(Fraction right, Fraction left)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator()*right.get_denominator()+
		right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();

}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator() * right.get_denominator() -
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
	
}
bool operator!=(Fraction left, Fraction right)
{
	
	return !(left == right);

}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(Fraction left, Fraction right)
{
	return !(left < right);
}
bool operator<=(Fraction left, Fraction right)
{
	return !(left > right);
}

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;//Конструктор по умолчанию
	A.print();
	double b = 5;
	Fraction B = 5;
	B.print();
	Fraction C(3, 4);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	/*int a, b;
	cout << "Введите 2 числа: "; cin >> a >> b;
	cout << a / b << endl;*/
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK

	double a = 2.5;
	double b = 3.4;
	double c = a * b;
	cout << c << endl;
	cout << "_____________________________" << endl;
	Fraction A(2, 1, 2);
	Fraction B(3, 2, 5);
	Fraction C = A * B;
	C.reduce();
	C.print();
	cout << "_____________________________" << endl;
	C = A / B;
	C.print();
	cout << "_____________________________" << endl;
	//A *= B;
	//A.print();
	cout << "_____________________________" << endl;
	C = A + B;
	C.print();
	cout << "_____________________________" << endl;
	C =A-B;
	C.print();
	cout << "_____________________________" << endl;
	C += B;
	C.print();
	cout << "_____________________________" << endl;
	C -= B;
	C.print();
	cout << "_____________________________" << endl;
	C /= B;
	C.print();
	cout << "_____________________________" << endl;
	if (A == B)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "_____________________________" << endl;
	if (A != B)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "_____________________________"<<endl;
	A.print();
	B.print();
	if (A > B)
		
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "_____________________________" << endl;
	A.print();
	B.print();
	if (A < B)

		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "_____________________________" << endl;
	
	A.print();
	B.print();
	if (A >= B)

		cout << "true" << endl;
	else
		cout << "false" << endl;
	A.print();
	B.print();
	if (A <= B)

		cout << "true" << endl;
	else
		cout << "false" << endl;
#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2; //нет преобразования
	double b = 3; // from less to more
	int c = b;//из большего в меньшее из double 
	int d = 4.5;// от большего к меньшему с потерей данных
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	double a = 2;//from int to double
	Fraction A = 5;//from int to Fraction
	//single-argument construction
	A.print();
	Fraction B;
	B = 8;
	B.print();
	//Fraction C = 12;no
	Fraction C(12);
	Fraction D{ 13 };//или так  
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
	//Fraction A(2);
	//int a (A);
	//cout << a << endl;

	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;


	double b = 2.75;
	Fraction B = b; //преобразуем другой тип в наш, нуужен конструктор с 1 параметром типа double
	B.print();


}
