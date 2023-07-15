/*arr[num]은 num을 1,2,3의 합으로 나타내는 방법의 수임
num-3이 가지는 경우의 수에 3을 추가하면 num이 됨 
num-2이 가지는 경우의 수에 2를 추가하면 num이 됨
num-1이 가지는 경우의 수에 1을 추가하면 num이 됨
따라서 num은 num-3, num-2, num-1 이 가지는 경우의 수를 모두 더하면 됨
*/
#include<iostream>
using namespace std;
int n, T;
int arr[12];
void sol(int n) {
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		sol(n);
		cout << arr[n] << endl;
	}
  return 0;
}
