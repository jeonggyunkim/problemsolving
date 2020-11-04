#include <iostream>
#include <set>
using namespace std;

int main() {
	set<long long> st;
	long long p = 10;
	for (int len = 3; len <= 17; ++len) {
		p *= 10;
		for (int pos = 0; pos < len; ++pos) { 
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					if (i == j) continue;
					long long num = 0;
					for (int k = 0; k < len; ++k) {
						num *= 10;
						if (k == pos) num += j;
						else num += i;
					}
					if (num >= p) st.insert(num);
				}
			}
		}
	}

	long long a, b;
	cin >> a >> b;
	int ans = 0;
	for (long long i: st) {
		if (i >= a && i <= b) ans++;
	}
	cout << ans;
}