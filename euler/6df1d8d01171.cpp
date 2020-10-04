#include <iostream>
#include <vector>
using namespace std;

vector<bool> prime(1000001, 1);

bool cir(int n) {
	vector<int> arr;
	while (n) {
		arr.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < arr.size() - 1; ++i) {
		int val = 0;
		for (int j = 0; j < arr.size(); ++j) {
			val *= 10;
			val += arr[(i - j + arr.size()) % arr.size()];
		}
		if (!prime[val]) return 0;
	}
	return 1;
}

int main() {
	prime[0] = prime[1] = 0;
	for (int i = 0; i * i <= 1000000; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= 1000000; j += i) prime[j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= 1000000; ++i) {
		if (prime[i] && cir(i)) cnt++;
	}
	cout << cnt << endl;
}