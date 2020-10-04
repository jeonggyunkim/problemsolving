#include <string>
using namespace std;

int solution(string dartResult) {
	int ans[3] = {};
	int ind = 0;
	for (int i = 0; i < dartResult.size(); ++i) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			if (i != dartResult.size() - 1 && dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9') {
				i++;
				ans[ind++] = 10;
			}
			else ans[ind++] = dartResult[i] - '0';
		}
		else if (dartResult[i] == 'D') ans[ind - 1] = ans[ind - 1] * ans[ind - 1];
		else if (dartResult[i] == 'T') ans[ind - 1] = ans[ind - 1] * ans[ind - 1] * ans[ind - 1];
		else if (dartResult[i] == '*') {
			ans[ind - 1] *= 2;
			if (ind >= 2) ans[ind - 2] *= 2;
		}
		else if (dartResult[i] == '#') ans[ind - 1] *= -1;
	}

	return ans[0] + ans[1] + ans[2];
}