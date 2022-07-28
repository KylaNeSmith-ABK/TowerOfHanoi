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
	void RemoveFromDiskUnder();

	// returns and resets the UnderDisk
	Disk* Lift();

	void PrintDisk();

	friend bool operator< (const Disk& diskA, const Disk& diskB);
};