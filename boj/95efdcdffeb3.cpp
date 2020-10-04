#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int depth = 1, i;
char inorder[21];

void tree_walk(vector<int>& input) {
	if (input.size() == 0) return;
	depth++;
	if (input.size() == 1) {
		inorder[i++] = depth;
	}
	else {
		int root = input[0];
		vector<int> left, right;
		for (int i = 1; i < input.size(); ++i) {
			if (input[i] < root) left.push_back(input[i]);
			else right.push_back(input[i]);
		}
		tree_walk(left);
		inorder[i++] = depth;
		tree_walk(right);
	}
	depth--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, t;
	cin >> n >> k;

	set<string> s;
	for (int i = 0; i < n; ++i) {
		vector<int> v;

		for (int j = 0; j < k; ++j) {
			cin >> t;
			v.push_back(t);
		}

		::i = 0;
		tree_walk(v);

		s.insert(inorder);
	}

	cout << s.size();
}