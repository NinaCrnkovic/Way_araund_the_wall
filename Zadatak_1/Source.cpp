#include <iostream>
#include<chrono>
#include<thread>
#include"Shortest_path.h"


using namespace std;
using namespace chrono;

int main() {

	Shortest_path p;
	do {
		system("cls");
		p.draw();
		duration<int, std::milli> timespan(100);
		this_thread::sleep_for(timespan);


	} while (p.next());

	return 0;
}

