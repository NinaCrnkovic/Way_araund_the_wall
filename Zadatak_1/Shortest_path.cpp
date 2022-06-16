#include "Shortest_path.h"


using namespace std;


Shortest_path::Shortest_path()
{
	cout << "Enter dots A and B:" << endl;

	while (!enter_dots()) {
		cout << "Number is out of range! Try again:" << endl;
	}

	set_field();
}

bool Shortest_path::enter_dots()
{
	cout << "Enter dot A x cordinate (Range: 1-" << this->ROW << "): ";
	cin >> _start_location.x;
	cout << "Enter dot A y cordinate (Range: 1-" << this->COL << "): ";
	cin >> _start_location.y;

	cout << "Enter dot B x cordinate (Range: 1-" << this->ROW << "): ";
	cin >> _end_location.x;
	cout << "Enter dot A y cordinate (Range: 1-" << this->COL << "): ";
	cin >> _end_location.y;

	return check_dot(_start_location) && check_dot(_end_location);
}

void Shortest_path::set_field()
{
	_start_location.x--;
	_start_location.y--;
	_end_location.x--;
	_end_location.y--;

	this->_current_location.x = _start_location.x;
	this->_current_location.y = _start_location.y;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == _start_location.x && j == _start_location.y)
			{
				_field[i][j] = 'A';
			}
			else if (i == _end_location.x && j == _end_location.y)
			{
				_field[i][j] = 'B';
			}
			else
			{
				_field[i][j] = '.';
			}

		}
	}

}

bool Shortest_path::check_dot(Dot dot)
{
	return !(dot.x < 1 || dot.x > ROW || dot.y < 1 || dot.y > COL);
}

void Shortest_path::draw()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (_current_location.x == i && _current_location.y == j)
			{
				cout << '#';
			}
			else
			{
				cout << _field[i][j];
			}
		}
		cout << endl;
	}
}


bool Shortest_path::next()
{
	if (_end_location.x == _current_location.x && _end_location.y == _current_location.y)
	{
		return false;
	}

	if (_start_location.x <= _end_location.x)
	{
		if (this->_current_location.y < this->_end_location.y)
		{
			_current_location.y++;
		}
		else
		{
			_current_location.x++;
		}
	}
	else
	{
		if (this->_current_location.y > this->_end_location.y)
		{
			_current_location.y--;
		}
		else
		{
			_current_location.x--;
		}
	}
	return true;
}