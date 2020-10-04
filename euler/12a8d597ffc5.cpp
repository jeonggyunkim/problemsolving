#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	for (int i = 0; i <= 9; ++i) arr.push_back(i);

	for (int i = 0; i < 999999; ++i) {
		next_permutation(arr.begin(), arr.end());
	}
	for (int u: arr) cout << u;
	cout << endl;
}