#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
int map[51][51];
int res_map[51][51];
int n, m;

void change(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (map[i][j] == 0)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	int count = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&res_map[i][j]);
		}
	}

	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != res_map[i][j]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			cout << -1 << endl;
		else
			cout << 0 << endl;
	}
	else {
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < m - 2; j++) {
				if (map[i][j] != res_map[i][j]) {
					change(i, j);
					count++;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != res_map[i][j]) {
					flag = 1;
				}
			}
		}
		if (flag == 1)
			cout << -1 << endl;
		else
			cout << count << endl;
	}





}