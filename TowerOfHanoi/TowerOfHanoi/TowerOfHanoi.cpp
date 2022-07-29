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
	printf("\n");
	TowerB->PrintTower();
	printf("\n");
	TowerC->PrintTower();
	printf("\n");
	printf("Count: %i", Counter);
	printf("\n\n");
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
		printf("ERROR! Handling null Disk!");
	}
	
	Counter++;
	Print();

	SolveHelper(numOfDisks - 1, auxiliary, destination, origin);
}
