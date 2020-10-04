#include <iostream>
using namespace std;

int main() {
	int n;
	char a[] = {0, 1, 1, 2, 3, 3, 3, 2};
	cin >> n;
	cout << (char)(a[n - 1] + 97);
}