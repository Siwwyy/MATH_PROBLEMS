#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const __int64 sigma(__int64 begin_value)
{
	__int64 sigma_value = 0;
	while (begin_value > 0)
	{
		sigma_value += begin_value;
		--begin_value;
	}
	return sigma_value;
}

int main(int argc, char * argv[])
{
	std::cout << sigma(98) << '\n';
	std::cout << sigma(5) << '\n';
	system("pause");
	return EXIT_SUCCESS;
}