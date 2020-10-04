#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	
	while (tc--) {
		string s, t;
		cin >> s >> t;

		int cnt[4] = {};
		for (char u: t) {
			if (u == 'B') cnt[0]++;
			else if (u == 'C') cnt[1]++;
			else if (u == 'M') cnt[2]++;
			else cnt[3]++;
		}
		cnt[0] *= 2;
		cnt[2] *= 4;
		cnt[3] *= 3;

		if (cnt[0] > cnt[1] && cnt[0] > cnt[2] && cnt[0] > cnt[3]) {
			cout << s << ": The Bobcat is the dominant species\n";
		}
		else if (cnt[1] > cnt[0] && cnt[1] > cnt[2] && cnt[1] > cnt[3]) {
			cout << s << ": The Coyote is the dominant species\n";
		}
		else if (cnt[2] > cnt[0] && cnt[2] > cnt[1] && cnt[2] > cnt[3]) {
			cout << s << ": The Mountain Lion is the dominant species\n";
		}
		else if (cnt[3] > cnt[0] && cnt[3] > cnt[1] && cnt[3] > cnt[2]) {
			cout << s << ": The Wolf is the dominant species\n";
		}
		else {
			cout << s << ": There is no dominant species\n";
		}
	}
}