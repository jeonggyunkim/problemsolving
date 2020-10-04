int solution(int n) {
	int answer = n + 1;
	int a = __builtin_popcount(n);
	while (__builtin_popcount(answer) != a) answer++;
	return answer;
}