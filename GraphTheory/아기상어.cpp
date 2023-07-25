/* 알고리즘 작동 순서는 다음과 같다.
1. 상어의 현 위치에서 BFS를 실행하여 먹을 수 있는 물고기를 모두 찾는다
2-1. 먹을 수 있는 물고기가 없다면 시간을 출력, 
2-2.한마리라면 상어를 그곳으로 이동시키고
2-3.여러마리라면 그 중에서 가장 가까운 물고기만 찾는다
2-3-1.가장 가까운 물고기 중에서 가장 위, 왼쪽에 있는 물고기를 먹고 그곳으로 상어를 이동시킨다
3. 상어를 이동시켰다면 BFS를 재실행 하기 위해 다시 dist, fish 벡터, q 큐를 초기화해준다
4. 여태 먹은 물고기 만큼 상어의 크기를 키워준다
5. 상어를 이동시킨 지점부터 다시 BFS를 통해 먹을 수 있는 물고기를 찾아준다(반복)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<pair<int, int>>q;
vector<pair<int,int>>fish; //BFS를 1회 돌렸을때 먹을 수 있는 물고기 좌표 저장
int N;
int map[21][21] = { 0, };
int dist[21][21] = { -1, }; //해당좌표까지 상어가 도달하는데에 걸리는 시간 계산
int moveX[4] = { -1,0,0,1 };
int moveY[4] = { 0,-1,1,0 };
int shark_x, shark_y, shark_size = 2;
int curr_time; // 상어가 물고기 섭취했을때 시간 기록
int eatfish = 0; // 물고기 먹는 횟수 기록
int finished = 0; // 먹을 수 있는 물고기가 없어 while문을 끝낼때 사용하는 변수
// 이동한 좌표가 맵의 범위에 들어오는지 판단
bool Inrange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) {
		return true;
	}
	else return false;
}
void BFS(int x, int y) {
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + moveX[i];
			int ny = y + moveY[i];
			if (dist[nx][ny] != -1) continue; //이미 방문한 곳이면 패스
			if (!Inrange(nx, ny)) continue; //범위를 벗어나면 패스
			if (shark_size < map[nx][ny]) continue; // 상어의 크기가 물고기보다 작으면 패스
			//상어가 물고기를 먹진 않으나 이동하는 경우
			else if (shark_size == map[nx][ny] || map[nx][ny] == 0) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			//상어가 물고기를 먹으면서 이동하는 경우
			else if (map[nx][ny] < shark_size && map[nx][ny] >= 1) {
				dist[nx][ny] = dist[x][y] + 1;
				fish.push_back(make_pair(nx, ny)); // 물고기가 있는 좌표를 fish 벡터에 저장
				q.push(make_pair(nx, ny));
			}
		}
	}
	// 먹을 수 있는 물고기 수가 없는 경우 -> 현재시간 출력 밑 프로그램 종료
	if (fish.size() == 0) {
		cout << curr_time << endl;
		finished = 1;
		return;
	}
	//먹을 수 있는 물고기가 한개라 상어를 그곳으로 이동 시킴
	else if (fish.size() == 1) {
		shark_x = fish[0].first;
		shark_y = fish[0].second;
		map[shark_x][shark_y] = 0;
		eatfish++; //먹은 물고기 수 +1
		curr_time += dist[shark_x][shark_y];
	}
	//먹을 수 있는 물고기가 여러개라 가장 가까운곳을 찾아야 하는 경우
	else {
		int mindist = 100000;
		//먹을 수 있는 물고기 들 중 가장 거리가 가까운 물고기들을 찾음
		for (int i = 0; i < fish.size(); i++) {
			mindist = min(mindist, dist[fish[i].first][fish[i].second]);
		}
		vector<pair<int, int>>minfish; //가장 가까운 거리의 물고기만 저장하는 벡터
		//물고기들 중 mindist와 같은 거리의 물고기만 minfish 벡터에 저장
		for (int i = 0; i < fish.size(); i++) {
			if (mindist == dist[fish[i].first][fish[i].second]) {
				minfish.push_back(make_pair(fish[i].first, fish[i].second));
			}
		}
		//minfish가 한마리 밖에 없으면 상어를 그곳으로 이동시킴
		if (minfish.size() == 1) {
			shark_x = minfish[0].first;
			shark_y = minfish[0].second;
			map[shark_x][shark_y] = 0;
			curr_time += dist[shark_x][shark_y];
			eatfish++;
		}
		//가장 가까운 거리의 물고기들 중 가장 위에 있고, 가장 왼쪽에 있는 물고기가 우선순위
		else {
			sort(minfish.begin(), minfish.end());
			shark_x = minfish[0].first;
			shark_y = minfish[0].second;
			curr_time += dist[shark_x][shark_y];
			map[shark_x][shark_y] = 0;
			eatfish++;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			// 숫자 9는 상어의 위치를 나타냄
			if (map[i][j] == 9) {
				shark_x = i;
				shark_y = j;
			}
		}
	}
	while (1) {
		//BFS가 끝나고 난 후에는 queue, vector, dist[][] 모두 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = -1;
			}
		}
		dist[shark_x][shark_y] = 0;
		map[shark_x][shark_y] = 0;
		q = queue<pair<int, int>>();
		fish = vector<pair<int, int>>();
		//상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다
		if (eatfish >= shark_size) {
			eatfish -= shark_size;
			shark_size++;
		}
		//물고기를 먹은 지점에서부터 상어를 다시 출발 시킴 
		q.push(make_pair(shark_x, shark_y));
		BFS(shark_x, shark_y);
		if (finished == 1) return 0; //먹을 수 있는 물고기가 없으면 프로그램 종료
	}
}
