#include<iostream>
using namespace std;
#define tab "\t"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstuctor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:\t" << this << endl;
	}*/
	Point(double x=0,double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)//Постфиксное значение инкремента
	{
		Point old = *this;//сохраняем старое значение объекта
		x++;
		y++;
		return old;//старое не изменяемое значение объекта
	}

	double distance(const Point& other)const//другая точка
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	
	void print()const
	{
		cout << "X= " << x << "\tY=" << y << endl;
	}
};
double distance(const Point& A,const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}


//Point G;//Глобальный объект
int g;//Глобальная переменная
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHEK
//#define DISTANCE 
//#define ASSIGNEMENT_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	int a;
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHEK
	Point A;
	/*A.set_x(2);
	A.set_y(3);*/
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(4, 5);
	B.print();

	Point C = 5;//single argument constructor
	C.print();
	Point D(8);
	D.print();
	Point E = D;
	E.print();
	Point F(B);
	F.print();
	Point G;
	G = F;//CopyAssiment(operator=)
	G.print();
#endif // CONSTRUCTORS_CHEK
#ifdef DISTANCE
	Point A(2, 3);
	Point B(3, 4);
	cout << "\n----------------------------------------------\n";
	cout << "Расстояние от точки А до точки В:" << A.distance(B) << endl;
	cout << "\n----------------------------------------------\n";
	cout << "Расстояние от точки B до точки A:" << B.distance(A) << endl;
	cout << "\n----------------------------------------------\n";
	cout << "Расстояние от точки А до точки В:" << distance(A, B) << endl;
	cout << "\n----------------------------------------------\n";
	cout << "Расстояние от точки B до точки A:" << distance(B, A) << endl;
	cout << "\n----------------------------------------------\n";
#endif // DISTANCE
#ifdef ASSIGNEMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c;

	Point A, B, C;
	cout << "\n----------------------------------------------\n";
	A = B = C = Point(2, 3);
	//Point(2,3)явно вызываем конструктор, который создает временный безымянный объект 
	cout << "\n----------------------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNEMENT_CHECK
	int a = 2;
	int b = 4;
	int c = a+b;
	Point A(2, 3);
	Point B(4, 5);
	/*Point C = A + B;
	C.print();
	C++;
	C.print();*/
	B = ++A;
	A.print();
	B.print();
}
