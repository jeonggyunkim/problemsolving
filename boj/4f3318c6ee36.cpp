#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	while (n--) {
		cin >> s;
		if (s == "anj") {
			cout << "뭐야;";
			return 0;
		}
	}
	cout << "뭐야?";
}