/* arr[num]은 num를 만들기 위한 최소 연산 횟수를 나타낸다.
이를 이용하여 arr[0]=arr[1]=0으로 설정하고 arr[2]부터 시작하여
3으로 나눠지는 경우, 2로 나눠지는 경우, -1을 하는경우 세 경우의 수를
모두 실행해가며 arr[num] 각각의 최솟값을 찾아 숫자를 키워간다 */
#include<iostream>
using namespace std;
int x;
int arr[1000000];
void sol(int x) {
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= x; i++) {
		int min = 1000000;
		if (i % 3 == 0) {
			arr[i] = arr[i / 3] + 1;
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		if (i % 2 == 0) {
			arr[i] = arr[i / 2] + 1;
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		arr[i] = arr[i - 1] + 1;
		if (arr[i] < min) {
			min = arr[i];
		}
		arr[i] = min;
	}
}
int main() {
	cin >> x;
	sol(x);
	cout << arr[x];
}
