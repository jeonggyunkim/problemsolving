#include <iostream>
using namespace std;

int sz;
int bi[500010];
int tri[500010];

void binary_search(int left, int right, int cnt) {
	if (right < left) return;
    int mid = (left + right) / 2;
	if (!bi[mid]) bi[mid] = cnt + 1;
    binary_search(left, mid - 1, cnt + 1);
    binary_search(mid + 1, right, cnt + 1);
}

void ternary_search(int left, int right, int cnt) {
	if (right < left) return;
    int left_third = left + (right - left) / 3;
    int right_third = right - (right - left) / 3;
	if (!tri[left_third]) tri[left_third] = cnt + 1;
	if (!tri[right_third]) tri[right_third] = cnt + 2;
    ternary_search(left, left_third - 1, cnt + 2);
    ternary_search(left_third + 1, right_third - 1, cnt + 2);
    ternary_search(right_third + 1, right, cnt + 2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> sz;
	binary_search(0, sz - 1, 0);
	ternary_search(0, sz - 1, 0);

	int arr[3] = {};
	for (int i = 0; i < sz; ++i) {
		if (bi[i] < tri[i]) arr[0]++;
		else if (bi[i] == tri[i]) arr[1]++;
		else arr[2]++;
	}

	for (int i = 0; i < 3; ++i) {
		cout << arr[i] << '\n';
	}
}