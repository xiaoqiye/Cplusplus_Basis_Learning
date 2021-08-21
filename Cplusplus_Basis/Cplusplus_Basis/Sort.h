#pragma once
#ifndef __SORT__
#define __SORT__

#include <vector>

class CSortAlgorithm
{
public:
	CSortAlgorithm() = default;
	~CSortAlgorithm() = default;

	void insertSortBasis(std::vector<int>& vVector, bool vIsAscending);

	void quickSortBasis(std::vector<int>& vVector, bool vIsAscending);
	void quickSortBasisHelper(std::vector<int>& vVector, int vBeginIndex, int vEndIndex, bool vIsAscending);

	void printEachElement(const std::vector<int>& vVector);
private:

};

void CSortAlgorithm::insertSortBasis(std::vector<int>& vVector, bool vIsAscending)
{
	int Size = vVector.size();
	if (Size < 2)
		return;

	for (int i = 1; i < Size; ++i)
	{
		for (int k = i; k > 0; --k)
		{
			if (vIsAscending)
			{
				if (vVector[k] < vVector[k - 1])
				{
					int Temp = vVector[k];
					vVector[k] = vVector[k - 1];
					vVector[k - 1] = Temp;

					continue;
				}
			}
			else
			{
				if (vVector[k] > vVector[k- 1])
				{
					int Temp = vVector[k];
					vVector[k] = vVector[k - 1];
					vVector[k - 1] = Temp;

					continue;
				}
			}
		}
	}
}

void CSortAlgorithm::quickSortBasis(std::vector<int>& vVector, bool vIsAscending)
{
	int Size = vVector.size();
	if (Size < 2)
		return;

	quickSortBasisHelper(vVector, 0, Size - 1, vIsAscending);
}

void CSortAlgorithm::quickSortBasisHelper(std::vector<int>& vVector, int vBeginIndex, int vEndIndex, bool vIsAscending)
{

}

void CSortAlgorithm::printEachElement(const std::vector<int>& vVector)
{
	int Size = vVector.size();
	if (Size < 1)
	{
		std::cout << "It is empty!" << std::endl;
		return;
	}

	for (auto& i : vVector)
		std::cout << i << ",";

	std::cout << std::endl;
}

#endif