#include <iostream>
#include<chrono>
#include<thread>
#include "Way_around_the_wall.h"


using namespace std;
using namespace chrono;

int main() {

	Way_around_the_wall p;


	do {
		system("cls");
		p.draw();
		duration<int, std::milli> timespan(100);
		this_thread::sleep_for(timespan);


	} while (p.next());

	

	return 0;
}