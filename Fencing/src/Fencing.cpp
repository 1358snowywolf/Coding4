#include <bits/stdc++.h>

using namespace std;

int count(int N, int K){
	int total = K;
	int same = 0, diff = K;

	for(int i = 2; i <= N; i++){
		same = diff;
		diff = total * (K - 1);
		total = same + diff;
	}

	return total;
}

int main() {
	int N = 3;
	int K = 2;

	cout << count(N, K) << endl;

	return 0;
}
