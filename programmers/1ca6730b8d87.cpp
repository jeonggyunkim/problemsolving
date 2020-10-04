#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int time2int(string& s) {
	return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
}

string int2time(int i) {
	string ret;
	ret += (i / 60) / 10 + '0';
	ret += (i / 60) % 10 + '0';
	ret += ':';
	ret += (i % 60) / 10 + '0';
	ret += (i % 60) % 10 + '0';
	return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
	sort(timetable.begin(), timetable.end());
	vector<int> inttable;
	for (string& s: timetable) inttable.push_back(time2int(s));

	set<int> s;
	for (int i = 0; i < n; ++i) s.insert(540 + i * t);

	for (int time = 1439; time >= 0; --time) {
		int cnt = 0, i = 0;
		bool board = 0;
		int after = 0;
		for (int now = 0; now < 1440; ++now) {
			while (i < inttable.size() && inttable[i] == now) {
				cnt++; i++;
				if (board) after++;
			}
			if (now == time) {
				cnt++;
				board = 1;
			}
			if (s.count(now)) cnt -= min(m, cnt);
		}
		if (cnt <= after) {
			return int2time(time);
		}
	}
}