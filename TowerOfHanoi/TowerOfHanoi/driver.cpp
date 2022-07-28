#include <iostream>;

#include "TowerOfHanoi.h"

void TowerOfHanoiText(int diskNum, char origin, char destination, char auxiliary);
static int Count = 0;

int main()
{
	TowerOfHanoi* ToH = new TowerOfHanoi(5);
	ToH->Solve();
}

void TowerOfHanoiText(int diskNum, char origin, char destination, char auxiliary)
{
	if (diskNum == 0)
	{
		return;
	}
	TowerOfHanoiText(diskNum - 1, origin, auxiliary, destination);
	std::cout << "Move disk #" << diskNum << " from " << origin << " to " << destination << std::endl;
	TowerOfHanoiText(diskNum - 1, auxiliary, destination, origin);
}