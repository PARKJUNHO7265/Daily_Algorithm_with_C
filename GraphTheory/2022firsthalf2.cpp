#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//변수
int n;
int map[30][30];
int next_map[30][30];
int visited[30][30];
int group_cnt[1000] = { 0 }; //그룹에 속해있는 격자 수
int group_n = 0; //그룹의 개수
int group[30][30]; //각 격자마다 그룹 번호 기재
int m_y[4] = { -1,1,0,0 };
int m_x[4] = { 0,0,-1,1 };
queue<pair<int, int>>q;

//함수
bool Inrange(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < n) return true;
	else false;
}
void BFS(int y, int x) {
	int temp = map[y][x]; //맵에 적혀있는 수
	visited[y][x] = 1;
	group[y][x] = group_n;
	group_cnt[group_n]++;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = y + m_y[i];
			int n_x = x + m_x[i];
			if (Inrange(n_y, n_x) && !visited[n_y][n_x]) {
				if (map[n_y][n_x] == temp) {
					group[n_y][n_x] = group_n;
					group_cnt[group_n]++;
					visited[n_y][n_x] = 1;
					q.push(make_pair(n_y, n_x));
				}
			}
		}
	}
}
void find_group() { //영역별 그룹 나누기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				q.push(make_pair(i, j));
				BFS(i, j);
				group_n++;
			}
		}
	}
}
int art_point() { // 예술점수 계산
	int art_score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + m_y[k];
				int nx = j + m_x[k];
				if (Inrange(ny, nx) && map[i][j] != map[ny][nx]) {
					int g1 = group[i][j], g2 = group[ny][nx]; //그룹 번호
					int num1 = map[i][j], num2 = map[ny][nx]; //격자 번호
					int cnt1 = group_cnt[g1], cnt2 = group_cnt[g2];
					art_score += num1 * num2 * (cnt1 + cnt2);
				}
			}
		}
	}
	return art_score / 2;
}
int Get_score() { //예술점수 반환
	find_group();
	return art_point();
}
void rotate_square(int s_y,int s_x,int square_n) { //정사각형 회전
	for (int i = s_y; i < s_y + square_n; i++) {
		for (int j = s_x; j < s_x + square_n; j++) {
			int o_y = i - s_y; // 시작좌표를 원점으로 옮겨줌
			int o_x = j - s_x;
			int r_y = o_x;
			int r_x = square_n - (o_y + 1);
			next_map[r_y + s_y][r_x + s_x] = map[i][j];
		}
	}
}
void rotate() { 
	memset(next_map, 0, sizeof(next_map));
	memset(visited, 0, sizeof(visited));
	memset(group, 0, sizeof(group));
	memset(group_cnt, 0, sizeof(group_cnt));
	group_n = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n / 2) {
				next_map[j][i] = map[i][j];
			}
			else if (i == n / 2) {
				next_map[n - j - 1][i] = map[i][j];
			}
		}
	}
	int square_n = n / 2;
	rotate_square(0, 0, square_n);
	rotate_square(0, square_n + 1, square_n);
	rotate_square(square_n + 1, 0, square_n);
	rotate_square(square_n + 1, square_n + 1, square_n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = next_map[i][j];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += Get_score();
		rotate();
	}
	cout << ans;
	return 0;
}
