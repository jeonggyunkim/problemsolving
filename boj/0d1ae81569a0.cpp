#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	cout << (A == V ? 1 : (V - A - 1) / (A - B) + 2);
}