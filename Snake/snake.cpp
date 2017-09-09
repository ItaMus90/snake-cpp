#include "snake.h"

using namespace std;

//Declere Variable

eDirection dir;
const int width = 20;
const int height = 20;
bool isGameOver = false;
int cordX, cordY, fruitX, fruitY, score;

//Implement Method
void setup()
{
	isGameOver = false;
	dir = STOP;
	cordX = width / 2;
	cordY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void setDir(eDirection eDir)
{
	dir = eDir;
}

eDirection gerDirection()
{
	return dir;
}

int getWidth()
{
	return width;
}

int getHeight()
{
	return height;
}

bool getGameOver()
{
	return isGameOver;
}

void setGameOver(bool game)
{
	isGameOver = game;
}

void draw()
{
	system("cls");

	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}

	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}

			if (j == width - 1)
			{
				cout << "#";
			}

			cout << " ";
		}

		cout << endl;
	}

	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}

	cout << endl;

}

void input()
{

}

void logic()
{

}