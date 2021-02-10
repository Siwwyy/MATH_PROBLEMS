#ifndef _POINT_H_INCLUDED_
#define _POINT_H_INCLUDED_


#include <iostream>
#include <concepts>
#include <cstddef>
#include <array>

//#define _STL_COMPILER_PREPROCESSOR

namespace Point
{
	//template<class T>
	//concept Arthmetic_Type = std::is_arithmetic_v<T>;

	template<typename T, std::size_t nDim, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Point
	{
	public:
		Point() = delete;
		Point(const Point& Object) = delete;
		Point& operator=(const Point& Object) = delete;

		~Point() = default;

		template<typename ... Elems>
		explicit Point(Elems && ... elems);

		Point(Point&& Object) noexcept;
		Point& operator=(Point&& Object) noexcept;

		bool operator==(const Point& rhs) const noexcept;
		[[nodiscard]] const T& operator[](const std::size_t& index) const noexcept;


	private:
		std::array<T, nDim> Coordinates;
	};

	template <typename T, std::size_t nDim, typename T0>
	template <typename ... Elems>
	Point<T, nDim, T0>::Point(Elems&&... elems) :
		Coordinates{ {std::forward<Elems>(elems)...} }
	{
		constexpr std::size_t elems_amount = sizeof...(Elems);
		static_assert((nDim == elems_amount), "Number of elements in constructor have to be equal to dimension of this point e.g 2D Point should has {1,2} etc.");
	}

	template <typename T, std::size_t nDim, typename T0>
	Point<T, nDim, T0>::Point(Point&& Object) noexcept :
		Coordinates(std::move(Object.Coordinates))
	{

	}

	template <typename T, std::size_t nDim, typename T0>
	Point<T, nDim, T0>& Point<T, nDim, T0>::operator=(Point&& Object) noexcept
	{
		if (this != &Object)
		{
			//Coordinates = std::exchange(Object.Coordinates, std::fill_n(Object.Coordinates, nDim, {}));
			Coordinates = std::move(Object.Coordinates);
		}
		return *this;
	}

	template <typename T, std::size_t nDim, typename T0>
	bool Point<T, nDim, T0>::operator==(const Point& rhs) const noexcept
	{
		if (Coordinates == rhs.Coordinates)
		{
			return true;
		}
		return false;
	}

	template <typename T, std::size_t nDim, typename T0>
	const T& Point<T, nDim, T0>::operator[](const std::size_t& index) const noexcept
	{
		//static_assert(!(index >= 0 && index < nDim), "Index must be between 0 and Point dimension - 1 e.g. 2D Point -> Indexes 0 and 1, 3D Point -> Indexes 0, 1, 2 and so forth");
		if (index >= 0 && index < nDim)
		{
			return Coordinates[index];
		}
		return Coordinates[0];
	}
}

#endif /* _POINT_H_INCLUDED_ */