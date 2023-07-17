/*벡터를 사용하여 주식값을 받고 뒤에서부터 차례대로 증감을 계산한다
*result는 이익의 합을 나타낸다
*만약 값이 증가하면 이익을 낼 수 없으며 max를 해당 값으로 갱신한다
*만약 값이 감소하면 이익을 낼 수 있으므로 result에 (max-해당값)을 더한다
*/
#include<iostream>
#include<vector>
using namespace std;
int T;
int N;
vector<int> v;
void sol() {
	int max = v.back();
	long long result = 0;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > max) {
			max = v[i];
		}
		else {
			result += max - v[i];
		}
	}
	cout << result << endl;
	v.clear();
}
int main() {
	cin >> T;
	for (int j = 0; j < T; j++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int price;
			cin >> price;
			v.push_back(price);
		}
		sol();
	}
	return 0;
}
