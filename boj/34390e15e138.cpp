#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	bool over = 0;
	int i = a.size() - 1, j = b.size() - 1;
	vector<int> ret;
	while (i >= 0 || j >= 0) {
		int t = 0;
		if (over) {
			t++;
			over = 0;
		}
		if (i >= 0) {
			t += a[i] - '0';
			i--;
		}
		if (j >= 0) {
			t += b[j] - '0';
			j--;
		}
		ret.push_back(t % 10);
		if (t >= 10) over = 1;

	}
	if (over) ret.push_back(1);

	for (int i = ret.size() - 1; i >= 0; --i) cout << ret[i];
}