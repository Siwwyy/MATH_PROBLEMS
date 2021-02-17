#ifndef _POINTS_COLLINEARITY_2D_H_INCLUDED_
#define _POINTS_COLLINEARITY_2D_H_INCLUDED_


#include <vector>
#include <iostream>

#include "Point.hpp"

namespace Math_Problems
{
	template<typename Head, typename...Tail>
	struct first_type
	{
		using type = Head;
	};

	template <typename...Tys>
	using first_type_t = typename first_type<Tys...>::type;

	template <typename...Tys>
	auto make_example(Tys&&... args)->std::array<first_type_t<Tys...>, sizeof...(Tys)>
	{
		return { std::forward<Tys>(args)... };
	}

	template<typename T>
	class Points_Collinearity_2D
	{
	public:

		using value_type = Points::Point<T, 2>;
		using const_iter = typename std::vector<value_type>::const_iterator;

		Points_Collinearity_2D() = delete;
		~Points_Collinearity_2D() = default;
		Points_Collinearity_2D(const Points_Collinearity_2D& Object) = default;
		Points_Collinearity_2D(Points_Collinearity_2D&& Object) noexcept = default;

		Points_Collinearity_2D& operator=(const Points_Collinearity_2D& Object) = default;
		Points_Collinearity_2D& operator=(Points_Collinearity_2D&& Object) noexcept = default;

		Points_Collinearity_2D(const std::initializer_list<value_type>& Elems);

		inline void show_collinear_points() const;

	private:

		inline bool is_collinear(const_iter& iter) const noexcept;

	private:
		std::vector<value_type> Points;
	};

	template <typename T>
	Points_Collinearity_2D<T>::Points_Collinearity_2D(const std::initializer_list<value_type>& Elems) :
		Points(Elems)
	{

	}

	template <typename T>
	inline void Points_Collinearity_2D<T>::show_collinear_points() const
	{
		//for (const auto& elem : Points)
		//{
		//	//auto it = container.begin();
		//	//std::advance(it, std::distance(&*it, &x));
		//	if (is_collinear(elem) == true)
		//	{
		//		//std::cout << *elem;
		//		std::cout << typeid(elem).name();
		//	}
		//}

		for (const_iter current_point = Points.begin(); current_point != Points.end(); ++current_point)
		{
			if (is_collinear(current_point) == true)
			{
				std::cout << *current_point;
			}
		}

		//for (std::size_t i = 0; i < Points.size() - 1; ++i)
		//{
		//	std::cout << Points[i];
		//}

	}

	template <typename T>
	inline bool Points_Collinearity_2D<T>::is_collinear(const_iter& iter) const noexcept
	{

		///*
		//	 formula:
		//	  M = (y2 - y1) / (x2 - x1)
		//	*/
		//const auto M_ab = (next_point->operator[](1) - iter->operator[](1)) / (next_point->operator[](0) - iter->operator[](0));
		//const auto M_ac = ((next_point + 1)->operator[](1) - iter->operator[](1)) / ((next_point + 1)->operator[](0) - iter->operator[](0));
		//auto& M_ac1 = next_point[1];

		//if (M_ab == M_ac)
		//{
		//	return true;
		//}

		for (const_iter next_point = iter + 1; next_point < Points.end() - 1; ++next_point)
		{
			
		}

		return false;
	}

}

#endif /* _POINTS_COLLINEARITY_2D_H_INCLUDED_ */