#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	char input[1003];
	scanf("%s", input);
	set<string> s;

	int n = -1;
	while (input[++n] != 0);

	for (int i = 0; i < n; ++i) {
		s.insert(input + i);
	}

	string str;
	for (auto it = s.begin(); it != s.end(); ++it) {
		str = *it;
		printf("%s\n", str.c_str());
	}
}