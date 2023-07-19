/*sum[k]는 수열 k번째 까지의 부분 수열 중 합이 가장 큰 수열의 합이다
* 즉 예를들면 {1,100,2,50,60}에서 sum[0]=1, sum[1]=101, sum[2]=3이다.
* 다음은 sum[k]의 값을 결정하는 과정이다.
* 0부터 k-1까지의 수열 중 k번째의 수열보다 작은 수열만 고려하여
* sum[0]+arr[k] 부터 sum[k-1]+arr[k] 까지 중에서 가장 큰 값을
* sum[k]라고 지정한다. 위 예시대로면 sum[k]는 다음과 같이 계산된다.
* sum[2]=sum[0]+arr[2]=3, sum[3]=sum[2]+arr[3]=53, sum[4]=sum[3]+arr[4]=113
* 모든 sum의 값을 구하면 총 N개의 sum 중에서 가장 큰 값이 부분 수열 중 합이
* 가장 큰 수열의 합이 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int sum[1001];
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void sol() {
	for (int i = 0; i < N; i++) {
		sum[i] = arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				sum[i] = max(sum[i], sum[j] + arr[i]);
			}
		}
	}
	sort(sum, sum + N);
	cout << sum[N - 1] << endl;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sol();
	return 0;
}
