#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;

	while(cin >> N){
		set<int> leftover;
		vector<int> numbers;

		for(int i = 0; i < N; i++){
			int input;
			cin >> input;
			numbers.push_back(input);
		}

		for(int i = 1; i <= N - 1; i++){
			leftover.insert(i);
		}

		for(int i = 0; i < N - 1; i++){
			int difference = abs(numbers[i] - numbers[i + 1]);
			leftover.erase(difference);
		}

//		for(int i : leftover){
//			cout << i << " ";
//		}
//
//		cout << endl;

		if(leftover.empty()){
			cout << "Jolly" << endl;
		}
		else{
			cout << "Not jolly" << endl;
		}
	}
	return 0;
}
