#include"Constants.h"
#include"Stdafx.h"
#include"Shape.cpp"
#include"Triangle.cpp"
namespace Geometry
{
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
}