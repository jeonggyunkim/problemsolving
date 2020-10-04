#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[100];
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int dec = 0;
	int t;
	for (int i = N - 1; i > 0; --i) {
		 t = arr[i] <= arr[i - 1] ? arr[i - 1] - arr[i] + 1 : 0;
		 dec += t;
		 arr[i - 1] -= t;
	}

	cout << dec << endl;

	return 0;
}