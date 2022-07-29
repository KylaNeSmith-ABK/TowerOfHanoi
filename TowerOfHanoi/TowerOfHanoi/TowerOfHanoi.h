#pragma once
#include <iostream>

#include "Tower.h"

class TowerOfHanoi
{
private:
	int Counter = 0;
	int NumberOfDisks = 3;
	bool bSolved = false;

	Tower* TowerA = new Tower("A", NumberOfDisks);
	Tower* TowerB = new Tower("B", NumberOfDisks);
	Tower* TowerC = new Tower("C", NumberOfDisks);

public:
	TowerOfHanoi(int numofDisks = 3);
	~TowerOfHanoi();

	void Solve();
	void Reset();
	void Clear();

	void Print();

private:
	void SolveHelper(int numOfDisks, Tower* origin, Tower* destination, Tower* auxiliary);
};