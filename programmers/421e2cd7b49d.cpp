#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums) {
	set<int> st;
	for (int u: nums) st.insert(u);
	return min(st.size(), nums.size() / 2);
}