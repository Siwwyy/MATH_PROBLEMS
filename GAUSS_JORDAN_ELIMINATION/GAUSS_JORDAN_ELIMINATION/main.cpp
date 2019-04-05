#include <iostream>
#include <windows.h>
#include <string>

#include "Gauss_Jordan_Elimination.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	_Equation_Solve Obj;	//basic matrix
	Obj.show_matrix();
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
	Obj.Gauss_Jordan_Elimination();
	system("pause");
	return EXIT_SUCCESS;
}