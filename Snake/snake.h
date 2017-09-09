#include <iostream>
#include <conio.h>

enum eDirection
{
	STOP = 0,
	RIGHT,
	LEFT,
	UP,
	DOWN,
};
//Declre Method
void setup();
void draw();
void input();
void logic();
void setGameOver(bool);
bool getGameOver();
int getScore();

