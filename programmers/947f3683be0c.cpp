#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); ++i) {
		int a = commands[i][0] - 1;
		int b = commands[i][1] - 1;
		int c = commands[i][2] - 1;
		
		vector<int> now;
		for (int j = a; j <= b; ++j) now.push_back(array[j]);
		sort(now.begin(), now.end());

		answer.push_back(now[c]);
	}
	return answer;
}