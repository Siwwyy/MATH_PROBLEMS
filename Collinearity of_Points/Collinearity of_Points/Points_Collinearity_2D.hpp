#ifndef _POINTS_COLLINEARITY_2D_H_INCLUDED_
#define _POINTS_COLLINEARITY_2D_H_INCLUDED_


#include <vector>
#include <iostream>

#include "Point_2D.hpp"

namespace Math_Problems
{

	
	template<typename T>
	class Points_Collinearity_2D
	{
	public:
		Points_Collinearity_2D() = default;
		~Points_Collinearity_2D() = default;

		
		//Points_Collinearity_2D(const std::initializer_list<Point_2D<T>> & elems);

		//void Print()
		//{
		//	for(const auto& elem: Points)
		//	{
		//		std::cout << elem.first << '\n';
		//	}
		//}
	private:
		//std::vector<Point::Point_2D<T>> Points;
	};

	//template <typename T>
	//Points_Collinearity_2D<T>::Points_Collinearity_2D(const std::initializer_list<std::pair<T, T>>& Points):
	//	Points(std::move(Points))
	//{
	//	
	//}
	
}

#endif /* _POINTS_COLLINEARITY_2D_H_INCLUDED_ */