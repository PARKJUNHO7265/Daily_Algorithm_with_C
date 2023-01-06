#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T, M, N, K;
int map[51][51];
int visited[51][51];
int x_move[4] = { 0,0,-1,1 };
int y_move[4] = { 1,-1,0,0 };
int cnt;
int X, Y;

void DFS(int x,int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int x_new = x + x_move[i];
		int y_new = y + y_move[i];
		if ((x_new >= 0 && x_new < M) && (y_new >= 0 && y_new < N) && !visited[x_new][y_new] && map[x_new][y_new] == 1) {
			DFS(x_new, y_new);
		}
	}
}
void Reset() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	cnt = 0;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			map[X][Y] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		Reset();
	}
	return 0;
}
