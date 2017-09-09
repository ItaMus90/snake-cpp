#include <iostream>
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
bool getGameOver();
void setGameOver(bool);
void setDir(eDirection);
eDirection gerDirection();

