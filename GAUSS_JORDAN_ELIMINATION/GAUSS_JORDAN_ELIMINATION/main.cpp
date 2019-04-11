#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <random>

#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

void matrix_generator(const size_t width, const size_t height)
{
	std::random_device rand;								//do odpalenia silnika
	std::mt19937 generator(rand());							//standardowy generator (mersenne_twister_engine)
	std::uniform_int_distribution<> dis(-50,100);			//zakres naszego losowania
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			std::cout << dis(generator) << ' ';
		}
		std::cout << '\n';
	}
}

int main(int argc, char * argv[])
{
	//setlocale(LC_ALL, "");
	/*matrix_generator(20, 21);
	std::cin.get();*/
	_Equation_Solve Obj;	//basic matrix
	cout << "----------------------------------------------------" << endl;
	Obj.show_matrix();
	cout << "----------------------------------------------------" << endl;
	Obj.Gauss_Jordan_Elimination();
	Obj.show_matrix();
	Obj.Show_Solve();
	//char abc[] = { 0x01, 0x02, 0x03, 0x04 };
	//unsigned short * ptr = (unsigned short*)(void*)abc;
	////std::cout << std::hex << ptr[1] << endl;
	//std::cout << "AĄ" << endl;
	system("pause");
	return EXIT_SUCCESS;
}