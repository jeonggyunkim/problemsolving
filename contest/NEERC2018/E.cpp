#include <bits/stdc++.h>
#define N 300001
using namespace std;

struct node {
	int prev = -1, next = -1;
	int prevNum = -1, nextNum = -1;
	int num;
};

vector<int> first;
node link[N];

void del(int i) {
	if (link[i].prev != -1) link[link[i].prev].next = link[i].next;
	if (link[i].next != -1) link[link[i].next].prev = link[i].prev;
	if (link[i].prevNum != -1) link[link[i].prevNum].nextNum = link[i].nextNum;
	if (link[i].nextNum != -1) link[link[i].nextNum].prevNum = link[i].prevNum;
	if (first[link[i].num] == i) first[link[i].num] = link[i].nextNum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	first.resize(N, -1);
	vector<int> now(N, -1);
	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;;
		if (i) link[i].prev = i - 1;
		if (i != n - 1) link[i].next = i + 1;
		link[i].num = t;

		if (first[t] == -1) {
			first[t] = i;
		}

		if (now[t] != -1) {
			link[i].prevNum = now[t];
			link[now[t]].nextNum = i;
		}

		now[t] = i;
	}

	int q;
	cin >> q;

	while (q--) {
		cin >> t;
		if (first[t] != -1 && link[first[t]].nextNum != -1) {
			int i = first[t];
			while (link[i].nextNum != -1) {
				del(link[i].next);
			}
		}
	}

	int i = 0, cnt;
	do {
		if (link[i].next == -1) cnt = n - i;
		else cnt = link[i].next - i;
		while (cnt--) cout << link[i].num << ' ';
		i = link[i].next;
	} while (i != -1);
}