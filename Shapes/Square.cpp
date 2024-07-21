#include"Constants.h"
#include"Stdafx.h"
#include"Shape.cpp"
#include"Rectangle.cpp"
namespace Geometry
{
	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {} //���������� ������������� � ������� � ������� � ����

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
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio"); //������ � ���� VS
			//HWND hwnd = GetConsoleWindow(); ������ � ���� ������
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 9, get_color());
			HBRUSH hBrush = CreateSolidBrush(get_color());
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			Ellipse(hdc, start_x, start_y, start_x + rad * 2, start_y + rad * 2);
			//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}

		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << get_rad() << endl;
			Shape::info();
		}

	};
}