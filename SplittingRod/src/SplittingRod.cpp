#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp (N + 1, 0);
	vector<int> values;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		values.push_back(input);
	}

	for(int i = 1; i < (int) dp.size(); i++){
		int maximum = INT_MIN;

		for(int j = 0; j < (int) values.size(); j++){
			if((i - j - 1) >= 0){
				maximum = max(maximum, dp[i - j - 1] + values[j]);
			}
		}

		dp[i] = maximum;
	}

	for(int i = 0; i < (int) dp.size(); i++){
		cout << dp[i] << " ";
	}

	cout << endl << dp[N] << endl;

	return 0;
}
