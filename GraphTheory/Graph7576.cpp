#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int path[1001][1001];
int visited[1001][1001];
int y_move[4] = { 0,0,-1,1 };
int x_move[4] = { 1,-1,0,0 };
queue<pair<int, int>>q;

void BFS() {
	while (!q.empty()) {
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << path[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int x_new = x + x_move[k];
			int y_new = y + y_move[k];
			if ((x_new >= 0 && x_new <= N - 1) && (y_new >= 0 && y_new <= M - 1) && (!visited[x_new][y_new]) && (map[x_new][y_new] == 0)) {
				q.push(make_pair(x_new, y_new));
				visited[x_new][y_new] = 1;
				path[x_new][y_new] = path[x][y] + 1; // path 변수를 선언하여 날짜 계산!!!
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				//BFS(i, j); 이 방법은 익은 토마토가 여러곳에 있고 동시에 익기 시작하는것을 고려할수 없음 
				q.push(make_pair(i, j));
			}
		}
	}
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	int max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (path[i][j] > max) {
				max = path[i][j];
			}
		}
	}
	cout << max;
	return 0;
}
