#include <iostream>
#include <queue>
using namespace std;
int N, K;
queue<int>q;
int visited[100001] = { 0, };
int t[100001] = { 0, };
void BFS(int x) {
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0) {
				nx = x - 1;
			}
			else if (i == 1) {
				nx = x + 1;
			}
			else {
				nx = x * 2;
			}
			if (nx >= 0 && nx <= 100000 && !visited[nx]) {
				t[nx] = t[x] + 1;
				visited[nx] = 1;
				q.push(nx);
			}
			if (nx == K) {
				cout << t[nx] << endl;
				return;
			}
		}
	}
}
int main() {
	cin >> N >> K;
	t[N] = 0;
	visited[N] = 1;
	q.push(N);
	BFS(N);
	return 0;
}
