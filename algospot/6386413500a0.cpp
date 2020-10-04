#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<double> solveBase(vector<double>& v) {
	vector<double> ret;
	if (v.size() == 2) ret.push_back(-v[1] / v[0]);
	else {
		ret.push_back((-v[1] - sqrt(v[1] * v[1] - 4 * v[0] * v[2])) / (2 * v[0]));
		ret.push_back((-v[1] + sqrt(v[1] * v[1] - 4 * v[0] * v[2])) / (2 * v[0]));
	}
	return ret;
}

vector<double> diff(vector<double>& v) {
	int n = v.size() - 1;
	vector<double> ret;
	for (int i = 0; i < n; ++i) {
		ret.push_back((n - i) * v[i]);
	}
	return ret;
}

double cal(double x, vector<double>& v) {
	double ret = 0;
	for (int i = 0; i < v.size(); ++i) {
		ret *= x;
		ret += v[i];
	}
	return ret;
}

double bsearch(double a, double b, vector<double>& v) {
	double ya = cal(a, v), yb = cal(b, v), mid, ymid;
	for (int i = 0; i < 100; ++i) {
		mid = (a + b) / 2;
		ymid = cal(mid, v);
		if (ya * ymid > 0) {
			a = mid;
			ya = ymid;
		}
		else {
			b = mid;
			yb = ymid;
		}
	}
	return mid;
}

vector<double> solve(vector<double>& v) {
	if (v.size() <= 3) return solveBase(v);

	vector<double> difv = diff(v);
	vector<double> loc = solve(difv);

	loc.insert(loc.begin(), -10);
	loc.push_back(10);

	vector<double> ret;
	for (int i = 0; i < loc.size() - 1; ++i) {
		ret.push_back(bsearch(loc[i], loc[i + 1], v));
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		double t;
		vector<double> v;
		for (int i = 0; i < n + 1; ++i) {
			cin >> t;
			v.push_back(t);
		}

		vector<double> ans = solve(v);
		cout.precision(12);
		for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}
