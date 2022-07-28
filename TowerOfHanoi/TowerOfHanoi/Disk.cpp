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

void Disk::RemoveFromDiskUnder()
{
	UnderDisk = nullptr;
}

Disk* Disk::Lift()
{
	Disk* temp = UnderDisk;
	UnderDisk = nullptr;
	return temp;
}

void Disk::PrintDisk()
{
	std::cout << Size;
}

bool operator<(const Disk& diskA, const Disk& diskB)
{
	return diskA.Size < diskB.Size;
}
