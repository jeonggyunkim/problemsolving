#include <iostream>
using namespace std;

int main() {
	int M, N, sum = 0, min = 0, sq, i = 1;
	cin >> M >> N;

	while ((sq = i * i) <= N) {
		if (sq >= M) {
			sum += sq;
			if (min == 0) min = sq;
		}
		++i;
	}
	if (sum == 0) cout << -1 << endl;
	else {
		cout << sum << endl;
		cout << min << endl;
	}
	return 0;
}