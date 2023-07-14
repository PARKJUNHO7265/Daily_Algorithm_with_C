#include<iostream>
using namespace std;
int sugar;
int N;
int A = 0;
int find_5k(int sugar) {
	while (1) {
		if (sugar % 5 == 0) {
			return A;
		}
		if (sugar <= 0) return -1;
		A++;
		sugar -= 3;
	}
}
int main() {
	cin >> N;
	int B = find_5k(N);
	if (B == -1) {
		cout << -1;
	}
	else cout << B + (N - B * 3) / 5;
}
