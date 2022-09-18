#include <iostream>
#include <stdio.h> //thu vien cua printf dung de lay so sau "." cua so thuc
#include <iomanip> //thu vien cua cout dung de lay so sau "." cua so thuc
using namespace std;
int main() {
	int a, b, c, d, e, f;
	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	float kq;
	kq = float(a + b + c) / float(d + e + f);
	//printf("%.1f \n", kq);
	cout << fixed << setprecision(1) << kq << endl;
	system("pause");
	return 0;
}