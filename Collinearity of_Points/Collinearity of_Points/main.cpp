#include <iostream>
#include <string>

#include "Points_Collinearity_2D.hpp"
#include "Point.hpp"



int main(int argc, char* argv[])
{
	//Math_Problems::Points_Collinearity_2D<int> a{std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1),std::make_pair(1,1)};


	//a.Print();

	Point::Point<int, 2> point{ 1,2 };

	//auto d = std::move(point);

	//std::cout << point[1] << '\n';
	//point[0];


	system("pause");
	return EXIT_SUCCESS;
}
