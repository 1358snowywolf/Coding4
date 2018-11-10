#include <iostream>

using namespace std;

int count(int N){
	int A[N + 1];
	int B[N + 1];
	A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;

	for(int i = 2; i <= N; i++){
		A[i] = A[i - 2] + 2 * B[i - 1];
		B[i] = A[i - 1] + B[i - 2];
	}

	return A[N];
}

int main() {
	int N = 8;

	cout << count(N) << endl;
	return 0;
}
