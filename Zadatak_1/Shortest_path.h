#pragma once
#include<iostream>



using namespace std;

struct Dot
{
	int x;
	int y;
};

class Shortest_path
{
private:
	static const unsigned int ROW = 20;
	static const unsigned int COL = 40;
	Dot _current_location;
	Dot _start_location;
	Dot _end_location;
	char _field[ROW][COL];
	bool enter_dots();
	void set_field();
	bool check_dot(Dot dot);

public:
	Shortest_path();
	void draw();
	bool next();
};

