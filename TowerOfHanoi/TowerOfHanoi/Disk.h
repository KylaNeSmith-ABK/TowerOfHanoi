#pragma once
#include <iostream>

class Disk
{
private:
	int Size = 0;
	Disk* UnderDisk = nullptr;

public:
	Disk(int size);

	void const PlaceOnto(Disk* disk);
	Disk* GetDiskUnder();

	void PrintDisk();

	friend bool operator< (Disk& diskA, Disk& diskB);
};