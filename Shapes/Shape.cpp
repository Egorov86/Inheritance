//Shape.cpp
#include"Constants.h"
#include"Stdafx.h"
namespace Geometry
{
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
}