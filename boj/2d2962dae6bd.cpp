#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	int a = 0, b = 0, c = 0;
	int ans = 0;
	while (n--) {
		cin >> s;
		if (s[0] == '3') c++;
		else if (s[2] == '2') b++;
		else a++;
	}

	ans += c;
	a = max(0, a - c);

	ans += b / 2;
	b %= 2;
	if (b) a += 2;
	
	ans += (a + 3) / 4;
	cout << ans;
}