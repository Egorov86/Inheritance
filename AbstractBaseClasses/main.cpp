//Geometric_Shapes
#include<iostream>
#include<cmath>

using namespace std;

#define delimiter "\n--------------------------\n"

class Shapes
{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

	// CONSTRUCTOR
};

class Square :public Shapes  //�������
{
private:
	double a = 2;
public:
	const double get_a()const
	{
		return a;
	}
	void set_a()
	{
		this->a = a;
	}
	double area()const
	{
		double S = (a*a)*2;
		cout << "������� ��������: " << S << endl;
		return S;
	}
	double perimeter()const
	{
		double P = (a + a) * 2;
		cout << "�������� ��������: " << P << endl;
		return P;
	}

}; 

class Rectangle : public Shapes //�������������
{ 
private:
	double a = 2;
	double b = 3.4;
public:
	const double ger_a()const
	{
		return a;
	}
	const double ger_b()const
	{
		return b;
	}
	void set_a()
	{
		this->a = a;
	}
	void set_b()
	{
		this->b = b;
	}
	double area()const
	{
		double P = (a + b) * 2;
		cout << "�������� ��������������: " << P << endl;
		return P;
	}
	double perimeter()const
	{
		double S = (a * b) * 2;
		cout << "������� ��������������: " << S << endl;
		return S;
	}

};

class Circle :public Shapes  //����
{
private:
	double r = 2.3;
public:
	const double Pi = 3.14;
	const double get_r()const
	{
		return r;
	}
	void set_r()
	{
		this->r = r;
	}
	double area()const
	{
		double S = Pi * r*r;
		cout << "������� �����: " << S << endl;
		return S;
	}
	double perimeter()const
	{
		double C = 2 * Pi * r;
		cout << "�������� �����: " << C << endl;
		return C;
	}

};

class Triangle : public Shapes  //����������
{
private:
	double a = 2.4;
	double b = 3;
	double c = 2.5;
public:
	const double get_a()const
	{
		return a;
	}
	void set_a()
	{
		this->a = a;
	}
	const double get_b()const
	{
		return b;
	}
	void set_b()
	{
		this->b = b;
	}
	const double get_c()const
	{
		return c;
	}
	void set_c()
	{
		this->c = c;
	}
	double area()const
	{
		double PP = (a + b + c) / 2;
		double S = sqrt(PP*((PP-a)*(PP-b)*(PP-c))); //������� ������
		cout << "������� ������������: " << S << endl;
		return S;
	}
	double perimeter()const
	{
		double P = a + b + c;
		cout << "�������� ������������: " << P << endl;
		return P;
	}

};


void main()
{
	setlocale(LC_ALL, "Rus");
	Square square;
	square.area();
	square.perimeter();
	
	cout << delimiter << endl;
	
	Rectangle restangle;
	restangle.area();
	restangle.perimeter();

	cout << delimiter << endl;

	Circle circle;
	circle.area();
	circle.perimeter();

	cout << delimiter << endl;

	Triangle triangle;
	triangle.area();
	triangle.perimeter();
}