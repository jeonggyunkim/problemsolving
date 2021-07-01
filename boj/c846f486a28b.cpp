#include <iostream>
#include <memory.h>
#define MOD 1000000007
using namespace std;

string str[8] = {
	"01100000",
	"10110000",
	"11011000",
	"01101100",
	"00110110",
	"00011001",
	"00001001",
	"00000110",
};

long long arr[8][8];
long long ans[8][8];
long long temp[8][8];

void mul(int p) {
	while (p) {
		if (p & 1) {
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					temp[i][j] = 0;
					for (int k = 0; k < 8; ++k) {
						temp[i][j] += ans[i][k] * arr[k][j];
						temp[i][j] %= MOD;
					}
				}
			}
			memcpy(ans, temp, sizeof(temp));
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				temp[i][j] = 0;
				for (int k = 0; k < 8; ++k) {
					temp[i][j] += arr[i][k] * arr[k][j];
					temp[i][j] %= MOD;
				}
			}
		}
		memcpy(arr, temp, sizeof(temp));
		p >>= 1;
	}
}

int main() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			arr[i][j] = str[i][j] - '0';
		}
		ans[i][i] = 1;
	}

	int d;
	cin >> d;
	mul(d);
	cout << ans[0][0];
}