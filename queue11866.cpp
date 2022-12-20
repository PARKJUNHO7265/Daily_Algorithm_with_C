#include <iostream>
#include <queue>
using namespace std;

int N;
int K;
queue<int>q1;
int start = 0;
int nextstart = 0;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) q1.push(i);
	cout << "<";
	while (!q1.empty()) {
		for (int i = 1; i < K; i++) {
			q1.push(q1.front());
			q1.pop();
		}
		cout << q1.front();
		if (q1.size() != 1) cout << ", ";
		q1.pop();
	}
	cout << ">";
}
