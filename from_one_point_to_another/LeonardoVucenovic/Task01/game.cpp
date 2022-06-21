#include "game.h"
using namespace std;
bool game::enter()
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

	return check(start) && check(end);
}
game::game()
{
	while (!enter()) { cout << "Number is out of range! Try again:" << endl;
	}
	set();
}
void game::set()
{
	start.x--;
	start.y--;
	end.x--;
	end.y--;

	this->currentl.x = start.x;
	this->currentl.y = start.y;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == start.x && j == start.y)
			{
				_field[i][j] = 'A';
			}
			else if (i == end.x && j == end.y)
			{
				_field[i][j] = 'B';
			}
			else
			{
				_field[i][j] = '-';
			}

		}
	}
}
bool game::check(Dot d)
{
	return !(d.x < 1 || d.x > R || d.y < 1 || d.y > C);
}
void game::draw()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (currentl.x == i && currentl.y == j)
			{
				cout << 'X';
			}
			else
			{
				cout << _field[i][j];
			}
		}
		cout << endl;
	}
}
bool game::next()
{
	if (end.x == currentl.x && end.y == currentl.y)
	{
		return false;
	}

	if (start.x <= end.x)
	{
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