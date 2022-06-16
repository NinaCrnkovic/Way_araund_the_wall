#include "Way_around_the_wall.h"
#include<vector>
using namespace std;


Way_around_the_wall::Way_around_the_wall()
{
	cout << "Enter dots A and B:" << endl;

	while (!enter_dots()) {
		cout << "Number is out of range! Try again:" << endl;
		vd.clear();
	}

	set_field();
}
void Way_around_the_wall::set_wall()
{
	Dot t;
	for (int i = 0; i < _wall_hight; i++)
	{
		t.x = _wall_location.x-1;
		t.y = _wall_location.y;
		vd.push_back(t);
		_wall_location.x += 1;
			 
	}
}

bool Way_around_the_wall::check_wall_cordinate_x_y(int n, int m)
{
	for (int i = 0; i < vd.size(); i++)
	{
		if (n == vd[i].x && m== vd[i].y) {
			return true;
		}
		
	
	}
	return false;
}

bool Way_around_the_wall::enter_dots()
{
	cout << "Enter dot A x cordinate (Range: 1-" << this->ROW << "): ";
	cin >> _start_location.x;
	cout << "Enter dot A y cordinate (Range: 1-" << this->COL << "): ";
	cin >> _start_location.y;

	cout << "Enter dot B x cordinate (Range: 1-" << this->ROW << "): ";
	cin >> _end_location.x;
	cout << "Enter dot A y cordinate (Range: 1-" << this->COL << "): ";
	cin >> _end_location.y;

	cout << "Enter hight of the wall: ";
	cin >> _wall_hight;
	if (_wall_hight < 1 || _wall_hight > 20) 
	{
		return false; 
	}


	cout << "Enter wall x cordinate (Range: 1-" << this->ROW << "): ";
	cin >> _wall_location.x;
	
	cout << "Enter wall y cordinate (Range: 1-" << this->COL << "): ";
	cin >> _wall_location.y;

	set_wall();

	return check_dot(_start_location) && check_dot(_end_location);

}


void Way_around_the_wall::set_field()
{
	_start_location.x--;
	_start_location.y--;
	_end_location.x--;
	_end_location.y--;
	_wall_location.x--;
	_wall_location.y--;
	_wall_hight--;


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
			else if (check_wall_cordinate_x_y(i, j)) {
				_field[i][j] = '|';
										
			}
			else
			{
				_field[i][j] = '.';
			}

		}
	}

}



bool Way_around_the_wall::check_dot(Dot dot)
{
	return !(dot.x < 1 || dot.x > ROW || dot.y < 1 || dot.y > COL );
}

void Way_around_the_wall::draw()
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


bool Way_around_the_wall::next()
{
	

	if (_end_location.x == _current_location.x && _end_location.y == _current_location.y)
	{
		return false;
	}
	
		
	if (_start_location.x <= _end_location.x)
	{
		
			

			while (	check_wall_cordinate_x_y(_current_location.x, _current_location.y))
			{

				_current_location.x++;
				

			}
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
		while (check_wall_cordinate_x_y(_current_location.x, _current_location.y))
		{

			_current_location.x--;


		}
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