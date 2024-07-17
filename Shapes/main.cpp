//AbstractGeometry
#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include<math.h>
using namespace std;


namespace Geometry
{
	enum Color  // enum (Enumeration) - это перечисление. Перечисление - это набор целочисленных констант
	{
		RED    = 0x000000FF,
		GREEN  = 0x0000FF00,
	    BLUE   = 0x00FF0000,
		YELLOW = 0X0000FFFF,
		CONSOLE_BLUE = 0x09,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_RED = 0xCC,
		CONSOLE_DEFAULT = 0x07,
	};
#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color
	class Shape
	{
	protected: //Защищенные поля, доступны только внутри класса и внутри его дочерних классов
		//благодяря protected к этим полям можно будет обращаться напрямую в дочерних классах(без гет/сет методов)
		Color color;
		unsigned int start_x; //координаты по которым будет выводиться фигура
		unsigned int start_y; //в любой графич оболочке координаты задаются в пикселях
		//Начало координат всегда находится в левом верхнем углу.
		unsigned int line_width; //толщина линии, которoй будет рисоваться контур фигуры
	public:
		Shape(SHAPE_TAKE_PARAMETERS) :color(color) 
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}  //КОНСТРУКТОР И ВИРТ.ДЕСТРУКТОР
		virtual ~Shape() {}   // {}пустая реализация, если ставить ; то нужно где то реализовывать
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
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
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width = line_width;
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
			HWND hwnd = GetConsoleWindow(); //1)Получаем дескриптор окна консоли. Переменная в которой хранится описание чего-то.
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
			this->rad = rad;
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
			HWND hwnd = GetConsoleWindow(); 
			HDC hdc = GetDC(hwnd); 
			HPEN hPen = CreatePen(PS_SOLID, 9, get_color());
			HBRUSH hBrush = CreateSolidBrush(get_color());
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x, start_y, start_x+rad*2, start_y+rad*2);
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
		~Triangle() {};
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
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
			HWND hwnd = FindWindow(NULL, "Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);



			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
	};

}

void main() //C2259 "Square" не удалось создать экземпляр                        абстрактоного класса
            //Е0322 Объект абстрактоного класса типа.квадрат не разрешён
{
	setlocale(LC_ALL, "Rus");
	//Shape shape(Color::CONSOLE_BLUE);
	Geometry::Square square(60, 220, 90, 5, Geometry::Color::BLUE);
	/*cout << "Длинна стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Перимет квадрата: " << square.get_perimeter() << endl;*/
	square.info();

	Geometry::Rectangle rect(120, 80, 300, 70, 3, Geometry::Color::BLUE);
	rect.info();

	Geometry::Circle circle( 40, 450, 75, 3, Geometry::Color::YELLOW);
	circle.info();

	/*Geometry::Triangle triangle(80, 80, 80, 480, 5, 3, Geometry::Color::YELLOW);
	triangle.info();*/
	Geometry::Triangle triangle(300, 300, 5, Geometry::Color::GREEN);
}
