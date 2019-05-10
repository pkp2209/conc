#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include "cnc.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Concert A(1);
	std::ifstream fin("1.txt");
	while (!fin.eof())
	{
		fin >> A;
	}

	std::cout << A;
	A.sortName();

	std::cout << A;
	std::cout << A.getN() << std::endl;
	std::cout << A[2].name << std::endl;
	std::cout << A;
	A.book(3);
	A.sortData();
	std::cout << A;
	system("pause");
	fin.close();
	return 0;
}