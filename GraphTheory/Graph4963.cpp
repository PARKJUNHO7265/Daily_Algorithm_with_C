#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int map[50][50];
int visited[50][50];
int cnt = 0;
queue<pair<int, int>>q;
int x_move[8] = { 0,0,-1,1,-1,1,-1,1 };
int y_move[8] = { 1,-1,0,0,1,1,-1,-1 };
void BFS() {
	while (!q.empty()) {
		int x = q.front().second; //j
		int y = q.front().first;  //i
		q.pop();
		for (int i = 0; i < 8; i++) {
			int x_new = x + x_move[i];
			int y_new = y + y_move[i];
			if (map[y_new][x_new] == 1 && !visited[y_new][x_new] && (x_new >= 0 && x_new < w) && (y_new >= 0 && y_new < h)) {
				q.push(make_pair(y_new, x_new));
				visited[y_new][x_new] = 1;
			}
		}
	}
}
int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					q.push(make_pair(i, j));
					visited[i][j] = 1;
					BFS();
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		cnt = 0;
	}
}
