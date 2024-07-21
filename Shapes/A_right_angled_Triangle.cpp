#include"Constants.h"
#include"Stdafx.h"
#include"Shape.cpp"
#include"Triangle.cpp"
namespace Geometry
{
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