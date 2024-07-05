﻿//AbstractGeometry
#include<Windows.h>
#include<iostream>
using namespace std;


namespace Geometry
{
	enum Color  // enum (Enumeration) - это перечисление. Перечисление - это набор целочисленных констант
	{
		CONSOLE_BLUE = 0x99,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07
	};

	class Shape
	{
		Color color;
	public:
		Shape(Color color) :color(color) {}  //КОНСТРУКТОР И ВИРТ.ДЕСТРУКТОР
		virtual ~Shape() {}   // {}пустая реализация, если ставить ; то нужно где то реализовывать
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Color get_color()const { return color; }  //Geters
		void set_color(Color color) { this->color = color; }  //Seters
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Shapes  // Класс фигуры
	{
	public:
		virtual double area() const = 0;
		virtual double perimeter() const = 0;
		virtual void draw()const = 0;
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		virtual ~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна стороны: " << side << endl;
			Shape::info();
		}


	};

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) :Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		virtual ~Rectangle() {};
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return(width + height) * 2;
		}
		void draw()const override
		{
			for (int i = 0; i < width; i++)
			{
				for (int i = 0; i < height; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << get_width() << endl;
			cout << "Высота: " << get_height() << endl;
			Shape::info();
		}
	};
}

void main() //C2259 "Square" не удалось создать экземпляр                        абстрактоного класса
            //Е0322 Объект абстрактоного класса типа.квадрат не разрешён
{
	setlocale(LC_ALL, "Rus");
	//Shape shape(Color::CONSOLE_BLUE);
	Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
	/*cout << "Длинна стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Перимет квадрата: " << square.get_perimeter() << endl;*/
	square.info();

	Geometry::Rectangle rect(8, 15, Geometry:: Color::CONSOLE_RED);
	rect.info();
}
