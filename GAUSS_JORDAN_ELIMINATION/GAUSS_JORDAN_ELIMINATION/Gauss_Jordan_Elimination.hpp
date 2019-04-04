#ifndef _GAUS_JORDAN_ELIMINATION_H_
#define _GAUS_JORDAN_ELIMINATION_H_
#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>

class _Equation_Solve
{
private:
	/*
		ZMIENNE PRIVATE
	*/
	float **Matrix;
	size_t width;
	size_t height;
	//////////////////////////////////////////////////////////////////////////////
protected:
	/*
		ZMIENNE PROTECTED
	*/

	//////////////////////////////////////////////////////////////////////////////
public:
	/*
		KONSTRUKTORY
	*/
	_Equation_Solve();			//konstruktor bezparametrowy
	//////////////////////////////////////////////////////////////////////////////
	/*
		FUNKCJE PUBLIC
	*/
	void show_matrix(void) const;
	void Gauss_Jordan_Elimination();
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Equation_Solve();				//destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _GAUS_JORDAN_ELIMINATION_H_ */