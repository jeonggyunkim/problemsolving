#include <iostream>
using namespace std;

char temp[6];

int ctime(char time[6]) {
	int m = 0;
	int s = 0;
	m += (time[0] - 48) * 10;
	m += (time[1] - 48);
	s += (time[3] - 48) * 10;
	s += (time[4] - 48);

	return 60 * m + s;
}

char* timec(int time) {
	int m = time / 60;
	int s = time % 60;

	::temp[0] = m / 10 + 48;
	::temp[1] = m % 10 + 48;
	::temp[2] = ':';
	::temp[3] = s / 10 + 48;
	::temp[4] = s % 10 + 48;
	::temp[5] = '\0';

	return ::temp;
}

int main() {
	int N;
	cin >> N;

	int team;
	char time[6];
	int score1 = 0;
	int score2 = 0;
	int past_time = 0;
	int curr_time = 0;
	int time1 = 0;
	int time2 = 0;

	for (int i = 0; i < N; ++i) {
		cin >> team >> time;
		past_time = curr_time;
		curr_time = ctime(time);
		if (score1 < score2) {
			time2 += curr_time - past_time;
		}
		if (score1 > score2) {
			time1 += curr_time - past_time;
		}
		team == 1 ? score1++ : score2++;
	}

	past_time = curr_time;
	curr_time = 48 * 60;
	if (score1 < score2) {
		time2 += curr_time - past_time;
	}
	if (score1 > score2) {
		time1 += curr_time - past_time;
	}

	cout << timec(time1) << endl;
	cout << timec(time2) << endl;

	return 0;
}