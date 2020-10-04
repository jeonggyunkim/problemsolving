#include <iostream>
#include <vector>
using namespace std;

char board[5][50];

int num[10] = {31599, 18724, 29671, 31207, 18925, 31183, 31695, 18727, 31727, 31215};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 5; ++i) cin >> board[i];

	vector<int> arr[10];
	for (int i = 0; i < n; ++i) {
		int t = 0;
		int start = 4 * i, end = 4 * i + 2;
		for (int j = 0; j < 5; ++j) {
			for (int k = start; k <= end; ++k) {
				if (board[j][k] == '#') t |= (1 << (3 * j + k - start));
			}
		}
		for (int j = 0; j < 10; ++j) {
			if ((t | num[j]) == num[j]) arr[i].push_back(j);
		}
	}

	long long t = 1;
	for (int i = 0; i < n; ++i) t *= arr[i].size();
	if (t == 0) {
		cout << -1;
		return 0;
	}
	double avg = 0;
	long long p = 1;
	for (int i = n - 1; i >= 0; --i) {
		int sum = 0;
		for (int j = 0; j < arr[i].size(); ++j) sum += arr[i][j];
		avg += sum * p * t / arr[i].size();
		p *= 10;
	}
	cout.precision(10);
	cout << avg / t;
}