#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, string> i2s;
typedef tuple<int, int, int, string> i3s;

// uncap_num, cap_num, uncap_str, cap_str
string num[1001][4];
string tru = "!![]";
string fal = "![]";

int concat(int i, int j) {
	if (j == 0) {
		return i * 10;
	}
	int t = j;
	while (t) {
		i *= 10;
		t /= 10;
	}
	return i + j;
}

i2s add(int i, int ti, int j, int tj) {
	string ret;
	ret += num[i][ti];
	ret += '+';
	if (tj == 1 || tj == 3) ret += '[' + num[j][tj] + ']';
	else ret += num[j][tj];

	if (ti == 1 && tj == 0) return {i + j, 1, ret};
	else return {concat(i, j), 3, ret};
}

i2s add_bracket(int i, int ti, int j, int tj) {
	if (ti == 0 && tj == 0) {
		return {i + j, 1, num[i][ti] + '+' + num[j][tj]};
	}
	string ret;
	if (ti == 1 || ti == 3) ret += '[' + num[i][ti] + ']';
	else ret += num[i][ti];
	ret += '+';
	if (tj == 1 || tj == 3) ret += '[' + num[j][tj] + ']';
	else ret += num[j][tj];

	return {concat(i, j), 3, ret};
}

i2s sub(int i, int ti, int j, int tj) {
	string ret;
	ret += num[i][ti];
	ret += '-';
	if (tj == 1 || tj == 3) ret += '[' + num[j][tj] + ']';
	else ret += num[j][tj];

	return {i - j, 1, ret};
}

i2s mul(int i, int ti, int j, int tj) {
	string ret;
	if (ti == 1 || ti == 3) ret += '[' + num[i][ti] + ']';
	else ret += num[i][ti];
	ret += '*';
	if (tj == 1 || tj == 3) ret += '[' + num[j][tj] + ']';
	else ret += num[j][tj];

	return {i * j, 0, ret};
};

int main() {
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j < 4; ++j) {
			num[i][j] = string(1000, '-');
		}
	}
	priority_queue<i3s, vector<i3s>, greater<i3s>> pq;
	num[0][0] = "![]*![]";
	pq.push({num[0][0].size(), 0, 0, num[0][0]});

	num[0][1] = "+![]";
	pq.push({num[0][1].size(), 0, 1, num[0][1]});

	num[1][0] = "!![]*!![]";
	pq.push({num[1][0].size(), 1, 0, num[1][0]});

	num[1][1] = "+!![]";
	pq.push({num[1][1].size(), 1, 1, num[1][1]});

	num[2][1] = "!![]+!![]";
	pq.push({num[2][1].size(), 2, 1, num[2][1]});

	while (!pq.empty()) {
		int len, now, type;
		string s;
		tie(len, now, type, s) = pq.top(); pq.pop();
		if (s != num[now][type]) continue;
		int n, tn;
		string nxt;
		for (int i = 0; i <= 1000; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (num[i][j].size() == 1000) continue;

				tie(n, tn, nxt) = add_bracket(now, type, i, j);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
//					cout << nxt << ' ' << n << ' ' << tn << endl;
				}
				if (type == 1 || type == 3) {
					tie(n, tn, nxt) = add(now, type, i, j);
					if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
					else {
						num[n][tn] = nxt;
						pq.push({nxt.size(), n, tn, nxt});
	//					cout << nxt << ' ' << n << ' ' << tn << endl;
					}
				}

				tie(n, tn, nxt) = sub(now, type, i, j);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
//					cout << nxt << ' ' << n << ' ' << tn << endl;
				}

				tie(n, tn, nxt) = mul(now, type, i, j);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
//					cout << nxt << ' ' << n << ' ' << tn << endl;
				}

				tie(n, tn, nxt) = add_bracket(i, j, now, type);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
//					cout << nxt << ' ' << n << ' ' << tn << endl;
				}
				if (j == 1 || j == 3) {
					tie(n, tn, nxt) = add(i, j, now, type);
					if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
					else {
						num[n][tn] = nxt;
						pq.push({nxt.size(), n, tn, nxt});
	//					cout << nxt << ' ' << n << ' ' << tn << endl;
					}
				}

				tie(n, tn, nxt) = sub(i, j, now, type);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
//					cout << nxt << ' ' << n << ' ' << tn << endl;
				}

				tie(n, tn, nxt) = mul(i, j, now, type);
				if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
				else {
					num[n][tn] = nxt;
					pq.push({nxt.size(), n, tn, nxt});
					//cout << nxt << ' ' << n << ' ' << tn << endl;
				}
			}
		}
		// add
		if (type <= 1) {
			n = now + 1;
			tn = 1;
			nxt = num[now][type] + '+' + tru;
			if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
			else {
				num[n][tn] = nxt;
				pq.push({nxt.size(), n, tn, nxt});
				//cout < nxt << ' ' << n << ' ' << tn << endl;
			}
		}
		n = now - 1;
		tn = 1;
		nxt = num[now][type] + '-' + tru;
		if (n < 0 || n > 1000 || nxt.size() >= num[n][tn].size()) {}
		else {
			num[n][tn] = nxt;
			pq.push({nxt.size(), n, tn, nxt});
		}
	}

	cout << "arr = [";
	for (int i = 0; i <= 1000; ++i) {
		//cout << i << ' ';
		int m = min({num[i][0].size(), num[i][1].size(), num[i][2].size(), num[i][3].size()});
		//cout << m << ' ';
		if (num[i][0].size() == m) cout << num[i][0];
		else if (num[i][1].size() == m) cout << num[i][1];
		else if (num[i][2].size() == m) cout << num[i][2] + "-[]";
		else cout << num[i][3] + "-[]";
		cout << ",\n";
	}
	cout << "]";
}