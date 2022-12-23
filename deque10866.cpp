#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int>dq;
	int N;
	string command;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "front") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
				continue;
			}
			cout << dq.front() << endl;
		}
		else if (command == "back") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
				continue;
			}
			cout << dq.back() << endl;
		}
		else if (command == "pop_front") {
			if (dq.size() == 0) { 
				cout << "-1" << endl; 
				continue; 
			}
			cout << dq.front() << endl;
			dq.pop_front();
		}
		else if (command == "pop_back") {
			if (dq.size() == 0) {
				cout << "-1" << endl;
				continue;
			}
			cout << dq.back() << endl;
			dq.pop_back();
		}
		else if (command == "size") {
			cout << dq.size() << endl;
		}
		else if (command == "empty") {
			cout << dq.empty() << endl;
		}
	}
	return 0;
}
