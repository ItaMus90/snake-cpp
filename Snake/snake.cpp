#include "snake.h"

using namespace std;

//Declere Variable

eDirection dir;
const int width = 20;
const int height = 20;
bool isGameOver = false;
bool isPrint = false;
int cordX, cordY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int lengthTail;

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

	for (int i = 0; i < width+1; i++)
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
			{
				isPrint = false;

				for (int k = 0; k < lengthTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i) 
					{
						cout << "o";
						isPrint = true;
					}
				}

				if (!isPrint)
				{
					cout << " ";
				}
			}
		}

		cout << endl;
	}

	for (int i = 0; i < width+1; i++)
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
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2x, prev2Y;
	tailX[0] = cordX;
	tailY[0] = cordY;

	for (int i = 1; i < lengthTail; i++)
	{
		prev2x = tailX[0];
		prev2Y = tailY[0];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2x;
		prevY = prev2Y;
	}

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

	if (cordX > width  || cordX  < 0 || cordY > height  || cordY  < 0)
	{
		isGameOver = true;
	}

	if (cordX >= width)
	{
		cordX = 0;
	}
	else if (cordX < 0)
	{
		cordX = width - 1;
	}

	if (cordY >= height)
	{
		cordY = 0;
	}
	else if (cordY < 0)
	{
		cordY = height - 1;
	}

	for (int i = 0; i < lengthTail; i++)
	{
		if (tailX[i] == cordX && tailY[i] == cordY)
		{
			isGameOver = true;
		}
	}
	if (cordX == fruitX && cordY == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		lengthTail++;

	}
}