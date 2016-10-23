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

std::vector<int> GetUniqueLengths(const std::vector<Order>& orders)
{
	// Hittar unika längder i en vector

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

	std::sort(result.begin(), result.end());
	return result;
}

int GetMaxPatternSize(const std::vector<int>& uniqueLengths, int length)
{
	// Beräknar hur många element en pattern max kan innehålla

	int minimumElementValue = uniqueLengths[0];
	int remainingMaterial = length;
	int result = 0;


	do
	{
		remainingMaterial -= minimumElementValue;
		if (remainingMaterial > 0)
		{
			result++;
		}
	} while (remainingMaterial > 0);
	return result;
}

int GetMinPatternSize(const std::vector<int>& uniqueLengths, int length)
{
	// Beräknar hur många element en pattern min kan innehålla


	int remainingMaterial = length;
	int result = 0;


	// Loopa baklänges genom vectorn för att börja med det största elementet.
	std::vector<int>::const_reverse_iterator it;
	for (it = uniqueLengths.rbegin(); it != uniqueLengths.rend(); it++)
	{
		do
		{
			if (remainingMaterial > *it)
			{
				// std::cout << "Lägger till längd: " << *it << std::endl;
				remainingMaterial -= *it;
				result++;
			}
		} while (remainingMaterial > *it);
	}
	return result;
}


void CreatePossiblePatterns(const std::vector<Order>& Orders, const int rawMaterialLength, std::vector<int>& Patterns)
{
	std::vector<Order> copyOfOrders = Orders;
	std::vector<int> uniqueLengths;

	uniqueLengths = GetUniqueLengths(copyOfOrders);


	for (size_t i = 0; i < uniqueLengths.size(); i++)
	{
		std::cout << "Skriver ut ordrarnas längder: " << uniqueLengths[i] << std::endl;
	}


	// Testkod, ta bort!
	int maxPatternSize = GetMaxPatternSize(uniqueLengths, 7000);
	std::cout << "Max antal element: " << maxPatternSize << std::endl;

	int minPatternSize = GetMinPatternSize(uniqueLengths, 7000);
	std::cout << "Minst antal element: " << minPatternSize << std::endl;

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

