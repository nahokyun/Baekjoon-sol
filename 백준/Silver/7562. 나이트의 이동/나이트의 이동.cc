#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

bool map[301][301];
int t;

int l;
int s_x, s_y;//시작 좌표
int f_x, f_y;//끝 좌표
int ct = 1000000;//몇번이동해야하는지 체크
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
queue<pair<pair<int, int>,int>>q;
void bfs() {
	while (!q.empty()) {
		int y=q.front().first.first;
		int x=q.front().first.second;
		int t = q.front().second;
		map[y][x] = true;
		if (y == f_y && x == f_x) {
			ct = t;
			break;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int n_y = y + dy[i];
			int n_x = x + dx[i];
			if (n_y >= 0 && n_y < l && n_x >= 0 && n_x < l && map[n_y][n_x] == false) {
				q.push({ { n_y,n_x },t+1 });
				map[n_y][n_x] = true;
			}
		}


	}



}
int main() {
	cin >> t;
	while (t--) {
		cin >> l;
		cin >> s_y >> s_x;
		cin >> f_y >> f_x;
		q.push({ { s_y,s_x },0 });
		bfs();
		

		for (int i = 0; i < 301; i++) {
			memset(map[i], false, sizeof(bool)*301);
		}
		cout << ct << endl;
		while (!q.empty())
			q.pop();
	}

}