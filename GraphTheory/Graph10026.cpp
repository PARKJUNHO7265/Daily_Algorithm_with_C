#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[101][101];
int visited[101][101];
int cnt = 0;
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
			if ((y_move >= 0 && y_move < N) && (x_move >= 0 && x_move < N) && !visited[y_move][x_move] && map[y_move][x_move] == map[y][x]) {
				visited[y_move][x_move] = 1;
				q.push(make_pair(y_move, x_move));
			}
		}
	}
	/*cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}*/
}
void startpoint() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				BFS();
				cnt++;
			}
		}
	}
}
void changecolor() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') {
				map[i][j] = 'R';
			}
		}
	}
}
int main() {
	string color;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> color;
		for (int j = 0; j < N; j++) {
			map[i][j] = color[j];
		}
	}
	startpoint();
	cout << cnt << " ";
	memset(visited, 0, sizeof(visited));
	cnt = 0;
	changecolor();
	startpoint();
	cout << cnt;
}
