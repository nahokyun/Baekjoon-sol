#include<iostream>


using namespace std;
int t;
int n;
int x_1, x_2, y_1, y_2;
int c_1, c_2;
int r;
int ct = 0;
void check() {
	int ar_1 = (c_1 - x_1) * (c_1 - x_1) + (c_2 - y_1) * (c_2 - y_1);
	int ar_2= (c_1 - x_2) * (c_1 - x_2) + (c_2 - y_2) * (c_2 - y_2);
	if (ar_1 >r* r && ar_2 < r*r) {
		ct++;
	}
	if (ar_1 < r*r && ar_2 > r*r) {
		ct++;
	}
}



int main() {
	cin >> t;
	while (t--) {
		ct = 0;
		cin >> x_1 >> y_1;
		cin >> x_2 >> y_2;

		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> c_1 >> c_2;
			cin >> r;
			check();

		}
		cout << ct<<endl;



	}


}