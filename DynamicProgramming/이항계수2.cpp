/*이항계수 nCk는 n-1Ck + n-1Ck-1 으로 나타낼수 있다.
* 이를 이용하여 arr[n][k]=arr[n-1][k]+arr[n-1][k-1]이란 점화식을
* 세울수 있다. 이때, n을 1부터 N까지 k를 1부터 K까지 반복 실행하면
* arr[N][K]을 구할 수 있다. 단 n=0 일때와 k=0일때를 구분하여 설정해주어야한다
*/
#include <iostream>
using namespace std;
int N, K;
long long arr[1001][1001] = { 0, };
void sol() {
	arr[0][0] = 1;
	for (int j = 1; j <= K; j++) {
		arr[0][j] = 0;
	}
	for (int i = 1; i <= N; i++) {
		arr[i][0] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 10007;
		}
	}
}
int main() {
	cin >> N >> K;
	sol();
	cout << arr[N][K];
	return 0;
}
