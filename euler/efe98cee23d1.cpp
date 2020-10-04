#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

vector<ii> factorize(unsigned int n) {
	vector<ii> ret;
	if (n <= 1) return ret;
	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) {
			cnt++;
			n /= 2;
		}
		ret.push_back(ii(2, cnt));
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				cnt++;
				n /= i;
			}
			ret.push_back(ii(i, cnt));
		}
	}
	if (n != 1) ret.push_back(ii(n, 1));
	return ret;
}

int main() {
	int con = 0;
	int i = 2;
	while (1) {
		if (factorize(i).size() == 4) {
			con++;
			if (con == 4) {
				cout << i - 3 << endl;
				return 0;
			}
		}
		else {
			con = 0;
		}
		i++;
	}
}
