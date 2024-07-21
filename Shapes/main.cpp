//AbstractGeometry
#include"Constants.h"
#include"Shape.cpp"
#include"Stdafx.h"
#include"Rectangle.cpp"
#include"Square.cpp"
#include"Triangle.cpp"
#include"EquilateralTriangle.cpp"
#include"IsoscelesTriangle.cpp"
#include"A_right_angled_Triangle.cpp"

void main() //C2259 "Square" не удалось создать экземпляр                        абстрактоного класса
            //Е0322 Объект абстрактоного класса типа.квадрат не разрешён
{
	setlocale(LC_ALL, "Rus");
	Geometry::Square square(50, 220, 90, 5, Geometry::Color::DARK_RED);
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rectangle(80, 40, 300, 70, 3, Geometry::Color::BLUE);
	rectangle.info();
	cout << delimiter << endl;
	Geometry::Circle circle( 150, 390, 65, 3, Geometry::Color::YELLOW);
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

	cout << "Количество фигур: " << equ_triangle.get_count()<< endl;
	cout << "Количество фигур: " << Geometry::Shape::get_count() << endl;
}
