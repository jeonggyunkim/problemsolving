#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> arr;
int n, k, d;

bool dotory(int num) {
	long long now = 0;
	for (int i = 0; i < k; ++i) {
		int a, b, c;
		tie(a, b, c) = arr[i];
		if (num >= a && num <= b) {
			now += (num - a) / c + 1;
		}
		else if (num > b) now += (b - a) / c + 1;
	}
	return now >= d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> d;

	int a, b, c;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c;
		arr.push_back({a, b, c});
	}

	int low = 0, high = n;
	while (high - low != 1) {
		int mid = (low + high) / 2;
		if (dotory(mid)) high = mid;
		else low = mid;
	}
	cout << high;
}