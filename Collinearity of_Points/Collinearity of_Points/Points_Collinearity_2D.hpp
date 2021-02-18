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

		//template<typename ... Elems>
		//explicit Points_Collinearity_2D(Elems && ... elems);

		void show_collinear_points() const;

	private:

		void collinear_points_algorithm() const noexcept;

	private:
		std::vector<value_type> Points;
	};

	template <typename T>
	Points_Collinearity_2D<T>::Points_Collinearity_2D(const std::initializer_list<value_type>& Elems) :
		Points(Elems)
	{

	}

	//template <typename T>
	//template <typename ... Elems>
	//Points_Collinearity_2D<T>::Points_Collinearity_2D(Elems&&... elems) :
	//	Points{ std::forward<Elems>(elems)... }
	//{

	//}

	template <typename T>
	inline void Points_Collinearity_2D<T>::show_collinear_points() const
	{
		if (Points.size() > 0 && Points.size() < 3)
		{
			std::cout << "Two points or one point always collinear!\n";
			return;
		}

		collinear_points_algorithm();
	}

	template <typename T>
	void Points_Collinearity_2D<T>::collinear_points_algorithm() const noexcept
	{
		auto are_collinear = [](const_iter& A, const_iter& B, const_iter& C)
		{
			/* formula:
				  Slop_AB = (y1 - y2) / (x1 - x2)
				  Slop_AC = (y1 - y3) / (x1 - x3)

				  Slop_AB == Slop_AC -> they are collinear, If not, they aren't
			*/
			//const auto Slop_AB = (A->Get_Y() - B->Get_Y()) / (A->Get_X() - B->Get_X());
			//const auto Slop_AC = (A->Get_Y() - C->Get_Y()) / (A->Get_X() - C->Get_X());

			const auto Slop_AB = A->Get_X() * B->Get_Y() + B->Get_X() * C->Get_Y() + C->Get_X() * A->Get_Y();
			const auto Slop_AC = B->Get_X() * A->Get_Y() + C->Get_X() * B->Get_Y() + A->Get_X() * C->Get_Y();

			return Slop_AB == Slop_AC ? true : false;
		};

		bool* const collinearity_state = new bool[Points.size()];
		std::fill(collinearity_state, collinearity_state + Points.size(), false);


		for (const_iter First_Point = Points.begin(); First_Point != Points.end(); ++First_Point)
		{
			const std::size_t index = std::distance(std::begin(Points), First_Point);
			if (collinearity_state[index])
			{
				continue;
			}

			bool collinear_state = false;
			for (const_iter Second_Point = First_Point + 1; Second_Point < Points.end(); ++Second_Point)
			{
				for (const_iter Third_Point = Second_Point + 1; Third_Point < Points.end(); ++Third_Point)
				{
					if (are_collinear(First_Point, Second_Point, Third_Point))
					{
						collinearity_state[index] = true;
						collinearity_state[std::distance(std::begin(Points), Second_Point)] = true;
						collinearity_state[std::distance(std::begin(Points), Third_Point)] = true;

						std::cout << "Collinear points: " << *First_Point << ' ' << *Second_Point << ' ' << *Third_Point << '\n';
						collinear_state = true;
						break;
					}
				}
				if (collinear_state)
				{
					break;
				}
			}
		}

		delete[] collinearity_state;
	}
}

#endif /* _POINTS_COLLINEARITY_2D_H_INCLUDED_ */