#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int map[26][26];
int visited[26][26];
int x_move[4] = { 0,0,-1,1 };
int y_move[4] = { 1,-1,0,0 };
int cnt;
vector<int>v;
string home;

void DFS(int x,int y) {
	visited[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int x_new = x + x_move[i];
		int y_new = y + y_move[i];
		if ((x_new >= 0 && x_new < N) && (y_new >= 0 && y_new < N) && !visited[x_new][y_new] && map[x_new][y_new] == 1) {
			DFS(x_new, y_new);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> home;
		for (int j = 0; j < N; j++) {
			map[i][j] = home[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				cnt = 0;
				DFS(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;;
	}
	return 0;
}
