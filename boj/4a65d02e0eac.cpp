#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {

		int h, w, m;
		cin >> h >> w >> m;

		w = (m - 1) / h + 1;
		if (m % h != 0) {
			h = m % h;
		}

		int room = 100 * h + w;

		cout << room << endl;
	}

	return 0;
}