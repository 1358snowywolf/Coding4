#include <bits/stdc++.h>

using namespace std;

int X[3010], Y[3010], temp[3010];

int Compression(int a[3010], int Z){
	memcpy(temp, a, sizeof(temp));
	sort(temp, temp + Z);
	int newZ = unique(temp, temp + Z) - temp;

	for(int i = 0; i < Z; i++){
		a[i] = (lower_bound(temp, temp + newZ, a[i]) - temp) * 2;
	}

	return newZ * 2;
}

int main() {
//	X[0] = 0;
//	X[1] = 0;
//	X[2] = 5;
//	X[3] = 5;
//	X[4] = 4;
//	X[5] = 0;
//	X[6] = 2;
//
//	Y[0] = 0;
//	Y[1] = 4;
//	Y[2] = 1;
//	Y[3] = 4;
//	Y[4] = 5;
//	Y[5] = 5;
//	Y[6] = 3;
//
//	Compression(X, 7);
//	Compression(Y, 7);
//
//	for(int i = 0; i < 7; i++){
//		cout << X[i] << " ";
//	}
//
//	cout << endl;
//
//	for(int i = 0; i < 7; i++){
//		cout << Y[i] << " ";
//	}

	return 0;
}
