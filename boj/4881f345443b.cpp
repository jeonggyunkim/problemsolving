#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int t;
	int score = 1;
	int tscore = 0;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		if (t) {
			tscore += score;
			score++;
		}
		else {
			score = 1;
		}
	}

	cout << tscore << endl;

	return 0;
}