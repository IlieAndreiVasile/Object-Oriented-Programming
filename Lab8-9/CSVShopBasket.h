#pragma once
#include "ShopBasket.h"
#include <Windows.h>

class CSV : public ShopBasket
{
public:
	void writeToFile() override
	{
		std::ofstream fout("ShopBasket.csv");
		for (auto it : v)
			fout << it;
		/*fout.close();*/
	}

	void executeThings() override
	{
		this->writeToFile();
		ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\Office14\\EXCEL.exe", "ShopBasket.csv", NULL, SW_SHOWMAXIMIZED);
	}
};