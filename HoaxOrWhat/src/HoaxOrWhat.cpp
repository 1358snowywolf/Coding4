#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K, input;

	while(true){
		cin >> N;
		if(N == 0) break;
		multiset<int> bills;
		int count = 0;

		for(int i = 0; i < N; i++){
			cin >> K;

			for(int j = 0; j < K; j++){
				cin >> input;
				bills.insert(input);
			}

			int maximum = *(prev(bills.end()));
			int minimum = *bills.begin();

			count += (maximum - minimum);
//			cout << maximum << " " << minimum << endl;

			bills.erase(bills.begin());
			bills.erase(prev(bills.end()));
		}

		cout << count << endl;
	}

	return 0;
}
