#include <iostream>
using namespace std;

int main() {
	int i = 1, ans = 1, sum = 0, d = 1;
	while (d != 10000000) {
		int j = i;
		int len = 0;
		while (j) {
			len++;
			j /= 10;
		}
		if (d <= sum + len) {
			int ind = sum + len - d;
			j = i;
			for (int k = 0; k < ind; ++k) j /= 10;
			ans *= j % 10;
			d *= 10;
		}
		sum += len;
		i++;
	}
	cout << ans << endl;
}