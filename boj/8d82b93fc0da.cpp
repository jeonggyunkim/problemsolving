#include <iostream>
using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	cin >> n;

	int* mem = new int[n];
	mem[0] = 0;

	for (int i = 1; i < n; ++i) {
		if ((i + 1) % 6 == 0) {
			mem[i] = min(min(mem[(i - 2) / 3], mem[(i - 1) / 2]), mem[i - 1]) + 1;
		}
		else if ((i + 1) % 3 == 0) {
			mem[i] = min(mem[(i - 2) / 3], mem[i - 1]) + 1;
		}
		else if ((i + 1) % 2 == 0){
			mem[i] = min(mem[(i - 1) / 2], mem[i - 1]) + 1;
		}
		else {
			mem[i] = mem[i - 1] + 1;
		}
	}

	cout << mem[n - 1] << endl;

	delete[] mem;

	return 0;
}