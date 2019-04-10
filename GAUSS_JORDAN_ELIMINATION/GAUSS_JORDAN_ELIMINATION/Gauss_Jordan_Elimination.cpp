#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

_Equation_Solve::_Equation_Solve():
	width(0),
	height(0)
{
	std::fstream file_in;
	//file_in.open("matrix2.in", std::ios_base::in);
	file_in.open("matrix.in", std::ios_base::in);
	//file_in.open("matrix4x5.in", std::ios_base::in);
	//file_in.open("matrix5x6.in", std::ios_base::in);
	//file_in.open("matrix_c.in", std::ios_base::in);
	file_in >> this->width;
	file_in >> this->height;
	Matrix = new float*[width];
	for (size_t i = 0; i < width; ++i)
	{
		Matrix[i] = new float[height+1];
	}

	//INITIALIZE THE MATRIX FROM FILE
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			file_in >> Matrix[i][j];
		}
	}
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = height; j < height + 1; ++j)
		{
			Matrix[i][j] = 0;
		}
	}
	file_in.close();
}

void _Equation_Solve::show_matrix(void) const
{
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			if (j < height - 1)
			{
				if (j > 0)
				{
					if (Matrix[i][j] >= 0)
					{
						std::cout << " + " << Matrix[i][j] << "x" << j;
					}
					else
					{
						std::cout << ' ' << Matrix[i][j] << "x" << j;
					}
				}
				else
				{
					std::cout << ' ' << Matrix[i][j] << "x";
				}
			}
			else
			{
				std::cout << " = " << Matrix[i][j] << ' ';
				/*std::cout << " Flag on: " << Matrix[i][height] << ' ';*/
			}
		}
		std::cout << endl;
	}
}

void _Equation_Solve::Gauss_Jordan_Elimination()
{
	for (size_t i = 0; i < this->width; ++i)
	{
		if (Matrix[i][i] < 0)
		{
			for (size_t j = 0; j < this->height; ++j)
			{
				Matrix[i][j] *= -1;
			}
		}
	}

	float divider = Matrix[0][0];
	for (size_t j = 0; j < this->height; ++j)
	{
		Matrix[0][j] /= divider;
	}
	
	size_t i = 1;
	float substractor = 0;
	float multiplier = 0;
	size_t which_row = 1;
	size_t where_one = 0;
	while (is_triangle_matrix() == false)
	{
		/*show_matrix();
		std::cin.get();*/
		//std::cin.get();
		if (Matrix[i][height] >= i)
		{
			//tutaj dziel caly badz mnoz przez odwrotnosc przekatnych
			size_t multiplier_position = this->Matrix[i][this->height];
			multiplier = Matrix[i][multiplier_position];
			for (size_t j = Matrix[i][height]; j < this->height; ++j)
			{
				this->Matrix[i][j] /= (multiplier);
			}
			where_one = multiplier_position;
		}
		else
		{
			/*show_matrix();
			std::cout << endl;*/
			size_t multiplier_position = this->Matrix[i][this->height];
			multiplier = Matrix[i][multiplier_position];
			if (multiplier != 0)
			{
				for (size_t j = Matrix[i][height]; j < this->height; ++j)
				{
					//std::cout << Matrix[where_one][j] << ' ';
					this->Matrix[i][j] = (Matrix[i][j] - (multiplier * (Matrix[where_one][j])));
				}
				Matrix[i][height] += 1;
			}
		//	std::cout << endl;
		}
		substractor = 0;
		multiplier = 0;
		++i;
		if (i == width)
		{
			i = 1;
		}
	}	
}

bool _Equation_Solve::is_triangle_matrix() const
{
	for (size_t i = 1; i < this->width; ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (Matrix[i][j] != 0 || Matrix[i][i] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

void _Equation_Solve::Show_Solve() const
{
	float row_equation_result = 0;
	float * results = new float[height - 1];
	for (size_t i = 0; i < height - 1; ++i)
	{
		results[i] = 0;
	}
	size_t counter = height - 2;
	//size_t result_counter = 0;
	for (__int32 i = width - 1; i >= 0; --i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			if (j < height - 1)
			{

			}
			else
			{
				/*row_equation_result = (Matrix[i][j]);
				std::cout << row_equation_result << endl;
				std::cin.get();*/
			}
		}
	/*	if (counter >= 0)
		{
			results[counter] = row_equation_result;
			--counter;
		}*/
	}

	for (size_t i = 0; i < height - 1; ++i)
	{
		std::cout << results[i] << ' ';
	}
	std::cout << '\n';
	delete[] results;
}

_Equation_Solve::~_Equation_Solve()
{
	for (size_t i = 0; i < width; ++i)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
}


/*for (size_t k = 0; k < height - 1; ++k)
		{
			if (results[k] == 0)
			{
				continue;
			}
			else
			{
				row_equation_result = results[k];
			}
		}*/


/*
if (j < height - 1)
			{
				for (size_t k = 0; k < height - 1; ++k)
				{
					if (results[k] == 0)
					{
						continue;
					}
					else
					{
						row_equation_result = Matrix[i][j];
					}
				}
				//row_equation_result = Matrix[i][j];
			}
			else
			{

			}
*/

//do
//{
//	if (Matrix[i][height] >= i)
//	{
//		//continue;//poki co continue, tutaj dziel caly badz mnzo przez odwrotnosc przekatnych
//		size_t multiplier_position = this->Matrix[i][this->height];
//		multiplier = Matrix[i][multiplier_position];
//		for (size_t j = Matrix[i][height]; j < this->height; ++j)
//		{
//			Matrix[i][j] /= (multiplier);
//		}
//		where_one = multiplier_position;
//	}
//	else
//	{
//		size_t multiplier_position = this->Matrix[i][this->height];
//		multiplier = Matrix[i][multiplier_position];
//		if (multiplier != 0)
//		{
//			for (size_t j = Matrix[i][height]; j < this->height; ++j)
//			{
//				Matrix[i][j] = (Matrix[i][j] - (multiplier * (Matrix[where_one][j])));
//			}
//			Matrix[i][height] += 1;
//		}
//	}
//	substractor = 0;
//	multiplier = 0;
//	++i;
//	if (i == width)
//	{
//		i = 1;
//	}
//} while (is_triangle_matrix() == false);