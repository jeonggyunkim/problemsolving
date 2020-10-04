#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int y = 0;
		int k = 0;

		int ty, tk;
		for (int j = 0; j < 9; ++j) {
			cin >> ty >> tk;
			y += ty;
			k += tk;
		}

		if (y > k) {
			cout << "Yonsei" << endl;
		}
		else if(y < k) {
			cout << "Korea" << endl;
		}
		else {
			cout << "Draw" << endl;
		}
	}

	return 0;
}