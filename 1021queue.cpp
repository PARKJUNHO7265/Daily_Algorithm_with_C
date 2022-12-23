#include <iostream>
#include <deque>
using namespace std;

deque<int>q;
int main() {
	int N, M, num;
	int left, right;
	int count = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		q.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		for (int i = 0; i < q.size(); i++) {
			if (num == q[i]) {
				left = i;
				right = q.size() - i;
				break;
			}
		}
		if (left <= right) {
			while (1) {
				if (q.front() == num)break;
				q.push_back(q.front());
				q.pop_front();
				count++;
			}
			q.pop_front();
		}
		else {
			while (1) {
				if (q.back() == num) break;
				q.push_front(q.back());
				q.pop_back();
				count++;
			}
			count++;
			q.pop_back();
		}
	}
	cout << count << endl;
}
