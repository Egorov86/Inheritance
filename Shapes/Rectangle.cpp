#include"Constants.h"
#include"Stdafx.h"
#include"Shape.cpp"

namespace Geometry
{
	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS) // ����������� ��������� - GIVE
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
			HWND hwnd = FindWindowA(NULL, "Inheritance - Microsoft Visual Studio"); //������ � ���� VS
			//HWND hwnd = GetConsoleWindow(); ������ � ���� ������
			//HWND hwnd = GetConsoleWindow(); 1)�������� ���������� ���� �������. ���������� � ������� �������� �������� ����-��.
			//description 
			//HWND - Handler to Window(���������� ��� ���������� ����)
			HDC hdc = GetDC(hwnd); //2) �������� �������� ���������� (Device context) ���� �������
			//DC - ��� �� �� ��� �� ����� ��������
			HPEN hPen = CreatePen(PS_SOLID, 5, get_color());
			//3) ������� ��������, Pen ������ ������ ������
			//PS_SOLID - �������� �����
			//5-������� ����� � ��������
			// 4) c������ ��������
			HBRUSH hBrush = CreateSolidBrush(get_color());
			//5) �������� ��� � �� ��� ��������
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) ������ �������������:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);
			//start_x, start_y -���������� �������� ������ ����
			// 800, 350 - ���������� ������� ������� ����
			//����� �������� ��� ��� ���������� ������� ���� ��������� ������� ��������� ��� �������� �����.
			//7) ����������� �������:
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
			cout << "������: " << get_width() << endl;
			cout << "������: " << get_height() << endl;
			Shape::info();
		}
	};
}