/*입력받은 직사각형의 좌표를 map에 저장한다
* 직사각형이 있는 map은 1로 없는 map은 0으로 저장한다
* 이후 for문을 통해 좌표 (0,0)부터 (M,N)까지 map을 순환하며 아직 방문하지 않은곳을 찾아다닌다
* moveX, moveY 배열을 통해 좌표의 동서남북을 관찰하고 관찰한 지점 중에서
* 아직 방문하지 않은곳이 있다면 방문한다.
* 만약 DFS 함수의 재귀가 종료되면 더 이상 연결된 지점 중에선 방문할 곳이 없으므로
* 다시 for문으로 돌아가 좌표 (M,N)까지 map을 순환한다
* DFS 함수를 실행할때마다 cnt 수를 더해주어 수를 세주면 해당 영역의 넓이를
* 측정할 수 있다. 모든 영역에 대해 cnt를 측정하여 Vector에 넣고 크기를 비교하여
* 이를 출력한다
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>res;
int M, N, K;
int x_1, y_1, x_2, y_2;
int cnt = 0;
int visited[101][101] = { 0, };
int map[101][101] = { 0, };
int moveX[4] = { 1,-1,0,0, };
int moveY[4] = { 0,0,1,-1 };
// moveX, moveY를 통해 해당 좌표의 동서남북 좌표중 아직 방문한 적이 없는 좌표를
// DFS를 통해 방문한다.
void DFS(int x, int y) {
	cnt++;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + moveX[i];
		int ny = y + moveY[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[nx][ny]) {
			DFS(nx, ny);
		}
	}
}
int main() {
	cin >> M >> N >> K;
	// 직사각형의 좌표를 입력받고 이를 MAP에 저장한다
	for (int i = 0; i < K; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int j = y_1; j < y_2; j++) {
			for (int k = x_1; k < x_2; k++) {
				map[j][k] = 1;
				visited[j][k] = 1;
			}
		}
	}
	// MAP 순환(아직 방문하지 않은 곳을 발견하면 해당 부분부터 DFS 시작)
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				cnt = 0;
				DFS(i, j);
				// 해당 영역에 대해 cnt 수를 센다
				res.push_back(cnt);
			}
		}
	}
	// 영역 별 크기를 비교한다
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}
