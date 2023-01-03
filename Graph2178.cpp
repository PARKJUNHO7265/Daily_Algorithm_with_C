#include <iostream>
#include <queue>
using namespace std;

int N, M;
int move_x[4] = { 0, 0, -1, 1 };
int move_y[4] = { 1,-1,0,0 };
string row;
queue<pair<int, int>>q;
int visited[101][101];
int map[101][101];
int dist[101][101];

void BFS(int x, int y) {
	q.push(make_pair(x,y));
	visited[x][y] = true;
	dist[x][y]++;	//이동거리 계산
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x_new = x + move_x[i];
			int y_new = y + move_y[i];
			if ((x_new >= 0 && x_new <= N) && (y_new >= 0 && y_new <= M) && !visited[x_new][y_new] && map[x_new][y_new] == 1) {
				visited[x_new][y_new] = 1;
				q.push(make_pair(x_new, y_new));
				dist[x_new][y_new] = dist[x][y] + 1;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j] - '0';
		}
	}
	BFS(0, 0);
	cout << dist[N - 1][M - 1];
	return 0;
}
