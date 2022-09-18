#include <iostream>
#include <vector>
#include <algorithm>	// thu vien dung cho sort, set_union, set_intersection

using namespace std;

vector<int> nhapVector(vector<int> vec, int soLuongPhanTu);
ostream & operator<<(ostream & os, vector<int> vec);

int main() {
	int n1, n2;

	//	nhap 2 vector
	cout << "nhap so luong phan tu cua vector 1 là: ";
	cin >> n1;
	cout << "nhap so luong phan tu cua vector 2 là: ";
	cin >> n2;

	/*	khai bao vector, can than viec co cap phat vector hay khong rat quan trong.
		neu cap phat thi se khong xai duoc cac lenh nhu push_back, pop_back, size,...
		chi co the xai: ten_vector[i]
		KHONG cap phat thi vector chua co phan tu la vector rong nen co the dung push_back, pop_back,...
		KHONG cap phat muon truy cap tung phan tu thi ta dung ham at(phan_tu_muon_truy_cap)*/

		//	vec1 va vec2 cho nhap xuat, vec3 va vec3 cung tham gia xu ly phep hoi
	vector<int> vec1(n1), vec2(n2), vec3(n1 + n2);

	//	khai bao iterator de dung trong set_union va set_intersection
	vector<int>::iterator it;

	//	nhap 2 vector
	cout << endl << "nhap vector 1 di: ";
	vec1 = nhapVector(vec1, n1);
	cout << "nhap vector 2 di: ";
	vec2 = nhapVector(vec2, n2);

	//	sap xep 2 vector vua nhap duoc, chieu tang dan
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	//	xuat 2 vector ra man hinh
	cout << endl << "xuat vector 1 ra: " << vec1;
	cout << endl << "xuat vector 2 ra: " << vec2;
	cout << endl;

	//	phep hoi cua 2 vector, phep hoi la tap hop tat ca cac phan tu thuoc vector 1 hoac vector 2
	cout << endl << "phep hoi cua 2 vector gom cac phan tu la: ";
	it = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	vec3.resize(it - vec3.begin());
	cout << vec3;

	//	phep giao cua 2 vector, phep giao la tap hop tat ca cac phan tu thuoc vector 1 va vector 2
	cout << endl << "phep giao cua 2 vector gom cac phan tu la: ";
	it = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	vec3.resize(it - vec3.begin());
	cout << vec3;

	cout << endl;
	system("pause");
	return 0;
}

//	nhap vector
vector<int> nhapVector(vector<int> vec, int soLuongPhanTu) {
	for (int i = 0; i < soLuongPhanTu; i++) {
		cin >> vec[i];
	}
	return vec;
}

//	toan tu xuat vector
ostream & operator<<(ostream & os, vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		os << vec[i] << " ";
	}
	return os;
}