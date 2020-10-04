#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	scanf("%d", &n);

	vector<int> v;
	vector< vector<int> > ans;
	scanf("%d", &t); v.push_back(t);
	vector<int> temp;
	temp.push_back(t);
	ans.push_back(temp);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &t);
		if (t < v.back()) {
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), t);
			*it = t;
			int ind = it - v.begin();
			if (ind != 0) {
				ans[ind] = ans[ind - 1];
				ans[ind].push_back(t);
			}
			else ans[0] = vector<int>(1, t);
		}
		else if (t > v.back()) {
			v.push_back(t);
			ans.push_back(ans.back());
			ans.back().push_back(t);
		}
	}
	printf("%d\n", v.size());
	vector<int>* ptr = &ans.back();
	for (int i = 0; i < ptr->size(); ++i) printf("%d ", ptr->at(i));
	printf("\n");
}