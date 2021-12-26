#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Binary
{
	unsigned int capacity;
	bool* number;
public:
	unsigned int get_capacity()const
	{
		return capacity;
	}
	const bool* get_number()const
	{
		return number;
	}
	bool* get_number()
	{
		return number;
	}
	void set_capacity(int capacity)
	{
		if (capacity > 32)capacity = 32;
		bool* new_number = new bool[capacity] {};
		for (int i = 0; i < (this->capacity < capacity ? this->capacity : capacity); i++)
			new_number[i] = this->number[i];
		this->capacity = capacity;
		delete[]this->number;
		
		this->number = new_number;

	}


		Binary()
	{
		capacity = 8;
		number = new bool[capacity] {};
		std::cout << "DefaultConstruct:" << this << std::endl;
	}

	Binary(int decimal)
	{
		int buffer = decimal;
		capacity = 0;
		for (; buffer; capacity++)
			buffer /= 2;

		if (capacity <= 8)
			capacity = 8;
		else if (capacity <= 16)
			capacity = 16;
		else if (capacity <= 24)
			capacity = 24;
		else if (capacity <=32)
			capacity = 32;

		number = new bool[capacity] {};

		for (int i = 0; decimal; ++i)
		{
			number[i] = decimal % 2;
			decimal /= 2;
		}
	}
	Binary(const Binary& other)
	{
		this->capacity = other.capacity;
		this->number = new bool[capacity] {};
		for (int i = 0; i < capacity; i++)
		{
			this->number[i] = other.number[i];
		}
		cout << "CopyConstructor:" << this<<endl;
	}
	Binary(Binary&& other)
	{
		this->capacity = other.capacity;
		this->number = other.number;
		other.number = nullptr;
		other.capacity = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~Binary()
	{
		delete[] number;
		number = nullptr;
		capacity = 0;
		std::cout << "Destructor:" << this << std::endl;
	}
	Binary& operator=(const Binary& other)
	{
		if (this == &other)return *this;
		delete[] this->number;
		this->capacity = other.capacity;
		this->number = new bool[capacity] {};
		for (int i = 0; i < capacity; i++)this->number[i] = other.number[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Binary& operator=(Binary&& other)
	{
		if (this == &other)return *this;
		delete[] number;
		this->capacity = other.capacity;
		this->number = other.number;
		other.number = nullptr;
		other.capacity = 0;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	Binary operator~()const
	{
		Binary inversion = *this;
		for (int i = 0; i < capacity; i++)
		{
			/*if (inversion.number[i] == 1)inversion.number[i] = 0;
			else inversion.number[i] = 1;*/
			inversion.number[i] = inversion.number[i] ? 0 : 1;
		}
		return inversion;
	}
	

	std::ostream& print(std::ostream& os = std::cout)const
	{
		if (capacity == 8)	os.width(11 * 3);
		if (capacity == 16)	os.width(11 * 2);
		if (capacity == 24)	os.width(11);
		/*os.width(35);*/
		for (int i = capacity - 1; i >= 0; i--)
		{
			os << number[i];
			if (i % 8 == 0)
				std::cout << " ";
			if (i % 4 == 0)
				std::cout << " ";
		}
		return os;
	}





};

Binary operator| (const Binary& left, const Binary& right)
{
	Binary result;
	//oпределяем большую и меньшую разрядность
	int capacity = 0;
	int max_capacity = left.get_capacity() < right.get_capacity() ? right.get_capacity() : left.get_capacity();
	int min_capacity= left.get_capacity() > right.get_capacity() ? right.get_capacity() : left.get_capacity();
	//задаем результату большую разрядность
	result.set_capacity(max_capacity);
	//проходим по минимальной разрядности и записываем минимальное большинство разрядов в результат
	for (int i = 0; i < min_capacity; i++)
		result.get_number()[i] = (left.get_number()[i]==1 || right.get_number()[i]==1) ? 1 : 0;
	// Проходим по большей разрядности и копируем оставшиеся разряды в результат
	for (int i = min_capacity; i < max_capacity; i++)
	result.get_number()[i] = left.get_capacity() > right.get_capacity() ? left.get_number()[i] : right.get_number()[i];
	return result;
}

std::ostream& operator<<(std::ostream& os, const Binary& obj)
{

	return obj.print(os);
}

//#define CONSRUCTOR

void main()
{
	setlocale(LC_ALL, "Rus");
	Binary num1;
#ifdef CONSRUCTOR
	num1.print();
	std::cout << std::endl;



	Binary num2 = 380;
	std::cout << num2 << std::endl;
	Binary num3 = num2;
	cout << ~num3 << endl;
#endif // CONSRUCTOR
	Binary bin1 = 202;
	Binary bin2 = 27;
	cout << (bin1 | bin2) << endl;
}