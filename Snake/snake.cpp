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
int getScore()
{
	return score;
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

			if (i == cordY && j == cordX)
			{
				cout << "O";
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}
			else
				cout << " ";
		}

		cout << endl;
	}

	for (int i = 0; i <= width; i++)
	{
		cout << "#";
	}

	cout << endl;
	cout << "Score: " << score <<endl;

}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'q':
			isGameOver = true;
			break;
		}
	}
}

void logic()
{
	switch (dir)
	{
	case RIGHT:
		cordX++;
		break;
	case LEFT:
		cordX--;
		break;
	case UP:
		cordY--;
		break;
	case DOWN:
		cordY++;	
		break;
	default:
		break;
	}

	if (cordX > width - 1 || cordX - 1 < 0 || cordY > height - 1 || cordY - 1 < 0)
	{
		isGameOver = true;
	}

	if (cordX == fruitX && cordY == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}