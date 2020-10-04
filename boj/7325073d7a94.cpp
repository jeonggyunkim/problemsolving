#include <iostream>
using namespace std;

int main() {
	int cnt[1001] = {};
	int i = 1, t;

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	i = 1;
	while (i <= 1000) {
		for (int j = 0; j < a && i <= 1000; ++j) cnt[i++]++;
		for (int j = 0; j < b && i <= 1000; ++j) i++;
	}
	i = 1;
	while (i <= 1000) {
		for (int j = 0; j < c && i <= 1000; ++j) cnt[i++]++;
		for (int j = 0; j < d && i <= 1000; ++j) i++;
	}
	for (i = 0; i < 3; ++i) {
		cin >> t;
		cout << cnt[t] << '\n';
	}
}