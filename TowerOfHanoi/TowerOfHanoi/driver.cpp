#include <iostream>;

#include "TowerOfHanoi.h"

void TowerOfHanoiText(int diskNum, char origin, char destination, char auxiliary);
static int Count = 0;

int main()
{
	TowerOfHanoiText(3, 'A', 'C', 'B');

	printf("\n");


	TowerOfHanoi* ToH = new TowerOfHanoi(16);
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
	printf("Move disk #%i from %c to %c\n", diskNum, origin, destination);
	TowerOfHanoiText(diskNum - 1, auxiliary, destination, origin);
}