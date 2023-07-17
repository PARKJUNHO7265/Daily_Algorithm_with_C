/*세개의 경우로 나누어 문제를 해결한다
* 1. 사용하려는 제품이 이미 멀티탭에 꽂혀있는 경우
* 2. 멀티탭에 빈자리가 있는 경우
* 3. 사용하려는 제품이 꽂혀있지 않고 멀티탭에 빈자리가 없는 경우
* 3번째 경우는 멀티탭에 꽂혀있는 제품중에서 이후에 가장 늦게 사용될 제품을 찾고
* 해당 제품은 뽑고 현재 사용하려는 제품을 꽂는다
*/
#include <iostream>
using namespace std;
int N, K;
int working[101] = { 0, };
int schedule[101];
int sol() {
	int count = 0;
	for (int i = 0; i < K; i++) {
		bool plugged = false;
		// 이미 꽂혀있는 경우
		for (int j = 0; j < N; j++) {
			if (working[j] == schedule[i]) {
				plugged = true;
				break;
			}
		}
		if (plugged == true) {
			continue;
		}
		// 빈칸이 있어 꽂는경우
		for (int j = 0; j < N; j++) {
			if (working[j] == 0) {
				working[j] = schedule[i];
				plugged = true;
				break;
			}
		}
		if (plugged == true) {
			continue;
		}
		// 빈칸이 없어 하나 빼야하는경우
		int last_need = -1; //제일 마지막에 사용되는 제품
		int getout = -1; //플러그 뽑을 제품
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			for (int t = i + 1; t < K; t++) {
				if (working[j] == schedule[t]) {
					break;
				}
				tmp++;
			}
			if (tmp > last_need) {
				last_need = tmp;
				getout = j;
			}
		}
		working[getout] = schedule[i];
		count++;
	}
	return count;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> schedule[i];
	}
	cout << sol();
}
