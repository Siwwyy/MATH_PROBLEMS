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

	const Math_Problems::Points_Collinearity_2D<int> Obj{ Points::Point<int, 2>{2,2}, Points::Point<int, 2>{4,4}, Points::Point<int, 2>{6,6}, Points::Point<int, 2>{-6,-1} };
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





//#include <iostream>
//#include <cmath>
//#include <cstdio>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//// 0 1 2
//// 3 4 5 
//// 6 7 8  
//// data [] = {0,1,2,3,4,5,6,7,8}
////
//// 0 1 2 5 8 7 6 3 4 
//// 
//// row, cols, data []
//
//
//void foo(int* data, const std::size_t rows, const std::size_t cols)
//{
//
//
//	//for (std::size_t i = 0; i < rows; ++i)
//	//{
//	//	if (i % 2 == 0 || i == 0)
//	//	{
//	//		std::size_t j = current_row;
//	//		for (; j < cols; ++j)
//	//		{
//	//			std::cout << data[j] << ' ';
//	//		}
//	//		current_col = j - 1;
//	//		std::cout << '\n';
//	//	}
//	//	else
//	//	{
//	//		std::size_t j = current_col;
//	//		for (; j < cols*rows; j += 3)
//	//		{
//	//			std::cout << data[j] << ' ';
//	//		}
//	//		current_row = 0;
//	//		std::cout << '\n';
//	//		//if(descending)
//	//		//{
//
//	//		//	
//	//		//	descending = false;
//	//		//}
//	//		//else
//	//		//{
//
//	//		//	
//	//		//	descending = true;
//	//		//}
//	//		
//
//	//	}
//	//}
//
//
//	//std::size_t current_row = 0llu;
//	//std::size_t current_col = 0llu;
//
//	//bool descending_row = false;
//	//bool descending_col = false;
//
//	//const std::size_t steps = std::round(static_cast<float>(static_cast<float>(rows * cols) / 2.f));
//
//	//std::size_t rows_step = rows;
//	//std::size_t cols_step = cols / 2;
//
//	//std::size_t current_pos = 0llu;
//
//	//for (std::size_t i = 0; i < steps; ++i)
//	//{
//	//	if (i % 2 == 0 || i == 0)
//	//	{
//	//		if (!descending_row)
//	//		{
//	//			descending_row = true;
//
//	//			std::size_t j = current_pos;
//	//			std::size_t counter = 0;
//	//			
//	//			while (counter < rows_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				++j;
//	//				++counter;
//	//			}
//	//			
//	//			current_pos = j - 1;
//	//		}
//	//		else
//	//		{
//	//			descending_row = false;
//
//	//			std::size_t j = current_pos;
//	//			std::size_t counter = 0;
//	//			
//	//			while (counter < rows_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				--j;
//	//				++counter;
//	//			}
//	//			
//	//			current_pos = j + 1;
//	//			rows_step /= 2;
//	//		}
//	//	}
//	//	else
//	//	{
//	//		if (!descending_col)
//	//		{
//	//			descending_col = true;
//
//	//			std::size_t j = current_pos + rows;
//	//			std::size_t counter = 0;
//	//			
//	//			while (counter < cols_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				j += rows;
//	//				++counter;
//	//			}
//	//			
//	//			current_pos = j;
//	//		}
//	//		else
//	//		{
//	//			descending_col = false;
//
//	//			std::size_t j = current_pos - rows;
//	//			std::size_t counter = 0;
//	//			while (counter < cols_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				j -= rows;
//	//				++counter;
//	//			}
//
//	//			current_pos = j + rows + 1;
//	//			cols_step /= 2;
//	//		}
//	//	}
//	//}
//
//
//
//	//for (std::size_t i = 0; i < steps; ++i)
//	//{
//	//	if (i % 2 == 0 || i == 0)
//	//	{
//	//		//std::cout << "Row ";
//	//		if (!descending_row)
//	//		{
//	//			descending_row = true;
//
//	//			//std::size_t j = current_pos;
//	//			//for (; j < cols - 1; ++j)
//	//			//{
//	//			//	std::cout << data[j] << ' ';
//	//			//}
//
//	//			//current_pos = j;
//
//
//	//			std::size_t j = current_pos;
//	//			std::size_t counter = 0;
//	//			while (counter < rows_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				++j;
//	//				++counter;
//	//			}
//	//			//rows_step--;
//	//			current_pos = j;
//	//		}
//	//		else
//	//		{
//	//			descending_row = false;
//
//	//			//std::size_t j = current_pos;
//	//			//for (; j < cols - 1; --j)
//	//			//{
//	//			//	std::cout << data[j] << ' ';
//	//			//}
//	//			//current_pos = j;
//
//	//			std::size_t j = current_pos - 1;
//	//			std::size_t counter = 0;
//	//			while (counter < rows_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				--j;
//	//				++counter;
//	//			}
//
//	//			current_pos = j + 1;
//	//			rows_step = rows / rows_step;
//	//		}
//	//	}
//	//	else
//	//	{
//	//		//std::cout << "Col ";
//	//		if (!descending_col)
//	//		{
//	//			descending_col = true;
//
//	//			//std::size_t j = current_pos;
//	//			//for (; j < cols * rows; j += 3)
//	//			//{
//	//			//	std::cout << data[j] << ' ';
//	//			//}
//	//			//current_pos = j - 3;
//
//	//			//std::size_t j = current_pos;
//	//			//while (j < cols * rows)
//	//			//{
//	//			//	std::cout << data[j] << ' ';
//	//			//	j += rows;
//	//			//}
//
//	//			std::size_t j = current_pos;
//	//			std::size_t counter = 0;
//
//	//			while (counter <= cols_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				j += rows;
//	//				++counter;
//	//			}
//
//	//			current_pos = j - rows;
//	//		}
//	//		else
//	//		{
//	//			descending_col = false;
//	//			//cols_step = cols/cols_step;
//	//			cols_step--;
//	//			//std::size_t j = current_pos;
//	//			//for (; j > 0; j -= 3)
//	//			//{
//	//			//	std::cout << data[j] << ' ';
//	//			//}
//	//			//current_pos = j + 3;
//
//	//			std::size_t j = current_pos - rows;
//	//			std::size_t counter = 0;
//
//	//			while (counter < cols_step)
//	//			{
//	//				std::cout << data[j] << ' ';
//	//				j -= rows;
//	//				++counter;
//	//			}
//
//	//			current_pos = j + rows + 1;
//
//	//		}
//	//	}
//	//	//std::cout << '\n';
//	//}
//
//
//
//
//
//
//	//std::size_t step_row = rows;
//	//std::size_t counter = 0ull;
//	//std::size_t position = 0ull;
//
//	//bool row_step = true;
//	//bool descending = false;
//
//
//	//while (step_row > 0)
//	//{
//	//	if (row_step && step_row == rows)
//	//	{
//	//		row_step = false;
//
//	//		while (counter < step_row)
//	//		{
//	//			std::cout << data[position] << ' ';
//	//			++counter;
//	//			++position;
//	//		}
//
//	//		counter = 0;
//	//		position += rows - 1;
//	//		--step_row;
//	//	}
//	//	else if (row_step)
//	//	{
//	//		if (!descending)
//	//		{
//	//			row_step = false;
//	//			//descending = true;
//
//	//			while (counter < step_row)
//	//			{
//	//				std::cout << data[position] << ' ';
//	//				++counter;
//	//				++position;
//	//			}
//
//	//			counter = 0;
//	//			position += rows - 1;
//	//			--step_row;
//	//		}
//	//		else
//	//		{
//	//			row_step = false;
//	//			//descending = false;
//
//	//			while (counter < step_row)
//	//			{
//	//				std::cout << data[position] << ' ';
//	//				++counter;
//	//				--position;
//	//			}
//
//	//			counter = 0;
//	//			position -= rows - 1;
//	//			--step_row;
//	//		}
//	//	}
//	//	else
//	//	{
//	//		if (!descending)
//	//		{
//	//			row_step = true;
//	//			descending = true;
//
//	//			while (counter < step_row)
//	//			{
//	//				std::cout << data[position] << ' ';
//	//				++counter;
//	//				position += cols;
//	//			}
//
//	//			counter = 0;
//	//			position -= cols + 1;
//	//			--step_row;
//	//		}
//	//		else
//	//		{
//	//			row_step = true;
//	//			descending = false;
//
//	//			while (counter < step_row)
//	//			{
//	//				std::cout << data[position] << ' ';
//	//				++counter;
//	//				position -= cols;
//	//			}
//
//	//			counter = 0;
//	//			if (step_row == 1)
//	//			{
//	//				if (cols % 2 != 0)	//is rows and cols are odd
//	//				{
//	//					position = (rows*cols) / 2;
//	//				}
//	//			}
//	//			else
//	//			{
//	//				position += cols + 1;
//	//			}
//	//		}
//	//	}
//	//}
//
//
//
//	std::size_t step_row = rows;
//	std::size_t step_col = cols - 1;
//	std::size_t counter = 0ull;
//	std::size_t position = 0ull;
//
//	bool row_step = true;
//	bool descending = false;
//
//
//	while (step_row > 0 || step_col > 0)
//	{
//		if (row_step && step_row == rows)
//		{
//			row_step = false;
//
//			while (counter < step_row)
//			{
//				std::cout << data[position] << ' ';
//				++counter;
//				++position;
//			}
//
//			counter = 0;
//			position += rows - 1;
//			--step_row;
//		}
//		else if (row_step)
//		{
//			if (!descending)
//			{
//				row_step = false;
//
//				while (counter < step_row)
//				{
//					std::cout << data[position] << ' ';
//					++counter;
//					++position;
//				}
//
//				counter = 0;
//				position += rows - 1;
//				--step_row;
//			}
//			else
//			{
//				row_step = false;
//
//				while (counter < step_row)
//				{
//					std::cout << data[position] << ' ';
//					++counter;
//					--position;
//				}
//
//				counter = 0;
//				position -= rows - 1;
//				--step_row;
//			}
//		}
//		else
//		{
//			if (!descending)
//			{
//				row_step = true;
//				descending = true;
//
//				while (counter < step_col)
//				{
//					std::cout << data[position] << ' ';
//					++counter;
//					position += rows;
//				}
//
//				counter = 0;
//				if (rows == cols)
//				{
//					position -= cols + 1;
//				}
//				else
//				{
//					position -= cols;
//				}
//				--step_col;
//			}
//			else
//			{
//				row_step = true;
//				descending = false;
//
//				while (counter < step_col)
//				{
//					std::cout << data[position] << ' ';
//					++counter;
//					position -= rows;
//				}
//
//				counter = 0;
//				if (rows == cols)
//				{
//					position += cols + 1;
//				}
//				else
//				{
//					position += cols;
//				}
//				--step_col;
//			}
//		}
//	}
//
//	std::cout << '\n';
//}
//
//
//int main()
//{
//	constexpr std::size_t rows = 5;
//	constexpr std::size_t cols = 5;
//	int data[rows * cols];
//
//	for (std::size_t i = 0; i < rows * cols; i++)
//	{
//		if (i % rows == 0 && i != 0)
//		{
//			std::cout << '\n';
//		}
//		data[i] = static_cast<int>(i + 1);
//		std::cout << data[i] << ' ';
//
//	}
//	std::cout << '\n';
//	std::cout << '\n';
//
//	foo(data, rows, cols);
//
//	system("pause");
//	return EXIT_SUCCESS;
//}