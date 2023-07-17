/*과제를 중요도 순서대로 나열한 후에
*순서대로 해당 과제를 최대한 늦게할 수 있는 날을 찾는다
*(제출기한,중요도)
*예제대로 라면 (4,60)은 넷째날 (2,50)은 둘째날 (4,40)은 셋째날
*(3,30)은 첫째날 (1,20)은 포기 (4,10)은 포기
*(6,5)은 다섯째날 혹은 여섯째날 하게 된다
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N, d, w;
int scheduled[1001] = { 0, };
vector<pair<int, int>>v;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
void sol() {
	int sum = 0;
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (scheduled[v[i].first] == 0) {
			scheduled[v[i].first] = 1;
			sum += v[i].second;
		}
		else {
			for (int j = v[i].first; j > 0; j--) {
				if (scheduled[j] == 0) {
					scheduled[j] = 1;
					sum += v[i].second;
					break;
				}
			}
		}
	}
	cout << sum << endl;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		v.push_back(make_pair(d, w));
	}
	sol();
	return 0;
}
