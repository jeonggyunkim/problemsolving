#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll pi[100];

void beautify(ll* a) {
	for (int i = 99; i >= 1; --i) {
		if (a[i] >= 10) {
			a[i - 1] += a[i] / 10;
			a[i] = a[i] % 10;
		}
		if (a[i] < 0) {
			a[i - 1] += a[i] / 10 - 1;
			a[i] = 10 + a[i] % 10;
		}
	}
}

void move(ll* a, ll* b) {
	for (int i = 0; i < 100; ++i) a[i] = b[i];
}

void add(ll* a, ll* b) {
	for (int i = 0; i < 100; ++i) a[i] += b[i];
	beautify(a);
}

void sub(ll* a, ll* b) {
	for (int i = 0; i < 100; ++i) a[i] -= b[i];
	beautify(a);
}

void intprod(ll* a, int n) {
	for (int i = 0; i < 100; ++i) a[i] *= n;
	beautify(a);
}

void prod(ll* a, ll* b) {
	ll ret[100] = {};
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i + j >= 100) break;
			ret[i + j] += a[i] * b[j];
		}
	}
	beautify(ret);
	move(a, ret);
}

void intdiv(ll* a, int n) {
	for (int i = 0; i < 99; ++i) {
		a[i + 1] += 10 * (a[i] % n);
		a[i] /= n;
	}
	a[99] /= n;
}

void sine(ll* ret, ll* a, int T) {
	ll t[100];
	move(t, pi);
	intprod(t, T);
	sub(a, t);

	move(ret, a);
	move(t, a);
	for (int i = 2; i <= 99; ++i) {
		intdiv(t, i);
		prod(t, a);
		if ((i - 1) % 4 == 0) add(ret, t);
		if ((i - 1) % 4 == 2) sub(ret, t);
	}
}

int main() {
	const char* pi100 = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067";
	for (int i = 0; i < 100; ++i) pi[i] = pi100[i] - '0';
	intprod(pi, 2);

	int a, b, c;
	cin >> a >> b >> c;

	ll low = 0, high = (b + c) * 10000000LL, t;
	while (high - low != 1) {
		ll mid = (low + high) / 2;
		ll v[100] = {};
		t = mid;
		for (int i = 7; i >= 0; --i) {
			if (i) v[i] = t % 10;
			else v[i] = t;
			t /= 10;
		}
		ll first[100];
		move(first, v);
		intprod(first, a);

		ll second[100];
		sine(second, v, (int)((double)mid / 20000000 / M_PI));
		intprod(second, b);
		add(first, second);

		if (first[0] >= c) high = mid;
		else low = mid;
	}

	if (low % 10 >= 5) {
		low /= 10;
		low++;
	}
	else low /= 10;

	vector<int> ans;
	for (int i = 0; i < 6; ++i) {
		ans.push_back(low % 10);
		low /= 10;
	}
	cout << low << '.';
	for (int i = 5; i >= 0; --i) cout << ans[i];
}
