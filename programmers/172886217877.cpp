#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	int prev = -1;
	for (int u: arr) {
		if (u != prev) answer.push_back(u);
		prev = u;
	}
	return answer;
}