#include <iostream>
#include <vector>
#define N 1000010
using namespace std;

vector<bool> is_prime(N, 1);
vector<int> sg(N, 0);

int sang(int n) {
	int ret = 0;
	while (n) {
		ret += (n % 10) * (n % 10);
		n /= 10;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < 1000; ++i) {
		for (int j = i * i; j < N; j += i) is_prime[j] = 0;
	}
	sg[1] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			if (sg[i] == 1) cout << i << '\n';
			else if (sg[i] == 0) {
				vector<int> temp;
				int t = i;
				while (sg[t] == 0) {
					temp.push_back(t);
					sg[t] = -1;
					t = sang(t);
				}
				for (int u: temp) sg[u] = sg[t];
				if (sg[i] == 1) cout << i << '\n';
			}
		}
	}
}