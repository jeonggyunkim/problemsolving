#include <iostream>
#include <memory.h>
using namespace std;

typedef pair<int*, int> vec;

vec sum(int* a, int* b, int sa, int sb) {
	int* ret = new int[sa];
	for (int i = 0; i < sa; ++i) ret[i] = a[i];
	int d = sa - sb;
	for (int i = 0; i < sb; ++i) ret[i + d] += b[i];
	return vec(ret, sa);
}

void sub(int* a, int* b, int sa, int sb) {
	int d = sa - sb;
	for (int i = 0; i < sb; ++i) a[i + d] -= b[i];
}

vec mul(int* a, int* b, int sa, int sb) {
	if (sa < sb) return mul(b, a, sb, sa);

	if (sa <= 30) {
		int* ret = new int[sa + sb - 1];
		memset(ret, 0, sizeof(int) * (sa + sb - 1));
		for (int i = 0; i < sa; ++i) for (int j = 0; j < sb; ++j) ret[i + j] += a[i] * b[j];
		return vec(ret, sa + sb - 1);
	}

	int s1 = sa / 2, s2 = sa - s1;

	if (sb <= s1) {
		vec r0 = mul(a, b, s1, sb);
		vec r1 = mul(a + s1, b, s2, sb);

		int size = sa + sb - 1;
		int* ret = new int[size];
		memset(ret, 0, sizeof(int) * size);


		for (int i = 0; i < r0.second; ++i) ret[i] += r0.first[i];
		for (int i = 0; i < r1.second; ++i) ret[size - 1 - i] += r1.first[r1.second - 1 - i];

		delete[] r0.first;
		delete[] r1.first;

		return vec(ret, size);
	}

	vec r0 = mul(a, b, s1, sb - s2);
	vec r2 = mul(a + s1, b + sb - s2, s2, s2);

	vec aa = sum(a + s1, a, s2, s1);
	vec bb = sum(b + sb - s2, b, s2, sb - s2);

	vec r1 = mul(aa.first, bb.first, aa.second, bb.second);

	sub(r1.first, r0.first, r1.second, r0.second);
	sub(r1.first, r2.first, r1.second, r2.second);

	int size = sa + sb - 1;
	int* ret = new int[size];
	memset(ret, 0, sizeof(int) * size);

	for (int i = 0; i < r0.second; ++i) ret[i] += r0.first[i];
	for (int i = 0; i < r1.second; ++i) ret[size - s2 - 1 - i] += r1.first[r1.second - 1 - i];
	for (int i = 0; i < r2.second; ++i) ret[size - 1 - i] += r2.first[r2.second - 1 - i];

	delete[] aa.first;
	delete[] bb.first;
	delete[] r0.first;
	delete[] r1.first;
	delete[] r2.first;

	return vec(ret, size);
}

int main() {
	int tc, n;
	scanf("%d", &tc);

	char mem[200010];
	char f[200010];
	while (tc--) {
		scanf("%s", mem);
		scanf("%s", f);
		int member = -1;
		while (mem[++member]);
		int fan = -1;
		while (f[++fan]);

		int* a = new int[member];
		memset(a, 0, sizeof(int) * member);

		int* b = new int[fan];
		memset(b, 0, sizeof(int) * fan);

		for (int i = 0; i < member; ++i) a[i] = (mem[i] == 'M' ? 1 : 0);
		for (int i = 0; i < fan; ++i) b[fan - 1 - i] = (f[i] == 'M' ? 1 : 0);

		vec c = mul(b, a, fan, member);
		int* cc = c.first;

		int cnt = 0;
		for (int i = member - 1; i < fan; ++i) if (cc[i] == 0) cnt++;
		printf("%d\n", cnt);

		delete[] a;
		delete[] b;
		delete[] cc;
	}
}
