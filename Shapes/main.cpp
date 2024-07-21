//AbstractGeometry
#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include<math.h>
#include<winuser.h>
//#include <cstdlib> //для случайного выбора вершин треугольника
using namespace std;


namespace Geometry
{
	enum Color  // enum (Enumeration) - это перечисление. Перечисление - это набор целочисленных констант
	{
		RED = 0x000000FF,
		DARK_RED = 0x00000077,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
		YELLOW = 0X0000FFFF,
		PURPLE = 0X00FF00FF,
		CONSOLE_BLUE = 0x09,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07,
	};
#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color
#define delimiter "\n--------------------------\n"
	class Shape
	{
	protected: //Защищенные поля, доступны только внутри класса и внутри его дочерних классов//благодяря protected к этим полям можно будет обращаться напрямую в дочерних классах(без гет/сет методов)
		Color color;
		unsigned int start_x; //координаты по которым будет выводиться фигура
		unsigned int start_y; //в любой графич оболочке координаты задаются в пикселях
		//Начало координат всегда находится в левом верхнем углу.
		unsigned int line_width; //толщина линии, которoй будет рисоваться контур фигуры
		static const int MIN_START_X = 100;  //Статическая константа 
		static const int MAX_START_X = 1000;
		static const int MIN_START_Y = 50;
		static const int MAX_START_Y = 900;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 3;
		static const int MIN_SIZE = 5;
		static const int MAX_SIZE = 60;
		//static const int MIN_RADIUS = 10;
		//static const int MAX_RADIUS = 50;
		static int count;
	public:
		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			count++;
		}  //КОНСТРУКТОР И ВИРТ.ДЕСТРУКТОР
		virtual ~Shape()
		{
			count--;
		}   // {}пустая реализация, если ставить ; то нужно где то реализовывать
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		static int get_count()
		{
			return count;
		}

