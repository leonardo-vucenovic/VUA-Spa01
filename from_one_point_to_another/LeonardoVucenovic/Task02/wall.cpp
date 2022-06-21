#include "wall.h"
using namespace std;
wall::wall()
{
	while (!enter()) {
		cout << "Number is out of range! Try again:" << endl;
	}
	set();
}
void wall::set_wall()
{
	Dot t;
	for (int i = 0; i < _wall_hight; i++)
	{
		t.x = wallloc.x - 1;
		t.y = wallloc.y;
		v.push_back(t);
		wallloc.x += 1;

	}
}
bool wall::checkw(int n, int m)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (n == v[i].x && m == v[i].y) {
			return true;
		}


	}
	return false;
}

bool wall::enter()
{
	cout << "Maximum for X cordinates is 20 and for Y is 40" << endl << endl << endl;
	cout << "Cordinates of point A " << endl;
	cout << "X: ";
	cin >> start.x;
	cout << "Y: ";
	cin >> start.y;
	cout << "Cordinates of point B " << endl;
	cout << "X: ";
	cin >> end.x;
	cout << "Y: ";
	cin >> end.y;
	cout << "Enter hight of the wall: ";
	cin >> _wall_hight;
	if (_wall_hight < 1 || _wall_hight > 20)
	{
		return false;
	}
	cout << endl << endl;
	cout << "Enter the coordinates of the wall! " << endl;
	cout << "X: ";
	cin >> wallloc.x;
	cout << "Y: ";
	cin >> wallloc.y;
	set_wall();
	return check(start) && check(end);

}
void wall::set()
{
	start.x--;
	start.y--;
	end.x--;
	end.y--;
	wallloc.x--;
	wallloc.y--;
	_wall_hight--;


	this->currentl.x = start.x;
	this->currentl.y = start.y;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == start.x && j == start.y)
			{
				field[i][j] = 'A';
			}
			else if (i == end.x && j == end.y)
			{
				field[i][j] = 'B';
			}
			else if (checkw(i, j)) {
				field[i][j] = '|';

			}
			else
			{
				field[i][j] = '-';
			}

		}
	}

}
bool wall::check(Dot dot)
{
	return !(dot.x < 1 || dot.x > R || dot.y < 1 || dot.y > C);
}

void wall::draw()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (currentl.x == i && currentl.y == j)
			{
				cout << '#';
			}
			else
			{
				cout << field[i][j];
			}
		}
		cout << endl;
	}
}
bool wall::next()
{
	if (end.x == currentl.x && end.y == currentl.y)
	{
		return false;
	}
	if (start.x <= end.x)
	{
		while (checkw(currentl.x, currentl.y))
		{
			currentl.x++;
		}
		if (this->currentl.y < this->end.y)
		{
			currentl.y++;
		}
		else
		{
			currentl.x++;
		}

	}
	else
	{
		while (checkw(currentl.x, currentl.y))
		{
			currentl.x--;

		}
		if (this->currentl.y > this->end.y)
		{
			currentl.y--;
		}
		else
		{
			currentl.x--;
		}
	}
	return true;
}
