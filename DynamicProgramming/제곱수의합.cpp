/*arr[N]은 N을 제곱수들의 합으로 표현할때 항의 최소 개수이다.
* 이때 arr[N]은 다음과 같이 나타낼수 있다
* arr[N-1^2]+1 or arr[N-2^2]+1 or arr[N-3^2]+1 ....
* 위 중에서 가장 작은 것이 arr[N]이 된다 
*/
#include <iostream>
using namespace std;

int N;
int arr[100001];
int sol(int n) {
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}
	for (int j = 1; j <= n; j++) {
		int min = 100001;
		for (int i = 1; i * i <= j; i++) {
			if (min > arr[j - i * i] + 1) {
				min = arr[j - i * i] + 1;
			}
		}
		arr[j] = min;
	}
	return arr[n];
}
int main() {
	cin >> N;
	cout << sol(N);
	return 0;
}
