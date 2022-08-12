#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int map[11][11];
int min_cost = 100000000;
bool visit[11];
int n;
int st = 0;//시작지점
void search(int cur, int count, int cur_cost) {
	if (count == n) {
		if (map[cur][st] > 0) {
			min_cost = min(min_cost, cur_cost + map[cur][st]);
		}
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (map[cur][i] == 0||visit[i]==true)
				continue;
			visit[i] = true;
			search(i, count + 1, cur_cost + map[cur][i]);
			visit[i] = false;
		}
	}

}



int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		st = i;
		visit[i] = true;
		search(i, 1, 0);
		visit[i] = false;
	}

	cout << min_cost;

}