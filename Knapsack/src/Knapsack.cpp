#include <bits/stdc++.h>

using namespace std;
vector<int> values = {6, 10, 12};
vector<int> weights = {1, 2, 3};
int maxWeight = 5;

void backtrack(const vector<vector<int>> dp, vector<int> used, int i, int j){
	if(i == 0 || j == 0){
		for(int i = 0; i < (int) used.size() - 1; i ++){
			cout << used[i] << ", ";
		}

		cout << "and " << used[used.size() - 1];
		return;
	}

	//not used
	if(dp[i][j] == dp[i - 1][j]){
		backtrack(dp, used, i - 1, j);
	}
	else{
		used.push_back(values[i - 1]);
		backtrack(dp, used, i - 1, j - weights[i - 1]);
	}
}

int main() {
	vector<vector<int>> dp (weights.size() + 1, vector<int> (maxWeight + 1, 0));

	for(int i = 1; i < (int) dp.size(); i++){
		for(int j = 1; j < (int) dp[0].size(); j++){
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
		}
	}

	cout << "Maximum value is " << dp[dp.size() - 1][dp[0].size() - 1] << "." << endl;

	cout << "These are the following numbers that are used: ";
	backtrack(dp, vector<int> (0, 0), dp.size() - 1, dp[0].size() - 1);
	cout << "." << endl;

	return 0;
}
