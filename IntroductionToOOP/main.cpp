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
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
	}

	double distance(Point other)//другая точка
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
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//Point G;//Глобальный объект
int g;//Глобальная переменная
//#define STRUCT_POINT
#define CONSTRUCTORS_CHEK
//#define DISTANCE 
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
	cout << "Расстояние от точки А до точки В:" << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A:" << B.distance(A) << endl;
	cout << "Расстояние от точки А до точки В:" << distance(A, B) << endl;
	cout << "Расстояние от точки B до точки A:" << distance(B, A) << endl;
#endif // DISTANCE



}
