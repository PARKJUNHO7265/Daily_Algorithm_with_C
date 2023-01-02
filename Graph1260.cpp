#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int num1, num2;
queue<int>q;
int visited[1001] = { 0, };
int map[1001][1001];
void DFS(int x){
	visited[x] = true;
	cout << x << " ";
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && map[x][i] == 1) {
			DFS(i);
		}
	}
}
void BFS(int x) {
	q.push(x);
	visited[x] = true;
	cout << x << " ";
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && map[x][i] == 1) {
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		map[num1][num2] = 1;
		map[num2][num1] = 1;
	}
	DFS(V);
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
	cout << "\n";
	BFS(V);
	return 0;
}
