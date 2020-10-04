#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int score[1001];

	int num;
	while (n--) {
		scanf("%d", &num);
		int avg = 0;
		for (int j = 0; j < num; j++) {
			scanf("%d", score + j);
			avg += score[j];
		}
		int high = 0;
		for (int j = 0; j < num; j++) {
			if (avg < score[j] * num) high++;
		}
		printf("%.3lf%%\n", (double)high / num * 100);
	}
}