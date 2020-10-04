#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, K;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N >> K;
		int currCnt = N;
		list<int> live;
		for (int i = 1; i <= N; ++i) {
			live.push_back(i);
		}
		list<int>::iterator it = live.begin();
		do {
			live.erase(it++);
			currCnt--;
			if (it == live.end()) {
				it = live.begin();
			}
			for (int i = 0; i < K - 1; ++i) {
				++it;
				if (it == live.end()) {
					it = live.begin();
				}
			}
		} while (currCnt > 2);
		for (it = live.begin(); it != live.end(); ++it) {
			cout << *it << " ";
		}
		cout << '\n';
	}
	return 0;
}
