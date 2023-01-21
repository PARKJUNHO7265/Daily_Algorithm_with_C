#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int map[101][101][101];
int visited[101][101][101];
int day[101][101][101];
queue<pair<int, pair<int, int>>>q;
int x_move[8] = { 0,0,-1,1,0,0 };
int y_move[8] = { 1,-1,0,0,0,0 };
int z_move[8] = { 0,0,0,0,1,-1 };
void BFS() {
	while (!q.empty()) {
		int x = q.front().second.second; //j
		int y = q.front().second.first;  //i
		int z = q.front().first;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];
			int z_new = z + z_move[i];
			if (!visited[z_new][y_new][x_new] && (x_new >= 0 && x_new < M) && (y_new >= 0 && y_new < N)&& (z_new >= 0 && z_new < H)) {
				visited[z_new][y_new][x_new] = 1;
				if (map[z_new][y_new][x_new] == 1 || map[z_new][y_new][x_new] == 0) {
					q.push(make_pair(z_new, make_pair(y_new, x_new)));
					day[z_new][y_new][x_new] = day[z][y][x] + 1;
					map[z_new][y_new][x_new] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> M >> N >> H;
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cin >> map[k][i][j];
				}
			}
		}
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[k][i][j] == 1 && !visited[k][i][j]) {
						q.push(make_pair(k, make_pair(i, j)));
						visited[k][i][j] = 1;
					}
				}
			}
		}
		BFS();
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[k][i][j] == 0) {
						cout << "-1";
						return 0;
					}
				}
			}
		}
		int max = 0;
		for (int k = 0; k < H; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (max < day[k][i][j]) {
						max = day[k][i][j];
					}
				}
			}
		}
		cout << max << endl;
		return 0;
}
