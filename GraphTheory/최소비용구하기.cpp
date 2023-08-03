/*map[1001][1001]을 사용하여 문제를 풀게되면 메모리 초과가 발생한다
* 따라서 2차원 배열 대신 vector<pair<int,int>>v[]를 사용해 문제를 풀어보자.
* city1에서 city2로 가는 비용이 cost라 주어지면 v[city1].push(make_pair(city2,cost) 로 값을 저장한다
* 이제 BFS 탐색을 하자. costnext.push(make_pair(cost,start)는 현재지점이 start지점이며 비용은 현재까지 cost란 소리다.
* BFS를 수행하면 start지점에서 탈 수 있는 버스를 찾는다.
* 해당 버스의 요금과 start 지점까지의 요금의 합을 ncost, 도착지를 next에 저장한다.
* 만약 ncost가 leastcost[next]보다 작으면 leastcost[next]를 ncost로 갱신한다.
* 다시말하면 (현 지점까지 총 비용)+(다음지점까지 비용) < (다음지점까지 총 비용) 이면 더 작은값을 갱신해준것이다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int, int>>v[1001]; //버스 정보를 저장하는 벡터
int start, finish; //출발, 도착지
queue<pair<int, int>> costnext; //BFS의 큐인데 배열의 좌표를 저장하는것과 달리 현위치, 현재까지비용 을 저장한다.
int leastcost[1001];

void BFS() {
    memset(leastcost, 0x3f, sizeof(leastcost));
    costnext.push(make_pair(0, start));
    leastcost[start] = 0;
    while (!costnext.empty()) {
        int cur = costnext.front().second;
        int cost = costnext.front().first;
        costnext.pop();
        if (leastcost[cur] < cost) continue;
        //cur지점에서 탈 수 있는 버스 모두 찾기
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second + leastcost[cur];
            //next지점까지 최소비용을 갱신해준다(필요시)
            if (leastcost[next] > ncost) {
                leastcost[next] = ncost;
                costnext.push(make_pair(leastcost[next], next));
            }
        }
    }
    cout << leastcost[finish] << endl;

}

int main() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        v[city1].push_back(make_pair(city2, cost));
    }
    cin >> start >> finish;
    BFS();
    return 0;
}

//memset에 관한 새로운 정보를 알았다
// memset은 0이외의 숫자로 초기화하면 더미값으로 초기화되는데 최대한 큰 숫자로 초기화하고 싶다면
// 0x3f 로 초기화하자
