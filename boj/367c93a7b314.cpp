#include <iostream>
#include <map>
using namespace std;

bool die[200010];
int mito[200010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	char c;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		mito[i] = i;
	}

	int num = n;

	cin >> m;
	int a, b;
	while (m--) {
		cin >> a;
		if (a < 0) {
			a = -(a + 1);
			die[a] = 1;
		}
		else {
			cin >> b >> c;
			a--; b--;
			mito[num] = mito[b];
			num++;
		}
	}

	map<int, int> mp;
	for (int i = 0; i < num; ++i) {
		if (!die[i]) mp[mito[i]] = -1;
	}

	int k;
	cin >> k;

	while (k--) {
		cin >> a >> b;
		a--;
		if (mp.count(mito[a])) mp[mito[a]] = b;
	}

	if (mp.size() == 1) {
		cout << "YES";
		exit(0);
	}
	bool unclear = 0;
	int first = -1;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second == -1) {
			unclear = 1;
		}
		else {
			if (first == -1) first = it->second;
			else if (first != it->second) {
				cout << "NO";
				exit(0);
			}
		}
	}

	if (unclear) cout << "POSSIBLY";
	else cout << "YES";
}