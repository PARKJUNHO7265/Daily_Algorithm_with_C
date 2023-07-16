/*M개의 사이트중 N개의 사이트를 골라 다리를 만들어야함 즉 조합으로 문제를 풀면된다
M_C_N = M-1_C_N-1 + M-1_C_N 으로 표현이 가능하다는 점을 이용하여 arr[1][1]부터 arr[N][M]까지 구하면된다
*/
#include <iostream>
using namespace std;

int N, M, T;
int arr[31][31];
int sol(int n, int m) {
	arr[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		arr[i][0] = 0;
	}
	for (int j = 1; j <= M; j++) {
		arr[0][j] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= M; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
		}
	}
	return arr[N][M];
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << sol(N, M) << endl;
	}
	return 0;
}
