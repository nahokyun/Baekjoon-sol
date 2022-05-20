#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[9][9];//벽을 세우기전 맵
int wall_arr[9][9];//벽을 세운 맵
int temp_arr[9][9];//dfs하기전 저장
bool flag[9][9];
bool track_flag[9][9];
vector<int> wall;

int dx[4] = { 0,1, - 1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m;
int sz = 0;
int max_sz = 0;
vector<pair<int, int>> virus;//virus의 위치를 저장할 벡터

void dfs(int y, int x) {
	flag[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int c_x = x + dx[i];
		int c_y = y + dy[i];
		if (c_x < m && c_x >= 0 && c_y < n && c_y >= 0//맵의 범위에 넘어가지않고
			&& wall_arr[c_y][c_x]==0//아무것도 없는곳이고
			&& flag[c_y][c_x]==false) {//방문한적이 없을때
			wall_arr[c_y][c_x] = 2;
			dfs(c_y, c_x);
		}
	}

}

void backtrack(int wall_count) {
	if (wall_count == 3) {
		sz = 0;
		copy(&wall_arr[0][0], &wall_arr[0][0] + 81, &temp_arr[0][0]);
		//dfs전 벽세운상태 저장
		for (int i = 0; i < virus.size(); i++) {	
			int cur_x = virus[i].first;
			int cur_y = virus[i].second;		
			dfs(cur_y, cur_x);
		}
		//바이러스 전이 완료
		int a = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (wall_arr[i][j] == 0)
					sz++;
			}
		}


		//안전구역 탐색
		if (sz > max_sz)
			max_sz = sz;
		for (int i = 0; i < n; i++) {
			memset(flag[i], false, sizeof(bool) * m);
		}
		copy(&temp_arr[0][0], &temp_arr[0][0] + 81, &wall_arr[0][0]);
	}
	else {
		for (int i = 0; i < n * m; i++) {
			if (wall.size() > 0) {
				if (i <wall[wall.size() - 1])//직전값보다 작은i는 고르지않는다
					continue;
			}
			int a = i / m;
			int b = i % m;
			if (flag[a][b] == false&&wall_arr[a][b]==0) {
				wall_arr[a][b] = 1;
				flag[a][b] = true;
				wall.push_back(i);
				backtrack(wall_count + 1);
				wall_arr[a][b] = 0;
				flag[a][b] = false;
				wall.pop_back();
			}

		}



	}
}




int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ j,i });//x좌표,y좌표로 저장
			}
		}
	}
	//초기 맵 설정 완료

	copy(&arr[0][0], &arr[0][0] + 81, &wall_arr[0][0]);

	backtrack(0);
	
	
	cout << max_sz<<endl;





	
	


	
}