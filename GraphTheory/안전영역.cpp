/*비의 양을 고려하여 BFS를 실행하면 된다
* map[x][y]>height 이면 영역에 포함 아니면 포함하지 않는다
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, map_max = -1;
int map[101][101];
int visited[101][101] = { 0, };
int moveX[4] = { -1,1,0,0 };
int moveY[4] = { 0,0,-1,1 };
int cnt;
queue<pair<int, int>>q;
vector<int>area;
bool Inrange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;
	else return false;
}
void BFS(int x, int y, int h) {
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + moveX[i];
			int ny = y + moveY[i];
			if (Inrange(nx, ny) && map[nx][ny] > h && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map_max < map[i][j]) {
				map_max = map[i][j];
			}
		}
	}
	for (int i = 0; i < map_max; i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && map[j][k] > i) {
					visited[j][k] = 1;
					q.push(make_pair(j, k));
					BFS(j, k, i);
					cnt++;
				}
			}
		}
		area.push_back(cnt);
	}
	sort(area.begin(), area.end());
	cout << area.back() << endl;
	return 0;
}
