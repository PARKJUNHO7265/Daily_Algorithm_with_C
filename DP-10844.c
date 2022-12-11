#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int sum = 0;
int arr[101][10]; //arr[자릿수][계단번호]
void sol(int N) {
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		arr[i][0] = arr[i - 1][1] % 1000000000;
		arr[i][9] = arr[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			/* ##3은 #2와 #4로 부터 만들어질수 있다. 즉 arr[3][3]=arr[2][2]+arr[2][4]이다 */
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum + arr[N][i]) % 1000000000;
	}
	printf("%d", sum);
}
int main() {
	scanf("%d", &N);
	sol(N);
	return 0;
}
