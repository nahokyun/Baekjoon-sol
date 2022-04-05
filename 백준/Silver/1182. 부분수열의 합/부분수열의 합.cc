#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int s;
int n;
int count_arr = 0;
int flag[20];

void tracking(int num,int sum) {
	if (num == n) {
		return;
	}
	else {
		sum = sum + arr[num];
		if (sum == s)
			count_arr++;
		tracking(num + 1, sum - arr[num]);//이번arr[num]을 더하지 않는경우
		tracking(num + 1, sum);//arr[num]을 더하는경우
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> s;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);

	}
	tracking(0,0);



	cout << count_arr << endl;
}