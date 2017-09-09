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
		Sleep(20);
	}
	cout << " Game is over and your score is: " << getScore() << endl;

	system("pause");
	return 0;
}