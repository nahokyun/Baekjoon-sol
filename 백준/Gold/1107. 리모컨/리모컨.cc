#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
using namespace std;
int remoteX[10];

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		remoteX[x] = 1;
	}
	int min_click = abs(n-100);
	int count = abs(100 - n);
	for (int j = 0; j <= 1000000; j++) {
		int count_cur = 0;
		int flag = 1;

		int cur = j;
		if (cur == 0) {
			if (remoteX[0] != 1)
				count_cur++;
			else
				continue;
		}

		while (cur > 0) {
			int mod = cur% 10;
			
			if (remoteX[mod] == 1) {
				flag = 0;
				break;
			}
			
			count_cur++;
			cur = cur / 10;
		}
		if (flag == 0)
			continue;
		if(count_cur>0)
		count_cur += abs(j - n);
		if (count_cur==0)
			int a = 0;
		
		if (min_click>min(count,count_cur))
			min_click = min(count,count_cur);
	}



	cout <<min_click<<endl;
}