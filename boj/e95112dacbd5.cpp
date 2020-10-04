#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cout << '*';
	for (int i = 0; i < 2 * n - 3; ++i) cout << ' ';
	for (int i = 0; i < n; ++i) cout << '*';
	cout << '\n';

	for (int i = 1; i <= n - 2; ++i) {
		for (int j = 0; j < i; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < 2 * (n - i) - 3; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; ++j) cout << ' ';
		cout << "*\n";
	}

	for (int i = 0; i < n - 1; ++i) cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; ++j) cout << ' ';
	cout << '*';
	for (int j = 0; j < n - 2; ++j) cout << ' ';
	cout << "*\n";

	for (int i = n - 2; i >= 1; --i) {
		for (int j = 0; j < i; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < 2 * (n - i) - 3; ++j) cout << ' ';
		cout << '*';
		for (int j = 0; j < n - 2; ++j) cout << ' ';
		cout << "*\n";
	}

	for (int i = 0; i < n; ++i) cout << '*';
	for (int i = 0; i < 2 * n - 3; ++i) cout << ' ';
	for (int i = 0; i < n; ++i) cout << '*';
	cout << '\n';
}