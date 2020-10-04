#include <iostream>
using namespace std;

int main() {
	int cnt = 1;
	char a;
	while (scanf("%c", &a) != EOF) {
		if (cnt == 1 && a == 'U') cnt++;
		else if (cnt == 2 && a == 'C') cnt++;
		else if (cnt == 3 && a == 'P') cnt++;
		else if (cnt == 4 && a == 'C') {
			cout << "I love UCPC";
			return 0;
		}
	}
	cout << "I hate UCPC";
}