#include<iostream>
using namespace std;
int n;
int arr[12];
int cal_c[4];
int res = 0;
int maximum =-1000000000;
int minimum =1000000000;


void calculate(int num,int res) {
	if (num == n-1) {
		if (res > maximum)
			maximum = res;
		if (res < minimum)
			minimum = res;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (cal_c[i] > 0) {
				if (i == 0) {
					cal_c[i]--;
					calculate(num + 1, res + arr[num + 1]);
					cal_c[i]++;
				}
				if (i == 1) {
					
					cal_c[i]--;
					calculate(num + 1, res - arr[num + 1]);
					cal_c[i]++;

				}
				if (i == 2) {

					cal_c[i]--;
					calculate(num + 1, res * arr[num + 1]);
					cal_c[i]++;

				}
				if (i == 3) {
					cal_c[i]--;
					calculate(num + 1, res / arr[num + 1]);
					cal_c[i]++;				
				}
			}
		}



	}
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal_c[i];
	}
	res = arr[0];
	calculate(0,res);


	cout << maximum << endl;
	cout << minimum << endl;
}