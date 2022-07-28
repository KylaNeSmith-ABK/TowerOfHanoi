#include "Disk.h"

Disk::Disk(int size)
	: Size(size)
{
}

void const Disk::PlaceOnto(Disk* disk)
{
	UnderDisk = disk;
}

Disk* Disk::GetDiskUnder()
{
	return UnderDisk;
}

void Disk::PrintDisk()
{
	std::cout << Size;
}

bool operator<(Disk& diskA, Disk& diskB)
{
	if (diskA.Size < diskB.Size)
	{
		return true;
	}

	return false;
}
