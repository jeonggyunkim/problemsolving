#include <iostream>
#include <stack>
#define INF 987654321
using namespace std;

typedef pair<long long, long long> ii;

int arr[300000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	long long ans = 0;
	stack<ii> st;
	long long stv = 0;
	st.push({INF, -1});
	for (int i = 0; i < n; ++i) {
		while (arr[i] >= st.top().first) {
			ii t = st.top(); st.pop();
			if (!st.empty()) {
				stv -= t.first * (t.second - st.top().second);
			}
		}
		stv += arr[i] * (i - st.top().second);
		st.push({arr[i], i});
		ans += stv;
	}
	while (!st.empty()) st.pop();
	stv = 0;

	st.push({-INF, -1});
	for (int i = 0; i < n; ++i) {
		while (arr[i] <= st.top().first) {
			ii t = st.top(); st.pop();
			if (!st.empty()) {
				stv -= t.first * (t.second - st.top().second);
			}
		}
		stv += arr[i] * (i - st.top().second);
		st.push({arr[i], i});
		ans -= stv;
	}
	cout << ans;
}