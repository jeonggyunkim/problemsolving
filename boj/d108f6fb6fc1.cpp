#include <iostream>
using namespace std;

int K;
int d[1000001];

int cal(int n) {
	int r = 0, t, u;
	while (n) {
		t = 1;
		u = n % 10;
		for (int i = 0; i < K; ++i) t *= u;
		r += t;
		n /= 10;
	}
	return r;
}

int minimal(int n) {
	if (n > 1000000) return minimal(cal(n));
	if (d[n] > 0) return d[n];

	int t = minimal(cal(n));
	return d[n] = t > n ? n : t;
}

int main() {
	int A, B;
	long long sum = 0;
	cin >> A >> B >> K;

	int a[7][20] = { {}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, { 1, 4 }, { 1, 371, 153, 55, 370, 160, 407, 919, 136 }, { 1, 1138, 8208, 2178, 1634, 9474 }, { 1, 24584, 9045, 10933, 9044, 244, 8299, 8294, 58618, 4150, 54748, 93084, 4151, 92727, 89883, 194979 }, { 1, 239459, 17148, 282595, 93531, 63804, 548834 } };

	int i = 0, n;
	while (a[K][i]) {
		n = a[K][i];
		do {
			if (n <= 1000000) d[n] = a[K][i];
			n = cal(n);
		} while (n != a[K][i]);
		++i;
	}

	for (int i = A; i <= B; ++i) {
		sum += minimal(i);
	}
	cout << sum << endl;

	return 0;
}