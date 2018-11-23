#include <bits/stdc++.h>

using namespace std;

int main() {
	string N;

	while(true){
		cin >> N;
		if(N == "#") break;

		if(next_permutation(N.begin(), N.end())){
			cout << N << endl;
		}
		else{
			cout << "No Successor" << endl;
		}
	}

	return 0;
}
