#include<iostream>

using namespace std;
int n;
int map[101][101];

void search() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (map[i][j] == 1 && map[j][k] == 1) {
					map[i][k] = 1;
				}
				if (map[j][i] == 1 && map[i][k] == 1) {
					map[j][k] = 1;
				}
			}
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
		map[i][i] = 0;
	}
	search();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j]<<" ";
		}
		cout << "\n";
	}




}