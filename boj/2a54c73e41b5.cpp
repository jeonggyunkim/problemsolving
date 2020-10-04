#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int temp;
	temp = x < y? x : y;
	temp = temp < y? temp : y;
	temp = temp < w - x? temp : w - x;
	temp = temp < h - y? temp : h - y;

	cout << temp << endl;

	return 0;
}