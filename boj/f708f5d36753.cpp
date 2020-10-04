#include <iostream>
#define N 7500000
using namespace std;

bool notprime[N];

int main() {
	for (int i = 2; 2 * i < N; ++i) {
		if (!notprime[i]) for (int j = 2 * i; j < N; j += i) notprime[j] = 1;
	}

	int k;
	cin >> k;

	int cnt = 0;
	for (int i = 2; i < N; ++i) {
		if (!notprime[i]) cnt++;
		if (cnt == k) {
			cout << i;
			return 0;
		}
	}
}