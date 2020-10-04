#include <iostream>
#include <vector>
#define EPS 1e-12
using namespace std;

typedef pair<int, int> ii;

vector<ii> lines;

double find_high(double t) {
	double ret = -1;
	for (int i = 0; i < lines.size(); ++i) {
		double loc = lines[i].first * t + lines[i].second;
		if (loc < 0) loc = -loc;
		ret = max(ret, loc);
	}
	return ret;
}

bool inc(double t) {
	return find_high(t) < find_high(t + EPS);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int px[50], py[50], vx[50], vy[50];
	for (int i = 0; i < n; ++i) {
		cin >> px[i] >> py[i] >> vx[i] >> vy[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			lines.push_back(ii(vx[j] - vx[i], px[j] - px[i]));
			lines.push_back(ii(vy[j] - vy[i], py[j] - py[i]));
		}
	}

	double low = 0, high = 10000;
	while (high - low > EPS) {
		double mid = (low + high) / 2;
		if (inc(mid)) high = mid;
		else low = mid;
	}

	cout.precision(15);
	cout << find_high(low);
}