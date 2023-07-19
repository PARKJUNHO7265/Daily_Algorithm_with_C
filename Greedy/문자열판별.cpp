/*word[k]를 S의 k번째 이후의 문자열을 문자열 A를 통해 만들 수 있는지
* 여부를 나타내는 함수라고 하자.
* 예시로 S가 softwarecontest일때 word[15]=1이 된다.
* word[14]는 문자열 A를 통해 t라는 문자열을 만들 수 있는지 물어보는것이다.
* 따라서 word[14]=0이다.
* 이렇게 15부터 문자열의 앞으로 계속 넘어가며 word[k] 값을 구한다.
* word[k]=1이 되는 지점에서 주의할 것이 있다.
* k지점에서 S를 만들 수 있는 A를 찾았을때 word[k+문자열A의 길이]=1인지
* 꼭 검사해야한다. 그래야 이후 word[k+문자열A의 길이] 지점에서도
* 문자열 A를 통해 S를 만들 수 있다는 보장이 생긴다.
* 문자열 S에서 A를 찾기 위한 함수로 S문자열.find(A문자열,int) 을 사용한다
* 해당 함수는 S문자열의 int번째 문자열 이후로 A문자열이 있는지 찾는 함수다
*/
#include <iostream>
#include <string>
using namespace std;
string S;
int N, word[101] = { 0, };
string A[101];
void sol() {
	word[S.length()] = 1;
	for (int i = S.length() - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (S.find(A[j], i) == i && word[i + A[j].length()] == 1) {
				word[i] = 1;
				break;
			}
		}
	}
	cout << word[0];
}
int main() {
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sol();
	return 0;
}
