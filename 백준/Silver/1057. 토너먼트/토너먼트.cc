#include<iostream>

using namespace std;
//2로 나누고 올림으로 접근하는방식


int n, a, b;
int main() {
	cin >> n >> a >> b;
	
	int ct = 0;
	while (a != b) {
		if (a % 2 == 1)
			a = a / 2 + 1;
		else
			a = a / 2;
		if (b % 2 == 1)
			b = b / 2 + 1;
		else
			b = b / 2;
		ct++;
	}
	cout << ct<<endl;





}