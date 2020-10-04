#include <iostream>
using namespace std;

int divnum[10001];

int main() {
	for (int i = 1; i <= 10000; ++i) {
		for (int j = i * i; j <= 10000; j += i) {
			divnum[j]++;
		}
	}

	int n;
	cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += divnum[i];

	cout << ans;
}