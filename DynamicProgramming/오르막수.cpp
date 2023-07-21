/*길이가 N인 오름차순의 개수는 0부터 9까지 10개의 숫자중에
*순서없이 중복하여 N개를 뽑는것과 같다. 따라서 10HN으로 나타낼 수 있다.
*10HN=10+N-1CN이므로 이를 arr[9+N][N]을 구하면 된다.
*/
#include <iostream>
using namespace std;
int N;
long long arr[1020][1001] = { 0, };
void sol() {
	arr[0][0] = 1;
	for (int i = 1; i <= N + 9; i++) {
		arr[i][0] = 1;
	}
	for (int j = 1; j <= N; j++) {
		arr[0][j] = 0;
	}
	for (int i = 1; i <= N + 9; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
		}
	}
}
int main() {
	cin >> N;
	sol();
	cout << arr[N + 9][N];
	return 0;
}
