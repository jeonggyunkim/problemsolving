#include <iostream>
#include <algorithm>

struct w {
	char c[51];
	int len = 0;
};

bool comp(w l, w r) {
	if (l.len != r.len) return l.len < r.len;
	for (int i = 0; i < l.len; ++i) if (l.c[i] != r.c[i]) return l.c[i] < r.c[i];
	return false;
}

bool same(w l, w r) {
	if (l.len != r.len) return false;
	for (int i = 0; i < l.len; ++i) if (l.c[i] != r.c[i]) return false;
	return true;
}

int main() {
	w arr[20000];
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%s", arr[i].c);
		while (arr[i].c[arr[i].len] != '\0') ++arr[i].len;
	}
	std::sort(arr, arr + N, comp);

	printf("%s\n", arr[0].c);
	for (int i = 1; i < N; ++i) if (!same(arr[i], arr[i - 1])) printf("%s\n", arr[i].c);

	return 0;
}