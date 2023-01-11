#include <iostream>
#include <queue>
using namespace std;

int N, M;
int u, v;
int map[1001][1001] = { 0, };
int visited[1001] = { 0, };
queue<int>q;
int cnt = 0;

void BFS(int x) {
	q.push(x);
	visited[x] = 1;
	//cout << x << " ";
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && map[x][i] == 1) {
				q.push(i);
				visited[i] = 1;
				//cout << i << " ";
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
