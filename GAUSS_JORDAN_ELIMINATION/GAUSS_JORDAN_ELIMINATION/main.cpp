#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	//setlocale(LC_ALL, "");
	_Equation_Solve Obj;	//basic matrix
	Obj.show_matrix();
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	Obj.Gauss_Jordan_Elimination();
	Obj.Show_Solve();
	//char abc[] = { 0x01, 0x02, 0x03, 0x04 };
	//unsigned short * ptr = (unsigned short*)(void*)abc;
	////std::cout << std::hex << ptr[1] << endl;
	//std::cout << "AĄ" << endl;
	system("pause");
	return EXIT_SUCCESS;
}