#include <iostream>
using namespace std;

int main() {
	long long k, a, b, c, d;
	cin >> k >> a >> b >> c >> d;
	long long p;
	p = a * k + b;
	if (p == c * k + d) cout << "Yes " << p;
	else cout << "No";
}