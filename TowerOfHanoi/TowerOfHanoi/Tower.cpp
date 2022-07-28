#include "Tower.h"

Tower::Tower(std::string towerName, int size)
	: TowerName(towerName)
	, FullSize(size)
{
}

void Tower::FillTower()
{
	TopDisk = new Disk(FullSize);

	// since one Disk has already been made, make FullSize - 1 more Disks
	for (int i = FullSize - 1; i > 0; i--)
	{
		Disk* temp = new Disk(i);
		temp->PlaceOnto(TopDisk);
		TopDisk = temp;
	}
	CurrentSize = FullSize;
}

void Tower::PlaceDisk(Disk* disk)
{
	// put in to test behavior
	// should never print this
	if (TopDisk && (*TopDisk < *disk))
	{
		std::cout << "ERROR! Cannot put larger Disk on smaller Disk!" << std::endl;
	}

	if (TopDisk != nullptr)
	{
		disk->PlaceOnto(TopDisk);
	}

	TopDisk = disk;
	CurrentSize++;
}

Disk* Tower::RemoveTopDisk()
{
	if (TopDisk)
	{
		Disk* temp = TopDisk;
		TopDisk = TopDisk->Lift();
		CurrentSize--;
		return temp;
	}

	return nullptr;
}

void Tower::PrintTower()
{
	std::cout << TowerName << ": ";
	Disk* temp = TopDisk;

	for (int i = 0; i < FullSize; i++)
	{
		if (temp && (i >= FullSize - CurrentSize))
		{
			std::cout << " ";
			temp->PrintDisk();
			temp = temp->GetDiskUnder();
		}
		else
		{
			std::cout << " -";
		}
	}
}
