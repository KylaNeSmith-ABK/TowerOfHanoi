#pragma once
#include <iostream>

#include "Disk.h"

class Tower
{
private:
	std::string TowerName = "ERROR!";
	int FullSize = 3;
	int CurrentSize = 0;
	Disk* TopDisk = nullptr;

public:
	Tower(std::string towerName,  int size = 3);
	~Tower();

	void FillTower();
	void EmptyTower();
	void PlaceDisk(Disk* disk);
	Disk* RemoveTopDisk();

	void PrintTower();
};