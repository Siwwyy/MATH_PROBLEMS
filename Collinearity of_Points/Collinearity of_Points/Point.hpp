#ifndef _POINT_H_INCLUDED_
#define _POINT_H_INCLUDED_


#include <iostream>
#include <concepts>
#include <cstddef>
#include <array>

//#define _STL_COMPILER_PREPROCESSOR

namespace Points
{
	//template<class T>
	//concept Arthmetic_Type = std::is_arithmetic_v<T>;

	template<typename T, std::size_t nDim, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
	class Point
	{
	public:
		Point() = delete;
		Point(const Point& Object) = default;
		Point& operator=(const Point& Object) = delete;

		~Point() = default;

		template<typename ... Elems>
		explicit Point(Elems && ... elems);

		Point(Point&& Object) noexcept;
		Point& operator=(Point&& Object) noexcept;

		bool operator==(const Point& rhs) const noexcept;
		//[[nodiscard]] decltype(auto) operator[](const std::size_t& index) const;
		[[nodiscard]] T& operator[](const std::size_t index);
		[[nodiscard]] const T& operator[](const std::size_t index) const;

		[[nodiscard]] inline decltype(auto) Get_X() const noexcept;
		[[nodiscard]] inline decltype(auto) Get_Y() const noexcept;

		template <typename T, std::size_t nDim, typename T0>
		friend std::ostream& operator<<(std::ostream& lhs, const Point<T, nDim, T0>& rhs);

	private:
		std::array<T, nDim> Coordinates;
	};

	template <typename T, std::size_t nDim, typename T0>
	inline std::ostream& operator<<(std::ostream& lhs, const Point<T, nDim, T0>& rhs)
	{
		auto distance = [&](const T& elem)
		{
			const std::size_t diff = (&elem - rhs.Coordinates._Unchecked_begin());
			return diff;
		};

		lhs << "[ ";
		for (const auto& elem : rhs.Coordinates)
		{
			if (distance(elem) != (rhs.Coordinates.size() - 1))
			{
				lhs << elem << " , ";
			}
			else
			{
				lhs << elem;
			}
		}
		lhs << " ]";
		return lhs;
	}


	template <typename T, std::size_t nDim, typename T0>
	template <typename ... Elems>
	Point<T, nDim, T0>::Point(Elems&&... elems) :
		Coordinates{ std::forward<Elems>(elems)... }
	{
		constexpr std::size_t elems_amount = sizeof...(Elems);
		static_assert((nDim == elems_amount), "Number of elements in constructor have to be equal to dimension of this point e.g 2D Point should has {1,2} etc.");
		//static_assert(std::is_same<T, Elems>::value, "If the point is a float, then in constructor, you have to put point as e.g {1.f,3.f}");
		//static_assert(std::is_same_v<T, Elems>, "If the point is a float, then in constructor, you have to put point as e.g {1.f,3.f}");
		//static_assert(std::is_same<T, decltype(elems)...>, "If the point is a float, then in constructor, you have to put point as e.g {1.f,3.f}");
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

	/*
	* @param Index must be between 0 and Point dimension - 1 e.g. 2D Point -> Indexes 0 and 1, 3D Point -> Indexes 0, 1, 2 and so forth
	*/
	template <typename T, std::size_t nDim, typename T0>
	T& Point<T, nDim, T0>::operator[](const std::size_t index)
	{
		return Coordinates.at(index);
	}

	/*
	* @param Index must be between 0 and Point dimension - 1 e.g. 2D Point -> Indexes 0 and 1, 3D Point -> Indexes 0, 1, 2 and so forth
	*/
	template <typename T, std::size_t nDim, typename T0>
	const T& Point<T, nDim, T0>::operator[](const std::size_t index) const
	{
		//		//return Coordinates.at(index);
		//#if _CONTAINER_DEBUG_LEVEL > 0
		//		_STL_VERIFY((index < Coordinates.size()), "array subscript out of range");
		//#endif // _CONTAINER_DEBUG_LEVEL > 0
		//		std::cout << Coordinates.size() << '\n';

		return Coordinates.at(index);
	}

	template <typename T, std::size_t nDim, typename T0>
	decltype(auto) Point<T, nDim, T0>::Get_X() const noexcept
	{
		return Coordinates[0];
	}

	template <typename T, std::size_t nDim, typename T0>
	decltype(auto) Point<T, nDim, T0>::Get_Y() const noexcept
	{
		return Coordinates[1];
	}

	//template <typename T, std::size_t nDim, typename T0>
	//decltype(auto) Point<T, nDim, T0>::operator[](const std::size_t& index) const
	//{
	//	return Coordinates.at(index);
	//}

	//template <typename T, std::size_t nDim, typename T0>
	//decltype(auto) Point<T, nDim, T0>::operator[](const std::size_t& index) const
	//{

	//	return *this;
	//}

	/*
	* @param Index must be between 0 and Point dimension - 1 e.g. 2D Point -> Indexes 0 and 1, 3D Point -> Indexes 0, 1, 2 and so forth
	*/
	//template <typename T, std::size_t nDim, typename T0>
	//T& Point<T, nDim, T0>::operator[](const std::size_t& index) const
	//{
	//	//static_assert(!(index >= 0 && index < nDim), "Index must be between 0 and Point dimension - 1 e.g. 2D Point -> Indexes 0 and 1, 3D Point -> Indexes 0, 1, 2 and so forth");
	//	//if (index >= 0 && index < nDim)
	//	//{
	//	//	return Coordinates[index];
	//	//}
	//	//return Coordinates[0];

	//	return Coordinates.at(index);
	//}


}

#endif /* _POINT_H_INCLUDED_ */