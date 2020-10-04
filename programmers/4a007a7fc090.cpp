#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#define INF 987654321
using namespace std;

vector<int> solution(vector<string> gems) {
	unordered_map<string, int> mp;
	vector<list<int>> index;

	int ind = 0;
	priority_queue<int> pq, del;
	for (int i = 0; i < gems.size(); ++i) {
		if (mp.count(gems[i])) index[mp[gems[i]]].push_back(i);
		else {
			mp[gems[i]] = ind++;
			index.push_back(list<int>(1, i));
			pq.push(i);
		}
	}
	for (int i = 0; i < ind; ++i) index[i].push_back(INF);

	int len = INF;
	vector<int> answer;
	for (int i = 0; i < gems.size(); ++i) {
		while (!del.empty() && pq.top() == del.top()) {
			pq.pop(); del.pop();
		}
		if (pq.top() - i < len) {
			len = pq.top() - i;
			answer = {i + 1, pq.top() + 1};
		}
		index[mp[gems[i]]].pop_front();
		del.push(i);
		pq.push(index[mp[gems[i]]].front());
	}

	return answer;
}