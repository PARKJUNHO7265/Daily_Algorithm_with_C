/*집들을 오름차순으로 정리했을때 중간값이 최소가 되는 지점이다
*v.push_back 으로 집 위치를 받고 sort(v.begin(),sort.end())로
*오름차순으로 집을 정렬하고 중간값을 구한다
*/#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int N;
void sol() {
	sort(v.begin(),v.end());
	if (N % 2 == 0) {
		cout << v[N / 2 - 1];
	}
	else {
		cout << v[N / 2];
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int house;
		cin >> house;
		v.push_back(house);
	}
	sol();
}
