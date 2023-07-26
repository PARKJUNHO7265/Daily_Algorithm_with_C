/*주어진 부모 자식 관계를 map으로 정리한다.
* x가 y의 부모이면 map[x][y]=1, map[y][x]=1
* 촌수를 알아야 하는 person1부터 BFS를 시작한다.
* dist[]를 통해 person1과의 거리를 측정한다.
* 최종적으로 dist[person2]가 구하려는 촌수가 된다.
*/
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int person1, person2;
int map[101][101] = {0,};
int dist[101] = {0,};
queue<int>q;
void BFS(int num) {
	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[num][i] == 0) continue;
			else if (map[num][i] == 1&&!dist[i]) {
				q.push(i);
				dist[i] = dist[num] + 1;
			}
		}
	}
	if (dist[person2] == 0) {
		cout << -1 << endl;
	}
	else cout << dist[person2] << endl;
}
int main() {
	cin >> n;
	cin >> person1 >> person2;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	q.push(person1);
	BFS(person1);
	return 0;
}
