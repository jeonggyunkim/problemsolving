#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C;

int b_search(vector<int>* v, int low, int high, int n) {
	if (high - low <= 0) return low;
	int mid = (low + high) / 2;
	if ((*v)[mid] < n) return b_search(v, mid + 1, high, n);
	else return b_search(v, low, mid, n);
}

void brute(vector<int>* v, int* arr, int n, long long sum) {
	if (n < 0) {
		v->push_back(0);
		return;
	}
	if (n == 0) {
		if (arr[n] + sum <= ::C) v->push_back(arr[n] + sum);
		if (sum <= ::C) v->push_back(sum);
		return;
	}
	brute(v, arr, n - 1, sum + arr[n]);
	brute(v, arr, n - 1, sum);
}

int main() {
	vector<int> a;
	vector<int> b;
	int N, arr[30], sum = 0;

	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; ++i) scanf("%d", arr + i);
	sort(arr, arr + N);

	brute(&a, arr, N / 2 - 1, 0);
	brute(&b, arr + N / 2, N - N / 2 - 1, 0);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < b.size(); ++i) sum += b_search(&a, 0, a.size(), C - b[i] + 1);
	cout << sum << endl;

	return 0;
}