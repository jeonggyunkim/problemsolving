// hashing
typedef long long ll;

const ll A = 982384651;
const ll B = 1032384667;

int h[1000010];
int p[1000010];

int strhash(int a, int b) {
	int ret = h[b + 1] - ((ll)h[a] * p[b - a + 1]) % B;
	if (ret < 0) ret += B;
	return ret;
}

int n;
string s;

for (int i = 1; i <= n; ++i) {
	h[i] = ((h[i - 1] * A) + s[i - 1]) % B;
}

p[0] = 1;
for (int i = 1; i <= n; ++i) p[i] = (p[i - 1] * A) % B;


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