#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int* A = new int[N];
	int* B = new int[N];

	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", B + i);
	}
	sort(A, A + N);
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i] * B[N - i - 1];
	}

	printf("%d\n", sum);

	delete[] A;
	delete[] B;

	return 0;
}