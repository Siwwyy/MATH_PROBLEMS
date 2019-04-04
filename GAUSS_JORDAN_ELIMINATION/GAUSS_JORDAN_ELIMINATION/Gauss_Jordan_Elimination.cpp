#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

_Equation_Solve::_Equation_Solve():
	width(3),
	height(4)
{
	std::fstream file_in;
	file_in.open("matrix2.in", std::ios_base::in);
	//file_in.open("matrix.in", std::ios_base::in);
	Matrix = new float*[width];
	for (size_t i = 0; i < width; ++i)
	{
		Matrix[i] = new float[height];
	}

	//INITIALIZE THE MATRIX FROM FILE
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			file_in >> Matrix[i][j];
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
				std::cout << " = " << Matrix[i][j];
			}
		}
		std::cout << endl;
	}
}

void _Equation_Solve::Gauss_Jordan_Elimination()
{	//to repair
	if (this->Matrix[0][0] != 1)
	{
		if (this->Matrix[0][0] > 0)
		{
			float divider = Matrix[0][0];
			for (size_t i = 0; i < this->height; ++i)
			{
				this->Matrix[0][i] /= divider;
			}
			show_matrix();
			system("pause");
		}
		else if (this->Matrix[0][0] == 0)
		{
			for (size_t i = 0; i < this->height; ++i)
			{
				this->Matrix[0][i] += 1;
			}
			system("pause");
			show_matrix();
			system("pause");
		}
		else
		{
			this->Matrix[0][0] *= -1;
			float divider = Matrix[0][0];
			for (size_t i = 0; i < this->height; ++i)
			{
				this->Matrix[0][i] /= divider;
			}
			system("pause");
			show_matrix();
			system("pause");
		}
		//for (size_t i = 0; i < this->width; ++i)
		//{
		//	float substractor = Matrix[i][0];
		//	/*if (substractor < 0)
		//	{
		//		substractor *= -1;
		//	}*/
		//	for (size_t j = 0; j < this->height; ++j)
		//	{
		//		if (i > 0)
		//		{
		//			Matrix[i][j] -= (substractor);
		//		}	
		//	}
		//}
		//show_matrix();
		//system("pause");
	}
	else
	{

	}
	//for (size_t j = 0; j < height; ++j)
	//{

	//}
	
			/*if (i == 0)
			{
				if (Matrix[i][j] != 1)
				{
					if (Matrix[i][j] > 0)
					{

					}
					else if (Matrix[i][j] == 0)
					{

					}
					else
					{

					}
				}
				else
				{

				}
			}
			else
			{

			}*/
		//}
	//}
}

_Equation_Solve::~_Equation_Solve()
{
	for (size_t i = 0; i < width; ++i)
	{
		delete[] Matrix[i];
	}
	delete[] Matrix;
}
