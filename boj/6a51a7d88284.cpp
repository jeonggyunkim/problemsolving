#include <iostream>
using namespace std;

bool cute(long long n) {
	int t[20];
	int i = 0;
	while (n) {
		t[i++] = n % 10;
		n /= 10;
	}
	if (i == 1) return 1;
	int dif = t[0] - t[1];
	for (int j = 1; j < i - 1; ++j) {
		if (t[j] - t[j + 1] != dif) return 0;
	}
	return 1;
}

int main() {
	long long n;
	cin >> n;

	if (cute(n)) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	else cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
}