#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n, num;
	char name[22];
	int result, mem, time, lan, len;
	map<string, int> m;
	m["megalusion"] = -1;
	int count_cor = 0;
	int count_try = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %s %d %d %d %d %d", &num, name, &result, &mem, &time, &lan, &len);
		if (result == 4) {
			if (m.find(name) == m.end()) {
				m[name] = -1;
				count_cor++;
			}
			else if (m[name] != -1) {
				count_try += m[name];
				count_cor++;
				m[name] = -1;
			}
		}
		else {
			if (m.find(name) == m.end()) m[name] = 1;
			else if (m[name] != -1) m[name] += 1;
		}
	}
	if (count_cor == 0) printf("0\n");
	else {
		double rat = count_cor * 100;
		rat /= (count_try + count_cor);
		printf("%.13lf\n", rat);
	}
}