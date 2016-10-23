// CuttingStock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Order
{
	int pipeLength;
	int orderSize;
};

void CreateOrders(std::vector<Order>& Orders)
{
	// Skapa ordrar 
	Order temp;
	temp.pipeLength = 1010;
	temp.orderSize = 10;
	Orders.push_back(temp);

	temp.pipeLength = 1200;
	temp.orderSize = 5;
	Orders.push_back(temp);

	temp.pipeLength = 105;
	temp.orderSize = 3;
	Orders.push_back(temp);

	temp.pipeLength = 540;
	temp.orderSize = 7;
	Orders.push_back(temp);

	temp.pipeLength = 648;
	temp.orderSize = 2;
	Orders.push_back(temp);

	temp.pipeLength = 1010;
	temp.orderSize = 10;
	Orders.push_back(temp);
}

std::vector<int> FindUniqueLengths(const std::vector<Order>& orders)
{
	// Hittar unika l�ngder i en vector

	std::vector<int> result;
	for (size_t i = 0; i < orders.size(); i++)
	{
		bool lengthExists;
		lengthExists = std::find(result.begin(), result.end(), orders[i].pipeLength) != result.end();
		if (!lengthExists)
		{
			result.push_back(orders[i].pipeLength);
		}
	}
	return result;
}

int FindMaxPatternSize(const std::vector<int>& uniqueLengths, const int rawMaterialLength)
{
	// Ber�knar hur m�nga element en pattern max kan inneh�lla

	// TODO: L�gg till en sortering av vectorn f�r att l�ttare kunna g�ra ber�kningen

	int minimumElementValue = *std::min_element(uniqueLengths.begin(), uniqueLengths.end());



	// return *std::min_element(uniqueLengths.begin(), uniqueLengths.end());
}

void CreatePossiblePatterns(const std::vector<Order>& Orders, const int rawMaterialLength, std::vector<int>& Patterns)
{
	std::vector<Order> copyOfOrders = Orders;
	std::vector<int> uniqueLengths;

	uniqueLengths = FindUniqueLengths(copyOfOrders);


	for (size_t i = 0; i < uniqueLengths.size(); i++)
	{
		std::cout << "Skriver ut ordrarnas l�ngder: " << uniqueLengths[i] << std::endl;
	}


	int test = FindMaxPatternSize(uniqueLengths, 7000);
	std::cout << "Minsta elementet: " << test << std::endl;

}


int main()
{
	std::vector<Order> Orders;
	std::vector<int> Patterns;

	CreateOrders(Orders);
	CreatePossiblePatterns(Orders, 7000, Patterns);
	




	std::cin.get();
    return 0;
}

