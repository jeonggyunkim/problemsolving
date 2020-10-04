#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<string, int> si;

bool comp(si& a, si& b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

struct node {
	node* ptr[26] = {};
	int recom = -1;
};

void remove(node* ptr) {
	for (int i = 0; i < 26; ++i) {
		if (ptr->ptr[i]) remove(ptr->ptr[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<si> arr(n);
		for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
		sort(arr.begin(), arr.end(), comp);

		node* root = new node;

		unordered_map<string, int> um;
		for (int i = n - 1; i >= 0; --i) {
			node* now = root;
			for (int j = 0; j < arr[i].first.size(); ++j) {
				if (!now->ptr[arr[i].first[j] - 'A']) {
					now->ptr[arr[i].first[j] - 'A'] = new node;
				}
				now = now->ptr[arr[i].first[j] - 'A'];
				now->recom = i;
			}
			um[arr[i].first] = i;
		}

		int ans = 0;
		for (int i = 0; i < m; ++i) {
			string t;
			cin >> t;
			if (um.count(t)) {
				node* now = root;
				int ind = um[t], cnt = 20;
				for (int j = 0; j < t.size(); ++j) {
					now = now->ptr[t[j] - 'A'];
					if (now->recom == ind) {
						cnt = j + 2;
						break;
					}
				}
				ans += min((int)t.size(), cnt);
			}
			else ans += t.size();
		}

		cout << ans + m - 1 << '\n';
		remove(root);
		delete root;
	}
}
