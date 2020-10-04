#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char input[110];
	while (1) {
		cin.getline(input, 110);
		if (input[0] == '.' && input[1] == 0) break;
		int i = 0;
		vector<char> st;
		bool right = 1;
		while (input[i]) {
			if (input[i] == '(' || input[i] == '[') st.push_back(input[i]);
			if (input[i] == ')') {
				if (st.empty() || st.back() != '(') {
					right = 0;
					break;
				}
				st.pop_back();
			}
			if (input[i] == ']') {
				if (st.empty() || st.back() != '[') {
					right = 0;
					break;
				}
				st.pop_back();
			}
			i++;
		}
		if (!st.empty() || !right) cout << "no\n";
		else cout << "yes\n";
	}
}