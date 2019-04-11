#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

_Equation_Solve::_Equation_Solve():
	width(0),
	height(0)
{
	std::fstream file_in;
	//file_in.open("matrix2.in", std::ios_base::in);
	//file_in.open("matrix.in", std::ios_base::in);
	//file_in.open("matrix10x11.in", std::ios_base::in);
	file_in.open("matrix20x21.in", std::ios_base::in);
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
				{//setprecision for precision result, if u want change it to bigger number, for example std::setprecision(10), u will se 10 numbers after the ,
					if (Matrix[i][j] >= 0)
					{
						std::cout << " + " << std::setprecision(2) << Matrix[i][j] << "x" << j;
					}
					else
					{
						std::cout << ' ' << std::setprecision(2) << Matrix[i][j] << "x" << j;
					}
				}
				else
				{
					std::cout << ' ' << std::setprecision(2) << Matrix[i][j] << "x";
				}
			}
			else
			{
				std::cout << " = " << std::setprecision(2) << Matrix[i][j] << ' ';
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
		if (Matrix[i][height] >= i)
		{
			//here multiply or divide the row by reverse value
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
			size_t multiplier_position = this->Matrix[i][this->height];
			multiplier = Matrix[i][multiplier_position];
			if (multiplier != 0)
			{
				for (size_t j = Matrix[i][height]; j < this->height; ++j)
				{
					this->Matrix[i][j] = (Matrix[i][j] - (multiplier * (Matrix[where_one][j])));
				}
				Matrix[i][height] += 1;
			}
		/*	if (zeros_row(i) == true)
			{
				for (size_t j = 0; j < this->height; ++j)
				{
					std::swap(Matrix[i][j], Matrix[i + 1][j]);
				}
			}*/
			/*show_matrix();
			std::cin.get();*/
		}
		substractor = 0;
		multiplier = 0;
		++i;
		/*if (zeros_row(width - 1) == true)
		{
			break;
		}*/
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

bool _Equation_Solve::zeros_row(const size_t row) const
{
	for (size_t i = row; i <= row; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			if (Matrix[i][j] != 0)
			{
				return false;
			}
		}
		return true;
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
	__int32 counter = height - 2;
	for (__int32 i = width - 1; i >= 0; --i)
	{
		if (Matrix[i][i] == 1)
		{
			float substract_result = 0;
			if (counter == height - 2)
			{
				results[counter] = Matrix[i][height - 1];
			}
			else
			{
				for (__int32 j = height - 2; j >= counter; --j)
				{
					substract_result += (Matrix[i][j]*results[j]);
				}
				row_equation_result = (Matrix[i][height - 1] + (-1*substract_result));
				results[counter] = row_equation_result;
			}
			--counter;
			row_equation_result = 0;
		}
	}

	std::cout << "----------------------------" << '\n';
	std::cout << "RESULTS:" << '\n';
	std::cout << "| ";
	for (size_t i = 0; i < height - 1; ++i)
	{
		std::cout << 'x' << i << " = " << results[i] << " | ";
	}
	std::cout << '\n';
	std::cout << "----------------------------" << '\n';
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