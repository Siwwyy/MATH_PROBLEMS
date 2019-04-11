#ifndef _GAUS_JORDAN_ELIMINATION_H_
#define _GAUS_JORDAN_ELIMINATION_H_
#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>

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
	bool is_triangle_matrix() const;
	bool zeros_row(const size_t row) const;
	void Show_Solve() const;
	//////////////////////////////////////////////////////////////////////////////
	/*
		DESTRUKTOR
	*/
	virtual ~_Equation_Solve();				//destruktor
	//////////////////////////////////////////////////////////////////////////////
};

#endif /* _GAUS_JORDAN_ELIMINATION_H_ */