#include <iostream>
#include<chrono>
#include<thread>
#include"game.h"
using namespace std;
using namespace chrono;
int main() {
	game from_one_point_to_another;
	do {
		system("cls");
		from_one_point_to_another.draw();
		duration<int, std::milli> timespan(100);
		this_thread::sleep_for(timespan);
	} while (from_one_point_to_another.next());
	return 0;
}