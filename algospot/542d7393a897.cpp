#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int i = 0;
		unsigned int ai = 1983;
		int input = 1983;

		int n, k;
		cin >> k >> n;

		int ans = 0;
		queue<int> q;
		int q_sum = 0;
		while (i < n) {
			if (q_sum < k) {
				q.push(input);
				q_sum += input;
				++i;
				ai = ai * 214013 + 2531011;
				input = ai % 10000 + 1;
			}
			else {
				if (q_sum == k) {
					ans++;
				}
				q_sum -= q.front();
				q.pop();
			}
		}
		cout << ans << '\n';
	}
}
