#include <iostream>
#include <vector>
using namespace std;

bool ispel(vector<int>& arr) {
	for (int i = 0; i < arr.size() / 2; ++i) {
		if (arr[i] != arr[arr.size() - 1 - i]) return 0;
	}
	return 1;
}

int main() {
	long long ans = 0;
	for (int i = 1; i <= 1000000; ++i) {
		vector<int> base10;
		int j = i;
		while (j) {
			base10.push_back(j % 10);
			j /= 10;
		}
		if (ispel(base10)) {
			vector<int> base2;
			j = i;
			while (j) {
				base2.push_back(j % 2);
				j /= 2;
			}
			if (ispel(base2)) ans += i;
		}
	}
	cout << ans << endl;
}