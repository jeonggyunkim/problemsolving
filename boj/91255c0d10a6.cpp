#include <string>
#include "colored_dealt.h"
using namespace std;

const char* chr = "RGB";

string guess(int N) {
	string s, ans;
	for (int i = 0; i < N; ++i) s += 'R';
	int sum = design(s), now = sum;

	for (int i = 0; i < N - 1; ++i) {
		s[i] = 'B';
		int ret = design(s);
		ret -= 3 * (i + 1);
		ans += chr[now - ret - 1];
		now = ret;
	}
	ans += chr[now - 1];
	return ans;
}