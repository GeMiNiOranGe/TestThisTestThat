#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ostream & operator<<(ostream & os, vector<int> vec);
bool checkReverse(int n);

int main() {
	int n, sum1 = 0, sum2 = 0, max, min;
	vector<int> vec, vecSort1, vecSort2;

	//	nhap file
	ifstream fileIn("vector_inp.txt");
	for (; fileIn >> n;) {
		vec.push_back(n);
	}
	fileIn.close();

	//	tim so doi xung va chuan bi sap xep so doi xung giam dan
	for (int i = 0; i < vec.size(); i++) {
		if (checkReverse(vec.at(i))) {
			sum1 += vec.at(i);
			vecSort1.push_back(vec.at(i));
		}
		else {
			sum2 += vec.at(i);
			vecSort2.push_back(vec.at(i));
		}
	}

	//	tim max
	max = *max_element(vecSort1.begin(), vecSort1.end());
	min = *min_element(vecSort2.begin(), vecSort2.end());

	//	sap xep giam dan
	sort(vecSort1.rbegin(), vecSort1.rend());
	sort(vecSort2.begin(), vecSort2.end());

	//	xuat file
	ofstream fileOut("vector_out.txt");
	fileOut << max << " " << sum1 << endl;
	fileOut << vecSort1 << endl;
	fileOut << min << " " << sum2 << endl;
	fileOut << vecSort2;
	fileOut.close();

	return 0;
}

bool checkReverse(int n) {
	int reverse = 0, original = n;
	for (; n > 0; ) {
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	if (reverse == original) {
		return true;
	}
	else {
		return false;
	}
}

ostream & operator<<(ostream & os, vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		os << vec.at(i) << " ";
	}
	return os;
}
