#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp (N + 1, 0);
	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i < (int) dp.size(); i++){
		dp[i] = dp[i - 1] + ((i - 1) * dp[i - 2]);
	}

	cout << dp[N] << endl;

	return 0;
}
