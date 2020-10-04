#include <iostream>
using namespace std;

int front[101];
int mid[101];

void back(int f_i, int f_f, int m_i, int m_f) {
	if (f_f - f_i < 1) return;
	if (f_f - f_i == 1) {
		cout << front[f_i] << ' ';
		return;
	}
	int p = front[f_i];
	int t = 0;
	while (mid[m_i + t] != p) t++;

	back(f_i + 1, f_i + 1 + t, m_i, m_i + t);
	back(f_i + t + 1, f_f, m_i + t + 1, m_f);
	cout << p << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> front[i];
		for (int i = 0; i < n; ++i) cin >> mid[i];
		back(0, n, 0, n);
		cout << '\n';
	}
}
