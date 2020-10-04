#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct s {
	int kor;
	int eng;
	int math;
	int name_ind;
};

char name[100001][11];

bool comp(s& a, s& b) {
	if (a.kor != b.kor) return a.kor > b.kor;
	if (a.eng != b.eng) return a.eng < b.eng;
	if (a.math != b.math) return a.math > b.math;
	if (strcmp(name[a.name_ind], name[b.name_ind]) < 0) return true;
	else return false;
}

int main() {
	int n;
	s stud[100001];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d %d", name + i, &stud[i].kor, &stud[i].eng, &stud[i].math);
		stud[i].name_ind = i;
	}
	sort(stud, stud + n, comp);
	for (int i = 0; i < n; ++i) {
		printf("%s\n", name + stud[i].name_ind);
	}
}