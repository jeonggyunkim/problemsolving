#include <iostream>
#include <vector>
using namespace std;

int divnum(long long n) {
	vector<int> num;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		num.push_back(cnt);
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			num.push_back(cnt);
		}
	}
	if (n != 1) num.push_back(1);

	int ret = 1;
	for (int u: num) ret *= (u + 1);
	return ret;
}

int main() {
	long long ans = 0;
	int i = 1;
	while (1) {
		ans += i++;
		if (divnum(ans) > 500) break;
	}
	cout << ans << endl;
}