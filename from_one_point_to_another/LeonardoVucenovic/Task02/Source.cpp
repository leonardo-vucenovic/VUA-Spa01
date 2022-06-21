#include <iostream>
#include<chrono>
#include<thread>
#include "wall.h"
using namespace std;
using namespace chrono;
int main() {
	wall w;
	do {
		system("cls");
		w.draw();
		duration<int, std::milli> timespan(100);
		this_thread::sleep_for(timespan);
	} while (w.next());
	return 0;
}