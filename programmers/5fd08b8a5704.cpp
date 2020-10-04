#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	vector<char> arr = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

	do {
		bool pos = 1;
		for (int i = 0; i < n; ++i) {
			int a = 0, b = 0, d = data[i][4] - '0';
			while (arr[a] != data[i][0]) a++;
			while (arr[b] != data[i][2]) b++;
			if (data[i][3] == '=') {
				if (abs(a - b) - 1 != d) pos = 0;
			}
			else if (data[i][3] == '<') {
				if (abs(a - b) - 1 >= d) pos = 0;
			}
			else {
				if (abs(a - b) - 1 <= d) pos = 0;
			}
		}
		if (pos) answer++;
	} while (next_permutation(arr.begin(), arr.end()));

	return answer;
}