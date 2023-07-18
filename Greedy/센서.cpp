/*N개의 센서를 오름차순으로 정렬하고 각 센서 사이의 거리 벡터를 추출한다.
* 센서 사이 거리 벡터를 다시 오름차순으로 정렬한다.
* 1개의 집중국이 센서를 모두 관리하면 해당 거리 벡터를 전부 더한 거리가
* 1개 집중국의 수신가능 영역이 될것이다.
* 2개의 집중국이 센서를 관리한다면 거리 벡터 중 가장 먼 거리벡터를 가지는
* 센서를 다른 1개의 집중국에 할당해주면 된다.
* 즉 N-1개의 거리벡터 중 가장 먼 거리벡터를 제외하고 N-1-1개를 더한 값이
* 수신가능 영역 길이 합이 된다.
* K개의 집중국이 있다면 N-1-K를 더한 값이 수신가능 영역 길이 합이 된다
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
vector<int>sensor;
vector<int>sensor_dist;
void sol() {
	sort(sensor.begin(), sensor.end());
	for (int i = 0; i < N - 1; i++) {
		int tmp = sensor.back();
		sensor.pop_back();
		int next = sensor.back();
		sensor_dist.push_back(abs(tmp - next));
	}
	sort(sensor_dist.begin(), sensor_dist.end());
	int sum = 0;
	for (int i = 0; i < N - K; i++) {
		sum += sensor_dist[i];
	}
	cout << sum << endl;
}
int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		int location;
		cin >> location;
		sensor.push_back(location);
	}
	sol();
	return 0;
}
