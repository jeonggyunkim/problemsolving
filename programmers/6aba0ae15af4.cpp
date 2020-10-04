#include <string>
using namespace std;

string solution(string p) {
	if (p.size() == 0) return "";
	int a = 0, b = 0;
	for (int i = 0; i < p.size(); i += 2) {
		if (p[i] == '(') a++;
		else b++;
		if (p[i + 1] == '(') a++;
		else b++;
		if (a == b) {
			int cnt = 0;
			bool bal = 1;
			for (int j = 0; j < i + 2; ++j) {
				if (p[j] == '(') cnt++;
				else cnt--;
				if (cnt < 0) bal = 0;
			}
			if (bal) {
				return p.substr(0, i + 2) + solution(p.substr(i + 2, p.size() - i - 2));
			}
			else {
				string ret = "(";
				ret += solution(p.substr(i + 2, p.size() - i - 2));
				ret += ')';
				for (int j = 1; j < i + 1; ++j) {
					if (p[j] == '(') ret += ')';
					else ret += '(';
				}
				return ret;
			}
		}
	}
}
