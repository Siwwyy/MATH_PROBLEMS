#include <iostream>

#include "Points_Collinearity_2D.hpp"



int main(int argc, char* argv[])
{
	//Math_Problems::Points_Collinearity_2D<int> a{std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1)};

	//std::vector<int> aa;
	//a.Print();

	//const Point::Point<int, 2> point{ 1,2 };
	//Point::Point<int, 2> point1 { 1,2 };
	//Point::Point<float, 2> point3{ 1.f,2.f };
	//Point::Point<double, 2> point4{ 1,2 };
	//Point::Point<uint8_t, 2> point3{ 1,2 };

	//auto d = std::move(point);

	//std::cout << point3[1] << '\n';
	//auto& a = point[1];
	//decltype(auto) a = point[1];
	//point[0];


	////////////////////////////////////////////////////////////////////////////

	Math_Problems::Points_Collinearity_2D<int> Obj{ Point::Point<int, 2>{2,2}, Point::Point<int, 2>{4,4}, Point::Point<int, 2>{6,6}, Point::Point<int, 2>{-6,-1} };
	//Math_Problems::Points_Collinearity_2D<int> Obj = { };
	//Math_Problems::Points_Collinearity_2D<int> Obj = { 1,2 };

	Obj.show_collinear_points();

	//auto size = sizeof(std::string);
	//auto capacity = std::string().capacity();
	//auto small = std::string(capacity, '*');
	//auto big = std::string(capacity + 1, '*');

	//std::vector<int> v{ 3, 1, 4 };

	//auto vi = v.begin();

	//std::advance(vi, 2);

	//std::cout << *vi << '\n';

	system("pause");
	return EXIT_SUCCESS;
}
