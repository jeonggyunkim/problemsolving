#include <iostream>
#include <memory.h>
#define N 1000010
using namespace std;

typedef long long ll;

const ll A = 982384651;
const ll B = 1032384667;

int h[N];
int p[N];
int arr[N];

int strhash(int a, int b) {
	int ret = h[b + 1] - ((ll)h[a] * p[b - a + 1]) % B;
	if (ret < 0) ret += B;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	p[0] = 1;
	for (int i = 1; i < N; ++i) p[i] = (p[i - 1] * A) % B;

	int test = 1;
	while (cin >> n, n) {
		cout << "Test case #" << test++ << '\n';
		string s;
		cin >> s;

		for (int i = 1; i <= n; ++i) {
			h[i] = ((h[i - 1] * A) + s[i - 1]) % B;
		}

		memset(arr, -1, sizeof(arr));

		for (int i = n / 2; i >= 1; --i) {
			int stand = strhash(0, i - 1);
			for (int j = i; j + i <= n; j += i) {
				if (strhash(j, j + i - 1) == stand) {
					arr[j + i] = (j + i) / i;
				}
				else break;
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (arr[i] != -1) cout << i << ' ' << arr[i] << '\n';
		}
		cout << '\n';
	}
}