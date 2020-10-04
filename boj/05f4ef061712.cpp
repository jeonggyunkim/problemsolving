#include <iostream>
#include <string>
using namespace std;

bool v1[] = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
bool v2[] = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
bool v3[] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
int m1[] = {3, 1, 1, 1, 3, 2, 2, 1, 3, 3};
int m2[] = {3, 1, 2, 1, 1, 1, 3, 1, 3, 1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s;
	string n;
	cin >> s >> n;

	for (int i = 0; i < n.size(); ++i) {
		cout << ' ';
		for (int j = 0; j < s; ++j) {
			if (v1[n[i] - '0'])  cout << '-';
			else cout << ' ';
		}
		cout << ' ';
		if (i != n.size() - 1) cout << ' ';
	}
	cout << '\n';

	for (int i = 0 ; i < s; ++i) {
		for (int j = 0; j < n.size(); ++j) {
			if (m1[n[j] - '0'] & 2) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; ++k) cout << ' ';

			if (m1[n[j] - '0'] & 1) cout << '|';
			else cout << ' ';

			if (j != n.size() - 1) cout << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n.size(); ++i) {
		cout << ' ';
		for (int j = 0; j < s; ++j) {
			if (v2[n[i] - '0'])  cout << '-';
			else cout << ' ';
		}
		cout << ' ';
		if (i != n.size() - 1) cout << ' ';
	}
	cout << '\n';

	for (int i = 0 ; i < s; ++i) {
		for (int j = 0; j < n.size(); ++j) {
			if (m2[n[j] - '0'] & 2) cout << '|';
			else cout << ' ';

			for (int k = 0; k < s; ++k) cout << ' ';

			if (m2[n[j] - '0'] & 1) cout << '|';
			else cout << ' ';

			if (j != n.size() - 1) cout << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n.size(); ++i) {
		cout << ' ';
		for (int j = 0; j < s; ++j) {
			if (v3[n[i] - '0'])  cout << '-';
			else cout << ' ';
		}
		cout << ' ';
		if (i != n.size() - 1) cout << ' ';
	}
}