		Color get_color()const { return color; }  //Geters
		void set_color(Color color) { this->color = color; }  //Seters
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_x < MIN_START_Y)start_x = MIN_START_Y;
			if (start_x > MAX_START_Y)start_x = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}
		double filter_size(double size)
		{
			if (size < MIN_SIZE) size = MIN_SIZE;
			if (size > MAX_SIZE) size = MAX_SIZE;
			return size;
		}
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
	int Shape::count = 0;
	/*class Square :public Shape
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


	};*/

	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) // принимаемые параметры - GIVE
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
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio"); //РИСУЕТ В ОКНЕ VS
			//HWND hwnd = GetConsoleWindow(); РИСУЕТ В ОКНЕ ВЫЗОВА
			//HWND hwnd = GetConsoleWindow(); 1)Получаем дескриптор окна консоли. Переменная в которой хранится описание чего-то.
			//description 
			//HWND - Handler to Window(обработчик или дескриптор окна)
			HDC hdc = GetDC(hwnd); //2) получаем контекст устройства (Device context) окна консоли
			//DC - это то на чем мы будем рисовать
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());
			//3) Создаем карандаш, Pen рисует контур фигуры
			//PS_SOLID - сплошная линия
			//5-толщина линии в пикселях
			// 4) cоздаем кисточку
			HBRUSH hBrush = CreateSolidBrush(get_color());
			//5) Выбираем чем и на чем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) Рисуем прямоугольник:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			//start_x, start_y -координаты верхнего левого угла
			// 800, 350 - координаты нижнего парвого угла
			//чтобы показать что это глобальная функция надо поставить двойное двоеточие без операнда слева.
			//7) Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
			/*for (int i = 0; i < height; i++)
			{
				for (int i = 0; i < width; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}*/
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
			this->width = filter_size(width);
		}
		void set_height(double height)
		{
			this->height = filter_size(height);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << get_width() << endl;
			cout << "Высота: " << get_height() << endl;
			Shape::info();
		}
	};
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {} //делегируем прямоугольник с шириной и высотой и цвет

	};
	class Circle :public Shape
	{
	private:
		double rad;
	public:
		//const double Pi = 3.14;
		Circle(double rad, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_rad(rad);
		}
		virtual ~Circle() {}
		double get_rad()const
		{
			return rad;
		}
		void set_rad(double rad)
		{
			//if (rad < MIN_RADIUS) rad = MIN_RADIUS;
			//if (rad > MAX_RADIUS) rad = MAX_RADIUS;
			this->rad = filter_size(rad);
		}
		double get_area()const override
		{
			return M_PI * rad * rad;
		}
		double get_perimeter()const override
		{
			return(M_PI * rad) * 2;
		}
		void draw()const override
		{
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio"); //РИСУЕТ В ОКНЕ VS
			//HWND hwnd = GetConsoleWindow(); РИСУЕТ В ОКНЕ ВЫЗОВА
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 9, get_color());
			HBRUSH hBrush = CreateSolidBrush(get_color());
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x, start_y, start_x + rad * 2, start_y + rad * 2);
			//чтобы показать что это глобальная функция надо поставить двойное двоеточие без операнда слева.
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}

		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус: " << get_rad() << endl;
			Shape::info();
		}

	};
	/*class Triangle : public Shape  //Треугольик
	{
	private:
		double a;
		double b;
		double c;
	public:
		const double get_a()const
		{
			return a;
		}
		void set_a(double a)
		{
			this->a = a;
		}
		const double get_b()const
		{
			return b;
		}
		void set_b(double b)
		{
			this->b = b;
		}
		const double get_c()const
		{
			return c;
		}
		void set_c(double c)
		{
			this->c = c;
		}
		Triangle(double a, double b, double c, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_a(a);
			set_b(b);
			set_c(c);
		}
		virtual ~Triangle() {};
		double get_area()const override
		{
			return sqrt((a + b + c) / 2 * (((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c)));
		}
		double get_perimeter()const override
		{
			return (a+b+c);
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 9, get_color()); //Solid -непрывн линия
			HBRUSH hBrush = CreateSolidBrush( get_color());
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//определяем координаты треугольника
			double x1 = a;
			double y1 = a;
			double x2 = x1 + a * cos(a/b);
			double y2 = y1 + a * sin(a/b);
			double x3 = x1 + c;
			double y3 = y1;
			//определяем массив точек которые образуют треугольник
			POINT point[] =
			{
				{(int)x1+ start_x, (int)y1+ start_y},
				{(int)x2+ start_x, (int)y2+ start_y},
				{(int)x3+ start_x, (int)y3+ start_y}
			};
			// Рисуем треугольник:
			Polygon(hdc,point, 3);
			//7) Освобождаем ресурсы:
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона a: " << get_a() << endl;
			cout << "Сторона b: " << get_b() << endl;
			cout << "Сторона c: " << get_c() << endl;
			Shape::info();
		}
	};*/

	class Triangle :public Shape  //Треугольyик
	{
	public:
		virtual double get_height()const = 0;
		Triangle(SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) {}
		//Triangle(double get_height(), SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS) {}
		virtual~Triangle() {};
		void info()const override
		{
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		EquilateralTriangle(double side, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
		}
		virtual ~EquilateralTriangle() {};
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = filter_size(side);
		}
		double get_height()const override
		{
			return sqrt(side * side - side / 2 * side / 2);
		}
		double get_area()const override
		{
			return side / 2 * get_height();
		}
		double get_perimeter()const override
		{
			return side * 3;
		}
		void draw() const override
		{
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio");
			//HWND hwnd = FindWindow(NULL, "Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			/*int choise = rand() % 2;
			double x1 = side;
			double y1 = side;
			double x2 = x1 + side * cos(side / side);
			double y2 = y1 + side * sin(side / side);
			double x3 = x1 + side;
			double y3 = y1;*/
			//определяем массив точек которые образуют треугольник
			POINT point[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};
			// Рисуем треугольник:
			Polygon(hdc, point, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина тороны а, b, c : " << get_side() << endl;
			cout << "Высота треугольника : " << get_height() << endl;
			Shape::info();
		}
	};
	class IsoscelesTriangle :public Triangle
	{
		double side;
		double base;
	public:
		IsoscelesTriangle(double side, double base, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
			set_base(base);
		}
		virtual ~IsoscelesTriangle() {};
		double get_side()const
		{
			return side;
		}
		double get_base()const
		{
			return base;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		void set_base(double base)
		{
			this->base = base;
		}
		double get_height()const override
		{
			return sqrt(side * side - base / 2 * base / 2);
		}
		double get_area()const override
		{
			return base / 2 * get_height();
		}
		double get_perimeter()const override
		{
			return side * 2 + base;
		}
		void draw() const override
		{
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio");
			//HWND hwnd = FindWindow(NULL, "Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//определяем массив точек которые образуют isoscelec треугольник
			POINT point[] =
			{
				{start_x, start_y + base},
				{start_x + base, start_y + base},
				{start_x + base / 2, start_y + base - get_height()}
			};
			// Рисуем треугольник:
			::Polygon(hdc, point, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Стороны а и c : " << get_side() << endl;
			cout << "Основание в : " << get_base() << endl;
			cout << "Высота треугольника : " << get_height() << endl;
			Shape::info();
		}

	};
	class A_right_angled_Triangle : public Triangle
	{
		double side;
		double base;
	public:
		A_right_angled_Triangle(double side, double base, SHAPE_TAKE_PARAMETERS) :Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side(side);
			set_base(base);
		}
		virtual ~A_right_angled_Triangle() {};
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_base()const
		{
			return base;
		}
		void set_base(double base)
		{
			this->base = base;
		}
		double get_height()const override
		{
			return sqrt(side * side - base * base);
		}
		double get_area()const override
		{
			return base / 2 * get_height();
		}
		double get_perimeter()const override
		{
			return side + base + get_height();
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, "Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			double x1 = 0;
			double y1 = get_height();
			double x2 = x1 + base;
			double y2 = get_height();
			double x3 = 0;
			double y3 = 0;
			//определяем массив точек которые образуют прямой треугольник
			POINT point[] =
			{
				{start_x, start_y + base},
				{start_x + base, start_y + base},
				{start_x + base, start_y + base - get_height()}
			};
			// Рисуем треугольник:
			Polygon(hdc, point, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Гипотенуза : " << get_side() << endl;
			cout << "Катет и основание : " << get_base() << endl;
			cout << "Высота и второй катет треугольника : " << get_height() << endl;
			Shape::info();
		}
	};

}
void main() //C2259 "Square" не удалось создать экземпляр                        абстрактоного класса
//Е0322 Объект абстрактоного класса типа.квадрат не разрешён
{
	setlocale(LC_ALL, "Rus");
	Geometry::Square square(50, 220, 90, 5, Geometry::Color::DARK_RED);
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rect(80, 40, 300, 70, 3, Geometry::Color::BLUE);
	rect.info();
	cout << delimiter << endl;
	Geometry::Circle circle(150, 390, 65, 3, Geometry::Color::YELLOW);
	circle.info();
	cout << delimiter << endl;
	Geometry::EquilateralTriangle equ_triangle(120, 550, 50, 3, Geometry::Color::GREEN);
	equ_triangle.info();
	cout << delimiter << endl;
	Geometry::IsoscelesTriangle iso_triangle(120, 100, 700, 75, 2, Geometry::Color::RED);
	iso_triangle.info();
	cout << delimiter << endl;
	Geometry::A_right_angled_Triangle ara_triangle(160, 120, 820, 50, 60, Geometry::Color::PURPLE);
	ara_triangle.info();

	cout << "Количество фигур: " << equ_triangle.get_count() << endl;
	cout << "Количество фигур: " << Geometry::Shape::get_count() << endl;
}
