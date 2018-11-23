#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> order, int N){
	stack<int> sta;
	int index = 0;
	int cargo = 0;

	while(cargo < (int) order.size() && index <= N){
		while(!sta.empty() && cargo < (int) order.size() && sta.top() == order[cargo]){
			sta.pop();
			cargo++;
		}

		if(index > N){
			continue;
		}

		index++;
		sta.push(index);
	}

	return cargo == (int) order.size();
}

int main() {
	int N;

	while(cin >> N){
		if(N == 0) break;
		int a;
		cin >> a;

		while(a != 0){
			vector<int> numbers;

			for(int i = 1; i <= N; i++){
				numbers.push_back(a);
				cin >> a;
			}

			if(check(numbers, N)){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
		}

		cout << endl;
	}

	return 0;
}
