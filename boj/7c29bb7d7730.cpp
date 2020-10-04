#include <iostream>
using namespace std;

int main() {
	int t;
	int max = 0;
	int maxi = 0;
	for (int i = 0; i < 5; ++i) {
		int score = 0;
		for (int j = 0; j < 4; ++j) {
			cin >> t;
			score += t;
		}
		if (max < score) {
			max = score;
			maxi = i + 1;
		}
	}
	cout << maxi << " " << max << endl;

	return 0;
}