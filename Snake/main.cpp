#include "snake.h"

using namespace std;

int main()
{
	setup();
	
	while (!getGameOver())
	{
		draw();
		input();
		logic();
	}
	system("pause");
	return 0;
}