#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	vector<int> rock;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			rock.push_back(i);
		}
	}

	vector<int> potato(n);
	vector<long long> time(n);
	int left_stand, right_stand;
	int real_left, real_right;
	vector<int> potato_left, potato_right;
	vector<int> suml, sumr;
	long long now;
	int left, right;
	if (rock.size() == 0) {
		vector<int> potato_pos;
		for (int i = 0; i < n; ++i) if (s[i] == 'P') {
			potato_pos.push_back(i);
		}
		if (potato_pos.size() == 0) {
			for (int i = 0; i < n; ++i) {
				if (s[i] == '.') {
					potato[i] = 0;
					time[i] = n - i;
				}
			}
			goto clear;
		}
		left_stand = right_stand = potato_pos[(potato_pos.size() - 1) / 2];
		real_left = real_right = potato.size();

		potato_left.push_back(-1);
		potato_right.push_back(n);
		for (int i = 0; i < potato_pos.size(); ++i) potato_left.push_back(potato_pos[i]);
		for (int i = potato_pos.size() - 1; i >= 0; --i) potato_right.push_back(potato_pos[i]);
		for (int i = 0; i < 10; ++i) potato_left.push_back(n);
		for (int i = 0; i < 10; ++i) potato_right.push_back(-1);

	}
	else {
		for (int i = 1; i < rock.size(); ++i) {
			int cnt = 0;
			for (int j = rock[i - 1]; j < rock[i]; ++j) {
				if (s[j] == 'P') cnt++;
			}
			for (int j = rock[i - 1]; j < rock[i]; ++j) {
				if (s[j] == '.') {
					potato[j] = cnt;
					time[j] = -1;
				}
			}
		}
		potato_left.push_back(-1);
		potato_right.push_back(n);
		for (int i = 0; i < rock[0]; ++i) {
			if (s[i] == 'P') potato_left.push_back(i);
		}
		for (int i = n - 1; i > rock.back(); --i) {
			if (s[i] == 'P') potato_right.push_back(i);
		}
		real_left = potato_left.size() - 1;
		real_right = potato_right.size() - 1;

		for (int i = 0; i < real_left + 10; ++i) potato_left.push_back(rock[0]);
		for (int i = 0; i < real_right + 10; ++i) potato_right.push_back(rock.back());

		left_stand = rock[0];
		right_stand = rock.back();
	}
	for (int i = 0; i < potato_left.size() - 1; ++i) potato_left[i] = potato_left[i + 1] - potato_left[i];
	for (int i = 0; i < potato_right.size() - 1; ++i) potato_right[i] = potato_right[i] - potato_right[i + 1];

	suml.resize(potato_left.size(), 0);
	sumr.resize(potato_right.size(), 0);
	for (int i = 1; i < potato_left.size(); ++i) suml[i] = suml[i - 1] + potato_left[i - 1];
	for (int i = 1; i < potato_right.size(); ++i) sumr[i] = sumr[i - 1] + potato_right[i - 1];

	now = potato_left[0] * 2;
	left = 0;
	for (int i = 0; i < left_stand; ++i) {
		now--;
		if (s[i] == 'P') {
			now += 4 * (suml[2 * left + 1] - suml[left + 1]);
			now += 4 * potato_left[2 * left + 1] + 2 * potato_left[2 * left + 2];
			left++;
		}
		if (s[i] == '.') {
			potato[i] = min(2 * left + 1, real_left);
			time[i] = now;
		}
	}
	now = 0;
	right = 0;
	for (int i = n - 1; i > right_stand; --i) {
		now++;
		if (s[i] == 'P') {
			if (right) {
				now += 4 * (sumr[2 * right] - sumr[right + 1]);
				now += 4 * potato_right[2 * right] + 2 * potato_right[2 * right + 1];
			}
			else {
				now += 2 * potato_right[1];
			}
			right++;
		}
		if (s[i] == '.') {
			potato[i] = min(2 * right, real_right);
			time[i] = now;
		}
	}

	clear:
	int t;
	while (q--) {
		cin >> t;
		t--;
		cout << potato[t] << ' ' << time[t] << '\n';
	}
}