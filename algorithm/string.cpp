// hashing
typedef long long ll;

const ll A = 950922101;

ll h[N + 1];
ll p[N + 1];

ll strhash(int a, int b) { // [a, b], 0-indexed
	return h[b + 1] - h[a] * p[b - a + 1];
}

p[0] = 1;
for (int i = 1; i <= N; ++i) p[i] = p[i - 1] * A;
for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * A + s[i - 1];

// KMP
vector<int> pi;

void getpi(string& N) {
	int m = N.size();
	pi.resize(m, 0);
	
	int begin = 1, match = 0;
	while (begin + match < m) {
		if (N[begin + match] == N[match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (match == 0) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int begin = 0, match = 0;
while (begin <= n - m) {
	if (match < m && H[begin + match] == N[match]) {
		++match;
		if (match == m) ans.push_back(begin);
	}
	else {
		if (match == 0) ++begin;
		else {
			begin += match - pi[match - 1];
			match = pi[match - 1];
		}
	}
}