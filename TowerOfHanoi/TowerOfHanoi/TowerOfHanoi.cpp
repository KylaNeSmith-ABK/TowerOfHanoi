#include "TowerOfHanoi.h"

TowerOfHanoi::TowerOfHanoi(int numofDisks)
	: NumberOfDisks(numofDisks)
{
	TowerA->FillTower();
}

TowerOfHanoi::~TowerOfHanoi()
{
	delete TowerA;
	delete TowerB;
	delete TowerC;
}

void TowerOfHanoi::Solve()
{
	if (bSolved)
	{
		Reset();
	}

	Print();
	SolveHelper(NumberOfDisks, TowerA, TowerC, TowerB);
	bSolved = true;
}

void TowerOfHanoi::Reset()
{
	Clear();
	TowerA->FillTower();
}

void TowerOfHanoi::Clear()
{
	TowerA->EmptyTower();
	TowerB->EmptyTower();
	TowerC->EmptyTower();
	Counter = 0;
	bSolved = false;
}

void TowerOfHanoi::Print()
{
	TowerA->PrintTower();
	std::cout << std::endl;
	TowerB->PrintTower();
	std::cout << std::endl;
	TowerC->PrintTower();
	std::cout << std::endl;
	std::cout << "Count: " << Counter << std::endl;
	std::cout << std::endl;
}

void TowerOfHanoi::SolveHelper(int numOfDisks, Tower* origin, Tower* destination, Tower* auxiliary)
{
	if (numOfDisks == 0)
	{
		return;
	}
	SolveHelper(numOfDisks - 1, origin, auxiliary, destination);

	Disk* temp = origin->RemoveTopDisk();
	if (temp != nullptr)
	{
		destination->PlaceDisk(temp);
	}
	else
	{
		// put in to test behavior
		// should never print this
		std::cout << "ERROR! Handling null Disk!" << std::endl;
	}
	
	Counter++;
	Print();

	SolveHelper(numOfDisks - 1, auxiliary, destination, origin);
}
