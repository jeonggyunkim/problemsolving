#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string s;
string now = "Taxi Garage";

struct city {
	int x, y;
	bool oil = 0;
	int oilPrice;
};

map<string, int> cityName;
vector<city> cityInfo;
map<string, pair<int, long long>> psg;
int cap = 0;

void getCity(int ind) {
	getline(cin, s);
	int i = s.size() - 1;
	while ('0' <= s[i] && s[i] <= '9') i--;
	int j = i;
	i--;
	while ('0' <= s[i] && s[i] <= '9') i--;
	cityName[s.substr(0, i)] = ind;
	cityInfo[ind].x = atoi(s.substr(i + 1, j - i - 1).c_str());
	cityInfo[ind].y = atoi(s.substr(j + 1, s.size() - j - 1).c_str());
}

void getOil() {
	getline(cin, s);
	int i = s.size() - 1;
	while ('0' <= s[i] && s[i] <= '9') i--;
	cityInfo[cityName[s.substr(0, i)]].oil = 1;
	cityInfo[cityName[s.substr(0, i)]].oilPrice = atoi(s.substr(i + 1, s.size() - i - 1).c_str());
}

pair<int, string> getQuery() {
	getline(cin, s);
	if (s[0] == 'G') {
		return make_pair(1, s.substr(6, s.size() - 7));
	}
	else {
		return make_pair(2, s.substr(28, s.size() - 29));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int n;
	cin >> n;
	cityInfo.resize(n);
	getline(cin, s);
	for (int i = 0; i < n; ++i) getCity(i);
	for (int i = 0; i < 3; ++i) getOil();

	int q;
	cin >> q;
	getline(cin, s);

	long long unit = C, money = 0;
	for (int i = 0; i < n; ++i) {
		if (cityInfo[i].oil) {
			unit *= cityInfo[i].oilPrice;
		}
	}

	long long oil = unit * A;
	while (q--) {
		pair<int, string> op = getQuery();
		string next = op.second;
		if (op.first == 1) {
			int dist = abs(cityInfo[cityName[now]].x - cityInfo[cityName[next]].x);
			dist += abs(cityInfo[cityName[now]].y - cityInfo[cityName[next]].y);
			oil -= (unit / C) * dist;
			if (oil < 0) {
				cout << "OUT OF GAS";
				return 0;
			}
			now = next;
			for (auto it = psg.begin(); it != psg.end(); ++it) {
				it->second.second += dist * it->second.first;
			}
			for (auto it = psg.begin(); it != psg.end(); ++it) {
				if (it->first == now) {
					money += it->second.second * B;
					cap -= it->second.first;
					psg.erase(it);
					break;
				}
			}
			if (cityInfo[cityName[now]].oil) {
				long long locUnit = unit / cityInfo[cityName[now]].oilPrice;
				long long need = (A * unit - oil) / locUnit;
				if (money >= need) {
					oil = A * unit;
					money -= need;
				}
				else {
					oil += locUnit * money;
					money = 0;
				}
			}
		}
		else {
			if (psg.find(next) == psg.end()) psg[next] = {1, 0};
			else psg[next].first++;
			cap++;
			if (cap > 3) {
				cout << "CAPACITY FULL";
				return 0;
			}
		}
	}
	if (now != "Taxi Garage") {
		cout << "NOT IN GARAGE";
		return 0;
	}
	if (!psg.empty()) {
		cout << "REMAINING PASSENGER";
		return 0;
	}
	cout << money;
}