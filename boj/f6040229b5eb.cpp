#include <iostream>
#include <memory.h>
#include <set>
using namespace std;

bool prime[201];

int main() {
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i * i <= 200; ++i) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= 200; j += i) {
			prime[j] = 0;
		}
	}

	set<int> p, pp;
	for (int i = 2; i <= 200; ++i) {
		if (prime[i]) p.insert(i);
	}

	for (auto it = p.begin(); ; ++it) {
		auto jt = it; jt++;
		if (jt == p.end()) break;
		pp.insert(*it * *jt);
	}

	int n;
	cin >> n;

	cout << *pp.upper_bound(n);
}