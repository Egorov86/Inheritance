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
	virtual void draw()const = 0;
};

class Square :public Shapes  //�������
{
private:
	double a = 3;
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
		double S = a*2;
		cout << "������� ��������: " << S << endl;
		return S;
	}
	double perimeter()const
	{
		double P = (a + a) * 2;
		cout << "�������� ��������: " << P << endl;
		return P;
	}
	void draw()const override
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				cout << " +";
			}
			cout << endl;
		}
	}

}; 

class Rectangle : public Shapes //�������������
{ 
private:
	double a = 3;
	double b = 5;
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
	void draw()const override
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << " +";
			}
			cout << endl;
		}
	}

};

class Circle :public Shapes  //����
{
private:
	double r = 5;
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
	void draw()const override
	{
		for (int i = 0; i < (r*r); i++)
		{
			for (int j = 0; j < (r*r); j++)
			{
				if ((i - r) * (i - r) + (j - r) * (j - r) <  r*r)cout << " +";
				//if (i - r)*(i - r) + (j + r) * (j + r) <= (2 * r)cout << "+";
				else cout << "  ";
			}
			cout << endl;
		}
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
	square.draw();
	
	cout << delimiter << endl;
	
	Rectangle restangle;
	restangle.area();
	restangle.perimeter();
	restangle.draw();

	cout << delimiter << endl;

	Circle circle;
	circle.area();
	circle.perimeter();
	circle.draw();

	cout << delimiter << endl;
	/*
	Triangle triangle;
	triangle.area();
	triangle.perimeter();
	cout << "������� � = " << triangle.get_a() << endl;*/
}