#include <iostream>
#include <algorithm>
using namespace std;

bool in(int* arr, int n, int start, int end) {
	if (end - start <= 0) return false;
	if (end - start == 1) {
		if (arr[start] == n) return true;
		else return false;
	}
	int point = (start + end) / 2;
	if (arr[point] == n) return true;
	else if (n < arr[point]) return in(arr, n, start, point);
	else return in(arr, n, point + 1, end);
}

int main() {
	int N;
	scanf("%d", &N);

	int* arr = new int[N];

	for (int i = 0; i < N; ++i) {
		scanf("%d", arr + i);
	}
	sort(arr, arr + N);

	int M;
	scanf("%d", &M);

	int t;
	for (int i = 0; i < M; ++i) {
		scanf("%d", &t);
		if (in(arr, t, 0, N)) printf("%d\n", 1);
		else printf("%d\n", 0);
	}

	delete[] arr;

	return 0;
}