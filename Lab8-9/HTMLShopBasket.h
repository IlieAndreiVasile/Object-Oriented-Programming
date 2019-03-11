#pragma once
#include "ShopBasket.h"
#include <Windows.h>

class HTML : public ShopBasket
{
public:
	void writeToFile() override
	{
		std::ofstream fout("ShopBasket.html");

		std::string rez = "<!DOCTYPE html>\n";
		rez += "<html>\n";
		rez += "<head>\n";
		rez += "<title>ShopBasket</title>\n";
		rez += "</head>\n";
		rez += "<body>\n";
		rez += "<table border=\"1\">\n";
		rez += "<tr>\n";
		rez += "<td>Size</td>\n";
		rez += "<td>Colour</td>\n";
		rez += "<td>Price</td>\n";
		rez += "<td>Photograph</td>\n";
		rez += "</tr>\n";

		for (auto it : v) {

			rez += "<tr>\n";
			std::stringstream ss1, ss2;

			ss1 << it.getSize();
			ss2 << it.getPrice();

			rez += "<td>" + ss1.str() + "</td>\n";
			rez += "<td>" + it.getColour() + "</td>\n";
			rez += "<td>" + ss2.str() + "</td>\n";
			rez += "<td><a href=\"" + it.getPhotograph() + "\">" + "Link" + "</a></td>\n";

			rez += "</tr>\n";
		}

		rez += "</table>";
		rez += "</body>\n";
		rez += "</html>\n";

		fout << rez;
	}

	void executeThings() override
	{
		this->writeToFile();
		ShellExecuteA(NULL, NULL, "chrome.exe", "ShopBasket.html", NULL, SW_SHOWMAXIMIZED);
	}
};
