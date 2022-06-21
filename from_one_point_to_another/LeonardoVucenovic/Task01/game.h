#pragma once
#include<iostream>
using namespace std;
struct Dot
{
	int x, y;
};
class game
{
private:
	static const unsigned int R = 20;
	static const unsigned int C = 40;
	Dot currentl;
	Dot start;
	Dot end;
	char _field[R][C];
	bool enter();
	void set();
	bool check(Dot d);
public:
	game();
	void draw();
	bool next();
};

