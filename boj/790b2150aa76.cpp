#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	long long sum = 0;
	int i = 0;
	bool exist = 0;
	while (i < n) {
		if (s[i] >= '0' && s[i] <= '9') {
			exist = 1;
			int start = i;
			while (i < n && s[i] >= '0' && s[i] <= '9') i++;
			sum += atoi(s.substr(start, i - start).c_str());
		}
		else i++;
	}

	if (exist) cout << sum;
	else cout << 0;
}