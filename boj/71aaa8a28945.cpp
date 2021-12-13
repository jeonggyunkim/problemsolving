#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int test = 1; test <= tc; ++test) {
		char in[20], out[20] = {};
		cin >> in;

		int i;
		for (i = 0; in[i]; ++i) {
			for (int j = (i == 0 ? '0' : out[i - 1]); j <= '9'; ++j) {
				for (int k = i; in[k]; ++k) out[k] = j;
				if (strcmp(in, out) < 0) {
					out[i] = j - 1;
					break;
				}
			}
		}
		out[i] = 0;
		char* ptr = out;
		while (*ptr == '0') ptr++;
		cout << "Case #" << test << ": " << ptr << '\n';
	}
}