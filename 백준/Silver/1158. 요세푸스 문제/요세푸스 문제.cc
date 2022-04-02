#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n;
	int k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int count = 1;
	cout << "<";
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		if(count%k==0){
			if (q.size() == 0)
				cout << first;
			else
				cout << first << ", ";
			count++;
		}
		else {
			q.push(first);
			count++;
		}


	}
	cout << ">";
}