#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9];
int map2[9][9];
int visited[9][9];
int wall = 3;
int ans = 0;
int i_move[4] = { 1,-1,0,0 };
int j_move[4] = { 0,0, -1,1 };
queue<pair<int,int>>q;

void BFS() {
	//cout << "BFS" << endl;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y_move = y + i_move[i];
			int x_move = x + j_move[i];
			if ((y_move >= 0 && y_move < N) && (x_move >= 0 && x_move < M) && !visited[y_move][x_move] && map2[y_move][x_move] == 0) {
				visited[y_move][x_move] = 1;
				map2[y_move][x_move] = 2;
				q.push(make_pair(y_move, x_move));
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map2[i][j] == 0) {
				temp++;
			}
		}
	}
	if (temp > ans) {
		ans = temp;
	}
	/*cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map2[i][j] << " ";
		}
		cout << "\n";
	}*/
}
void startpoint() {
	//cout << "start" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map2[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map2[i][j] == 2) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
		}
	}
}
void search() {
	//cout << "search" << endl;
	if (wall == 0) {
		startpoint();
		BFS();
		memset(visited, 0, sizeof(visited));
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				wall--;
				map[i][j] = 1;
				search();
				wall++;
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	search();
	cout << ans;
}
