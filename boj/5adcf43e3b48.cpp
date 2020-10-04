#include <iostream>

int arr[10001][100] = {};
int info[101][2];

int cal(int N, int T) {
	if (N == 0) {
		if (T >= info[N][0]) return arr[T][N] = info[N][1];
		else return 0;
	}
	if (arr[T][N] > 0) return arr[T][N];
	if (info[N][0] > T) return arr[T][N] = cal(N - 1, T);
	else {
		int a = cal(N - 1, T);
		int b = cal(N - 1, T - info[N][0]) + info[N][1];

		return arr[T][N] = (a > b ? a : b);
	}
}

int main() {
	int N, T;
	scanf("%d", &N);
	scanf("%d", &T);
	for (int i = 0; i < N; ++i) scanf("%d %d", info[i], info[i] + 1);

	printf("%d\n", cal(N - 1, T));

	return 0;
}