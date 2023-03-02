#include <iostream>
using namespace std;

bool exist[1000001];
int score[1000001];
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		exist[arr[i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = arr[i]; j <= 1000000; j += arr[i]) {
			if (exist[j]) {
				score[arr[i]]++;
				score[j]--;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << score[arr[i]] << ' ';
	}
}