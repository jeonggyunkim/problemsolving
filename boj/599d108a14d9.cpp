#include <iostream>
using namespace std;

int main() {
	long N, M, D;
	cin >> N >> M;

	if (N > M) D = N - M;
	else D = M - N;
	printf("%ld", D);

	return 0;
}