#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


int n, m;
int map[16][16];
int visited[16][16];
int step[16][16];
int move_y[4] = { -1,0,0,1 };
int move_x[4] = {0,-1,1,0};
int curr_t = 0;
queue<pair<int, int>>q;
pair<int, int>conv[31]; // 편의점 위치
pair<int, int>people[31]; //사람 위치


void BFS(int y, int x) {
	memset(visited, 0, sizeof(visited));
	memset(step, 0, sizeof(step));
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	step[y][x] = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int y_new = y + move_y[i];
			int x_new = x + move_x[i];
			if (map[y_new][x_new] != 2 && (y_new < n && y_new >= 0) && (x_new < n && y_new >= 0) && !visited[y_new][x_new]) {
				q.push(make_pair(y_new, x_new));
				step[y_new][x_new] = step[y][x] + 1;
				visited[y_new][x_new] = 1;
			}
		}
	}
}
void Simulate() {
	// 격자에 있는 사람 1칸 이동
	for (int i = 0; i < m; i++) {
		if (people[i] == make_pair(-1, -1) || people[i] == conv[i]) continue; //아직 밖에 있거나 편의점 도착한 사람은 패스
		BFS(conv[i].first, conv[i].second); // 편의점에서 캠프지까지 최단거리 구하기
		int px, py; //격자에 있는 사람 위치
		py = people[i].first;
		px = people[i].second;
		int min_dist = 100;
		int min_y = -1, min_x = -1;
		//최단거리 대로 한칸 이동 visited[ny][nx]가 포인트임
		for (int j = 0; j < 4; j++) {
			int ny = py + move_y[j], nx = px + move_x[j];
			if ((ny >= 0 && ny < n && nx < n && nx >= 0) && visited[ny][nx] && min_dist > step[ny][nx]) {
				min_dist = step[ny][nx];
				min_y = ny; min_x = nx;
			}
		}
		//위에서 계산한 위치로 사람 좌표 한칸 이동
		people[i] = make_pair(min_y, min_x);
	}
	for (int i = 0; i < m; i++) {
		if (people[i] == conv[i]) {
			int py, px;
			py = people[i].first; px = people[i].second;
			map[py][px] = 2;
		}
	}
	// 현재 시간이 m 초과시 종료
	if (curr_t > m) return;
	// 현재 시간에 해당하는 사람 추가(편의점->베이스캠프의 최단거리 찾기)
	BFS(conv[curr_t - 1].first, conv[curr_t - 1].second);
	int min_dist = 100;
	int min_y = -1, min_x = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] && map[i][j] == 1 && min_dist > step[i][j]) {
				min_dist = step[i][j];
				min_y = i; min_x = j;
			}
		}
	}
	people[curr_t - 1] = make_pair(min_y, min_x);
	map[min_y][min_x] = 2;
}
bool End() {
	// 편의점에 모두 도착
	for (int i = 0; i < m; i++) {
		if (people[i] != conv[i]) return false;
	}
	return true;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		conv[i] = make_pair(a - 1, b - 1);
	}
	for (int i = 0; i < m; i++) {
		people[i] = make_pair(-1, -1);
	}
	while (true) {
		curr_t++;
		Simulate();
		if (End()) break;
	}
	cout << curr_t;
	return 0;
}
