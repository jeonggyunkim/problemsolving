#include <iostream>
#define EPS 1e-8
using namespace std;

int n;
double arr[500][500], ans[500][500];

void change(int a, int b) {
	for (int i = 0; i < n; ++i) {
		swap(arr[a][i], arr[b][i]);
		swap(ans[a][i], ans[b][i]);
	}
}

void sub(int a, int b, double c) {
	for (int i = 0; i < n; ++i) {
		arr[a][i] -= arr[b][i] * c;
		ans[a][i] -= ans[b][i] * c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
		ans[i][i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		if (abs(arr[i][i]) < EPS) {
			bool cng = 0;
			for (int j = i + 1; j < n; ++j) {
				if (abs(arr[j][i]) > EPS) {
					change(i, j);
					cng = 1;
					break;
				}
			}
			if (!cng) {
				cout << "no inverse";
				return 0;
			}
		}
		double t = arr[i][i];
		for (int j = 0; j < n; ++j) {
			arr[i][j] /= t;
			ans[i][j] /= t;
		}
		for (int j = i + 1; j < n; ++j) {
			sub(j, i, arr[j][i] / arr[i][i]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			sub(j, i, arr[j][i] / arr[i][i]);
		}
	}

	cout.precision(10);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}