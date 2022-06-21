#pragma once
#include<iostream>
#include<vector>
using namespace std;
struct Dot
{
	int x, y;
};
class wall
{
private:
	static const unsigned int R = 20;
	static const unsigned int C = 40;
	Dot currentl;
	Dot start;
	Dot end;
	Dot wallloc;
	int _wall_hight;
	vector <Dot> v;
	char field[R][C];
	bool enter();
	void set();
	void set_wall();
	bool checkw(int n, int m);
	bool check(Dot d);

public:
	wall();
	void draw();
	bool next();

};
