#include <iostream>
#include <algorithm>

int l, c;
int ja = 0, mo = 0;
char arr[15];
char ans[15];

bool is_mo(char a) { return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'; }

void search(int pos, int rem) {
	if (rem == 0) {
		if (ja >= 2 && mo >= 1) {
			for(int i = 0; i < l; ++i) printf("%c", ans[i]);
			printf("\n");
		}
		return;
	}
	for (int i = pos; i <= c - rem; ++i) {
		ans[l - rem] = arr[i];
		if (is_mo(arr[i])) mo++;
		else ja++;
		search(i + 1, rem - 1);
		if (is_mo(arr[i])) mo--;
		else ja--;
	}
}


int main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; ++i) std::cin >> arr[i];
	std::sort(arr, arr + c);
	search(0, l);
}