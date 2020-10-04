#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[1000];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	int max = 0;
	int start = 0;
	int end = 0;
	bool cont = false;

	for (int i = 0; i < N - 1; ++i) {
		if (arr[i + 1] > arr[i]) {
			if (!cont) start = arr[i];
			end = arr[i + 1];
			cont = true;
		}
		else {
			cont = false;
		}
		if (max < end - start) max = end - start;
	}

	cout << max << endl;

	return 0;
}