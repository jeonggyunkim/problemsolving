#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define N 10000
using namespace std;

bool isArith(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = i + 1; j < arr.size(); ++j) {
			for (int k = j + 1; k < arr.size(); ++k) {
				if (arr[k] - arr[j] == arr[j] - arr[i]) {
					cout << arr[i] << arr[j] << arr[k] << endl;
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	vector<bool> prime(N + 1, 1);
	prime[0] = prime[1] = 0;
	for (int i = 0; i * i <= N; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = 0;
			}
		}
	}

	vector<bool> vis(N + 1, 0);
	for (int i = 1000; i <= N; ++i) {
		if (vis[i]) continue;
		vector<int> s;
		vector<int> arr;
		int j = i;
		while (j) {
			arr.push_back(j % 10);
			j /= 10;
		}
		sort(arr.begin(), arr.end());
		do {
			int now = 0;
			for (j = 0; j < 4; ++j) {
				now *= 10;
				now += arr[j];
			}
			if (now >= 1000 && prime[now]) s.push_back(now);
			vis[now] = 1;
		} while (next_permutation(arr.begin(), arr.end()));
		isArith(s);
	}
}