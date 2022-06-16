#pragma once
#include<iostream>
#include<vector>




using namespace std;

struct Dot
{
	int x;
	int y;
};

class Way_around_the_wall
{
private:
	static const unsigned int ROW = 20;
	static const unsigned int COL = 40;
	Dot _current_location;
	Dot _start_location;
	Dot _end_location;
	Dot _wall_location;
	int _wall_hight;

	vector <Dot> vd;
	char _field[ROW][COL];
	bool enter_dots();
	void set_field();

	void set_wall();
	bool check_wall_cordinate_x_y(int n, int m);
	

	bool check_dot(Dot dot);

public:
	Way_around_the_wall();
	void draw();
	bool next();

};

