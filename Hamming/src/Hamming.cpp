#include <bits/stdc++.h>

using namespace std;

bool check(string current, int H){
	int ones = 0;

	for(int i = 0; i < (int) current.size(); i++){
		if(current[i] == '1'){
			ones++;
		}
	}

	return (ones == H);
}

void DFS(string current, int H, int N){
//	if((int) current.size() == N){
//		if(check(current, H)){
//			cout << current << endl;
//		}
//
//		return;
//	}

	if((int) current.size() == N){
		if(H == 0){
			cout << current << endl;
		}
		return;
	}

	DFS(current + "0", H, N);

	if(H > 0){
		DFS(current + "1", H - 1, N);
	}
}

int main() {
//	freopen("ham.out", "w", stdout);
	int C, N, H;
	cin >> C;

	for(int times = 0; times < C; times++){
		cin >> N >> H;
		DFS("", H, N);
		cout << endl;
	}
	return 0;
}
