#include"Constants.h"
#include"Stdafx.h"
#include"Shape.cpp"
namespace Geometry
{
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
}