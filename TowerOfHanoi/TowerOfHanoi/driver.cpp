#include <iostream>;

#include "TowerOfHanoi.h"

void TowerOfHanoiText(int diskNum, char origin, char destination, char auxiliary);
static int Count = 0;

int main()
{
	TowerOfHanoiText(3, 'A', 'C', 'B');
	std::cout << std::endl;


	TowerOfHanoi* ToH = new TowerOfHanoi(20);
	ToH->Solve();

	delete ToH;
	ToH = nullptr;
}

// from https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
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