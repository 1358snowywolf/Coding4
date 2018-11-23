#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	vector<int> numbers;
	while(cin >> N){
		numbers.push_back(N);
		sort(numbers.begin(), numbers.end());

		if(numbers.size() % 2 == 0){
			int right = numbers[(int) numbers.size() / 2];
			int left = numbers[((int) numbers.size() / 2) - 1];

			cout << (left + right) / 2 << endl;
		}
		else{
			cout << numbers[(int) numbers.size() / 2] << endl;
		}
	}

	return 0;
}
